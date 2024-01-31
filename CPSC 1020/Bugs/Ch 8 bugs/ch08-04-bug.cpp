#include <iostream>
#include <vector>
using namespace std;

// Function prototype
void showValues(vector<int>);
void showStats(vector<int>);

int main()
{
    vector<int> values = {4,2,6,7,2,9};

    // Store a series of numbers in the vector
    for (int count = 0; count < 7; count++)
        values.push_back(count * 2);

    // Display the numbers
    showValues(values);
    showStats(values);
    values.pop_back();
    showStats(values);
    for (int i=0; i<1000; i++) {
        values.push_back(i);
    }
    showStats(values);
    values.clear();
    showStats(values);
    return 0;
}

/*****************************************************************
 *                       showValues                              *
 * This function accepts an int vector as its sole argument, and *
 * displays the value stored in each of the vector's elements.   *
 *****************************************************************/
void showValues(vector<int> vect)
{
    for (int count = 0; count < vect.size(); count++)
        cout << vect[count] << "  ";
    cout << endl;
}

void showStats(vector<int> vect) {
    cout << "size: " << vect.size() << " capacity: " << vect.capacity() << endl;
}
