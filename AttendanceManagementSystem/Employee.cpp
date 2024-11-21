#include "Employee.h"
#include <iostream>

void Employee::showAttendanceReport() {
    std::cout << "Showing attendance report for employee: " << Name << "\n";
}

void Employee::showLeaveReport() {
    std::cout << "Showing leave report for employee: " << Name << "\n";
}

void Employee::applyForLeave() {
    std::cout << Name << " has applied for leave.\n";
}

void Employee::checkIn() {
    std::cout << Name << " checked in.\n";
}

void Employee::checkOut() {
    std::cout << Name << " checked out.\n";
}
