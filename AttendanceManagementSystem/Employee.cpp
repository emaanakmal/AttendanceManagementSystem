#include <iostream>
#include "Employee.h"
#include "Supervisor.h"
#include "Guard.h"
#include "Leave.h"

void Employee::showAttendanceReport() {
   
}

void Employee::showLeaveReport() {
   
}

void Employee::applyForLeave(Supervisor* sup) {
    int lvprd;
    char lvtype;

    cout << "Enter leave period: "; cin >> lvprd; cout << "\n";
    cout << "Casual(C) Earned(E) Official(E) Unpaid(U)\nEnter leave type: "; cin >> lvtype; cout << "\n";
    if (lvtype == 'C' || lvprd > 4)
    {
        cout << "Leave period for casual leaves cannot be greater than 4. Please apply again\n";
        return;
    }
    Leave lv(ID, lvprd, lvtype);
    bool decision = lv.RequestApproval(sup);

    if (decision == 1)
    {
        cout << "Request accpeted!\n";
        lv.addLeave();
    }
    else
        cout << "Request denied!\n";
}

void Employee::checkIn(Guard grd) {
    
}

void Employee::checkOut() {
 
}
