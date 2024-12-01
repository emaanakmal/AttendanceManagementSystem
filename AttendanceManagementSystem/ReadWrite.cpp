#include"ReadWrite.h"
#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<unordered_map>
using namespace std;

//void ReadWriteAttendance::write()
//{
//	ifstream wr("Attendance.txt"); // open attendance file
//    if (!wr.is_open()) {
//        cout << "Unable to open the file!" << endl;
//        return;
//    }
//
//    vector<string> lines;
//    string line;
//    bool found = false; // check if the employee ID was found
//    while (getline(wr, line)) {
//        stringstream ss(line);
//        string currentEmpID;
//        ss >> currentEmpID;
//
//        if (currentEmpID == EmpID) { // check if its the target employee
//            int hours = stoi(endTime) - stoi(startTime);
//            hours /= 100;
//            string hrs = to_string(hours);
//            line += " " + date + " " + hrs; // append new date and start time
//            found = true;
//        }
//
//        lines.push_back(line); // store the line
//    }
//
//    wr.close();
//
//    if (!found) {
//        cout << "Employee ID " << EmpID << " not found in the file." << endl;
//        return;
//    }
//
//    // write the updated content back to the file
//    ofstream outFile("Attendance.txt");
//    if (!outFile.is_open()) {
//        cout << "Unable to open the file for writing!" << endl;
//        return;
//    }
//
//    for (const auto& l : lines) {
//        outFile << l << endl;
//    }
//
//    outFile.close();
//    cout << "Attendance marked for " << EmpID << "." << endl;
//
//}
//
//void ReadWriteAttendance::displayAttendance() {
//    ifstream file("Attendance.txt");
//    if (!file.is_open()) {
//        cerr << "Error: Could not open file." << endl;
//        return;
//    }
//
//    string line;
//    bool employeeFound = false;
//
//    // Read the file line by line
//    while (getline(file, line)) {
//        stringstream ss(line);
//        string id;
//        ss >> id;
//
//        // Check if the current line is for the given employee
//        if (id == EmpID) {
//            employeeFound = true;
//            cout << "Attendance for Employee ID: " << EmpID << endl;
//            cout << "Date        Hours Worked" << endl;
//            cout << "------------------------" << endl;
//
//            string date;
//            int hours;
//            while (ss >> date >> hours) {
//                cout << setw(10) << date << setw(15) << hours << endl;
//            }
//            break;
//        }
//    }
//
//    file.close();
//
//    if (!employeeFound) {
//        cout << "No attendance record found for Employee ID: " << EmpID << endl;
//        return;
//    }
//
//}
//
//void ReadWriteAttendance::displayLowAttendance(int month, double minPercentage) {
//    ifstream file("Attendance.txt");
//    if (!file.is_open()) {
//        cerr << "Error: Could not open file." << endl;
//        return;
//    }
//
//    const int requiredMonthlyHours = 126; // Total hours required in a month
//    unordered_map<string, int> employeeHours; // To store total hours worked by each employee in the given month
//
//    string line;
//    // Read the file line by line
//    while (getline(file, line)) {
//        stringstream ss(line);
//        string id;
//        ss >> id; // Read employee ID
//
//        string date;
//        int hours;
//        while (ss >> date >> hours) {
//            size_t slashPos = date.find('/');
//            if (slashPos == string::npos) {
//                cerr << "Error: Invalid date format in file." << endl;
//                continue;
//            }
//
//            int fileMonth = stoi(date.substr(slashPos + 1)); // Extract the month from the date
//            if (fileMonth == month) {
//                employeeHours[id] += hours; // Sum hours for the specified month
//            }
//        }
//    }
//
//    file.close();
//
//    // Display employees with attendance percentage below the given threshold
//    cout << "Employees with Attendance Percentage below " << minPercentage << "% in Month " << month << ":\n";
//    cout << "-------------------------------------------------\n";
//    bool found = false;
//
//    // Iterate over the map without structured bindings
//    for (unordered_map<string, int>::iterator it = employeeHours.begin(); it != employeeHours.end(); ++it) {
//        string id = it->first;
//        int totalHours = it->second;
//
//        double attendancePercentage = (totalHours / static_cast<double>(requiredMonthlyHours)) * 100.0;
//        if (attendancePercentage < minPercentage) {
//            found = true;
//            cout << "Employee ID: " << id << ", Attendance Percentage: "
//                << fixed << setprecision(2) << attendancePercentage << "%" << endl;
//        }
//    }
//
//    if (!found) {
//        cout << "No employees found with attendance below " << minPercentage << "%.\n";
//    }
//}

void ReadWriteAttendance::writeOfficialLeave(int lvprd)
{
    fstream file("Attendance.txt", ios::in | ios::out);
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return;
    }

    // Read the entire file content into memory
    stringstream buffer;
    buffer << file.rdbuf();
    string fileContent = buffer.str();

    // Close the file for reading, will reopen for writing later
    file.close();

    // Find the employee's record in the file
    size_t empPos = fileContent.find(EmpID);
    if (empPos == string::npos) {
        cerr << "Error: Employee ID not found in the file." << endl;
        return;
    }

    // Parse the start date (DD/MM format)
    size_t slashPos = date.find('/');
    if (slashPos == string::npos) {
        cerr << "Error: Invalid start date format. Use DD/MM format." << endl;
        return;
    }

    int day = stoi(date.substr(0, slashPos));
    int month = stoi(date.substr(slashPos + 1));

    // Generate attendance entries for the leave days
    stringstream leaveEntries;
    for (int i = 0; i < lvprd; ++i) {
        leaveEntries << day << "/" << month << " 8 ";
        ++day;

        // Handle month-end wrapping
        if (day > 31) { // Assuming 31 days for simplicity; you can enhance this to handle exact month lengths.
            day = 1;
            ++month;
            if (month > 12) {
                month = 1; // Wrap to January
            }
        }
    }

    // Insert leave entries into the employee's record
    size_t recordEnd = fileContent.find('\n', empPos);
    if (recordEnd == string::npos) recordEnd = fileContent.length();
    fileContent.insert(recordEnd, " " + leaveEntries.str());

    // Write the updated content back to the file
    file.open("Attendance.txt", ios::out | ios::trunc);
    file << fileContent;
    file.close();

    cout << "Leave attendance marked successfully for Employee ID: " << EmpID << endl;
}

//------------------------------------------------------------------------//

//void ReadWriteLeave::write()
//{
//    ifstream update("LeftLeaves.txt");
//    if (!update.is_open()) {
//        cout << "Unable to open the file!" << endl;
//        return;
//    }
//
//    // Read all lines from the file
//    vector<string> lines;
//    string line;
//    bool found = false; // To check if the employee ID was found
//
//    while (getline(update, line)) {
//        stringstream ss(line);
//        string currentEmpID;
//        int casualLeaves, earnedLeaves;
//
//        ss >> currentEmpID >> casualLeaves >> earnedLeaves;
//        if (LeaveType == 'C')
//        {
//            if (casualLeaves >= LeavePeriod) {
//                casualLeaves -= LeavePeriod; // Decrement casual leaves
//            }
//        }
//        else if (LeaveType == 'E')
//        {
//            if (earnedLeaves >= LeavePeriod) {
//                earnedLeaves -= LeavePeriod; // Earned casual leaves
//            }
//        }
//        if (currentEmpID == EmpID) { // Check if it's the target employee
//            found = true;
//            line = currentEmpID + " " + to_string(casualLeaves) + " " + to_string(earnedLeaves);
//        }
//
//        lines.push_back(line); // Store the updated or unchanged line
//    }
//
//    update.close();
//
//    if (!found) {
//        cout << "Employee ID " << EmpID << " not found in the file." << endl;
//        return;
//    }
//
//    // Write the updated content back to the file
//    ofstream outFile("LeftLeaves.txt");
//    if (!outFile.is_open()) {
//        cout << "Unable to open the file for writing!" << endl;
//        return;
//    }
//
//    for (const auto& l : lines) {
//        outFile << l << endl;
//    }
//
//    outFile.close();
//    cout << "File updated successfully." << endl;
//}
//
//void ReadWriteLeave::readleftleaves(string* Cleft, string* Eleft)
//{
//    ifstream fl("LeftLeaves.txt");
//    if (!fl.is_open()) {
//        cout << "Unable to open the file!" << endl;
//        return;
//    }
//
//    string line;
//    bool found = false; // To check if the employee ID was found
//
//    while (getline(fl, line)) {
//        stringstream ss(line);
//        string currentEmpID;
//        string casualLeaves, earnedLeaves;
//
//        ss >> currentEmpID >> casualLeaves >> earnedLeaves;
//        if (currentEmpID == EmpID) { // Check if it's the target employee
//            found = true;
//            *Cleft = casualLeaves;
//            *Eleft = earnedLeaves;
//        }
//    }
//    if (!found) {
//        cout << "Employee ID " << EmpID << " not found in the file." << endl;
//    }
//    fl.close();
//}
//
//void ReadWriteLeave::displayLeftLeaves()
//{
//    ifstream file("LeftLeaves.txt"); // Open the file
//    if (!file) {
//        cerr << "Error: Unable to open file." << endl;
//        return;
//    }
//
//    string line, id;
//    int casualLeaves, earnedLeaves;
//    bool anyEmployeeFound = false;
//
//    cout << "Employees with remaining leaves:" << endl;
//    cout << "---------------------------------" << endl;
//
//    while (getline(file, line)) { // Read the file line by line
//        stringstream ss(line);
//        ss >> id >> casualLeaves >> earnedLeaves;
//
//        if (casualLeaves > 0 && earnedLeaves > 0) {
//            cout << "Employee ID: " << id << endl;
//            cout << "Remaining Casual Leaves: " << casualLeaves << endl;
//            cout << "Remaining Earned Leaves: " << earnedLeaves << endl;
//            cout << "---------------------------------" << endl;
//            anyEmployeeFound = true;
//        }
//        else if (casualLeaves > 0)
//        {
//            cout << "Employee ID: " << id << endl;
//            cout << "Remaining Casual Leaves: " << casualLeaves << endl;
//            cout << "---------------------------------" << endl;
//            anyEmployeeFound = true;
//        }
//        else if (earnedLeaves > 0)
//        {
//            cout << "Employee ID: " << id << endl;
//            cout << "Remaining Earned Leaves: " << earnedLeaves << endl;
//            cout << "---------------------------------" << endl;
//            anyEmployeeFound = true;
//        }
//    }
//
//    if (!anyEmployeeFound) {
//        cout << "No employees with remaining leaves found." << endl;
//    }
//
//    file.close();
//}
//
//void ReadWriteLeave::displayLeaveDetails()
//{
//    ifstream file("LeaveDetails.txt");  // Open the file for reading
//    if (!file) {
//        cerr << "Error: Unable to open file." << endl;
//        return;
//    }
//
//    string line;
//    bool found = false;
//
//    // Search through the file line by line
//    while (getline(file, line)) {
//        stringstream ss(line);
//        string id;
//        ss >> id;  // Read the Employee ID from the line
//
//        // If the Employee ID matches, display the leave details
//        if (id == EmpID) {
//            found = true;
//            cout << "Leave details for Employee ID " << EmpID << ":" << endl;
//
//            // Extract and display each leave detail
//            string leaveType, date;
//            int leavePeriod;
//
//            // Loop through each leave record in the line
//            while (ss >> leaveType >> date >> leavePeriod) {
//                // Display the formatted leave details
//                cout << "Date: " << date;
//                cout << " Leave Type: ";
//
//                // Format the leave type
//                if (leaveType == "C") cout << "Casual |";
//                else if (leaveType == "E") cout << "Earned |";
//                else if (leaveType == "O") cout << "Official |";
//                else if (leaveType == "U") cout << "Unpaid |";
//                else cout << "Unknown";
//
//                cout << " Leave Period: " << leavePeriod << " days" << endl;
//            }
//            break;  // Exit the loop once the employee's details are found
//        }
//    }
//
//    if (!found) {
//        cout << "Employee ID " << EmpID << " not found in the file." << endl;
//    }
//
//    file.close();  // Close the file
//
//    ifstream file1("LeftLeaves.txt"); // Open the file
//    if (!file1) {
//        cerr << "Error: Unable to open file." << endl;
//        return;
//    }
//
//    string line1, id;
//    int casualLeaves, earnedLeaves;
//    bool found1 = false;
//
//    while (getline(file1, line1)) { // Read the file line by line
//        stringstream ss(line1);
//        ss >> id >> casualLeaves >> earnedLeaves;
//
//        if (id == EmpID) {
//            cout << "Employee ID: " << id << endl;
//            cout << "Remaining Casual Leaves: " << casualLeaves << endl;
//            cout << "Remaining Earned Leaves: " << earnedLeaves << endl;
//            found1 = true;
//            break;
//        }
//    }
//
//    if (!found1) {
//        cout << "Employee ID " << EmpID << " not found." << endl;
//    }
//
//    file1.close();
//}