#include <stdio.h>
#include <windows.h>
#include <stdarg.h>
#include "Process.h"
#include <iostream>

int Bail(int result) {
    printf("Press enter to exit.\n");
    std::cin.ignore();
    return result;
}

bool FileExists(const char* fileName) {
    DWORD dwAttrib = GetFileAttributesA(fileName);
    return (dwAttrib != INVALID_FILE_ATTRIBUTES && !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

int main()
{
    const char* exePath = "Enchanted Cave 2.exe";

    if (!FileExists(exePath)) {
        printf("%s not found!", exePath);
        return 1;
    }


    Process process(exePath);

    //Create game in suspended state
    if (!process.Create()) {
        printf("Failed to create process: %lu", GetLastError());
        return Bail(1);
    } else {
        printf("%s was successfully started.\n\n", exePath);
    }

    process.InjectDLL(std::string("ModLoader.dll"));
    Sleep(250);

    process.Run();

    Sleep(3000);
    return 0;
}