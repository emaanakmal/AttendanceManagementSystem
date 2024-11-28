#include <iostream>
#include "Employee.h"
#include"ReadWrite.h"
#include "Supervisor.h"
#include "Guard.h"
#include "Leave.h"

void Employee::showAttendanceReport() {
    ReadWriteAttendance rwa(ID, "", "", "");
    rwa.displayAttendance();
}

void Employee::showLeaveReport() {
   
}

void Employee::applyForLeave() {
    int lvprd;
    char lvtype;
    string lvdate;

    cout << "Enter date of application: "; cin >> lvdate; cout << endl;
    cout << "Enter leave period: "; cin >> lvprd; cout << "\n";
    cout << "Casual(C) Earned(E) Official(E) Unpaid(U)\nEnter leave type: "; cin >> lvtype; cout << "\n";
    if (lvtype == 'C' && lvprd > 4)
    {
        cout << "Leave period for casual leaves cannot be greater than 4. Please apply again\n";
        return;
    }
    Leave lv(ID, lvprd, lvtype);
    bool decision = lv.RequestApproval();
   
    if (decision == 1)
    {
        cout << "Request accpeted!\n";
        lv.addLeave(lvdate);
        lv.updateTable();
    }
    else
        cout << "Request denied!\n";
}

void Employee::MarkAttendance(Guard* grd) {
    grd->mark(ID);
}

string Employee::returnEID()
{
    return ID;
}