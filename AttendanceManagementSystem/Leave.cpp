#include "Leave.h"
#include "ReadWrite.h"
#include "Employee.h"
#include "Supervisor.h"
#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

bool Leave:: RequestApproval()
{
	Supervisor s1("supervisor1", "Supervisor");
	bool decision = s1.reviewApplication(EID, LeavePeriod, LeaveType);
	return decision;
}	

void Leave::addLeave(string date)
{
    fstream file("LeaveDetails.txt", ios::in | ios::out | ios::app);
    if (!file) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // Read all lines from the file to check if the employee ID exists
    string line;
    bool idFound = false;
    vector<string> lines; // To store the file contents

    while (getline(file, line)) {
        lines.push_back(line); // Store the existing lines
        stringstream ss(line);
        string id;
        ss >> id; // Read the Employee ID from the line

        if (id == EID) {
            idFound = true; // Employee ID found in the file
        }
    }

    // If the Employee ID is found, append the new leave details to the same line
    if (idFound) {
        // Now, open the file in write mode to modify the line
        file.close();
        file.open("LeaveDetails.txt", ios::out);

        for (string& existingLine : lines) {
            stringstream ss(existingLine);
            string id;
            ss >> id;

            // If the employee ID is found, append the leave details to the line
            if (id == EID) {
                existingLine += " " + string(1, LeaveType) + " " + date + " " + to_string(LeavePeriod);
            }
            // Write the modified or unmodified line back to the file
            file << existingLine << endl;
        }

        cout << "Leave details updated successfully!" << endl;
    }
    else {
        file.close();
        file.open("LeaveDetails.txt", ios::app);
        file << EID << " " << LeaveType << " " << date << " " << LeavePeriod << " " << endl;

        cout << "Leave details added successfully!" << endl;
    }

    file.close(); // Close the file
}

void Leave::updateTable()
{
	ReadWriteLeave rwl(EID, LeavePeriod, LeaveType);
	rwl.write();
}