#ifndef ATTENDANCEREPORT_H
#define ATTENDANCEREPORT_H

#include <string>
#include "Report.h"
#include "ReadWrite.h"
using namespace std;

class AttendanceReport : public Report {
public:
    AttendanceReport(const string repid = "", const string empid = "") : Report(repid, empid) {}
    void generateReport(string ID) override;
    void lowAttendanceReport();
};

#endif