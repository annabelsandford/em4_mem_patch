/**********************************************
  EM4 Memory Patcher (PEMemLimitMod)
  
  Written by: @annabelsandford
  June 2023
  
  This program allows you to patch the memory limit of
  the EM4 (Emergency 4) executable file. It modifies
  the Portable Executable (PE) file header to increase
  the memory limit, enabling the program to access more
  than 2GB of memory.
**********************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint16_t magic_number;
    uint32_t image_base;
} PEHeader;

typedef struct {
    char* file_path;
    FILE* file_handle;
    uint32_t pe_signature_offset;
    char pe_signature[4];
    uint16_t optional_header_size;
    PEHeader pe_header;
    uint32_t new_memory_limit;
    int success;
} FileData;

typedef struct {
    FileData* files;
    size_t count;
    uint32_t default_memory_limit;
} ApplicationData;

FileData createFileData(const char* file_path, uint32_t new_memory_limit) {
    FileData file_data;
    file_data.file_path = strdup(file_path);
    file_data.file_handle = NULL;
    file_data.pe_signature_offset = 0;
    memset(file_data.pe_signature, 0, sizeof(file_data.pe_signature));
    file_data.optional_header_size = 0;
    memset(&file_data.pe_header, 0, sizeof(file_data.pe_header));
    file_data.new_memory_limit = new_memory_limit;
    file_data.success = 0;
    return file_data;
}

void destroyFileData(FileData* file_data) {
    if (file_data->file_path) {
        free(file_data->file_path);
        file_data->file_path = NULL;
    }
}

void openFiles(ApplicationData* app_data) {
    for (size_t i = 0; i < app_data->count; ++i) {
        app_data->files[i].file_handle = fopen(app_data->files[i].file_path, "r+b");
        if (!app_data->files[i].file_handle) {
            fprintf(stderr, "Failed to open the file: %s\n", app_data->files[i].file_path);
            app_data->files[i].success = 0;
        }
    }
}

void closeFiles(ApplicationData* app_data) {
    for (size_t i = 0; i < app_data->count; ++i) {
        if (app_data->files[i].file_handle) {
            fclose(app_data->files[i].file_handle);
            app_data->files[i].file_handle = NULL;
        }
    }
}

void processPEHeader(FileData* file_data) {
    fseek(file_data->file_handle, file_data->pe_signature_offset, SEEK_SET);
    fread(file_data->pe_signature, sizeof(char), sizeof(file_data->pe_signature), file_data->file_handle);

    if (file_data->pe_signature[0] != 'P' || file_data->pe_signature[1] != 'E' || file_data->pe_signature[2] != '\0' || file_data->pe_signature[3] != '\0') {
        fprintf(stderr, "Invalid PE file: %s\n", file_data->file_path);
        file_data->success = 0;
        return;
    }

    fseek(file_data->file_handle, file_data->pe_signature_offset + 0x18 + 2, SEEK_SET);
    fread(&file_data->optional_header_size, sizeof(uint16_t), 1, file_data->file_handle);

    fseek(file_data->file_handle, file_data->pe_signature_offset + 0x18 + 0x10 + file_data->optional_header_size, SEEK_SET);

    fread(&file_data->pe_header, sizeof(PEHeader), 1, file_data->file_handle);

    if (file_data->pe_header.magic_number == 0x10B) {
        fseek(file_data->file_handle, 0x34, SEEK_CUR);
        fwrite(&file_data->new_memory_limit, sizeof(uint32_t), 1, file_data->file_handle);
    } else if (file_data->pe_header.magic_number == 0x20B) {
        fseek(file_data->file_handle, 0x30, SEEK_CUR);
        fwrite(&file_data->new_memory_limit, sizeof(uint32_t), 1, file_data->file_handle);
    } else {
        fprintf(stderr, "Invalid PE format: %s\n", file_data->file_path);
        file_data->success = 0;
    }

    printf("Memory limit updated for: %s\n", file_data->file_path);
    file_data->success = 1;
}

void modifyExecutableMemoryLimit(ApplicationData* app_data) {
    openFiles(app_data);

    for (size_t i = 0; i < app_data->count; ++i) {
        if (app_data->files[i].file_handle) {
            processPEHeader(&app_data->files[i]);
        }
    }

    closeFiles(app_data);
}

ApplicationData createApplicationData(const char** file_list, size_t count, uint32_t default_memory_limit) {
    ApplicationData app_data;
    app_data.count = count;
    app_data.default_memory_limit = default_memory_limit;

    app_data.files = (FileData*)malloc(count * sizeof(FileData));
    for (size_t i = 0; i < count; ++i) {
        app_data.files[i] = createFileData(file_list[i], default_memory_limit);
    }

    return app_data;
}

void destroyApplicationData(ApplicationData* app_data) {
    if (app_data->files) {
        for (size_t i = 0; i < app_data->count; ++i) {
            destroyFileData(&app_data->files[i]);
        }
        free(app_data->files);
        app_data->files = NULL;
    }
}

int main() {
    const char* file_list[] = { "C:/Users/sabrina/OneDrive/Documents/EEM/em4.exe", "C:/Program Files (x86)/Steam/steamapps/common/EMERGENCY 4 Deluxe/em4.exe"};
    const size_t num_files = sizeof(file_list) / sizeof(file_list[0]);
    const uint32_t default_memory_limit = 3 * 1024 * 1024 * 1024;  // 3GB

    ApplicationData app_data = createApplicationData(file_list, num_files, default_memory_limit);
    modifyExecutableMemoryLimit(&app_data);
    destroyApplicationData(&app_data);

    return 0;
}