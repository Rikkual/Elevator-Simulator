//
// Created by Rikkual on 2024/5/3.
//

#include "AdvElevator.h"
#include "TerminalControl.h"


AdvElevator::AdvElevator(int _floor): Elevator(_floor) {}

void AdvElevator::addPerson(Person p) {
    people.push_back(p);
}

void AdvElevator::addPerson(int id, int target) {
    addPerson(Person{id, target});
}

int AdvElevator::getPersonNum() {
    return (int)people.size();
}

void AdvElevator::setUpButton() {
    std::sort(people.begin(), people.end(), [](const Person &a, const Person &b) {
        return a < b;
    });
    int cnt = 0;
    for(auto &p: people) {
        if(p.getTargetFloor() != currentFloor) {
            Elevator::setUpButton(p.getTargetFloor());
            // Printer::clearAbout(INTERACT_Y + cnt); cnt = 0;
        }
        mySleep(500);
        logger->info(std::format("乘客{}已抵达{}楼", p.getId(), p.getTargetFloor()));
        Printer::print(std::format("乘客{}已抵达{}楼", p.getId(), p.getTargetFloor()), ++cnt);
        mySleep(500);
    }
    mySleep(1000);
    Printer::clearAbout(INTERACT_Y + cnt);
}

void AdvElevator::setDownButton() {
    std::sort(people.begin(), people.end(), [](const Person &a, const Person &b) {
        return a > b;
    });
    int cnt = 0;
    for(auto &p: people) {
        if(p.getTargetFloor() != currentFloor) {
            Elevator::setDownButton(p.getTargetFloor());
            // Printer::clearAbout(INTERACT_Y + cnt); cnt = 0;
        }
        mySleep(500);
        logger->info(std::format("乘客{}已抵达{}楼", p.getId(), p.getTargetFloor()));
        Printer::print(std::format("乘客{}已抵达{}楼", p.getId(), p.getTargetFloor()), ++cnt);
        mySleep(500);
    }
    mySleep(1000);
    Printer::clearAbout(INTERACT_Y + cnt);
}
