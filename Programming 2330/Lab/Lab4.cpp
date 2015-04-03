// Derick Warshaw
// Lab #4 Volume Calculator for Snowman Family
// COSC2330 Section 001

#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
void displayInstructions();
void computeVolumes(double &, double &);
void getRadii(double &);
void displayResults(double, double, double);

// setting constant for PI value used in Volume forumula in computeVolumes()
const double PI = 3.14;

int main()
	{
		
		// formatting output
		cout << fixed << setprecision(2) << showpoint;
		
		// variable initializations
		double mommaVolume1 = 0.00;
		double mommaVolume2 = 0.00;
		double mommaVolume3 = 0.00;
		
		double papaVolume1 = 0.00;
		double papaVolume2 = 0.00;
		double papaVolume3 = 0.00;
		
		double babyVolume1 = 0.00;
		double babyVolume2 = 0.00;
		double babyVolume3 = 0.00;
		
		double totalVolume = 0.00;
		

		/* call to displayInstructions - this function provides details of
		how to use the program and what it is looking for as data input*/
		displayInstructions();
		
		cout << "Please enter 3 radii for momma" << endl;
		cout << "" << endl;
		cout << "" << endl;
		
		
		/* call to computeVolumes - passing by reference mommaVolume1, 2, and 3
		as well as an accumulator for total snow volume for the family.  */
		computeVolumes(mommaVolume1, totalVolume);
		computeVolumes(mommaVolume2, totalVolume);
		computeVolumes(mommaVolume3, totalVolume);
		
		
		cout << "" << endl;
		cout << "" << endl;
		cout << "Please enter 3 radii for papa" << endl;
		cout << "" << endl;
		cout << "" << endl;
		
		/* call to computeVolumes - passing by reference mommaVolume1, 2, and 3
		as well as an accumulator for total snow volume for the family.*/
		computeVolumes(papaVolume1, totalVolume);
		computeVolumes(papaVolume2, totalVolume);
		computeVolumes(papaVolume3, totalVolume);
		
		
		cout << "" << endl;
		cout << "" << endl;
		cout << "Please enter 3 radii for baby" << endl;
		cout << "" << endl;
		cout << "" << endl;
		
		/* call to computeVolumes - passing by reference mommaVolume1, 2, and 3
		as well as an accumulator for total snow volume for the family.*/
		computeVolumes(babyVolume1, totalVolume);
		computeVolumes(babyVolume2, totalVolume);
		computeVolumes(babyVolume3, totalVolume);
		cout << "" << endl;
		cout << "" << endl;
		
		
		cout << "Momma ";
		/*display results of the three radii entered for momma - these are
		passed by reference and any changes to the variable were done in 
		function getRadii()*/
		displayResults(mommaVolume1, mommaVolume2, mommaVolume3);
		
		
		cout << "Papa ";
		/*display results of the three radii entered for papa - these are
		passed by reference and any changes to the variable were done in 
		function getRadii()*/
		displayResults(papaVolume1, papaVolume2, papaVolume3);
		
		
		cout << "Baby ";
		/*display results of the three radii entered for baby - these are
		passed by reference and any changes to the variable were done in 
		function getRadii()*/
		displayResults(babyVolume1, babyVolume2, babyVolume3);
		
		
		/*passing in totalVolume, an accumulator for all snow needed to create
		the family of snow people. Every time computeVolumes() sends a value
		in by reference to getRadii() and it is changed, the data is stored
		in the bucket being sent for display. 0.00 is being passed twice because
		the displayResults function expects 3 doubles to be on their way but
		only 1 is needed 1 displayed this time. */
		cout << "Family ";
		displayResults(totalVolume, 0.00, 0.00);
		
		
		return 0;
	}
	
// function to display instructions to the user	
void displayInstructions()
	{
		
		cout << "* The user will enter 3 radii for each snow person" << endl;
		cout << "* The program will calculate and display the volume" << endl;
		cout << "  of snow required for each family member and for the" << endl;
		cout << "  entire family" << endl;
		cout << "" << endl;
		cout << "" << endl;
		
	}
	
// function to compute the volumes for the family of snow people	
void computeVolumes(double &volume, double &volumeContainer)
	{
		
		// variables to hold radii entry from user
		double radii1 = 0;
		
		
		// getting values from the user
		getRadii(radii1);
		
		
		/* this is the formula used to derive volume for the snow people */
		volume = (4.0/3.0 * (PI * (radii1 * radii1 * radii1))); 
		
		/* this statement allows an accumulator for total volume of snow
		for the entire family. This will be displayed after the individual
		volumes for mama, papa, and baby are displayed */
		volumeContainer+= volume;
		
	}
	
// function to get the radii	
void getRadii(double &val1)
	{
		
		cout << "-------- > ";
		cin >> val1;
		
		// if the user attempts to enter a negative radii - display error
		// and ask for good data until they provide good data.
		while (val1 <= 0.00)
		{
			cout << "Distance can only be given with a positive value" << endl;
			cout << "Please enter valid data" << endl;
			cout << "" << endl;
			cout << "" << endl;
			cout << "-------- > ";
			cin >> val1;
			
		}
		
	}
	
// function to display the results	
void displayResults(double result1, double result2, double result3)
{
	
	cout << "\tVolume:\t" << result1 + result2 + result3 << endl;
	
}

