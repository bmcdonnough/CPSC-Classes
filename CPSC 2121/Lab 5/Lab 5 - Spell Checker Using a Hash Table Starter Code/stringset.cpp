/*
 * Name: Benjamin McDonnough
 * Date Submitted: 10/09/2023
 * Lab Section: 006
 * Assignment Name: Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    //Make a hash and figure out the index
    hash<string> hash;
    int index = hash(word) % size;

    //If the word is not already in the hash table, then put it in the table
    //and increase the number of elements
    if(!find(word)){
        table[index].push_back(word);
        num_elems++;
    }
    
    if(num_elems == size){
        //Double the size of the table
        int tempSize = size * 2;
        vector<list<string>> temp(tempSize);
        list<string>::iterator lstPtr;

        //Take the values in table and put them into the temp list that is double the size
        for(int i = 0; i < size; i++){
            for(lstPtr = table[i].begin(); lstPtr != table[i].end(); lstPtr++){
                int tempIndex = hash(*lstPtr) % tempSize;
                temp[tempIndex].push_back(*lstPtr);
            }
        }
        //Set the size to be the tempSize and make the table equal to the temp list.
        size = tempSize;
        table = temp;
    }
}

bool Stringset::find(string word) const
{
    hash<string> hash;
    int index = hash(word) % size;
    list<string>::const_iterator indexPtr;

    //Loop through each linked list in table and see if the word passed to the method is in it
    for(indexPtr = table[index].begin(); indexPtr != table[index].end(); indexPtr++){
        if (*indexPtr == word){
            return true;
        }
    }
    return false;
}

void Stringset::remove(string word)
{
    hash<string> hash;
    int index = hash(word) % size;

    table[index].remove(word);
    num_elems--;
}