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
            int hours = stoi(endTime) - stoi(startTime);
            hours /= 100;
            string hrs = to_string(hours);
            line += " " + date + " " + hrs; // Append new date and start time
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
    cout << "Attendance marked for " << EmpID << "." << endl;

}

void ReadWriteLeave::write()
{
    ifstream update("LeftLeaves.txt");
    if (!update.is_open()) {
        cout << "Unable to open the file!" << endl;
        return;
    }

    // Read all lines from the file
    vector<string> lines;
    string line;
    bool found = false; // To check if the employee ID was found

    while (getline(update, line)) {
        stringstream ss(line);
        string currentEID;
        int casualLeaves, earnedLeaves;

        ss >> currentEID >> casualLeaves >> earnedLeaves;
        if (LeaveType == 'C')
        {
            if (casualLeaves >= LeavePeriod) {
                casualLeaves -= LeavePeriod; // Decrement casual leaves
            }
        }
        else if (LeaveType == 'E')
        {
            if (earnedLeaves >= LeavePeriod) {
                earnedLeaves -= LeavePeriod; // Earned casual leaves
            }
        }
        if (currentEID == EID) { // Check if it's the target employee
            found = true;
            line = currentEID + " " + to_string(casualLeaves) + " " + to_string(earnedLeaves);
        }

        lines.push_back(line); // Store the updated or unchanged line
    }

    update.close();

    if (!found) {
        cout << "Employee ID " << EID << " not found in the file." << endl;
        return;
    }

    // Write the updated content back to the file
    ofstream outFile("LeftLeaves.txt");
    if (!outFile.is_open()) {
        cout << "Unable to open the file for writing!" << endl;
        return;
    }

    for (const auto& l : lines) {
        outFile << l << endl;
    }

    outFile.close();
    cout << "File updated successfully." << endl;
}

void ReadWriteLeave::readleftleaves(string* Cleft, string* Eleft)
{
    ifstream fl("LeftLeaves.txt");
    if (!fl.is_open()) {
        cout << "Unable to open the file!" << endl;
        return;
    }

    string line;
    bool found = false; // To check if the employee ID was found

    while (getline(fl, line)) {
        stringstream ss(line);
        string currentEID;
        string casualLeaves, earnedLeaves;

        ss >> currentEID >> casualLeaves >> earnedLeaves;
        if (currentEID == EID) { // Check if it's the target employee
            found = true;
            *Cleft = casualLeaves;
            *Eleft = earnedLeaves;
        }
    }
    if (!found) {
        cout << "Employee ID " << EID << " not found in the file." << endl;
    }
    fl.close();
}