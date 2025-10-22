#include "cpsc3120homework03part02.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){

  vector< vector<int> > matrices;
  int r;
  int c;
  while( cin >> r >> c ){
    vector<int> matrix(2,0);
    matrix[0] = r;
    matrix[1] = c;
    matrices.push_back( matrix );
  }

  for( int i = 0; i < matrices.size(); i++ ){
    fprintf( stderr , "Matrix % 3d: %d×%d\n" , i + 1 , matrices[i][0] , matrices[i][1] );
  }
  
  try{
    fprintf( stdout , "The matrices can be multiplied with a minimum of %d multiplications\n" , matrixChainMultiplication( matrices ) );
  }
  catch( exception e ){
    cerr << "An error occurred." << endl;
  }
}
