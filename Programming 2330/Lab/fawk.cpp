// Derick Warshaw
// Lab #3 
// COSC2330 Section 001

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

	const int TEAM = 4;
	const int PLAYER = 5;
	
	double points[TEAM][PLAYER];
	
	int tcount, pcount;
	
	for (tcount = 0; tcount < TEAM; tcount++)
	{
		for(pcount = 0; pcount < PLAYER; pcount++)
		{
			cout << "Team " << (tcount + 1);
			cout << " Player " << (pcount + 1) << " Points: ";
			cin >> points[tcount][pcount];
		}
		cout << "" << endl;
	}
	return 0;
}
