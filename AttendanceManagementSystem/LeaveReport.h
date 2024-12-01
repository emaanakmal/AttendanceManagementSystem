#ifndef LEAVEREPORT_H
#define LEAVEREPORT_H

#include <string>
#include "Report.h"
#include "ReadWrite.h"
using namespace std;

class LeaveReport : public Report {
public:
    LeaveReport(const string repid = "", const string empid = "") : Report(repid, empid) {}
    void generateReport(string ID) override;
    void outstandingLeavesReport();
};

#endif