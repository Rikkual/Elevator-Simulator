//
// Created by Rikkual on 2024/5/3.
//

#ifndef Person_H
#define Person_H


class Person {
private:
    int target;
    friend bool operator<(const Person& p1, const Person& p2) {
        return p1.target < p2.target;
    }
public:
    Person() {};
    Person(int _target): target(_target) {};
};


#endif //Person_H
