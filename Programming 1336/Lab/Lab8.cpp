// Derick Warshaw
// Lab #8 - get number of bacteria present at beginning of observation from user and compute number of bacteria in the culture after each of the first 10 days. Display output in form of table.
// COSC1336 Section 001

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
float startBac, result; // variable definition
int day;

cout << "Please enter a positive number for the starting amount of bacteria: "; // Get starting bacteria
cin >> startBac; // put starting bacteria into variable
cout << "" << endl;

while (startBac <1) // loop in case user attempts to enter less than 1 for starting bacteria
	{
	cout <<"You cannot enter a number less than 1" << endl;
	cout <<"\nPlease enter a positive number for the starting amount of bacteria: ";
	cin >> startBac;
	cout << "" << endl;
	}
	
cout << "Day" << "\tNumber of Bacteria" << endl; //formatting columns to hold day and number of bacteria
cout << "-----------------------------" << endl;
cout << "" << endl;

for (day = 1; day <=10; ++day) // loop for equation N = P * 2 ^ t/10.
	{
	result = pow(2,static_cast<float>(day)/10); // static_cast day variable to a float
	result = result * startBac;
	cout << fixed << setprecision(0); // format output
	cout << day <<"." << "\t" << result << endl; // display result
	}

	system("PAUSE");
	return 0;
}
