/*
 * Name: Benjamin McDonnough
 * Date Submitted: 09/26/23
 * Lab Section: 006
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>
#include <cstdlib>
#include <time.h>

//Takes the two halves, sorts them, and puts them into the sorted vector
template <class T>
void merge(std::vector<T> halfL, std::vector<T> halfR, std::vector<T> &sorted){
    int i = 0, j = 0;

    //Go through and sort through the halves
    while(i < halfL.size() && j < halfR.size()){
        if (halfL[i] <= halfR[j]){
            sorted.push_back(halfL[i]);
            i++;
        }
        else{
            sorted.push_back(halfR[j]);
            j++;
        }
    }

    //Catch any of the extra values if one half is larger than the other
    while(i < halfL.size()){
        sorted.push_back(halfL[i]);
        i++;
    }
    while (j < halfR.size())
    {
        sorted.push_back(halfR[j]);
        j++;
    }
}
template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    
    //Create the temp vectors and the sorted vector
    std::vector<T> halfL;
    std::vector<T> halfR;
    std::vector<T> sorted;

    //Check the base case
    if(lst.size() == 1){
        return lst;
    }
    else{
        //Find the midpoitn, fill the temp vectors, and recurse
        int mid = lst.size() / 2;

        for(int i = 0; i < mid; i++){
            halfL.push_back(lst[i]);
        }
        for(int j = mid; j < lst.size(); j++){
            halfR.push_back(lst[j]);
        }

        halfL = mergeSort(halfL);
        halfR = mergeSort(halfR);
        merge(halfL, halfR, sorted);
    }

    return sorted;
    
}

//Exchanges two values inside of a vector
template <class T>
void exchange(T &val1, T &val2){
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){

    //Base case returns lst if already sorted or empty
    if(lst.size() <= 1){
        return lst;
    }

    //Declare and initialize variables
    srand(time(0));
    int randIndex = rand() % lst.size();
    T pivotVal = lst[randIndex];
    int pivotIndex = 0;
    int recCtr = 0;

    //Switch the value at randIndex with the first val
    exchange(lst[0], lst[randIndex]);

    //Sort the values before and after the randIndex val
    for(int i = 1; i < lst.size(); i++){
        if(lst[i] < pivotVal){
            pivotIndex++;
            exchange(lst[i], lst[pivotIndex]);
        }
    }
    //Put the randIndex val back where it goes
    exchange(lst[0], lst[pivotIndex]);

    //Create some temp vectors for recursion
    std::vector<T> tempL, tempR;

    //Fill the temp vectors with their respective halves 
    for(int i = 0; i < pivotIndex; i++){
        tempL.push_back(lst[i]);
    }
    for(int j = pivotIndex + 1; j < lst.size(); j++){
        tempR.push_back(lst[j]);
    }
    
    //Recurse through the halves
    tempL = quickSort(tempL);
    tempR = quickSort(tempR);

    //Create a vector for the sorted values and pass all of the sorted values to it
    std::vector<T> sortedList;
    sortedList.insert(sortedList.end(), tempL.begin(), tempL.end());
    sortedList.push_back(pivotVal);
    sortedList.insert(sortedList.end(), tempR.begin(), tempR.end());
   
    return sortedList;
}

