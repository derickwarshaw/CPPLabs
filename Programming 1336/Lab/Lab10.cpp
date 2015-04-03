// Derick Warshaw
// Lab #10 Write program that accepts positive integer and display the product of all positive 
//			integers up to and including that number
// COSC1336 Section 001
#include <iostream>
#include <iomanip>
using namespace std;

double getVal(); // function prototypes
double calcVal(double);
void displayVal(double, double);

int main()
{
double userInt,result; // variable definitions

cout << "\t---------------------------------------------------------------" << endl; // instructions
cout << "\tThis program allows the user to enter a positive integer " << endl;
cout << "\tso that it may calculate the product of all positive integers " << endl;
cout << "\tup to and including that number." << endl;
cout << "\t---------------------------------------------------------------" << endl;

userInt = getVal(); // taking the result of the call to getVal and assigning it to userInt
result = calcVal(userInt); // taking the result of the calculation in call to calcVal and assigning it to result
displayVal(result,userInt); // calling displayVal and sending result and userInt to it

	system("pause");
	
	return 0;
}

double getVal() // function definition
{
	double value; // local variable definition
	cout << "" << endl;
	cout << "" << endl;
	cout << "Please enter a positive integer: "; // getting integer from user
	cin >> value; // put integer into value variable
	
	while (value < 1) // making sure user doesn't enter less than 1
		{
		cout << "" << endl;
		cout << "" << endl;
		cout << "You have entered an integer that is less than 1." << endl;
		cout << "Please enter a positive integer: ";
		cin >> value;
		}
	return value; // returning user input
}

double calcVal(double userInt) // function definition set to receive the user entry for positive integer
{
	double counter, result; // local variable definition
	
	result = 1; // initializing result to 1
	
	for(counter=1;counter<=userInt;counter++) // for loop to obtain result of factorial of user input
		{
		result = result * counter;
		}
	return result; // return complete calculatation for factorial of user input
}

void displayVal(double display, double yourNumber) // function definition - set to receive the result of the calculation and the original user selected integer
{
	cout << "" << endl;
	cout << "" << endl;
	cout << fixed << setprecision(0); // formatting of output - larger numbers get weird looking fast.
	cout << "The result of the product of all positive integers up to " <<endl;
	cout << "and including " << yourNumber << " is: " << display << endl;
}
