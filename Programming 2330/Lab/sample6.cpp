#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
	//Variables
	const int SIZE = 100;
	int b, a, k;
	int count = -1;
	double temp;
	double tempp;
	double digit [SIZE];
	double gpa [SIZE] ;
	ifstream inputFile;
	char dataFile[20];
	
	cout <<"Please enter the data file's name \n";
	cin >> dataFile;
	inputFile.open (dataFile);
	do
	{
		count++;
		inputFile >> digit[count];
		inputFile >> gpa [count];
		//count++;
	}
	while (gpa[count] < 99.9);
	
	//Bubble sort
	for (a=1; a<= count; a++)
	{
		b=0;
		while (b < (count-1))
		{
			if (gpa[b] > gpa [b+1])
			{
				temp = gpa[b];
				tempp = digit [b];
				gpa [b] = gpa[b+1];
				digit [b] = digit [b+1];
				gpa [b+1] = temp;
				digit [b+1] = tempp;
				
			}
			
			b++;
		}
	}
	
 //display

 for (k =0; k < count; k++)

{
	cout <<"Id: ";
	cout << digit[k] << endl;
	cout << "Gpa: ";
	cout << gpa [k] << endl;
}
	inputFile.close ();
return 0;	
}



