// Derick Warshaw
// Lab #3 
// COSC2330 Section 001

#include <iostream>
#include <fstream>

 

using namespace std;

int main()
{

	// variable declarations
	int quantity = 0;
	int userItemCode = -1;
	int itemCode = -1;
	char description[20];
	double price = 0;
	int number = 0;
	
	// definition of file stream objects
	ofstream outputFile;
	ifstream inputFile;
	
	// create output file object
	outputFile.open("Sales.txt");
	
	cout << "Welcome to the cash register" << endl;
	
	// loop to gather input from user and output to file
	while (userItemCode != 0)
	{
		
		// open Stock.txt
		inputFile.open("Stock.txt");
		
		// prompt user to enter code
		cout << "Enter the item code to see the details: ";
		cin >> userItemCode;
		
		// allow sentinal value to terminate program
		if (userItemCode == 0)
		{
		inputFile.close();	
		outputFile.close();	
		return 0;
		}
		
		//  loop to search the Stock.txt until it finds an itemCode match
		while (userItemCode != itemCode)
		{
		
			inputFile >> itemCode;
			inputFile >> description;
			inputFile >> price;
		}
		
		// get quantity of items
		cout << "Quantity: ";
		cin >> quantity;
		
		// once itemCode match is found - output details to Sales.txt
		outputFile << "Quantity: " << quantity << endl;
		outputFile << "Item Code " << itemCode << endl;
		outputFile << description << endl;
		outputFile << "$" << price << endl;
		outputFile << "" << endl;
		
		/* close Stock.txt so when loop re-iterates, it can be reopened and
		   continue its search from the top of the file*/
		inputFile.close();
	}
	outputFile.close();
return 0;	
}
