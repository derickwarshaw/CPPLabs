// Derick Warshaw
// Lab #8 Character processing with arrays
// COSC2330 Section 001

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// variable initialization
	const int SIZE = 20;
	char line[SIZE];
	int count = 0;
	char letter;
	bool stop = false;
	int bucket = 0;
	bool big = true;
	
	
	// prompting user to enter a name
	cout << "Enter a fully lower case or uppercase name of no more than " 
	                                      << (SIZE - 1) << " characters "<<endl;
	// reading name into array of characters
	cin.getline(line, SIZE);
	
	cout << "The name you entered in uppercase is ";
	
	// loop to iterate until it encounters null value in the array
	while (line[count] != '\0')
	{
		// if the user entered all lower case letters
		if (line[count] > 90)
		{
			// convert to uppercase and put in variable
			letter = line[count] - 32;
			
			// output the character to the console
			cout << letter;
			
			// add one to the bucket accumulator -- keeping track of # charac.'s
			bucket = bucket + 1;	
			
			// increment the loop counter
			count++;
			
		}
		
		// if the user entered uppercase characters i.e. line[count] < 90
		else
		{
			
			// put character in variable
			letter = line[count];
			
			// output the character to console
			cout << letter;
			
			// add one to the bucket accumulator -- keeping track of # charac.'s
			bucket = bucket + 1;
			
			// increment the loop counter
			count ++;
			
			
		}
	
	}
	
	
	cout << "" << endl;
	
	cout << "The name you entered in reverse order is ";
	
	/** since we know how many elements are in the array we can use that to
	count backwards and print the characters minus the null terminator */
	for (count = bucket - 1; count >= 0; count--)
	{
		// put character in variable and then print to console
		letter = line[count];
		cout << letter;	

	}
	
	cout << "" << endl;
	
	// we have a record of the number of characters in the accumulator - print
	cout << "The number of characters in the name is " << (bucket) << endl;
	
	cout << "A Weird way to display the name you entered is ";
	
	// if user enters all lower case for the name
	for (count = 0; count <= (bucket - 1); count++)
	{
		/** if the character is lower case and we need a uppercase character */
		if (line[count] >= 90 && big == true)
		{
			// read character in, make it upper case, print it out
			letter = line[count] - 32;
			cout << letter;
			
			// set big flag to false because we don't need another uppercase
			big = false;

		}
		
		/** if the character is lower case and we don't need another uppercase*/
		else if (line[count] >= 90 && big == false)
		{
			// read in the character, print the character to console
			letter = line[count];
			cout << letter;
			
			// set big flag to true because we need the next character uppercase
			big = true;
			
		}

	}
	
	
	big = true;
	// Loop to catch if user enters all caps for the name
	for (count = 0; count <= (bucket - 1); count++)
	{
		// if the character is uppercase and we need to print an uppercase
		if (line[count] <= 90 && big == true)
		{
			// read the character in and print to console
			letter = line[count];
			cout << letter;
			
			// set flag to false since we don't need an uppercase next
			big = false;

		}
		
		// if the character is uppercase and we don't need uppercase
		else if (line[count] <= 90 && big == false)
		{
			// read in character, make it lower case, print to console
			letter = line[count] + 32;
			cout << letter;
			
			// set flag to true since we need an uppercase character next
			big = true;
			
		}
	
	}
	
	return 0;
}

	
	

