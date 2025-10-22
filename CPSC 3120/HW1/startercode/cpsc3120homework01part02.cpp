#include "cpsc3120homework01part02.h"
#include <vector>

using namespace std;

void removeMultiplesOfThree( vector<int> &numbers ){
  for (int i = 0; i < numbers.size(); i++){
    if(numbers[i] % 3 == 0){
      numbers.erase(numbers.begin() + i);
      i -= 1;
    }
  }
  return;
}
