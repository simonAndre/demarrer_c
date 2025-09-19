# tester cmake sur vscode

ce projet permet de valider et lancer la mise en place de l'utilisation de cmake sur vscode.
Le projet C est très simple, il ne comporte que 2 fichiers de code. tous les fichiers de code doivent être déclarés dans le fichier CMakeLists.txt. Donc si on en rajoute, il faut mettre à jour ce fichier.

## prérequis: installation vscode et cmake

sous windows: 
1. Installer Visual Studio Code ---
Write-Host "Installation de Visual Studio Code..."
winget install --id Microsoft.VisualStudioCode -e --accept-source-agreements --accept-package-agreements

2. Installer CMake ---
Write-Host "Installation de CMake..."
winget install --id Kitware.CMake -e --accept-source-agreements --accept-package-agreements

3. Installer 7-Zip (utile pour extraire MinGW) ---
Write-Host "Installation de 7-Zip..."
winget install --id 7zip.7zip -e --accept-source-agreements --accept-package-agreements

4. Télécharger MinGW-w64 (WinLibs) ---
Write-Host "Téléchargement de MinGW-w64 (WinLibs)..."
$mingwUrl = "https://github.com/brechtsanders/winlibs_mingw/releases/download/13.2.0-17.0.6-11.0.1-r1/winlibs-x86_64-posix-seh-gcc-13.2.0-llvm-17.0.6-mingw-w64ucrt-11.0.1-r1.7z"
$zipPath = "$env:TEMP\mingw64.7z"
Invoke-WebRequest -Uri $mingwUrl -OutFile $zipPath

5. Extraire dans C:\mingw64 ---
Write-Host "Extraction de MinGW-w64..."
$destPath = "C:\mingw64"
if (!(Test-Path $destPath)) { New-Item -Path $destPath -ItemType Directory }
& "C:\Program Files\7-Zip\7z.exe" x $zipPath -o"$destPath" -y

6. Ajouter MinGW-w64 au PATH ---
Write-Host "Configuration du PATH..."
$mingwBin = "C:\mingw64\mingw64\bin"
[System.Environment]::SetEnvironmentVariable("Path", $env:Path + ";$mingwBin", [System.EnvironmentVariableTarget]::Machine)

7. Vérification ---
Write-Host "Vérification des installations..."
cmd /c "gcc --version"
cmd /c "cmake --version"
cmd /c "code --version"

## configuration de cmake pour ce projet

### Pour Windows

1. vérifier le fichier CMakeLists.txt
2. créer un repertoire build dans le repertoire projet,
3. depuis ./build/ lancer la commande: `cmake -G "MinGW Makefiles" ..`
4. lancez la commande  `cmake -DCMAKE_BUILD_TYPE=Debug ..` pour activer la génération des symboles de debogage au build
5. installez l'extension `ms-vscode.cpptools-extension-pack`
6. ajoutez une fichier.vscode/launch.json avec ce contenu  (adaptez les lignes: program et miDebuggerPath) : 
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/hello.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/msys64/ucrt64/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }

    ]
}
``` 

### Pour Linux

#### configuration de cmake en ligne de commande

1. vérifier le fichier CMakeLists.txt
2. créer un repertoire build dans le repertoire projet,
3. se déplacer dans ./build/ : `cd build`
4. générer le Makefile avec la commande: `cmake -G "Unix Makefiles" ..`  
5. builder le projet avec le make file : `make`
6. lancer le programme: `./hello`

#### configuration du débogage dans vscode

1. installer l'extension vs-code `ms-vscode.cmake-tools`
2. sur le bandeau de commandes de gauche, lancer CMake
3. si besoin, installer gdb (sur arch : `yay -S gdb`)
4. lancez la commande  `cmake -DCMAKE_BUILD_TYPE=Debug ..` pour activer la génération des symboles de debogage au build
5. installez l'extension `ms-vscode.cpptools-extension-pack`
6. ajoutez une fichier.vscode/launch.json avec ce contenu  (adaptez les lignes: program et miDebuggerPath) : 
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/hello",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/sbin/gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }

    ]
}
``` 
## utilisation de cmake