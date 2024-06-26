//
// Created by Rikkual on 2024/4/25.
//

#ifndef Printer_H
#define Printer_H


#include <bits/stdc++.h>

#include "config.h"

class Printer {
private:
    int curX, curY;
    string message = {};
public:
#ifdef DEBUG_ABOUT_JUMP
    static void printOpenDoor();
#endif
    void setxy(int x, int y);
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    static void printCloseDoor();
    static void printAbout();
    static void clearLine(int x, int y, int len = DELETE_LINE_LENGTH, bool animation = true);
    static void clearLine(int x, int y, bool animation);
    static void clearAbout(int y = 18);
    static void closeDoor();
    static void openDoor();
    static void printFloorBase(int floor);
    static void printDevisionLine(int &x, int &y, int len = DEVISIONLINE_LENGTH);
    void setMessage(const string& _message);
    [[nodiscard]] string Message() const;
    void printOptions(int x, int y, const std::vector<string>& options);
    void print(const string &message, int x, int y);
    void print(const string &message);
};


#endif //Printer_H
