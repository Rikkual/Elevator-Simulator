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

NAMESPACE_SOLVE_ELEVAOTR
void solve(Elevator &elevator, Logger &logger, Printer &printer);
NAMESPACE_END

NAMESPACE_SOLVE_ADVELEVAOTR
void solve(AdvElevator &advElevator, Logger &logger, Printer &printer);
NAMESPACE_END

void choseMode(Logger &logger, Printer &printer);
void solveElevator(Logger &logger, Printer &printer);
void solveAdvElevator(Logger &logger, Printer &printer);

signed main() {
    setUTF8();
    Logger logger;
    Printer printer;

    hideCursor(); disableEcho();
    Printer::printDoor();
    Printer::printAbout();
    waitForEnter();
    Printer::openDoor();
    Printer::clearAbout();

    choseMode(logger, printer);
    // showCursor(); enableEcho();

    // SolveElevator::solve(elevator, logger, printer);

    return 0;
}

std::vector<string> options = {
        "单人电梯",
        "多人电梯",
        "退出程序",
};

void choseMode(Logger &logger, Printer &printer) {
    int x = INTERACT_X, y = INTERACT_Y;
    printer.setMessage("本电梯支持两种运行模式");
    printer.printOptions(x, y, options);
    showCursor(); enableEcho();
    int mode; cin >> mode;
    hideCursor(); disableEcho();

    getCursorPos(x, y);
    Printer::clearAbout(y);

    switch(mode) {
        case 1:
            Printer::clearAbout(y);
            solveElevator(logger, printer);
            break;

        case 2:
            Printer::clearAbout(y);
            solveAdvElevator(logger, printer);
            break;

        default:
            break;
    }
}

void solveElevator(Logger &logger, Printer &printer) {
    Elevator elevator(FLOOR);
    elevator.setLogger(&logger);
    elevator.setPrinter(&printer);
    Printer::printFloorBase(elevator.getCurrentFloor());
    SolveElevator::solve(elevator, logger, printer);
}

void solveAdvElevator(Logger &logger, Printer &printer) {
    AdvElevator elevator(FLOOR);
    elevator.setLogger(&logger);
    elevator.setPrinter(&printer);
    Printer::printFloorBase(elevator.getCurrentFloor());
    SolveAdvElevator::solve(elevator, logger, printer);
}