#pragma once

#include <iostream>
#include <windows.h>
#include <string>

class Process
{
public:
    Process(std::string path);
    virtual ~Process();
    bool InjectDLL(std::string dllName);
    bool Create();
    void Run();

protected:

private:
    std::string path;
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

};