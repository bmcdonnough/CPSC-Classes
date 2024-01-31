// This program demonstrates a recursive function for
// counting the number of times a character appears
// in a string.
#include <iostream>
#include <string>
using namespace std;

class Frequency {
public:
    Frequency() {}
    //************************************************
    // Function frequency. This recursive function   *
    // counts the number of times the character      *
    // ch appears in inputString. The search begins  *
    // at index position in the string.              *
    //************************************************
    int recurse(char ch, string inputString, int position)
    {
       if (position == inputString.length())   //base case
          return 0;
       else if (ch == inputString[position]){
          position++;
          return 1 + recurse(ch, inputString, position);
       }
          
       else{
            position++;
            return recurse(ch, inputString, position);
       }
    }
};

int main()
{
    string inputString;
    cin >> inputString;
    char letter;
    cin >> letter;

    Frequency f;

    cout << "The letter " << letter << " appears "
 << f.recurse(letter, inputString, 0) << " times.\n";
   return 0;
}