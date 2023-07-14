#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <time.h>
#include <fstream>
#include <shared_mutex>
#include <Windows.h>        // for color console
#include <conio.h>          // for color console
#include <stdio.h>          // for color console

enum colorConsole {
    White = 0,
    Blue = 1,
    Green = 2,
    Red = 4,
    Pink = 5
};


class Logger {
private:
    std::ofstream outStream;
    std::shared_mutex shared_mutex;
    HANDLE hConsole;
public:
    Logger();
    ~Logger() {}
    void writeFile(std::string str);
    void last_line();
};

