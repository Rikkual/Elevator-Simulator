//
// Created by Rikkual on 2024/5/3.
//

#ifndef Person_H
#define Person_H


class Person {
private:
    int id;
    int targetFloor;
    friend bool operator<(const Person& p1, const Person& p2) {
        return p1.targetFloor < p2.targetFloor || (p1.targetFloor == p2.targetFloor && p1.id < p2.id);
    }
    friend bool operator>(const Person& p1, const Person& p2) {
        return p1.targetFloor > p2.targetFloor || (p1.targetFloor == p2.targetFloor && p1.id > p2.id);
    }
public:
    Person() = default;
    Person(int _id, int _targetFloor): id(_id), targetFloor(_targetFloor) {};
    [[nodiscard]] int getId() const {
        return id;
    }
    [[nodiscard]] int getTargetFloor() const {
        return targetFloor;
    }
};


#endif //Person_H
