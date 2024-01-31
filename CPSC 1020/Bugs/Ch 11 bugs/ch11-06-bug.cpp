// This program demonstrates the use of the [ ] operator.
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
class Name
{
    string first_name;
    string last_name;
    void subError()
    {
        cout << "Index must be 1 or 2\n" ;
        exit(1);
    }
public:
    string &operator[ ](int index)
    {
        switch(index)
        {
            case 1: return first_name; break;
            case 2: return last_name; break;
            default: subError();
        }
                return first_name;  // not needed logically but gets rid of warning
    }
        string const getLastName() {return last_name; }
};

int main()
{
    Name  name;

    // Set first name and last name
    name[1] = "Joseph";
    name[2] = "Puff";

    // Access first name and last name
    cout << name[1] << " " << name[2] << " aka Joe Blow\n";

        cout << "last name is: " << name.getLastName() << endl; 

    return 0;
}