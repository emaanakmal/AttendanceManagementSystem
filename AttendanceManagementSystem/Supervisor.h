#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Person.h"
#include "ReadWrite.h"
#include "AttendanceReport.h"
#include "LeaveReport.h"

class Supervisor : public Person {
public:
    Supervisor(const std::string& id, const std::string& name) : Person(id, name, "Supervisor") {}

    void showOutstandingLeaveReport();
    void showAttendanceReport();
    void showLowAttendanceReport();
    void showLeaveReport();
    bool reviewApplication(string EID, int lvprd, char lvtype);
};

#endif