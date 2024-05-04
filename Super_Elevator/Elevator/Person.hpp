//
// Created by Rikkual on 2024/5/3.
//

#ifndef Person_H
#define Person_H


class Person {
private:
    int id;
    int target;
    friend bool operator<(const Person& p1, const Person& p2) {
        return p1.target < p2.target || (p1.target == p2.target && p1.id < p2.id);
    }
public:
    Person() = default;
    Person(int _id, int _target): id(_id), target(_target) {};
};


#endif //Person_H
