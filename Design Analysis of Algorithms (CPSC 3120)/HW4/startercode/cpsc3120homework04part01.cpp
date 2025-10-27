#include <vector>
#include "cpsc3120homework04part01.h"
#include <cmath>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

double maximumST( vector< vector<double> > adjacencyMatrix ){
    vector<int> row(4,-1);
    vector< vector<int> > matrix(5,row);
    cerr << matrix.size() << endl;
    cerr << matrix[0].size() << endl;
    for( int i = 0; i < 5; i++ ){
    for( int j = 0; j < 4; j++ ){
      fprintf( stderr , "% 2d " , matrix[i][j] );
    }
    cerr << endl;
    }
    
    int n = adjacencyMatrix.size();
    vector<bool> visited(n, false);
    priority_queue<pair<double, int>> maxHeap;
    double maxSpanningTableWeight = 0.0;
    
    maxHeap.push({0, 0});
    
    while (!maxHeap.empty()){
        auto [weight, currentNode] = maxHeap.top();
        maxHeap.pop();
        
        if (!visited[currentNode]){
            visited[currentNode] = true;
            
            maxSpanningTableWeight += weight;
            
            for (int neighbor = 0; neighbor < n; ++neighbor){
                double edgeWeight = adjacencyMatrix[currentNode][neighbor];
                if (edgeWeight != -1 && !visited[neighbor]) {
                    maxHeap.push({edgeWeight, neighbor});
                }
            }
        }
    }
    return maxSpanningTableWeight;
}
