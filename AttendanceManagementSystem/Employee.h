#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "ReadWrite.h"
#include "Guard.h"
#include "Leave.h"
#include "AttendanceReport.h"
#include "LeaveReport.h"
#include "Supervisor.h"
#include "Director.h"

#include<iostream>
#include<fstream>
using namespace std;

class Employee : public Person {
private:

public:
    Employee(const string id, const string name): Person(id, name, "Employee") 
    {
        ofstream create("Attendance.txt", ios::app);
        if (!create.is_open()) {
            cout << "Unable to open the file!" << endl;
            return;
        }
        create << ID << endl;
        create.close();

        ofstream create1("LeftLeaves.txt", ios::app);
        if (!create1.is_open()) {
            cout << "Unable to open the file!" << endl;
            return;
        }
        create1 << ID << " 15" << " " << "21" << endl;
    }

    void showAttendanceReport();
    void showLeaveReport();
    void applyForLeave(Supervisor* spv, Director* drc);
    void MarkAttendance(Guard* grd);
    string getEID();
};

#endif