#ifndef GUARD_H
#define GUARD_H

#include "Person.h"

class Guard : public Person {
public:
    Guard(const std::string& id, const std::string& name)
        : Person(id, name, "Guard") {}

    void markAttendance();
};

#endif