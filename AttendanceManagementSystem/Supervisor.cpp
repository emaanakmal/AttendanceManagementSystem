#include "Supervisor.h"
#include <iostream>
using namespace std;

bool Supervisor::reviewApplication(string EID, int lvprd, char lvtype)
{
	bool decision = 1;
	int daysleft;
	cout << "Employee " << EID << " is requesting for a " << lvtype << " leave for a time period of " << lvprd << " days\n";
	switch (lvtype)
	{
	case 'C':
		
		//daysleft = readfromdatabase();
		if (daysleft < lvprd)
			decision = 0;

	case 'E':
		//daysleft readfromdatabase();
		if (daysleft < lvprd)
			decision = 0;
		else
		{
			cout << "Enter 1 for approval and 0 for denying "; cin >> decision; cout << "\n";
		}
	default:
	}
	return decision;
}