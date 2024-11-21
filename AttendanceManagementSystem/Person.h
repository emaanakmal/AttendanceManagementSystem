#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    std::string ID;
    std::string Name;
    std::string Position;

public:
    Person(const std::string& id, const std::string& name, const std::string& position)
        : ID(id), Name(name), Position(position) {}
    virtual ~Person() = default;
};

#endif