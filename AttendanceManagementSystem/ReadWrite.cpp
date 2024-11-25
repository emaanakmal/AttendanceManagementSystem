#include"ReadWrite.h"
#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void ReadWriteAttendance::write()
{
	ifstream wr("Attendance.txt");
    if (!wr.is_open()) {
        cout << "Unable to open the file!" << endl;
        return;
    }

    vector<string> lines;
    string line;
    bool found = false; // To check if the employee ID was found
    while (getline(wr, line)) {
        stringstream ss(line);
        string currentEmpID;
        ss >> currentEmpID;

        if (currentEmpID == EmpID) { // Check if it's the target employee
            line += " " + date + " " + startTime + " " + endTime; // Append new date and start time
            found = true;
        }

        lines.push_back(line); // Store the line
    }

    wr.close();

    if (!found) {
        cout << "Employee ID " << EmpID << " not found in the file." << endl;
        return;
    }

    // Write the updated content back to the file
    ofstream outFile("Attendance.txt");
    if (!outFile.is_open()) {
        cout << "Unable to open the file for writing!" << endl;
        return;
    }

    for (const auto& l : lines) {
        outFile << l << endl;
    }

    outFile.close();
    cout << "Date and start time added successfully for employee " << EmpID << "." << endl;

}
