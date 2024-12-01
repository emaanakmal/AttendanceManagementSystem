#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Person.h"
#include "ReadWrite.h"
#include "AttendanceReport.h"
#include "LeaveReport.h"
#include <string>
using namespace std;

class Director : public Person {
public:
    Director(const string& id, const string& name)
        : Person(id, name, "Director") {
    }

    void showLowAttendanceReport();
    void showOutstandingLeaveReport();
    void showAttendanceReport();
    void showLeaveReport();
    bool reviewApplication(string EID, int lvprd, char lvtype);
};

#endif