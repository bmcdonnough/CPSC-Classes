#include "cpsc3120homework03part02.h"
#include <vector>
#include <climits>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int matrixChainMultiplication( vector< vector<int> > matrices ){
    int n = matrices.size();
    if (n == 0){
        return 0;
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));
    
    for (int i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    
    for (int len = 2; len <= n; ++len){
        for (int i = 0; i <= n - len; ++i){
            int j = i + len - 1;
            for (int k = i; k < j; ++k){
                int cost = dp[i][k] + dp[k+1][j] + matrices[i][0] * matrices[k][1] * matrices[j][1];
                dp[i][j] = std::min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n-1];
}
