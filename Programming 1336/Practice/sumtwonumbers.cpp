//This program calculates the sum of two numbers

#include <iostream>
using namespace std;

int main()
{
	int number1, number2, total;
	total = number1 + number2;
		
	cout << "Enter a number: ";
	cin >> number1;
	
	cout << "Enter another number: ";
	cin >> number2;
	
	cout << "The sum of " << number1 <<" and " << number2 <<" is " << total;
	
	return 0;
}
