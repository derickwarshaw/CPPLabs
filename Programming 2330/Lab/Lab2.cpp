// Derick Warshaw
// Lab #2 Number generator: 3 digit numbers that are equal to sum of cube of
//                          digits
// COSC2330 Section 001

#include <iostream>

using namespace std;


int main()
{
	// initialization of variables
	int number = 100;
	int comparisonNumber = 0;
	int firstDigit = 0;
	int secondDigit = 0;
	int thirdDigit = 0;
	
	// text output for user to know what the program does
	cout << "---------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "--         Welcome to the Number Discovery Engine!     --" << endl;   
	cout << "-- The numbers generated will be 3 digit numbers that  --" << endl;
	cout << "--          are equal to the sum of the cube           --" << endl;
	cout << "--                  of their digits.                   --" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "" << endl;
	cout << "" << endl;
	
	cout << "\tTHESE NUMBERS MET CRITERIA" << endl;
	cout << "" << endl;
	cout << "" << endl;
	
	/* loop from 100 - 999 that breaks out individual digits of number using 
	modulus and then assigns the calculation result of the sum of each digit 
	broken out raised to the third power (i.e. multiplied by itself 3 times) to 
	a variable used for comparing that result to the number having its digits 
	broken out */
	while ( number <= 999)
	{
		// break out digits
		firstDigit = (number / 100);
		secondDigit = (number % 100) / 10;
		thirdDigit = (number % 100) % 10;
		
		// calculate sum of cubed digits and assign to comparisonNumber
		comparisonNumber = (firstDigit * firstDigit * firstDigit) + 
						   (secondDigit * secondDigit * secondDigit) + 
						   (thirdDigit * thirdDigit * thirdDigit);
		
		
		/* if the comparisonNumber is equal to the number who's digits are being
		 checked for meeting the requirements of the loop - display the number*/
		if (comparisonNumber == number)
		{
			
			cout << "\t------[   " << comparisonNumber << "   ]------" << endl;
			
		}
		
		// increment/update the number variable by 1
		number++;
		
	}
	
	// end process
	return 0;
	
}
