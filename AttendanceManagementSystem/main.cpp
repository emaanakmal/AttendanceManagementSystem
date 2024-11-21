#include <iostream>
#include "Employee.h"
#include "Supervisor.h"
#include "Director.h"
#include "Guard.h"
#include "Attendance.h"
#include "Leave.h"

int main() {
    Employee emp("E001", "Zainab");
    Supervisor sup("S001", "Abdullah");
    Director dir("D001", "Hannan");
    Guard guard("G001", "Emaan");

    std::cout << "Employee actions:\n";
    emp.checkIn();
    emp.applyForLeave();
    emp.showAttendanceReport();

    std::cout << "\nSupervisor actions:\n";
    sup.showLowAttendanceReport();
    sup.reviewApplication();

    std::cout << "\nDirector actions:\n";
    dir.showAttendanceReport("E001");
    dir.reviewApplication();

    std::cout << "\nGuard actions:\n";
    guard.markAttendance();

    Attendance attendance;
    attendance.updateRecord("E001", "09:00", "17:00");

    Leave leave;
    if (leave.requestApproval()) {
        leave.addLeave();
        std::cout << "Leave application approved and(girly pop) recorded.\n";
    }
    else {
        std::cout << "Leave application rejected.\n";
    }

    return 0;
}
