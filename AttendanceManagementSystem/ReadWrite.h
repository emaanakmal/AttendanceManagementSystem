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
	int startTime;
	int endTime;
public:
	ReadWriteAttendance(string id, string date, int start, int end) : EmpID(id), date(date), startTime(start), endTime(end) {}
	void writeStart();
	void writeEnd();
};


#endif