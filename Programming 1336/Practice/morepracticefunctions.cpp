#include <iostream>
using namespace std;

void showDouble(int);

int main()
{
	int num;
	
	for (num = 0; num < 10; num++)
		showDouble(num);
	
	return 0;
}

void showDouble(int value)
{
	cout << value << "\t" << (value * 2) << endl;
}

