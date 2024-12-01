#ifndef READWRITE_H
#define READWRITE_H

#include<string>
#include<iostream>
using namespace std;

class ReadWriteAttendance
{
private:
	string EmpID;
	string date;
	string startTime;
	string endTime;
public:
	ReadWriteAttendance(string id, string date = "", string start = "", string end = "") : EmpID(id), date(date), startTime(start), endTime(end) {}
	void write();
	void displayAttendance();
	void displayLowAttendance(int month, double minPercentage);
	void writeOfficialLeave(int lvprd);
};

class ReadWriteLeave
{
private:
	string EmpID;
	int LeavePeriod;
	char LeaveType;
public:
	ReadWriteLeave(string id, int lvprd = 0, char lvtype = NULL) : EmpID(id), LeavePeriod(lvprd), LeaveType(lvtype) {}
	void write();
	void readleftleaves(string* Cleft, string* Eleft);
	void displayLeftLeaves();
	void displayLeaveDetails();
};


#endif