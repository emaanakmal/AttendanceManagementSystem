#include <iostream>
#include "Employee.h"

void Employee::showAttendanceReport() {
    // create attendance report object
    AttendanceReport ar;
    // generate regular attendance report showing details and work hours
    ar.generateReport(ID);
}

void Employee::showLeaveReport() {
    // create leave report object
    LeaveReport lr;

    // generate regular leave report showing number of leaves taken/left and their details
    lr.generateReport(ID);
}

void Employee::applyForLeave(Supervisor* spv, Director* drc) {
    int lvprd;
    char lvtype;
    string lvdate;

    // get leave details as input
    cout << "Enter date of application: "; cin >> lvdate; cout << endl;
    cout << "Enter leave period: "; cin >> lvprd; cout << "\n";
    cout << "Casual(C) Earned(E) Official(E) Unpaid(U)\nEnter leave type: "; cin >> lvtype; cout << "\n";

    lvtype -= 32;
    // stop if applied for casual leave period > 4
    if (lvtype == 'C' && lvprd > 4)
    {
        cout << "Leave period for casual leaves cannot be greater than 4. Please apply again\n";
        return;
    }

    // otherwise send for approval
    Leave lv(ID, lvprd, lvtype);
    bool decision = lv.RequestApproval(spv, drc);
   
    // if request for leave accepted then add leave to file record
    if (decision == 1){
        cout << "Request accepted!\n";
        lv.addLeave(lvdate);
        lv.updateTable();
    }
    else
        cout << "Request denied!\n";
}

void Employee::MarkAttendance(Guard* grd) {
    // invoke guard to mark attendance
    grd->mark(ID);
}

string Employee::getEID(){
    return ID;
}