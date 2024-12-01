#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Employee.h"
#include "ReadWrite.h"
#include <string>
using namespace std;

class Director : public Employee {
public:
    Director(const string& id, const string& name)
        : Employee(id, name) {
        Position = "Director";
    }

    void showLowAttendanceReport();
    void showOutstandingLeaveReport();
    void showAttendanceReport();
    void showLeaveReport();
    bool reviewApplication(string EID, int lvprd, char lvtype);
};

#endif