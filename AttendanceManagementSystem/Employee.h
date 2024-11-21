#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
public:
    Employee(const std::string& id, const std::string& name): Person(id, name, "Employee") {}

    void showAttendanceReport();
    void showLeaveReport();
    void applyForLeave();
    void checkIn();
    void checkOut();
};

#endif