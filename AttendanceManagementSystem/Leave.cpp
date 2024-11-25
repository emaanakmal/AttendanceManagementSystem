#include "Leave.h"
#include "Employee.h"
#include "Supervisor.h"
#include <iostream>
using namespace std;

bool Leave:: RequestApproval()
{
	Supervisor s1("supervisor1", "Supervisor");
	bool decision = s1.reviewApplication(EID, LeavePeriod, LeaveType);
	return decision;
}	

void Leave::addLeave()
{

}