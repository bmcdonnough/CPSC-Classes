#include "cpsc3120homework01part02.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <time.h>

using namespace std;

int main( int argc , char* argv[] ){
  vector<int> numbers;
  int val;
  while( cin >> val ){
    numbers.push_back( val );
  }

  cout << "Before: ";
  cout << numbers[0];
  for( int i = 1; i < numbers.size(); i++ ){
    cout << " " << numbers[i];
  }
  cout << endl;
  
  try{
    clock_t start = clock();
    removeMultiplesOfThree( numbers );
    clock_t end = clock();
    cout << "After : ";
    cout << numbers[0];
    for( int i = 1; i < numbers.size(); i++ ){
      cout << " " << numbers[i];
    }
    cout << endl;
    fprintf( stderr , "removeMultiplesOfThree took %.7f seconds.\n" , 1.0 * ( end - start ) / CLOCKS_PER_SEC );
  }
  catch( exception e ){
    cerr << "An error occurred." << endl;
  }
}
