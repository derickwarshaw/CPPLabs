// Derick Warshaw
// Lab #3 Write a program that computes the batting average of a baseball player when the user inputs the number of hits and the number of at bats for the player
// COSC1336 Section 001

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int hits, atBats;												// define variables
	float battingAvg;
	
	cout << "How many hits did the player have? ";					// ask user to input "hits"
	cin >> hits;
	cout << "How many times did the player bat? ";  				// ask user to input "at bats"
	cin >> atBats;
	
	battingAvg = static_cast<float>(hits) / atBats; 				// calculating batting average and using static_cast<DataType>(DataValue) to convert hits from int to float
	
	cout << fixed << setprecision(3) << showpoint;					// formatting batting average to display fixed, precision of 3, showing decimal point
	cout << "The player has a "<< battingAvg << " batting average.";// display batting average
	
	system("pause");
	return 0;
}
