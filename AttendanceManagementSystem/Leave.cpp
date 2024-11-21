#include "Leave.h"
#include "Employee.h"
#include "Supervisor.h"
#include <iostream>
using namespace std;

bool Leave::RequestApproval(Supervisor* sup)
{
	bool decision = sup->reviewApplication(EID, LeavePeriod, LeaveType);
	return decision;
}

void Leave::addLeave()
{

}