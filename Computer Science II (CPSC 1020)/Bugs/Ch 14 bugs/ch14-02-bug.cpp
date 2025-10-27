// This program demonstrates a recursive function
// to calculate the factorial of a number.
#include <iostream>
#include <string>
using namespace std;

class Factorial {
public:
    Factorial() {}
    //****************************************************
    // Definition of factorial. A recursive function to  *
    // calculate the factorial of the parameter, num.    *
    //****************************************************
    int recurse(int num)
    {
      if (num == 0)  //base case
        return 1;
      else
        if(num - 1 != 0){
            return num * recurse(num - 1);
        }
        else
            return num;
    }

};

int main()
{

     Factorial f;
     int num;
     cin >> num;
     cout << num << "! = " << f.recurse(num) << endl;
   return 0;
}