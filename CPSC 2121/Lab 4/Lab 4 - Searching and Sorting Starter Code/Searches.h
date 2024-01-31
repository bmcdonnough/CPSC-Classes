/*
 * Name: Benjamin McDonnough
 * Date Submitted: 09/26/23
 * Lab Section: 006
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>

//Goes through each value of the data vector and checks if hte value
//at that position is equal to the target value.
template <class T>
int linearSearch(std::vector<T> data, T target){
    for(int i = 0; i < data.size(); i++){
        if (data[i] == target){
            return i;
        }
    }
    return -1;
}

/*
* Continuously goes through the data vector by altering
* three different int iterators and checking if the midpoint
* between the lowIndex and highIndex is equal to the target 
* passed to the function.
*/
template <class T>
int binarySearch(std::vector<T> data, T target){
    int lowIndex = 0, highIndex = data.size();

    while(lowIndex <= highIndex){
        int midIndex = (highIndex + lowIndex) / 2;

        if(data[midIndex] == target){
            return midIndex;
        }
        else if(data[midIndex] < target){
            lowIndex = midIndex + 1;
        }
        else{
            highIndex = midIndex - 1;
        }
    }
    return -1;
}
