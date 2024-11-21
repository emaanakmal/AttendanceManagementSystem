#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Employee.h"
#include "Person.h"

class Supervisor : public Person {
public:
    Supervisor(const std::string& id, const std::string& name) : Person(id, name, "Supervisor") {}

    //void showLowAttendanceReport();
    //void showOutstandingLeaveReport();
    //void showAttendanceReport(const std::string& empID);
    //void showLeaveReport(const std::string& empID);
    bool reviewApplication(string EID, int lvprd, char lvtype);
};

#endif