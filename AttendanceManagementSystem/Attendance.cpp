#include <iostream>
#include<fstream>
#include "Attendance.h"
#include"ReadWrite.h"
#include<string>

using namespace std;

void Attendance::update(string empID, string date, string startTime, string endTime)
{
	ReadWriteAttendance wr(empID, date, startTime, endTime);
	wr.write();

}