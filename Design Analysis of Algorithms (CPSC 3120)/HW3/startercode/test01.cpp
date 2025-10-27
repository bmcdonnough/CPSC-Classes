#include "cpsc3120homework03part01.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){
  vector<int> values;
  int val;
  while( cin >> val ){
    values.push_back( val );
  }

  int n = ( values.size() + 2 ) / 4;
  vector<int> line1;
  vector<int> line2;
  vector<int> t12;
  vector<int> t21;

  for( int i = 0; i < values.size(); i++ ){
    if( i < n ){
      line1.push_back( values[i] );
    }
    else if( i < 2*n - 1 ){
      t12.push_back( values[i] );
    }
    else if( i < 3*n - 2 ){
      t21.push_back( values[i] );
    }
    else{
      line2.push_back( values[i] );
    }
  }

  /*
  for( int i = 0; i < n; i++ ){
    fprintf( stderr , "% 2d  " , line1[i] );
  }
  cerr << endl;

  cerr << "  ";
  for( int i = 0; i < n-1; i++ ){
    fprintf( stderr , "% 2d  " , t12[i] );
  }
  cerr << endl;

  cerr << "  ";
  for( int i = 0; i < n-1; i++ ){
    fprintf( stderr , "% 2d  " , t21[i] );
  }
  cerr << endl;

  for( int i = 0; i < n; i++ ){
    fprintf( stderr , "% 2d  " , line2[i] );
  }
  cerr << endl;
  */
  
  try{
    fprintf( stdout , "An item can be made in a minimum of %d seconds\n" , assemblyLine( line1 , line2 , t12 , t21 ) );
  }
  catch( exception e ){
    cerr << "An error occurred." << endl;
  }
}
