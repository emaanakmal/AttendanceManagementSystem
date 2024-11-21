#include <iostream>
//#include "Employee.h"
//#include "Supervisor.h"
//#include "Director.h"
//#include "Guard.h"
//#include "Attendance.h"
//#include "Leave.h"

#include <string>
#include <fstream>
using namespace std;


int main() {
   /* Employee emp("E001", "Zainab");
    Supervisor sup("S001", "Abdullah");
    Director dir("D001", "Hannan");
    Guard guard("G001", "Emaan");*/

    // only reads from csv file
    fstream attRecord;
    attRecord.open("weekly_attendance.csv");

   
    char x[20] = "";
    cout << "hey girl\n";
    while (attRecord.good()) {
        attRecord.getline(attRecord, 20);
        cout << x;
    }

    return 0;
}
