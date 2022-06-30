/**
 * @file clic.cpp
 * @author your name (you@domain.com)
 * @brief 命令行-彩色
 * @version 0.1
 * @date 2022-06-30
 *
 */

#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

void info(string str)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "[" << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << "]";
    cout << "\033[36m " << str << " \033[0m" << endl;
}
void warn(string str)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "[" << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << "]";
    cout << "\033[33m " << str << " \033[0m" << endl;
}
void triu(string str)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "[" << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << "]";
    cout << "\033[31m " << str << " \033[0m" << endl;
}

int main()
{
    info("Visual Studio Code");
    warn("Visual Studio Code");
    triu("Visual Studio Code");
    return 0;
}

/* Waiting to die... */
