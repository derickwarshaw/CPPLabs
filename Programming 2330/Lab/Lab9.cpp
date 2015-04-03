// Derick Warshaw
// Lab #9 Cash Register Simulation using Array of Structures
// COSC2330 Section 001

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// function prototypes
void instructions();
int getQuantity();

// constant used for tax rate
const double TAX = .08;

// definition of structure StockField
struct StockField
{
	int stockNo;
	char description[20];
	double price;	
};


int main()
{
	// variable initialization
	int count;
	int quantity = 0;
	int userItemCode = 9999;
	bool found = false;
	double balanceDue = 0.00;
	double cashTendered = 0.00;
	double change = 0.00;
	double runningTotal = 0.00;
	double lineTotal = 0.00;
	
	// constant value for array size
	const int ARRAY_SIZE = 9;
	
	// variable stock is of StockField data type (structure)
	StockField Stock[ARRAY_SIZE];

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
                                                
	// call to instruction function to explain to user how to use program
	instructions();
	
	// opening Stock.txt using input file stream object called inputFile
	inputFile.open("Stock.txt");
	
	// using a loop to read Stock.txt into an array
	for (count = 0; count < 9; count++)
	{
		inputFile >> Stock[count].stockNo;
		inputFile >> Stock[count].description;
		inputFile >> Stock[count].price;			
	}
	
	// close inputFile object - good house keeping!	
	inputFile.close();
	
	// Loop to keep user entering item codes to search for as long as they
	// Don't enter a zero sentinal value to escape the loop
	while (userItemCode != 0)
	{
		// prompt user to enter item code
		cout << "" << endl;
		cout << "Enter the Item Code to See the Details: ";
		cin >> userItemCode;
		cout << "                                                     " << endl;
		
		// this flag indicates that a match for userItemCode and an itemCode in
		// the array read from Stock.txt has not yet been found, if at all.
		found = false;
		
		// counter controlled loop to match user input to an item code in
		// the array read in from Stock.txt
		for (count = 0;count < 9 && userItemCode != 0;count++)
		{
			
			// if a match between user input and item code in the array happens
			if(userItemCode==Stock[count].stockNo)
			{
				
				// flag set to true because a match was found
				found = true;
				
				// display the item details
				cout << "Item Code " << Stock[count].stockNo << endl;
				cout << Stock[count].description << endl;
				cout << "$" << Stock[count].price << endl;
				cout << "" << endl;
				
				 
				// a call to getQuantity returns an integer value to quantity
				// variable
				quantity = getQuantity();
				
				// getting the price for the line item using base cost *quantity
				lineTotal = Stock[count].price * quantity;
		
				// putting lineTotal in runningTotal accumulator
				runningTotal+= lineTotal;
				
				// once itemCode match is found - output details to Sales.txt
				outputFile << "Quantity: " << quantity << endl;
				outputFile << "Item Code " << Stock[count].stockNo << endl;
				outputFile << Stock[count].description << endl;
				outputFile << quantity << " units" << " @ $"<<Stock[count].price << 
				                                             " per item" <<endl;
				outputFile << "" << endl;
			
			}
			
		
		}
		

		// if the user is asked for an item code and they enter a 0 - they are
		// brought here.
		if(userItemCode==0)
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
			
			// formula for change
			change = (cashTendered - (runningTotal + (runningTotal * TAX)));
			
			outputFile << "" << endl;
			outputFile << "" << endl;
			outputFile << "Cash Tendered: \t$" << setw(9) << cashTendered 
			
					                                                    << endl;
			// if the customer doesn't pay the correct amount - void transaction
			if (change < -0.005)
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
				
						
				// close file stream object
				outputFile.close();
				
				// end process
				return 0;
			}
			
			// if the customer pays in full or has change to receive
			else
			{
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
			
			// close file stream object	
			outputFile.close();
			
			// end process	
			return 0;	
				
			
			}
				
		}
		
		// if the for loop runs through the entire array and a found flag
		// has not been set to true and remains false - the user is brought
		// here. - they are then sent back to enter an item code
		if(found == false)
		{
			cout << "You have entered an invalid item code!" << endl;
			
		}	
				
	}
		

	return 0;
	
}

// instructions offers the user a set of text based instructions on how to
// proceed
void instructions()
{
	
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
	
}

// get quantity is used to capture an integer value referencing how many of
// a particular item the customer would like to purchase.
// an integer value is returned.
// negative values are not accepted.
int getQuantity()
{
	int howMany;
	
	// get quantity of items
	cout << "Quantity: ";
	cin >> howMany;
	// preventing user from entering a negative value for quantity
		while (howMany < 0)
		{
			cout << "" << endl;
			cout << "A negative quantity cannot be entered." << endl;
			cout << "" << endl;
			
			// get quantity of items
			cout << "Quantity: ";
			cin >> howMany;
		
		}
	// returning positive integer value	
	return (howMany);
	
}	

