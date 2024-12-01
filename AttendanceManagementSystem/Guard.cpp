#include "Guard.h"
#include"Attendance.h"
#include<iostream>
#include<string>
using namespace std;

void Guard::mark(string id)
{
	string startTime, endTime;
	string date;

	// taking date and work hours input
	cout << "Enter date in (DD/MM) format: "; cin >> date; cout << "\n";
	cout << "Enter Start Time (for e.g. 1400): "; cin >> startTime; cout << "\n";
	cout << "Enter End Time (for e.g. 1600): "; cin >> endTime; cout << "\n";

	// updating records accordingly using attendance object
	Attendance at;
	at.update(id, date, startTime, endTime);
}