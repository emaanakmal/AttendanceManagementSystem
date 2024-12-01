#ifndef LEAVE_H
#define LEAVE_H

#include "Supervisor.h"
#include "Director.h"
#include "Employee.h"

#include <iostream>
#include <string>
using namespace std;

class Leave {
private:
    string EID;
    int LeavePeriod;
    char LeaveType;

public:
    Leave(string id, int lvprd, char lvtype) : EID(id), LeavePeriod(lvprd), LeaveType(lvtype) {}

    bool RequestApproval(Supervisor* spv, Director* drc);
    void addLeave(string date);
    void updateTable();
};

#endif

