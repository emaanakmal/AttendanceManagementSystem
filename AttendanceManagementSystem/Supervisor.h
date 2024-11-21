#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Employee.h"

class Supervisor : public Employee {
public:
    Supervisor(const std::string& id, const std::string& name)
        : Employee(id, name) {
        Position = "Supervisor";
    }

    void showLowAttendanceReport();
    void showOutstandingLeaveReport();
    void showAttendanceReport(const std::string& empID);
    void showLeaveReport(const std::string& empID);
    void reviewApplication();
};

#endif