#include <string>
#include <vector>
#include <iostream>

#ifndef ACCUM_H
#define ACCUM_H

//Take two strings and put them together with a comma in the middle.
//Returns the combination of the words
std::string &operator+(std::string &word, std::string &word2)
    {
        if(word == "") 
            return word2;

        if(word2 == "") 
            return word;
        word = word + ", ";
        word += word2;
        // word[0] = '\0';
        return word;
    }


//Create a template class to combine the ints or strings
template <class T>
class Accumulator{
    private:
        std::vector<T> vect;
    public:
        T accum(std::vector<T> v)
        {
            vect = v;
            T sum = T();

            for(auto &value: vect)
            {
            sum = sum + value;      //Is number
            }
            return sum;
        }
};
#endif