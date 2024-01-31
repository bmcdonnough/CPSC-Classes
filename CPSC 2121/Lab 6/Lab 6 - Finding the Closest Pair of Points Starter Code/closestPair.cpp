/*
 * Name: Benjamin McDonnough
 * Date Submitted: 
 * Lab Section: 006
 * Assignment Name: Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

double findLowDistance(point, point);
double lowDistSearch(vector<vector<vector<point>>>, point, point, point, double, double);

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/

double closestPair(string filename){
  ifstream inFile;
  inFile.open(filename);

  double num_points;
  //Get the number of points from the file
  inFile >> num_points;
  
  //Calculate b by finding the floor of the square root of num_points
  double b = floor(pow(num_points, .5));
  double interval;
  

  interval = b / num_points;
  //Get the input from the file and put it into the spatial hash table
  vector<vector<vector<point>>> table(b, vector<vector<point>>(b));
  //vector<point> points;

  for(int i = 0; i < num_points; i++){
    point tempPoint;
    inFile >> tempPoint.x >> tempPoint.y;

    int xpos, ypos;

    xpos = floor(tempPoint.x * b);
    ypos = floor(tempPoint.y * b);


    table[xpos][ypos].push_back(tempPoint);
  }

  point current_cell;
  

  point startCell;
  double smallDistance = 0;

  for(int i = 0; i < b; ++i){
    for(int j = 0; j < b; ++j){
      for(int k = 0; k < table[i][j].size(); ++k){
        if(!(i + 1 == b)){
          current_cell.x = i;
          current_cell.y = j;
          startCell = current_cell;
          point current_point = table[current_cell.x][current_cell.y][k];

          if(smallDistance > lowDistSearch(table, current_cell, current_point, startCell, smallDistance, b) || smallDistance == 0)
            smallDistance = lowDistSearch(table, current_cell, current_point, startCell, smallDistance, b); 
        }
        else{
          for(int t = 0; t < table[i][j].size(); ++t){
            if(smallDistance > findLowDistance(table[i][j][k], table[i][j][t]) && t != k){
              smallDistance = findLowDistance(table[i][j][k], table[i][j][t]);
            }
          }
        }
      }
    }
  }
  return smallDistance;
}

double lowDistSearch(vector<vector<vector<point>>> table, point current_cell, point current_point, point startCell, double smallDist, double tableSide){
  if(current_cell.x - startCell.x > 1){
    current_point.x = -1;
    current_point.y = -1; 
    return smallDist;
  }
  else{
    for(int i = 0; i < table[current_cell.x][current_cell.y].size(); ++i){
      if(table[current_cell.x][current_cell.y][i].x != -1){
        point tempPoint = table[current_cell.x][current_cell.y][i];
        if(smallDist > findLowDistance(current_point, tempPoint) || smallDist == 0){
          smallDist = findLowDistance(current_point, tempPoint);
        }
      }
    }

    if(current_cell.y + 1 == tableSide){
      current_cell.x += 1;
      current_cell.y = 0;
    }
    else{
      current_cell.y += 1;
    }
    return lowDistSearch(table, current_cell, current_point, startCell, smallDist, tableSide);
  }
}                   

double findLowDistance(point one, point two){
  double xDist = pow((two.x - one.x), 2);
  double yDist = pow((two.y - one.y), 2);
  double dist = sqrt(xDist + yDist);

  return dist;
}



/*int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}*/