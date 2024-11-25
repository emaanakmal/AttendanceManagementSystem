#ifndef LEAVE_H
#define LEAVE_H
using namespace std;
#include <iostream>
#include <string>

class Leave {
private:
    string EID;
    int LeavePeriod;
    char LeaveType;

public:
    Leave(string id, int lvprd, char lvtype) : EID(id), LeavePeriod(lvprd), LeaveType(lvtype) {}

    bool RequestApproval();
    void addLeave();
};

#endif

