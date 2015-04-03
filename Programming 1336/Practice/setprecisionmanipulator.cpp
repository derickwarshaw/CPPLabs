// setprecision program 3-15 in book p.114 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double quotient, number1 = 132.364, number2 = 26.91;
	
	quotient = number1 / number2;
	cout << quotient << endl;
	cout << setprecision(5) << quotient << endl;
	cout << setprecision(4) << quotient << endl;
	cout << setprecision(3) << quotient << endl;
	cout << setprecision(2) << quotient << endl;
	cout << setprecision(1) << quotient << endl;
	
	return 0;
}
