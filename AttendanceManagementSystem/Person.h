#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string ID;
    string Name;
    string Position;

public:
    Person(const string& id, const string& name, const string& position)
        : ID(id), Name(name), Position(position) {}
    virtual ~Person() = default;
};

#endif