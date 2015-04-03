// program 4-12
// this program uses nested if/else statements to assign
// a letter grade to a numeric test score

#include <iostream>
using namespace std;

int main()
{
	// constants for grade thresholds
	const int A_SCORE = 90,
			  B_SCORE = 80,
			  C_SCORE = 70,
			  D_SCORE = 60;
			  
	int testScore; // to hold a numeric test score
	
	// get the numeric test score
	cout << "Enter your numeric test score and I will\n";
	cout << "tell you the letter grade you earned: ";
	cin >> testScore;
	
	// determine the letter grade
	if (testScore >= A_SCORE)
	{
		cout << "Your grade is an A." << endl;
		cout << "Excellent work!!!!!" << endl;
	}
	else
	{
		if (testScore >= B_SCORE)
		{
			cout << "Your grade is B." << endl;
		}
		else
		{
			if (testScore >= C_SCORE)
			{
				cout << "Your grade is C." << endl;
			}
			else
				{
					if (testScore >= D_SCORE)
					{
						cout << "Your grade is D." << endl;
					}	
					else
					{	
						cout << "Your grade is F." << endl;
					}
			}
		}
	}
	
	return 0;
}


