//
// Created by Rikkual on 2024/4/12.
//

#include <bits/stdc++.h>
#include "Elevator.h"
#include "TerminalControl.h"

// using namespace std;

Elevator::Elevator(int _floor): floor(_floor) {
    currentFloor = INIT_FLOOR;
    up = down = false;
}

void Elevator::setUpButton(int targetFloor) {
    logger->info(std::format("电梯上行，计划从{}至{}楼", currentFloor, targetFloor));
    Printer::closeDoor(); up = true;
    int tmp = currentFloor + 1;
    for(int i = tmp; i <= targetFloor; i++) {
        int cnt = std::min(i - tmp, targetFloor - i);
        cnt = ELEVATOR_SPEED_CNT - cnt;
        if(cnt < 1) cnt = 1;
        setFloorNumber(i, cnt);
    }
    Printer::openDoor(); up = false;
    logger->info(std::format("电梯已抵达{}楼", targetFloor));
}

void Elevator::setDownButton(int targetFloor) {
    logger->info(std::format("电梯下行，计划从{}至{}楼", currentFloor, targetFloor));
    Printer::closeDoor(); down = true;
    int tmp = currentFloor - 1;
    for(int i = tmp; i >= targetFloor; i--) {
        int cnt = std::min(tmp - i, i - targetFloor);
        cnt = ELEVATOR_SPEED_CNT - cnt;
        if(cnt < 1) cnt = 1;
        setFloorNumber(i, cnt);
    }
    Printer::openDoor(); down = false;
    logger->info(std::format("电梯已抵达{}楼", targetFloor));
}

void Elevator::setFloorNumber(int floorNumber, int cnt) {
    logger->info(std::format("电梯目前位于{}层", floorNumber));
    // gotoxy(FLOOR_DISPLAY_X, FLOOR_DISPLAY_Y);
    // cout << floorNumber;
    for(int i = 1; i <= cnt; i++) {
        gotoxy(FLOOR_DISPLAY_X + 2, FLOOR_DISPLAY_Y);
        if(up) cout << "↑";
        if(down) cout << "↓";
        mySleep(ELEVATOR_SPEED / 2);
        gotoxy(FLOOR_DISPLAY_X + 2, FLOOR_DISPLAY_Y);
        cout << " ";
        mySleep(ELEVATOR_SPEED / 2);
    }
    gotoxy(FLOOR_DISPLAY_X, FLOOR_DISPLAY_Y);
    cout << floorNumber;
    currentFloor = floorNumber;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

void Elevator::setLogger(Logger* _logger) {
    logger = _logger;
}

void Elevator::setPrinter(Printer* _printer) {
    printer = _printer;
}