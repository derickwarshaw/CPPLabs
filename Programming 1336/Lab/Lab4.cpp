// Derick Warshaw
// Lab #4 Write program that takes user input and calculates square root of input. If non-negative - display. If negative - display message/not defined
// COSC1336 Section 001

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	// variables defined here
	double number, squareRoot;
	
	// get user input and put it in variable
	cout << "Please enter a number so we can calculate it's square root: ";
	cin >> number;
	
	// if the user enters a negative number a statement is displayed - otherwise the square root is displayed
	if (number < 0)
		cout << "The square root of " << number << " is not defined." << endl;
	else
	{
		// variable assignment
		squareRoot = sqrt(number);
	
		// formatting output
		cout << fixed << setprecision(2) << showpoint;
		cout << "The square root of " << number << " is " << squareRoot;
	}

	
	return 0;
}
