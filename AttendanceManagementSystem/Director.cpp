#include "Director.h"

#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool Director::reviewApplication(string EID, int lvprd, char lvtype) { 
    // director approves official and earned leaves after supervisors has done so too and passed it on

    bool decision = 1;
    string Eleft;
    string Cleft;
    cout << "Employee " << EID << " is requesting for a " << lvtype << " leave for a time period of " << lvprd << " days\n";

    ReadWriteLeave rdl(EID, lvprd, lvtype);
    rdl.readleftleaves(&Eleft, &Cleft);

    if (lvtype == 'O') {
        cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
    }

    else if (lvtype == 'E') {
        if (lvprd <= stoi(Eleft))
            cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
    }

    return decision;
}

void Director::showLowAttendanceReport() {
    AttendanceReport ar;
    ar.lowAttendanceReport();
}

void Director::showAttendanceReport()
{
    string EID;
    cout << "Enter Employee ID: "; cin >> EID; cout << endl;

    AttendanceReport ar;
    ar.generateReport(EID);
}

void Director::showOutstandingLeaveReport()
{
    LeaveReport lr;
    lr.outstandingLeavesReport();
}

void Director::showLeaveReport()
{
    string EID;
    cout << "Enter the Employee ID of the employee whose Leave details are required: "; cin >> EID; cout << endl;

    LeaveReport lr;
    lr.generateReport(EID);
}