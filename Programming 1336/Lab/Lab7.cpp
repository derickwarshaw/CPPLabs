// Derick Warshaw
// Lab #7 - input a list of people's ages from the user (terminated by a 0) and find the average age
// COSC1336 Section 001

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int age, people; 															// variable definition
	float total;
	
	total = 0; 																	// variable assignment  - total bucket is set at 0
	people = 1; 																// people counter set at 1
	
	cout << "Enter a person's age and we will calculate" << endl; 				// introducing purpose of program and instructions for user 
	cout << "the average for all of the ages you entered." << endl;
	cout << "Enter 0 when you are finished." << endl;
	cout << "" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout <<"Please enter the age for person " << people << ": ";
	cin >> age; 																// put user entry into age

	while (age > 0) 															// loop for when user entry is greater than zero
		{
		total += age; 															// take age entry and put it in total bucket
		people++; 																// add one to people counter
		cout <<"Please enter the age for person " << people << ": ";
		cin >> age; 															// get next user entry and put it in age
			while (age < 0) 													// data validation loop so user cannot enter less than 0 for age
			{
			cout << "\nYou may only enter a positive number for age!" << endl;
			cout << "\nPlease enter the age for person "<< people << ": ";
			cin >> age; 														//get user input and put it in age
			}	
		}
	
	cout << fixed << showpoint << setprecision(2); 								// format console output
	cout << "\nThe average age entered is " << total / people << "." << endl;	// display
	
	
	

	system("PAUSE");
	return 0;
}
