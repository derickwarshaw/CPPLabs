#include <iostream>
using namespace std;

void qualify();
void noQualify();

int main()
{
	double salary;
	int years;
	
	cout << "This program will determine if you qualify\n";
	cout << "for our credit card.\n";
	cout << "What is your annual salary? ";
	cin >> salary;
	cout << "How many years have you worked at your ";
	cout << "current job? ";
	cin >> years;
	if (salary >= 17000.0 && years >= 2)
		qualify();
	else
		noQualify();
	
	
	return 0;
}

void qualify()
	{
	cout << "You qualify for the card at an annual interest rate of 12 percent." << endl;
	}
void noQualify()
	{
	cout << "You do not qualify for the card due to not meeting criteria." << endl;
	}
