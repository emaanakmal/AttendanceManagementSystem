#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>
using namespace std; 

class Attendance {
public:
    void update(string empID, string date, string startTime, string endTime);
};

#endif