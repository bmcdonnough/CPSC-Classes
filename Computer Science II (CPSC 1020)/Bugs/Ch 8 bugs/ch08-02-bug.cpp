// This program reads employee work hours from a file
// and stores them in an int array. It uses one loop
// to input the hours and another to display them.

// BUGS: be sure to look at the work.dat file so you can figure out what the output should look like.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   const int NUM_EMPLOYEES = 11;  // Sets number of employees
   int hours[NUM_EMPLOYEES];     // Holds each employee's hours
   int count = 0;                // Loop control variable counts
                                 // how many data items have been read in
   int total = 0;
   ifstream inputFile;           // Input file stream object

   // Open the data file.
   inputFile.open("work.dat");
   if (!inputFile)
       cout << "Error opening data file\n";
   else
   {   // Read the numbers from the file into the array. When we exit
       // the loop, count will hold the number of items read in.
       while (inputFile >> hours[count] )
           count++;

       // Close the file.
       inputFile.close();

       // Display the contents of the array.
       cout << "The hours worked by each employee are\n";
       for (int employee = 1; employee <= count; employee++)
       {   cout << "Employee " << employee << ": ";
           cout << hours[employee - 1] << endl;
                 total += hours[employee - 1];
       }
         cout << "Total hours: " << total << endl;
   }
   return 0;
}