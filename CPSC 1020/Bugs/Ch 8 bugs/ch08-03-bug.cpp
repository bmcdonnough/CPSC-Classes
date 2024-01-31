// This program demonstrates how an overloaded constructor
// that accepts an argument can be invoked for multiple objects
// when an array of objects is created.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Circle.h"         // Circle class declaration file
using namespace std;

int main()
{
    double mean = 0.0;
    //Circle circles;
    // Define a vector of  Circle objects. Use an initia // to call the 1-argument constructor for the objects.
    vector<Circle> circles;
    circles.push_back(0.0);
    circles.push_back(2.0);
    circles.push_back(2.5);
    circles.push_back(56.0);
    circles.push_back(75.0);
    circles.push_back(5.0); 

    // Display the area of each object
    cout << "\nHere are the areas of the " << circles.size()
         << " circles.\n";

    for (auto& x : circles) {
      cout << "circle " << setw(8) << fixed << setprecision(2) << x.findArea() << endl;

      mean += x.findArea();
    }

    mean = mean / circles.size();

    cout << "The average area of these circles is: " << mean << endl;
    return 0;
}