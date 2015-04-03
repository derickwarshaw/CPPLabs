// Derick Warshaw
// Lab #5 user enters the month, the day, and the four digit year. Determine if product of month and day is equal to last two digits of year
// COSC1336 Section 001

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int month, day, year;
	
	cout << "All User Entries are in Numeric Form" << endl;				// letting user know what the expectation is for data entry
	cout << "\n------------------------------------------" << endl;
	cout << "\nPlease enter a month: ";									// asking user to enter month
	cin >> month;														// putting user input into variable month
	cout << "Please enter a day: ";										// asking user to enter day
	cin >> day;															// putting user input into variable day
	cout << "Please enter a four digit year: ";							// asking user to enter year
	cin >> year;														// putting user input into variable year
	
	if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1000 || year > 9999)// checking for data validity/range	
		cout << "The data you entered is invalid" << endl;				// if true for being invalid data - display message
	
	else if (month * day == year % 100)									// if month multiplied by day is equal to last two digits of year - date is magic
		cout << "The date you entered is magic!" << endl;				// display message if true
	
	else
		cout << "The date you entered is not magic" << endl;			// if date was not magic - display message
	
	
	
	
	system ("pause");
	return 0;
}
