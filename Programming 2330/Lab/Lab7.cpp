// Derick Warshaw
// Lab #7 Distillation of Human Knowledge using two dimensional array
// COSC2330 Section 001

#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
	
	// variable initialization
	int col = 0;
	int row = 0;
	double old = 0.0;
	const int ARRAY_SIZE = 20;
	double still[ARRAY_SIZE][ARRAY_SIZE];
	bool doAgain = true;
	
	
	// formatting output appropriately to see the precision of the calculation
	cout << fixed << setprecision(4) << showpoint;
	
	// set the inner pipe to 212 degrees
	for (col = 1; col <= 19; col++)
	{
		for (row = 1; row <=18; row++)
		{
			
			if (row >= 7 && row <= 12 && col > 7 && col <= 12)
			{

				still[row][col] = 212.0;
	
			}	
		}
	}
	
	// set everything around the middle pipe to 90 degrees
	for (col = 1; col <= 19; col++)
	{
		for (row = 1; row <=18; row++)
		{
			
			if (!(row >= 7 && row <= 12 && col > 7 && col <= 12))
			{

				still[row][col] = 90.0;
			
			}	
		}
	}
	
	// set top of still to 100 degrees
	for (col = 0; col <= 19; col++)
	{
		for (row = 0; row <=19; row++)
		{
			
			if (row == 0 && col <= 19)
			{
	
				still[row][col] = 100.0;

			}	
		}
	}
	
	
	// set left side of still to 90 degrees
	for (col = 0; col == 0; col++)
	{
		for (row = 0; row <=19; row++)
		{
			
			if (row == 0 && col <= 0)
			{
	
				still[row][col] = 90.0;

			}	
		}
	}
	
	// set right side of still to 90 degrees
	for (col = 19; col == 19; col++)
	{
		for (row = 0; row <=19; row++)
		{
			
			if (row <= 0 && col == 19)
			{
	
				still[row][col] = 90.0;
	
			}	
		}
	}
	
	
	// set bottom row temp for still at 32
	for (col = 0; col <= 19; col++)
	{
		for (row = 19; row ==19; row++)
		{
			
			if (row == 19 && col <=19)
			{

				still[row][col] = 32.0;

			}	
		}
	}
	
	/* while the doAgain flag is set to true - the process of comparing the
	squares will continue until the difference between them is less than .01 .
	Then the loop will stop once doAgain is set to false and the average temp
	prints out to the console.
	*/
	while(doAgain == true)
	{
		
		for (col = 1; col <=18;col++)
		{
			
			
			for (row = 1; row <= 18; row++)
			{
				
				if(row >= 7 && row <= 12 && col > 7 && col <= 12)
				{
					
					
					old = still[row][col];
					still[row][col] = (still[row][col - 1] + still[row-1][col] + 
					still[row][col + 1] + still[row + 1][col]) / 4;

					if (old - still[row][col] > .01)
					{
						
						doAgain = true;
						
					}
					
					else if (old - still[row][col] < .01)
					{
						cout << "The average temperature is: " <<  old << endl;
						doAgain = false;
					}
					
				}
		
			}
		
		}
		
	}
	
	return 0;
}
