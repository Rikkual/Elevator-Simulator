//
// Created by Rikkual on 2024/4/14.
//

#ifndef TERMINALCONTROL_H
#define TERMINALCONTROL_H

#include <bits/stdc++.h>

#include "config.h"

extern const std::unordered_map<string, string> charMap;

void setUTF8();
void disableEcho();
void enableEcho();
void hideCursor();
void showCursor();
void getCursorPos(int& row, int& col);
void gotoxy(int x, int y);
void clearScreen();
void mySleep(int ms);
void waitForEnter();


#endif //TERMINALCONTROL_H