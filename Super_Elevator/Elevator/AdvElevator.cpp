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