//Program that calculates amount of isolation time needed
//for people exposed to or tested positive with covid
//Benjamin McDonnough

#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
    Date();
    Date(int, int, int);
    bool setDay(int);
    bool setMonth(int);
    bool setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    string showDate();
};



#endif