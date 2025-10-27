#include <vector>
#include "cpsc3120homework04part02.h"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

vector< vector<double> > allPairsSP( vector< vector<double> > adjacencyMatrix , int i ){
    int n = adjacencyMatrix.size();
    double INF = numeric_limits<double>::infinity();
    
    for (int u = 0; u < n; u++){
        for (int v = 0; v < n; v++){
            if(adjacencyMatrix[u][v] == -1){
                adjacencyMatrix[u][v] = INF;
            }
        }
    }
    
    for (int k = 0; k < i; k++){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(adjacencyMatrix[u][k] < INF && adjacencyMatrix[k][v] < INF){
                    adjacencyMatrix[u][v] = min(adjacencyMatrix[u][v], adjacencyMatrix[u][k] + adjacencyMatrix[k][v]);
                }
            }
        }
    }
    
    for (int u = 0; u < n; u++){
        for (int v = 0; v < n; v++){
            if(adjacencyMatrix[u][v] == INF){
                adjacencyMatrix[u][v] = -1;
            }
        }
    }
    
    return adjacencyMatrix;
}
