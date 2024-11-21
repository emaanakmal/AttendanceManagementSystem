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

    return 0;
}
