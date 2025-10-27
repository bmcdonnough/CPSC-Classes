// This program illustrates a problem that can occur if
// cin is used to read character data into a string object.
// input a name with first and last (space between) and observe the bug, then fix
#include <iostream>
#include <string>       // Header file needed to use string objects
using namespace std;

int main()
{
    string name;
    string city;

    cout << "Please enter your name: ";
	 getline(cin, name);
    cout << "Enter the city you live in: ";
	 getline(cin, city);

    cout << "Hello, " << name << endl;
    cout << "You live in " << city << endl;
    return 0;
}
