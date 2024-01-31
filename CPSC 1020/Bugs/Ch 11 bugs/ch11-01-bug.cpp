// This program demonstrates a static class member variable.
#include <iostream>
#include <iomanip>
using namespace std;

class Budget {
private:
   static double corpBudget;
   double divBudget;
public:
   Budget() { divBudget = 0; }
   void addBudget(double b) { 
    divBudget += b;
    corpBudget += divBudget; }
    
   double getDivBudget() const { return divBudget; }
   double getCorpBudget() const { return corpBudget; }
};
// Definition of the static member of the Budget class.
double Budget::corpBudget = 0;

int main() {
      const int N_DIVISIONS = 4;
      Budget divisions[N_DIVISIONS];

      // Get the budget request for each division
      for (int count = 0; count < N_DIVISIONS; count++) {
          double bud;

          cout << "Enter the budget request for division ";
          cout << (count + 1) << ": ";
          cin >> bud;
          divisions[count].addBudget(bud);
          //cout << divisions[count].getDivBudget() << endl;
      }

      // Display the budget request for each division
      cout << setprecision(2);
      cout << showpoint << fixed;
      cout << "\nHere are the division budget requests:\n";
      for (int count = 0; count < N_DIVISIONS; count++){
        cout << "Division " << (count + 1) << "\t$ ";
         cout << divisions[count].getDivBudget() << endl;
      }

      // Display the total budget request
      cout << "Total Budget Requests:\t$ ";
      cout << divisions[0].getCorpBudget() << endl;

      return 0;
}