#ifndef LEAVEREPORT_H
#define LEAVEREPORT_H

#include <string>
#include "Report.h"
using namespace std;

class LeaveReport : public Report {
public:
    void generateReport() override;
    void outstandingLeavesReport();
};

#endif