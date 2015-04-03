// Derick Warshaw
// Lab #9 create a table of the costs, revenue, and profit(or loss) corresponding to range of production levels.
// COSC1336 Section 001
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
int prodLevel, count, numPin; // variable definition
double cost, rev, costBucket, revBucket, prolossBucket, proLos;

// initialize accumulators to zero
costBucket = 0;
revBucket = 0;
prolossBucket = 0;

cout << "KingPin Manufacturing Company Production Analytics" << endl;
cout << "----------------------------------------------------------------------" << endl;
cout << "Select a production level to see Revenue, Cost, and P&L" << endl;
cout << "\nPlease Enter Production Level: "; // get user entry for production level
cin >> prodLevel;

while (prodLevel < 1) // error when user attempts to enter production value < 1
	{
	cout <<"You have entered an invalid production level." << endl;
	cout <<"Please Enter Production Level: ";
	cin >> prodLevel;
	}
cout << "" << endl;
cout << "Level" << "\tCost" << "\t\t\tRevenue" << "\t\t\tProfit/Loss" << endl; // formatting column headers for data output
cout << "----------------------------------------------------------------------" << endl;
cout << "" << endl;

for (count=1; count<=prodLevel;count = count + 1) // loop to calculate the revenue and cost at each level of production
	{
	numPin = 100 * count;
	cost = 100000 + (12 * numPin);
	costBucket += cost; // put cost in cost accumulator
	
	rev = numPin * (1000 - numPin);
	revBucket += rev; // put rev in rev accumulator
	
	proLos = revBucket - costBucket;
	prolossBucket += proLos; // put prof or loss in accumulator
	
	cout << fixed << setprecision(2) << showpoint; // formatting output
	cout << count << "\t$" << costBucket << "\t\t$" << revBucket << "\t\t$" << proLos << endl;	// output calculated data at each production level
	
	if (count==prodLevel) // when loop is done display average profit or loss
		cout << "\n\nAverage Profit/Loss: $" << prolossBucket / prodLevel << endl; // display average profit or loss
	}
cout << "" << endl;
cout << "----------------------------------------------------------------------" << endl;
cout << "" << endl;
	
	//system("pause");
	
	return 0;
}
