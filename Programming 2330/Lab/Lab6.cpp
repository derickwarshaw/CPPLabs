// Derick Warshaw
// Lab #6 GPA / student ID parallel arrays sorted in ascending order
// COSC2330 Section 001

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// function prototypes
void sortArray(double [], int [], const int);
void showArray(double [], int [], const int);


int main()
{
	const int ARRAY_SIZE = 20;				// holds number of elements in array
	int studentNumber[ARRAY_SIZE];		    // array to hold student id number
	double gpa[ARRAY_SIZE];					// array to hold gpa for student
	char dataFile[20];						// holds user provided file name
	bool stopReading = false;				// boolean used to stop reading file
	int count = 0;
	
	
	// formatting output appropriately
	cout << fixed << setprecision(1) << showpoint;
	
	
	// creating input file stream object
	ifstream inputFile;
	
	cout << "What is the file name you want to open and read into array: ";
	cin >> dataFile;
	
	cout << " " << endl;
	cout << "STUDENT ID" << "\tGPA" << endl;
	cout << "--------------------- " << endl;
	cout << " " << endl;

	// passing name of file user provides to input file stream object to open
	inputFile.open(dataFile);
	
	// count controlled loop to read file contents into parallel arrays
	for (count = 0; count < ARRAY_SIZE && stopReading == false; count++)
		{
			
			inputFile >> studentNumber[count];
			inputFile >> gpa[count];
			
			// 99.9 is sentinal value in data file - this stops the input stream
			if (gpa[count] > 99.0)
			{
				
				stopReading = true;
				
			}

		}
	
	/* calling sortArray and passing gpa array, studentNumber array, and number
	of elements in the arrays */
	sortArray(gpa, studentNumber, ARRAY_SIZE);
	
	/* calling showArray and passing gpa array, studentNumber array, and number
	of elements in the arrays
	*/	
	showArray(gpa, studentNumber, ARRAY_SIZE);
	
	return 0;
	
}


/* sortArray() is a function that can be passed a double array, int array, and 
constant integer as it's arguments. gpaArray, studentArray, and size are 
parameters that are used in the bubble sort algorithm for ascending order.
 */
void sortArray(double gpaArray[], int studentArray[], const int size)
{
	bool swap;
	double gpaTemp = 0.0;
	int idTemp = 0;
	bool stopSorting = false;
	
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1) && stopSorting == false; count ++)
		{
			if (gpaArray[count] > gpaArray[count + 1])
			{
				gpaTemp = gpaArray[count];
				idTemp = studentArray[count];
				
				gpaArray[count] = gpaArray[count + 1];
				studentArray[count] = studentArray[count +1];
				
				gpaArray[count + 1] = gpaTemp;
				studentArray[count + 1] = idTemp;
				swap = true;
				
				if(gpaArray[count > 99.0])
				{
					stopSorting = true;
				}
			}
		}
		
	} 
	while(swap);
}


/* showArray()is a function that can be passed a double array, int array, and 
constant integer as it's arguments. gpaArray, studentArray, and size are 
parameters that are used to display the parallel arrays.
 */
void showArray(double gpaArray[], int studentArray[], const int size)
{
	bool stopShowing = false;
	
	for (int count = 0; count < size && stopShowing == false; count++)
	{
		/* stop displaying if GPA value is greater than 99.0 - avoids
		displaying contents of sentinal value 99.9
		*/
		if (gpaArray[count] > 99.0)
		{
			stopShowing = true;
		}
		
		if (gpaArray[count] < 99.0)
		{
		
		cout << studentArray[count] << "\t\t" << gpaArray[count] << endl;
		cout << " " << endl;	
		
		}
		
	}
		
}


