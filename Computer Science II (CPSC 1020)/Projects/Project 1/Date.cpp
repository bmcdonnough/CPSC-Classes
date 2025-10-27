//Program to determine the number of isolation days
//after being exposed to or testing positive for covid

//Defines the class Date with its variables and functions
//Benjamin McDonnough

#include "Date.h"

Date::Date(){
    day = 1;
    month = 1;
    year = 2021;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    if(setMonth(m) && setDay(d) && setYear(y)){
        month = m;
        day = d;
        year = y;
    }
    else if(!setMonth(m) || !setDay(d) || !setYear(y)){
        month = 1;
        day = 1;
        year = 2021;
    }
}


bool Date::setDay(int dayTest){
            
    bool isDay = true;
            
    //Checks what month it is to determine correct number of days
    if(month == 1 || month == 3 || month == 5 || month == 7 ||
       month == 8 || month == 10 || month == 12){
        //Checks to see if user input is valid
        if (dayTest >= 1 && dayTest <= 31){
            day = dayTest;
        }
        else{
            isDay = false;
        }
    }
    else if(month == 4 || month == 6 ||
            month == 9 || month == 11){
                //Checks to see if user input is valid
                if(dayTest >= 1 && dayTest <= 30){
                    day = dayTest;
                }
                else{
                    isDay = false;
                }
            }
    else if(month == 2){
        if(dayTest >= 1 && dayTest <= 28){
            day = dayTest;
        }
        else{
            isDay = false;
        }
    }
    else{
        isDay = false;
    }
    return isDay;
}
        
bool Date::setMonth(int monthTest){
    bool isMonth = true;
            
    //Checks to see if user input is valid
    if(monthTest >= 1 && monthTest <= 12){
        month = monthTest;
    }
    else{
        isMonth = false;
    }
    return isMonth;

}

bool Date::setYear(int yearTest){
    
    bool isYear = true;

    //Checks to see if user input is valid
    if(yearTest == 2021 || yearTest == 2022){
        year = yearTest;
    }
    else{
        isYear = false;
    }
    return isYear;
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}
int Date::getYear(){
    return year;
}

string Date::showDate(){
    string date, d, m, y;
    
    d = to_string(day);
    m = to_string(month);
    y = to_string(year);

    while (d.length() < 2)
    {
        d = "0" + d;
    }
    while (m.length() < 2)
    {
        m = "0" + m;
    }
    while (y.length() < 4)
    {
        y = "0" + y;
    }
    
    date = m + "/" + d + "/" + y;
    return date;
}


