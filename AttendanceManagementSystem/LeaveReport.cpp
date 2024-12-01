#include <iostream>
#include "LeaveReport.h"

void LeaveReport::generateReport(string ID)
{
	ReadWriteLeave rwl(ID);
	rwl.displayLeaveDetails();
}

void LeaveReport::outstandingLeavesReport()
{
	ReadWriteLeave rwl("");
	rwl.displayLeftLeaves();
}
