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
	bool decision = 1;
    string Eleft;
    string Cleft;
    cout << "Employee " << EID << " is requesting for a " << lvtype << " leave for a time period of " << lvprd << " days\n";

    ReadWriteLeave rdl(EID, lvprd, lvtype);
    rdl.readleftleaves(&Eleft, &Cleft);

    if (lvtype == 'O' || lvtype == 'U') 
	{
		cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
	}
	else if (lvtype == 'C')
	{
        if (lvprd <= stoi(Eleft))
        {
            cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
        }
	}
	else if (lvtype == 'E')
	{
        if (lvprd <= stoi(Eleft))
        {
            cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
        }
	}

	return decision;
}

void Supervisor::showLowAttendanceReport()
{
    int month;
    double percentage;
    cout << "Enter the month you want to see a low attendance report for: "; cin >> month; cout << endl;
    cout << "Enter the minimum percentage allowed: "; cin >> percentage; cout << endl;
    ReadWriteAttendance rwa("", "", "", "");
    rwa.displayLowAttendance(month, percentage);
}

void Supervisor::showAttendanceReport()
{
    string EID;
    cout << "Enter Employee ID: "; cin >> EID; cout << endl;
    ReadWriteAttendance rwa(EID, "", "", "");
    rwa.displayAttendance();
}

void Supervisor::showOutstandingLeaveReport()
{
    ReadWriteLeave rwl("", 0, 'a');
    rwl.displayLeftLeaves();
}

void Supervisor::showLeaveReport()
{
    string EID;
    cout << "Enter the Employee ID of the employee whose Leave details are required: "; cin >> EID; cout << endl;
    ReadWriteLeave rwl(EID, 0, 'a');
    rwl.displayLeaveDetails();
}