# Emergency 4 Memory Patcher

[![License](https://img.shields.io/badge/License-BSD%203--Clause-orange.svg)](https://opensource.org/licenses/BSD-3-Clause) [![Platform](https://img.shields.io/badge/Platform-Windows-brightgreen.svg)](https://www.microsoft.com/en-us/windows)

The EM4 Mem Patcher is a tool specifically developed to tackle memory-related issues and crashes that players may encounter while playing Emergency 4. By expanding the memory capacity of your Emergency 4 executable, this patcher enables the game to handle larger amounts of data. This enhancement significantly reduces crashes caused by memory limitations, resulting in a more stable gaming environment and an improved gameplay experience.

## Troubleshooting
- **"XXXXX.dll is missing" error**: This error means that the game cannot access a Library needed to start the game. This usually means that your particular Version of EM4 is not supported. Do not open an issue, you are simply not compatible. I cannot help you.
- **The game crashes**: Check both `em4.exe` and `Em4Deluxe.exe`, as both are modified by the tool. Try starting the game with both executables. If you do not have two executables, that's okay and to be expected as well depending on your setup. Start the game as administrator and enable Windows XP SP3 compatibility mode. If it still doesn't help, please [contact me here for more assistance](https://github.com/annabelsandford/). There is a chance your specific setup does not support the changes made to the executables.
- **The EM4P.exe doesn't start**: You need the .NET Framework to run EM4 Mem Patcher. Please make sure that's installed.
- **The EM4P.exe crashes**: If .NET Framework is installed and the EM4P.exe starts (but then crashes), please make sure to run EM4P.exe as an administrator. If that doesn't help, make sure you're on Windows 7 or newer. Windows XP / Vista aren't necessarily supported (untested). If all of that doesn't help, check if you're on a 64 Bit System. Most people do not realize that this tool won't start (or even help you if you manage to run it) when run on a 32 Bit System.
- **The patching process fails**: Check the Console within the EM4 Mem Patcher (bottom right). Usually that should give you a clear error and help you figuring out what the problem is. Most of the time that problem is a read/write issue, means the directory where your EM4.exe, or the EM4.exe itself, is write-locked and cannot be edited. Usually, running the EM4P.exe as an administrator should help. If not, you need to figure out your Windows User settings and make sure you have the rights to run a tool like this.

## Key Features

- **Enhanced Memory Support**: The EM4 Memory Patcher significantly expands the memory capacity of your Emergency 4 executable, enabling the game to efficiently handle larger amounts of data. By doing so, it effectively reduces crashes resulting from memory limitations, resulting in a more stable and enjoyable gaming environment.

- **Intuitive User Interface**: With its intuitive design, applying the required modifications to your Emergency 4 executable becomes a hassle-free process, requiring just a few simple clicks.

- **Versatile Compatibility**: The EM4 Mem Patcher seamlessly integrates with different versions of Emergency 4, ensuring compatibility across various game releases. Whether you possess the Steam or CD version, the patcher effortlessly adapts to provide the necessary fixes and enhancements, guaranteeing a smooth experience regardless of your game edition.

## Usage

1. Download the latest release of EM4 Mem Patcher from the [Releases](https://github.com/annabelsandford/em4_mem_patch/releases) page.
2. Extract the downloaded archive to a convenient location on your System. (EM4P.exe & readme.txt)
3. Launch the EM4 Mem Patcher executable (EM4P.exe)
4. IF STEAM: The EM4 Mem Patcher should automatically patch your correct executable.
5. IF NOT AUTOMATIC: Select your Emergency 4 executable file (e.g., `em4.exe` or `Em4Deluxe.exe`)
6. Click the "OK" button to apply the modifications.
7. Launch Emergency 4 and enjoy a more stable and enjoyable gameplay experience.

Be aware that the EM4 Mem Patcher automatically creates a backup of your Emergency 4 executable file within the same folder, named "ba4".
**It is strongly advised that users independently create their own backups of their em4.exe**. This ensures that you have an additional safeguard and a secure restore point in the event of any unexpected issues that may arise during the patching process.

## Compatibility
- All versions of EM4 / 911:FR are 100% compatible. Thanks to all contributors!

## Contributing

Contributions to EM4 Mem Patcher are welcome! If you encounter any bugs, have suggestions, or would like to contribute to the project, please open an issue or submit a pull request. For major changes, it is recommended to discuss them first in an issue to ensure they align with the project's goals.

## License

EM4 Mem Patcher is licensed under the [BSD 3-Clause License](https://opensource.org/licenses/BSD-3-Clause). Feel free to use, modify, and distribute the patcher in accordance with the terms of the license.
