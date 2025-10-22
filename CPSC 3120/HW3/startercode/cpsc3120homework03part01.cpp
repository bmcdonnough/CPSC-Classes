#include "cpsc3120homework03part01.h"
#include <vector>
#include <algorithm>

using namespace std;

int assemblyLine( vector<int> line1 , vector<int> line2 , vector<int> t12 , vector<int> t21 ){
    int n = line1.size();
    std::vector<int> dp1(n), dp2(n);
    
    dp1[0] = line1[0];
    dp2[0] = line2[0];
    
    for (int i = 1; i < n; i++){
        dp1[i] = std::min(dp1[i-1] + line1[i], dp2[i-1] + t21[i-1] + line1[i]);
        
        dp2[i] = std::min(dp2[i-1] + line2[i], dp1[i-1] + t12[i-1] + line2[i]);
    }
  return std::min(dp1[n-1], dp2[n-1]);
}
