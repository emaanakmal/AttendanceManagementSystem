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

    // get info on how many leaves left for each type
    ReadWriteLeave rdl(EID, lvprd, lvtype);
    rdl.readleftleaves(&Eleft, &Cleft);

    // if official then no cap on number of leaves
    if (lvtype == 'O') {
        cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
    }

    // if earned leaves then check if quota full before approving
    else if (lvtype == 'E') {
        if (lvprd <= stoi(Eleft))
            cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
    }

    return decision;
}

void Director::showLowAttendanceReport() {
    // create attendance report object
    AttendanceReport ar;
    // call low attendance function
    ar.lowAttendanceReport();
}

void Director::showAttendanceReport() {
    // input employee id for relevant employee   
    string EID;
    cout << "\nEnter Employee ID: "; cin >> EID; cout << endl;

    // create attendance report object
    AttendanceReport ar;
    ar.generateReport(EID);
}

void Director::showOutstandingLeaveReport() {
    // create leave report object
    LeaveReport lr;
    lr.outstandingLeavesReport();
}

void Director::showLeaveReport() {
    // input employee id for relevant employee
    string EID;
    cout << "\nEnter the Employee ID of the employee whose Leave details are required: "; cin >> EID; cout << endl;

    // create leave report object
    LeaveReport lr;
    lr.generateReport(EID);
}