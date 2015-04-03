// Derick Warshaw
// Lab #6 Calculator that adds, multiplies, divides, subtracts - using switch to implement
// COSC1336 Section 001

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double number1, number2; // variable definition here
	char choice;
	
	cout << "Please choose A,S,M or D [CAPITAL LETTERS]" << endl; // asking user to select A,S,M,D menu choice for operator they would like to use
	cout << "to select the operator you would like to use: " << endl;
	cout << "" << endl;
	cout << "A <---- + [addition]" << endl;
	cout << "S <---- - [subtraction]" << endl;
	cout << "M <---- * [multiplication]" << endl;
	cout << "D <---- / [division]" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "Selection: ";
	cin >> choice; // put user selected choice from menu into choice variable
	
	cout << "" << endl;
	
	switch (choice)
	{
		case 'A': cout << "Enter the first number: "; // getting data from user
				cin >> number1;						  // putting data in number1 variable
				cout << "Enter the second number: ";  // getting data from user
				cin >> number2;						  // putting data in number2 variable
				cout << fixed << setprecision(2) << showpoint; // formatting console output
				cout << "\nThe sum of " << number1 <<" and " << number2 << " is " << number1 + number2 << endl; // display results of addition
				break; // exit structure
		
		case 'S': cout << "Enter the first number: "; // getting data from user
				cin >> number1;						  // putting data in number1 variable
				cout << "Enter the second number: ";  // getting data from user
				cin >> number2;						  // putting data in number2 variable
				cout << fixed << setprecision(2) << showpoint; // formatting console output
				cout << "\nThe difference of " << number1 <<" and " << number2 << " is " << number1 - number2 << endl; // display results of subtraction
				break; // exit structure
				
		case 'M': cout << "Enter the first number: "; // getting data from user
				cin >> number1;						  // putting data in number1 variable
				cout << "Enter the second number: ";  // getting data from user
				cin >> number2;						  // putting data in number2 variable
				cout << fixed << setprecision(2) << showpoint; // formatting console output
				cout << "\nThe product of " << number1 <<" and " << number2 << " is " << number1 * number2 << endl; // display results of multiplication
				break; // exit structure
				
		case 'D': cout << "Enter the first number: "; // getting data from user
				cin >> number1;						  // putting data in number1 variable
				cout << "Enter the second number: ";  // getting data from user
				cin >> number2;						  // putting data in number2 variable
				if (number2 == 0)					  // input validation - dividing by zero is invalid
					cout << "You may not divide by zero. Please terminate the program and try again!" << endl; 
				else
				{	
					cout << fixed << setprecision(2) << showpoint; // formatting console output
					cout << "\nThe quotient of " << number1 <<" and " << number2 << " is " << number1 / number2 << endl; // display results of division
				}
				break; // exit structure
		default: cout << "You have keyed in an invalid selection." << endl; //if user has entered anything other than A, S, M, or D - this message will display
				 cout << "You may choose A, S, M, or D as your selection." <<endl;
				 cout << "Please terminate the program and try again!" << endl;
	}
	
	
	
	
	
	system("pause");
	
	return 0;
}
