#include <iostream>
using namespace std;

// Why do I use cin.ignore() after cin.getline(name,30) to flush before getting city - but I don't have to do it before cin.getline(profession,30)?
// If I use cin.ignore() before profession - it cuts off the first character of the user input. Why?


int main()
{
	char name[30], city[30], college[30], profession[30], animal[30], pname[30];
	int age;
	
	cout << " Enter your name: ";			// asking for user to enter name
	cin.getline(name,30);					// gets user input and puts it in name
	cout << " Enter your age: ";			// asking for age
	cin >> age;								// gets age
	cout << " Enter the name of a city: ";	// asks for city
	cin.ignore();							// flush cin
	cin.getline(city,30);					// get user input and puts it in city
	cout << " Enter a profession: "; 		// asking for profession
	cin.ignore();
	cin.getline(profession,30);				// gets user input and puts it in profession 
	cout << " Enter the name of an animal: ";// asks for the name of an animal
	cin >> animal;							// gets an	imal
	cout << " Enter the name of a pet: ";	// asks for a name of pet
	cin >> pname;							// gets pet name
	cout << " Enter a college: " ;			// asks for college
	cin >> college;							// gets college
	
	cout << " There once was a person named " << name
		 << " who lived in " << city
		 << ".\nAt the age of " << age 
		 << ", " << name << " went to college at " << college << ". " 
		 << name << " \ngraduated and went to work as a " << profession
		 << ". Then, " << name << " \nadopted a(n) " << animal
		 << " named " << pname << ". They both lived happily ever after!";
		 
	return 0; 
}	
