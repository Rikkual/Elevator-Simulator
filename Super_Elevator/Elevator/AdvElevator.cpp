//
// Created by Rikkual on 2024/5/3.
//

#include "AdvElevator.h"


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
    for(auto &p: people) {
        if(p.getTargetFloor() == currentFloor) {
            logger->info("");
            printer->print(std::format(""));
        }
    }
}

void AdvElevator::setDownButton() {

}
