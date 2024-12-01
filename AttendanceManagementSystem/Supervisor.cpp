#include "Supervisor.h"
#include "ReadWrite.h"

#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool Supervisor::reviewApplication(string EID, int lvprd, char lvtype) {
	bool decision = 1;
    string Eleft;
    string Cleft;
    cout << "Employee " << EID << " is requesting for a " << lvtype << " leave for a time period of " << lvprd << " days\n";

    // reading from files whether leaves available
    ReadWriteLeave rdl(EID, lvprd, lvtype);
    rdl.readleftleaves(&Eleft, &Cleft); // checking quota left

    if (lvtype == 'O' || lvtype == 'U') { // no quota, supervisor's decision
		cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
	}

	else if (lvtype == 'C') {
        if (lvprd <= stoi(Eleft)) // if quota of leaves not yet full
            cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
	}

	else if (lvtype == 'E') {
        if (lvprd <= stoi(Eleft)) // if quota of leaves not yet full
            cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
	}

	return decision;
}

void Supervisor::showLowAttendanceReport() {
    // create attendance report object
    AttendanceReport ar;
    ar.lowAttendanceReport();
}

void Supervisor::showAttendanceReport() {
    // input employee id for relevant employee
    string EID;
    cout << "\nEnter Employee ID: "; cin >> EID; cout << endl;

    // create attendance report object
    AttendanceReport ar;
    ar.generateReport(EID);
}

void Supervisor::showOutstandingLeaveReport() {
    // create leave report object
    LeaveReport lr;
    lr.outstandingLeavesReport();
}

void Supervisor::showLeaveReport(){
    // input employee id for relevant employee
    string EID;
    cout << "\nEnter the Employee ID of the employee whose Leave details are required: "; cin >> EID; cout << endl;

    // create leave report object
    LeaveReport lr;
    lr.generateReport(EID);
}