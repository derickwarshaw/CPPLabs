// Derick Warshaw
// Lab #1 Number counting program
// COSC2330 Section 001

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{

// variable definitions	
double entryCounter, sumAccumulator, posCounter, negCounter, zeroCounter, mostSequenced, occurenceCounter, userEntry, entry_A, entry_B;

// variable initialization
entryCounter=0;
posCounter=0;
zeroCounter=0;
negCounter=0;
sumAccumulator=0;
userEntry=0;
mostSequenced=0;
occurenceCounter=0;
entry_A=9999;
entry_B=0;

cout << "Please enter a number: ";
cin >> userEntry;
occurenceCounter++;

while(userEntry != 9999)
	{
	cout << "Please enter a number: ";
	cin >> userEntry;	
	entryCounter++;
	sumAccumulator+= userEntry;
	
	if(userEntry > 0)
		posCounter++;
	if(userEntry == 0)
		zeroCounter++;
	if(userEntry < 0)
		negCounter++;
	
	
		
	if(entry_A == entry_B)
		{
			occurenceCounter++;
		}
	
	entry_B = userEntry;	
	
	}
	
	
	
	
cout << "" << endl;
cout << "" << endl;	
cout << "" << endl;	
cout << "Sum of entries: " << sumAccumulator << endl;	
cout << "Number of entries: " << entryCounter << endl;
cout << "Number of positive entries: " << posCounter << endl;
cout << "Number of negative entries: " << negCounter << endl;
cout << "Number of zero entries: " << zeroCounter << endl;
cout << "Number entered the most times in a row: " << mostSequenced << endl;
cout << mostSequenced << " was entered " << occurenceCounter << " times in a row." << endl;

		
return 0;


	
}










