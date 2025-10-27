//Program to determine the number of isolation days
//after being exposed to or testing positive for covid

//Function that calculates the difference between two dates
//Benjamin McDonnough

#include "calcDays.h"
#include "Date.h"

int calcDays(Date dateOne, Date dateTwo){
    int numDays;

    //Array that holds the number of days for each month
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //Code to calculate numDays

    //Code to get the date exposed that the user inputted
    int date1Year = dateOne.getYear();
    int date1Month = dateOne.getMonth();
    int date1Day = dateOne.getDay();

    //Code to get the current day that the user inputted
    int date2Year = dateTwo.getYear();
    int date2Month = dateTwo.getMonth();
    int date2Day = dateTwo.getDay();

    //Initial date ot compare dates to.
    int dateDayStart = 1;
    int dateMonthStart = 1;
    int dateYearStart = 2021;

    int daysDiff1 = (date1Year - dateYearStart) * 365 + (date1Day - dateDayStart);
    int daysDiff2 = (date2Year - dateYearStart) * 365 + (date2Day - dateDayStart);

    for (int i = 0; i < date1Month; i++){
        daysDiff1 += (monthDays[i] - dateMonthStart);
    }

    for (int i = 0; i < date2Month; i++){
        daysDiff2 += (monthDays[i] - dateMonthStart);
    }

    numDays = daysDiff2 - daysDiff1;

    return numDays;
}