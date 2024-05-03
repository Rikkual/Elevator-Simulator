//
// Created by Rikkual on 2024/4/15.
//

#include "TerminalControl.h"
#include <bits/stdc++.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else // defined(__linux__) || defined(__unix__)
#include <termios.h>
#include <unistd.h>
#endif

#include "config.h"

#define RESET   "\033[0m"               // 重置颜色
#define RED     "\033[31m"              // 红色
#define GREEN   "\033[32m"              // 绿色
#define YELLOW  "\033[33m"              // 黄色
#define BLUE    "\033[34m"              // 蓝色
#define MAGENTA "\033[35m"              // 紫色
#define CYAN    "\033[36m"              // 青色

const std::unordered_map<string, string> charMap = {
        {"version", VERSION},
        {"default", RESET},
        {"red",     RED},
        {"green",   GREEN},
        {"yellow",  YELLOW},
        {"blue",    BLUE},
        {"magenta", MAGENTA},
        {"cyan",    CYAN}
};

void setUTF8() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#else
    setlocale(LC_ALL, "");
#endif
}

void disableEcho() {
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    mode &= ~ENABLE_ECHO_INPUT;
    SetConsoleMode(hStdin, mode);
#else
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
#endif
}

void enableEcho() {
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    mode |= ENABLE_ECHO_INPUT;
    SetConsoleMode(hStdin, mode);
#else
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
#endif
}

void hideCursor() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
    printf("\033[?25l");
    cout.flush();
#endif
}

void showCursor() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
    cout << "\033[?25h";
    cout.flush();
#endif
}

void getCursorPos(int &x, int &y) {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    x = csbi.dwCursorPosition.X + 1;
    y = csbi.dwCursorPosition.Y + 1;
#else
    printf("\033[6n");
    fflush(stdout);
    scanf("\033[%d;%dR", &y, &x);
#endif
}

void gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    // cout << "\033[2J\033[1;1H";
}

void mySleep(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

void waitForEnter() {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}