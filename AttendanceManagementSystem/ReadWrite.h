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
	ReadWriteAttendance(string id, string date, string start, string end) : EmpID(id), date(date), startTime(start), endTime(end) {}
	void write();
};


#endif