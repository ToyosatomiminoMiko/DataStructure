/**
 * @file clic.cpp
 * @author your name (you@domain.com)
 * @brief 命令行-彩色
 * @version 0.1
 * @date 2022-06-30
 */

#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

void timenow()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "[" << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << "]";
}

void info(string str)
{
    timenow();
    cout << "\033[36m[Info]\033[0m" << str << endl;
}

void warn(string str)
{
    timenow();
    cout << "\033[33m[Warn]\033[0m" << str << endl;
}

void fini(string str)
{
    timenow();
    cout << "\033[31m[Fini]\033[0m" << str << endl;
}

int main()
{
    info("Visual Studio Code");
    warn("Visual Studio Code");
    fini("Visual Studio Code");
    return 0;
}

/* Waiting to die... */
