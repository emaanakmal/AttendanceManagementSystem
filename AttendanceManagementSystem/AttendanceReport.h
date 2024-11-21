#ifndef ATTENDANCEREPORT_H
#define ATTENDANCEREPORT_H

#include <string>
#include "Report.h"
using namespace std;

class AttendanceReport : public Report {
public:
    void generateReport() override;
    void lowAttendanceReport();
};

#endif