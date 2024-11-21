#ifndef LEAVE_H
#define LEAVE_H

#include <string>

class Leave {
private:
    std::string ID;
    std::string Name;
    std::string LeavePeriod;
    std::string Reason;
    std::string DateOfApplication;
    std::string LeaveType;

public:
    bool requestApproval();
    void addLeave();
};

#endif