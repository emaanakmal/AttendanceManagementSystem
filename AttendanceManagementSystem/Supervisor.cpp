#include "Supervisor.h"
#include "ReadWrite.h"

#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool Supervisor::reviewApplication(string EID, int lvprd, char lvtype)
{
	bool decision = 0;
    string Eleft;
    string Cleft;
    cout << "Employee " << EID << " is requesting for a " << lvtype << " leave for a time period of " << lvprd << " days\n";

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
    AttendanceReport ar;
    ar.lowAttendanceReport();
}

void Supervisor::showAttendanceReport()
{
    string EID;
    cout << "Enter Employee ID: "; cin >> EID; cout << endl;

    AttendanceReport ar;
    ar.generateReport(EID);
}

void Supervisor::showOutstandingLeaveReport()
{
    LeaveReport lr;
    lr.outstandingLeavesReport();
}

void Supervisor::showLeaveReport()
{
    string EID;
    cout << "Enter the Employee ID of the employee whose Leave details are required: "; cin >> EID; cout << endl;

    LeaveReport lr;
    lr.generateReport(EID);
}