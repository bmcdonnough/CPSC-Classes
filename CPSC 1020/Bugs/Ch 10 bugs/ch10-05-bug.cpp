// This program uses a pointer to display the contents
// of an integer array. It illustrates the comparison of
// pointers.
#include <iostream>
using namespace std;

int main()
{
   const int SIZE = 8;
    int numbers[ ] = {5, 10, 15, 20, 25, 30, 35, 40};
    int *numPtr = numbers;        // Make numPtr point to numbers

    cout << "The numbers in the array are:\n";
    cout << *numPtr << " ";   // Display first element
    while (numPtr < &numbers[SIZE-1])
    {
        // Advance numPtr to the next element
        numPtr++;
        // Display the value pointed to by numPtr
        cout << *numPtr << " ";
    }

    // Display the numbers in reverse order
    cout << "\nThe numbers in reverse order are:\n";
    cout << *numPtr << " "; // Display last element
    while (numPtr > numbers)
    {
        // Move backward to the previous element
        numPtr--;
        // Display the value pointed to by numPtr
        cout << *numPtr << " ";
    }
    return 0;
}