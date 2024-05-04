//
// Created by Rikkual on 2024/4/12.
//

#include <bits/stdc++.h>
#include "Elevator.h"
#include "AdvElevator.h"
#include "Logger.h"
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
    // Printer::printFloorBase(elevator.getCurrentFloor());
    // showCursor(); enableEcho();

    // SolveElevator::solve(elevator, logger, printer);

    return 0;
}

std::vector<string> options = {
        "电梯上行",
        "电梯下行",
        "打开日志",
        "退出程序"
};

void choseMode(Logger &logger, Printer &printer) {
    int x = INTERACT_X, y = INTERACT_Y;
    printer.printOptions(x, y, options);
    showCursor(); enableEcho();
    int mode; cin >> mode;
    hideCursor(); disableEcho();
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
    SolveElevator::solve(elevator, logger, printer);
}

void solveAdvElevator(Logger &logger, Printer &printer) {

}