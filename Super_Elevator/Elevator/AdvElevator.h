//
// Created by Rikkual on 2024/5/3.
//

#ifndef AdvElevator_H
#define AdvElevator_H


#include <bits/stdc++.h>
#include "Elevator.h"
#include "Person.hpp"

class AdvElevator : public Elevator {
protected:
    std::vector<Person> people;
public:
    explicit AdvElevator(int _floor);
};


#endif //AdvElevator_H