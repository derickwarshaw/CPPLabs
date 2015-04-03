// Derick Warshaw
// Lab #3 Cash Register Simulation
// COSC2330 Section 001

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

	// variable initialization
	int count;
	int quantity = 0;
	int userItemCode = -2;
	int itemCode = -1;
	char description[20];
	double balanceDue = 0.00;
	double cashTendered = 0.00;
	double change = 0.00;
	double price = 0.00;
	double runningTotal = 0.00;
	double lineTotal = 0.00;
	
	// constant used for tax rate
	const double TAX = .08;
	
	// definition of file stream objects
	ofstream outputFile;
	outputFile.open("Sales.txt");
	ifstream inputFile;
	
	// formatting output
	outputFile << fixed << setprecision(2) << showpoint;
	cout << fixed << setprecision(2) << showpoint;
	
	// output to top of all receipts
	outputFile << "--------------------------"<< endl;
	outputFile << "FUNNY STUFF RETAIL INC." << endl;
	outputFile << "  www.funnyretail.com" << endl;
	outputFile << "   Established 2014"<< endl;
	outputFile << "                   "<< endl;
	outputFile << "4503 Funny Way"<< endl;
	outputFile << "Sherman, Texas 75092"<< endl;
	outputFile << "Phone: 903-555-5555"<< endl;
	outputFile << "--------------------------"<< endl;
	outputFile << "                   "<< endl;



	cout << "---------------------------------------------------------" << endl;
	cout << "                       POWERED BY                        " << endl;
	cout << "__________                                               " << endl;
	cout << "1          1      1  1\\      1   1\\      1   \\       /" << endl;
	cout << "1          1      1  1 \\     1   1 \\     1    \\     / " << endl;
	cout << "1          1      1  1  \\    1   1  \\    1     \\   /  " << endl;
	cout << "1_____     1      1  1   \\   1   1   \\   1      \\ /   " << endl;
	cout << "1          1      1  1    \\  1   1    \\  1       |     " << endl;
	cout << "1          1      1  1     \\ 1   1     \\ 1       |     " << endl;
	cout << "1          1______1  1      \\1   1      \\1       |     " << endl;
	cout << "                                                         " << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "                                                         " << endl;
                                                
	
	
	// instructions for the clerk
	cout << "* Enter the item code for an item the customer wants to ";
	cout << "purchase" << endl;
	cout << "" << endl;
	cout << "* Enter the quantity of the item "<< endl;
	cout << "" << endl;
	cout << "* After all items/quantities are entered - enter 0 for ";
	cout << "item code" << endl;
	cout << "" << endl;
	cout << "* Complete the transaction" << endl;
	cout << "" << endl;
	cout << "" << endl;
	
	////////////////////////////////////////////////////////////////////
   	//loop to gather input from user and output to file
   	////////////////////////////////////////////////////////////////////
	while (userItemCode != 0)
	{
		
		// open Stock.txt
		inputFile.open("Stock.txt");
		
		// prompt user to enter code
		cout << "" << endl;
		cout << "Enter the Item Code to See the Details: ";
		cin >> userItemCode;
		cout << "                                                     " << endl;
		
		// allow sentinal value to stop gathering item codes
		if (userItemCode == 0)
		{
			
			
			// total cost accumulator to output file
			outputFile << "--------------------------" << endl;
			outputFile << "Subtotal: \t$" << setw(9) << runningTotal << endl;
			outputFile << "Tax: \t\t$" << setw(9) << runningTotal * TAX << endl;
			outputFile << "--------------------------" << endl;
			outputFile << "Final Bill: \t$" << setw(9) << runningTotal + 
			                                (runningTotal * TAX) << endl;
			
			cout << "Final bill is $" << runningTotal + 
			                                (runningTotal * TAX) << endl;
			cout << "                                                 " << endl;
			
			// how much cash was collected for the sale                               
			cout << "Cash Tendered: $";
			cin >> cashTendered;
		
			// temporarily using static_cast to render change to an int so it
			// can be used in a comparison expression
			change = static_cast<int>(cashTendered - (runningTotal + 
			                                             (runningTotal * TAX)));
			
		
			////////////////////////////////////////////////////////////////////
    		// if the customer has not paid the full amount
    		////////////////////////////////////////////////////////////////////
			if (change < 0)
			{
				
				// let the clerk know that the customer hasn't paid in full
				cout << "                                             " << endl;
				cout << "I N S U F F I C I E N T  F U N D S" << endl;
				cout << "                                             " << endl;
				cout << "Please put the customer's items back." << endl;
				cout << "The customer has not provided enough" << endl;
				cout << "funds for this transaction" << endl;
					
				// void transaction
				outputFile << "" << endl;
				outputFile << "" << endl;
				outputFile << "Cash Tendered: \t$" << setw(9) << cashTendered;
				outputFile << " " << endl;
				outputFile << " " << endl;
				outputFile << "VOID TRANSACTION" << endl;
				outputFile << "INSUFFICIENT FUNDS" << endl;
				outputFile << " " << endl;
				outputFile << " " << endl;
				outputFile << " " << endl;
				outputFile << "Come back soon!" << endl;
			
					
				// close file stream objects
				inputFile.close();	
				outputFile.close();
				return 0;
				
			}
			
			////////////////////////////////////////////////////////////////////
	    	// if there is no change due
	    	////////////////////////////////////////////////////////////////////
			else if (change == 0)
			{
				
				outputFile << "" << endl;
				outputFile << "" << endl;
				outputFile << "Cash Tendered: \t$" << setw(9) << cashTendered 
																		<< endl;
				outputFile << "--------------------------" << endl;
				outputFile << "Change: \t$" << setw(9) << change << endl;
				outputFile << " " << endl;
				outputFile << " " << endl;
				outputFile << " " << endl;
				outputFile << "Come back soon!" << endl;
				
				cout << "Your change is: $" << change << endl;
				cout << "" << endl;
				cout << "Thank the customer for shopping with us" << endl;
				cout << "" << endl;
				cout << "E N D  O F  T R A N S A C T I O N" << endl;
				
				// close file stream objects
				inputFile.close();	
				outputFile.close();
				return 0;
				
			}
			
			////////////////////////////////////////////////////////////////////
	    	// if there is change due
	    	////////////////////////////////////////////////////////////////////
			else
			{
				// reverting change back to it's non-integer self
				change = (cashTendered - (runningTotal + (runningTotal * TAX)));
				outputFile << "" << endl;
				outputFile << "" << endl;
				outputFile << "Cash Tendered: \t$" << setw(9) << cashTendered 
				                                                        << endl;
				outputFile << "--------------------------" << endl;
				outputFile << "Change: \t$" << setw(9) << change << endl;
				outputFile << " " << endl;
				outputFile << " " << endl;
				outputFile << " " << endl;
				outputFile << "Come back soon!" << endl;
				
				cout << "Your change is: $" << change << endl;
				cout << "" << endl;
				cout << "Thank the customer for shopping with us" << endl;
				cout << "" << endl;
				cout << "E N D  O F  T R A N S A C T I O N" << endl;
				
				// close file stream objects
				inputFile.close();	
				outputFile.close();
				return 0;
				
			}
				
		}
		
		/*  loop to search the Stock.txt until it finds an itemCode match or 
		    the loop iterates 1000 times. If the number of items in the stock
		    list increases in the future - this count may need to be increased
		    to allow the full list to be looped through.*/
		for (count = 1; userItemCode != itemCode && count <= 9; count++)
		{
		
			inputFile >> itemCode;
			inputFile >> description;
			inputFile >> price;
			
			/* if user enters an item code that is not found in 1000 iterations
			   of the loop - error message will present itself and the user will
			   be provided with another opportunity to enter a correct code*/
			if (count == 9)
			{
				// close the input file so we can open again fresh
				inputFile.close(); 
				
				cout << "You entered an item code that is not found!" << endl;
				
				// reset count to 1 so loop can re-iterate at fresh start
				count = 1;
				cout << "Please enter a code that can be found: ";
				cin >> userItemCode;
				
				// open input file to get fresh start for new loop iteration
				inputFile.open("Stock.txt"); 

			}
			
		}
		
		// display the item details
		cout << "Item Code " << itemCode << endl;
		cout << description << endl;
		cout << "$" << price << endl;
		cout << "" << endl;
		
		// get quantity of items
		cout << "Quantity: ";
		cin >> quantity;
		
		// preventing user from entering a negative value for quantity
		while (quantity < 0)
		{
			cout << "" << endl;
			cout << "A negative quantity cannot be entered." << endl;
			cout << "" << endl;
			
			// get quantity of items
			cout << "Quantity: ";
			cin >> quantity;
		}
		
		// getting the price for the line item using base cost * quantity
		lineTotal = price * quantity;
		
		// putting lineTotal in runningTotal accumulator
		runningTotal+= lineTotal;
		
		// once itemCode match is found - output details to Sales.txt
		outputFile << "Quantity: " << quantity << endl;
		outputFile << "Item Code " << itemCode << endl;
		outputFile << description << endl;
		outputFile << quantity << " units" << " @ $"<<price<<" per item" <<endl;
		outputFile << "" << endl;
		
		/* close Stock.txt so when loop re-iterates, it can be reopened and
		   continue its search from the top of the file*/
		inputFile.close();
		
		// reset counter to 1 so the next search gets fresh limit on iterations
		count = 1;
	}
	

	return 0;
		
}
