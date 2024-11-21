#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>
using namespace std; 

class Attendance {
    string EmployeeID;
    string PunchInTime;
    string PunchOutTime;

public:
    void updateRecord(const string& empID, const string& punchIn, const string& punchOut);
};

#endif