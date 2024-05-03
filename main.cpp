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

signed main() {
    setUTF8();

    Logger logger;
    Printer printer;
    Elevator elevator(FLOOR);
    elevator.setLogger(&logger);
    elevator.setPrinter(&printer);

    hideCursor(); disableEcho();
    Printer::printDoor();
    Printer::printAbout();
    waitForEnter();

    Printer::openDoor();
    Printer::clearAbout();
    Printer::printFloorBase(elevator.getCurrentFloor());
    // showCursor(); enableEcho();

    SolveElevator::solve(elevator, logger, printer);

    return 0;
}

void choseMode(Logger &logger, Printer &printer) {

}