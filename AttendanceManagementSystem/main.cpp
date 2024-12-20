#include <iostream>
#include "Employee.h"
#include "Supervisor.h"
#include "Director.h"
#include "Guard.h"
#include "Attendance.h"
#include "Leave.h"

#include <string>
#include <fstream>
using namespace std;


int main() {
	Employee e1("E1", "Daniyal");
	Employee e2("E2", "Emaan");
	Guard g1("guard1", "Guard");
	Supervisor s1("supervisor1", "Supervisor");
	Director d1("director1", "Director");

	e1.MarkAttendance(&g1);
	e1.showAttendanceReport();
	e1.applyForLeave(&s1, &d1);
	e1.showLeaveReport();

	s1.showLeaveReport();
	s1.showLowAttendanceReport();
	s1.showAttendanceReport();
	s1.showOutstandingLeaveReport();

    return 0;
}
