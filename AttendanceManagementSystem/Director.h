#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Employee.h"

class Director : public Employee {
public:
    Director(const std::string& id, const std::string& name)
        : Employee(id, name) {
        Position = "Director";
    }

    void showLowAttendanceReport();
    void showOutstandingLeaveReport();
    void showAttendanceReport(const std::string& empID);
    void showLeaveReport(const std::string& empID);
    void reviewApplication();
};

#endif