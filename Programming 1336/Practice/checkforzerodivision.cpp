// Program 4-9 
// This program asks the user for two numbers - tested for the value of zero

#include <iostream>
using namespace std;

int main()
{
	double numb1, numb2, quotient;
	
	// get first number
	cout << "Enter a number: ";
	cin >> numb1;
	
	// get second number
	cout << "Enter another number: ";
	cin >> numb2;
	
	// if num2 is not zero, perform division
	if(numb2 == 0)
	{
		cout << "Division by zero is not possible.\n";
		cout << "Please run the program again and enter\n";
		cout << "a number other than zero.\n";
	}
	else 
	{
		quotient = numb1 / numb2;
		cout << "The quotient of " << numb1 << " divided by ";
		cout << numb2 << " is " << quotient << ".\n";
	}
	
	return 0;
}
