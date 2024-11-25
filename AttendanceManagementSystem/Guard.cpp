#include "Guard.h"
#include"Attendance.h"
#include<iostream>
#include<string>
using namespace std;

void Guard::mark(string id)
{
	string startTime, endTime;
	string date;
	cout << "Enter date in (DD/MM) format: "; cin >> date; cout << "\n";
	cout << "Enter Start Time: "; cin >> startTime; cout << "\n";
	cout << "Enter End Time: "; cin >> endTime; cout << "\n";
	Attendance at;
	at.update(id, date, startTime, endTime);
}