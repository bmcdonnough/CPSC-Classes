/*
 * Name: Benjamin McDonnough
 * Date Submitted: 9/21/23
 * Lab Section: 006
 * Assignment Name: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below

//Constructor for the Grouping class
Grouping::Grouping(string fileName){
    ifstream inFile (fileName);
    int counter = 0;
    char c;

    //Read in all of the values in the input file and
    //change the value of '.' to 0 and anything else to 1
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            inFile.get(c);
            if(c == '.'){
                grid[i][j] = 0;
            }
            else{
                grid[i][j] = 1;
            }
        }
        //Consume (I like devour better) the \n character
        inFile.get(c);
    }

    //Find the groups by looping through the 2d vector
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            vector<GridSquare> temp;
            findGroup(i, j, temp, counter);
            if(!temp.empty()){
                groups.push_back(temp);
            }
        }
    }
}

//Used to check for repeat values in groups. Base case for findGroup
bool Grouping::valFinder(GridSquare key){
    vector<vector<GridSquare> >::iterator row;
    vector<GridSquare>::iterator col;

    //Loop through the 2d vector and see if the GridSquare is already
    //in the 2d vector.
    for(row = groups.begin(); row != groups.end(); ++row){
        for(col = row->begin(); col != row->end(); ++col){
            if(*col == key){
                return true;
            }
        }
    }
    return false;
}

//Use recurssion to find pairs
void Grouping::findGroup(int r, int c, vector<GridSquare> &currentGroup, int recCtr){
    //Base Case: Call valFinder and check if the position in the grid is = 0
    if(!valFinder(GridSquare(r, c)) && grid[r][c] != 0){
        currentGroup.push_back(GridSquare(r, c));

        //Set the current grid value = 0 so that it knows if 
        //it has already been there done that
        grid[r][c] = 0;

        //Loop through and check each direction
        if(recCtr == 0){
            recCtr++;
            if(c != 0){
                findGroup(r, c - 1, currentGroup, 0);
            }
        }

        if(recCtr == 1){
            recCtr++;
            if(c != 9){
                findGroup(r, c + 1, currentGroup, 0);
            } 
        }

        if(recCtr == 2){
            recCtr++;
            if(r != 0){
                findGroup(r - 1, c, currentGroup, 0);
            }
        }

        if(recCtr == 3){
            if(r != 9){
                findGroup(r + 1, c, currentGroup, 0);
            }
        } 
    }
    else{
        return;
    }
    recCtr = 0;
}


//Simple main function to test Grouping
//Be sure to comment out main() before submitting
/*int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}*/

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid(),groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare> > Grouping::getGroups() //Needed in unit tests
{
    return groups;
}