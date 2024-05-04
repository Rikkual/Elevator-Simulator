//
// Created by Rikkual on 2024/4/12.
//

#ifndef Elevator_H
#define Elevator_H

#include <bits/stdc++.h>
#include "Logger/Logger.h"
#include "Printer/Printer.h"

#include "config.h"

class Elevator {
protected:
    int floor;
    bool up, down;
    int currentFloor;
    Logger *logger = nullptr;
    Printer *printer = nullptr;
public:
    explicit Elevator(int floor);
    void setUpButton(int targetFloor);
    void setDownButton(int targetFloor);
    void setFloorNumber(int floorNumber, int cnt = 1);
    [[nodiscard]] int getCurrentFloor() const;
    void setLogger(Logger *logger);
    void setPrinter(Printer *printer);
};


#endif //Elevator_H