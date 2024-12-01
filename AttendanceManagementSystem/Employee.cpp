#include <iostream>
#include "Employee.h"

void Employee::showAttendanceReport() {
    AttendanceReport ar;
    ar.generateReport(ID);
}

void Employee::showLeaveReport() {
    LeaveReport lr;
    lr.generateReport(ID);
}

void Employee::applyForLeave(Supervisor* spv, Director* drc) {
    int lvprd;
    char lvtype;
    string lvdate;

    cout << "Enter date of application: "; cin >> lvdate; cout << endl;
    cout << "Enter leave period: "; cin >> lvprd; cout << "\n";
    cout << "Casual(C) Earned(E) Official(E) Unpaid(U)\nEnter leave type: "; cin >> lvtype; cout << "\n";

    // stop if applied for casual leave period > 4
    if (lvtype == 'C' && lvprd > 4)
    {
        cout << "Leave period for casual leaves cannot be greater than 4. Please apply again\n";
        return;
    }

    // otherwise send for approval
    Leave lv(ID, lvprd, lvtype);
    bool decision = lv.RequestApproval(spv, drc);
   
    if (decision == 1)
    {
        cout << "Request accepted!\n";
        lv.addLeave(lvdate);
        lv.updateTable();
    }
    else
        cout << "Request denied!\n";
}

void Employee::MarkAttendance(Guard* grd) {
    grd->mark(ID);
}

string Employee::getEID()
{
    return ID;
}