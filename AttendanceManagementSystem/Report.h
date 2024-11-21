#ifndef REPORT_H
#define REPORT_H

#include <string>
using namespace std;

class Report {
protected:
    string ReportID;
    string EmployeeID;

public:
    virtual void generateReport() = 0;
    virtual ~Report() = default;
};


class AttendanceReport : public Report {
public:
    void generateReport() override;
    void lowAttendanceReport();
};


class LeaveReport : public Report {
public:
    void generateReport() override;
    void outstandingLeavesReport();
};

#endif