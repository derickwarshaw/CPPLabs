// Derick Warshaw
// Lab #2 Write a program to compute and print (a) the interest payment at the end of one year and (b) the new bank balance
// COSC1336 Section 001

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// declare variables for starting bank balance, annual interest rate, interest payment, new bank balance
	double bankBal, interestRate, interestPay, nbankBal;
	
	// calculate and assign starting bank balance, interest rate, interest payment, new bank balance
	bankBal = 580.00;
	interestRate = .025;
	interestPay = bankBal * interestRate;
	nbankBal = interestPay + bankBal;
	
	// format output to not display scientific notation, print 2 places after decimal, and show decimal if zero
	cout << fixed << setprecision(2) << showpoint;
	// display calculation for interest payment and new bank balance
	cout << " The interest payment at the end of one year will be $" << interestPay << endl;
	cout << " The new bank balance will be $" << nbankBal << endl;
	
	
	//system("pause");
	return 0;
}
