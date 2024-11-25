#include "Supervisor.h"
#include "ReadWrite.h"
#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool Supervisor::reviewApplication(string EID, int lvprd, char lvtype)
{
	bool decision = 1;
    string Eleft;
    string Cleft;
    cout << "Employee " << EID << " is requesting for a " << lvtype << " leave for a time period of " << lvprd << " days\n";

    ReadWriteLeave rdl(EID, lvprd, lvtype);
    rdl.readleftleaves(&Eleft, &Cleft);

    if (lvtype == 'O' || lvtype == 'U') 
	{
		cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
	}
	else if (lvtype == 'C')
	{
        if (lvprd <= stoi(Eleft))
        {
            cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
        }
	}
	else if (lvtype == 'E')
	{
        if (lvprd <= stoi(Eleft))
        {
            cout << "Enter 1 for approval and 0 for denial "; cin >> decision; cout << "\n";
        }
	}

	return decision;
}