#ifndef REPORT_H
#define REPORT_H

#include <string>
using namespace std;

class Report {
protected:
    string ReportID;
    string EmployeeID;

public:
    Report(const string& repid, const string& empid)
        : ReportID(repid), EmployeeID(empid) {}
    virtual void generateReport(string ID) = 0;
    virtual ~Report() = default;
};

#endif