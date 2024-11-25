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
	Guard g1("guard1", "Guard");
	e1.MarkAttendance(&g1);
	e1.applyForLeave();
}
