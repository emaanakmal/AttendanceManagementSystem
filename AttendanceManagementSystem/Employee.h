#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Guard.h"
#include "Supervisor.h"
#include<fstream>
#include<iostream>
#include "Supervisor.h"
#include "Guard.h"
using namespace std;

class Employee : public Person {
private:

public:
    Employee(const std::string id, const std::string name): Person(id, name, "Employee") 
    {
        ofstream create("Attendance.txt", ios::app);
        if (!create.is_open()) {
            cout << "Unable to open the file!" << endl;
            return;
        }
        create << ID << endl;
        create.close();
    }

    void showAttendanceReport();
    void showLeaveReport();
    void applyForLeave();
    void MarkAttendance(Guard* grd);
};

#endif