#include "cpsc3120homework01part01.h"
#include <vector>
#include <cmath>

using namespace std;

int maxSubSlow( const vector<int> &numbers ){
  int m = 0;
  for(int j = 1; j < numbers.size(); j++){
    for(int k = j; k < numbers.size(); k++){
      int s = 0;
      for(int i = j; i <= k; i++){
        s += numbers[i];
      }
      if(s > m){
        m = s;
      }
    }
  }
  return m;
}

int maxSubFaster( const vector<int> &numbers ){
  vector<int> S(numbers.size());

  for(int i = 1; i < numbers.size(); i++){
    S[i] = S[i-1] + numbers[i];
  }
  int m = 0;
  for(int j = 1; j < numbers.size(); j++){
    for(int k = j; k < numbers.size(); k++){
      int s = S[k] - S[j-1];
      if(s > m){
        m = s;
      }
    }
  }
  return m;
}

int maxSubFastest( const vector<int> &numbers ){
  vector<int> M(numbers.size());
  for(int t = 1; t < numbers.size(); t++){
    M[t] = max(0, M[t-1] + numbers[t]);
  }
  int m = 0;
  for(int t = 1; t < numbers.size(); t++){
    m = max(m, M[t]);
  }
  return m;
}
