#include <iostream>
#include "AttendanceReport.h"

using namespace std;

void AttendanceReport::generateReport(string ID) {
    ReadWriteAttendance rwa(ID, "", "", "");
    rwa.displayAttendance();
}

void AttendanceReport::lowAttendanceReport() {
    int month;
    double percentage;

    // enter specifications
    cout << "Enter the month you want to see a low attendance report for: "; cin >> month; cout << endl;
    cout << "Enter the minimum percentage allowed: "; cin >> percentage; cout << endl;

    // report generated according to specs
    ReadWriteAttendance rwa("", "", "", "");
    rwa.displayLowAttendance(month, percentage);
}
