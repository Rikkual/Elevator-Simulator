//
// Created by Rikkual on 2024/4/12.
//

#include <bits/stdc++.h>
#include "Elevator/Elevator.h"
#include "Elevator/AdvElevator.h"
#include "Logger/Logger.h"
#include "TerminalControl.h"

#include "config.h"
// using namespace std;

NAMESPACE_SOLVE_ELEVATOR
void solve(Elevator &elevator, Logger &logger, Printer &printer);
NAMESPACE_END

NAMESPACE_SOLVE_ADVELEVATOR
void solve(AdvElevator &advElevator, Logger &logger, Printer &printer);
NAMESPACE_END

void choseMode(Logger &logger, Printer &printer);
bool executeOption(Logger &logger, Printer &printer, int choice);
void solveElevator(Logger &logger, Printer &printer);
void solveAdvElevator(Logger &logger, Printer &printer);

signed main() {
    setUTF8();
    Logger logger;
    Printer printer;
    hideCursor(); disableEcho();
#ifdef DEBUG_ABOUT_JUMP
    Printer::printOpenDoor();
#else
    Printer::printCloseDoor();
    Printer::printAbout();
    waitForEnter();
    // Printer::openDoor();
    Printer::clearAbout();
#endif
    choseMode(logger, printer);
    return 0;
}

std::vector<string> options = {
        "单人电梯",
        "多人电梯",
        "退出程序",
};

void choseMode(Logger &logger, Printer &printer) {
#ifdef DEBUG_ELEVATOR
    solveElevator(logger, printer);
    return;
#endif
#ifdef DEBUG_ADVELEVATOR
    solveAdvElevator(logger, printer);
    return;
#endif
    int stx = INTERACT_X, sty = INTERACT_Y;
    printer.setMessage("本电梯支持两种运行模式");
    while(true) {
        int x = stx, y = sty;
        printer.printOptions(x, y, options);
        showCursor(); enableEcho();
        int mode;
        if(!cin >> mode) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mode = -114514;
        }
        hideCursor(); disableEcho();

        getCursorPos(x, y);
        Printer::clearAbout(y);
        if(!executeOption(logger, printer, mode)) break;
    }
}

bool executeOption(Logger &logger, Printer &printer, int choice) {
    switch(choice) {
        case 1:
            solveElevator(logger, printer);
            return false;

        case 2:
            solveAdvElevator(logger, printer);
            return false;

        case 3:
            return false;

        default:
            return true;
    }
}

void solveElevator(Logger &logger, Printer &printer) {
#ifndef DEBUG_ABOUT_JUMP
    Printer::openDoor();
#endif
    logger.info("电梯当前运行模式：单人电梯");
    Elevator elevator(FLOOR);
    elevator.setLogger(&logger);
    elevator.setPrinter(&printer);
    Printer::printFloorBase(elevator.getCurrentFloor());
    SolveElevator::solve(elevator, logger, printer);
}

void solveAdvElevator(Logger &logger, Printer &printer) {
#ifndef DEBUG_ABOUT_JUMP
    Printer::openDoor();
#endif
    logger.info("电梯当前运行模式：多人电梯");
    AdvElevator elevator(FLOOR);
    elevator.setLogger(&logger);
    elevator.setPrinter(&printer);
    Printer::printFloorBase(elevator.getCurrentFloor());
    SolveAdvElevator::solve(elevator, logger, printer);
}