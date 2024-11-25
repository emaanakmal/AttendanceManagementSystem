#include "Leave.h"
#include "ReadWrite.h"
#include "Employee.h"
#include "Supervisor.h"
#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
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

void Leave::updateTable()
{
	ReadWriteLeave rwl(EID, LeavePeriod, LeaveType);
	rwl.write();
}