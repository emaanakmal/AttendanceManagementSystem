#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Guard.h"

class Employee : public Person {
private:

public:
    Employee(const std::string& id, const std::string& name): Person(id, name, "Employee") {}

    void showAttendanceReport();
    void showLeaveReport();
    void applyForLeave(Supervisor* sup);
    void checkIn(Guard grd);
    void checkOut();
};

#endif