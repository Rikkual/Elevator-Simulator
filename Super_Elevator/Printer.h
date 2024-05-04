//
// Created by Rikkual on 2024/4/25.
//

#ifndef Printer_H
#define Printer_H


#include <bits/stdc++.h>

#include "config.h"

class Printer {
private:
    string message = {};
public:
    static void printDoor();
    static void printAbout();
    static void clearLine(int x, int y);
    static void clearAbout(int y = 18);
    static void closeDoor();
    static void openDoor();
    static void printFloorBase(int floor);
    static void printDevisionLine(int &x, int &y, int len = DEVISIONLINE_LENGTH);
    void setMessage(const string& _message);
    [[nodiscard]] string Message() const;
    void printOptions(int x, int y, const std::vector<string>& options);
};


#endif //Printer_H
