#include <iostream>
#include <string>
#include <cctype>
#include "Date.h"
#include "calcDays.h"
using namespace std;

int main(){
    char testResult;

    //varialbes for testing positve
    int dayP = 0;
    int monthP = 0;
    int yearP = 0;

    //variables for exposed
    int dayE = 0;
    int monthE = 0;
    int yearE = 0;

    char exposed;
    //varibles for second dosage
    int dayS = 0;
    int monthS = 0;
    int yearS = 0;

    char secondVac;

    bool fullVac = false;


    cout << "Test result (p or n):";
    cin >> testResult;

    if(testResult == 'p'){
        Date datePositive(1, 1, 2021);
        
        //Input validation for month
        cout << "What date did you test positive? (just month): ";
        cin >> monthP;

        datePositive.setMonth(monthP);
    
        //Input validation for day
        cout << "What date did you test positive? (just day): ";
        cin >> dayP;
        
        datePositive.setDay(dayP);

        //Input validation for year
        cout << "What date did you test positive? (just year): ";
        cin >> yearP;

        datePositive.setYear(yearP);

        cout << "Test result: positive" << endl;
        cout << "Date tested positive: " << datePositive.showDate() << endl;
        cout << "Length of isolation: 5 days";

    }
    else if(testResult == 'n'){
        cout << "Were you exposed?: ";
        cin >> exposed;

        if(tolower(exposed) == 'y'){
            Date dateExposed(1, 1, 2021);

            //Input validation for month
            cout << "What date were you exposed? (just month): ";
            cin >> monthE;

            dateExposed.setMonth(monthE);

            //Input validation for day
            cout << "What date were you exposed? (just day): ";
            cin >> dayE;
            
            dateExposed.setDay(dayE);

            //Input validation for year
            cout << "What date were you exposed? (just year): ";
            cin >> yearE;
    
            dateExposed.setYear(yearE);

            cout << "Second vaccination received?: ";
            cin >> secondVac;

            if(tolower(secondVac) == 'y'){
                Date dateSecondDose(1, 1, 2021);

                //Input validation for month
                cout << "What date did you get your second dose? (just month): ";
                cin >> monthS;

                dateSecondDose.setMonth(monthS);

                //Input validation for day

                cout << "What date did you get your second dose? (just day): ";
                cin >> dayS;
                
                dateSecondDose.setDay(dayS);
                
                //Input validation for year
                cout << "What date did you get your second dose? (just year): ";
                cin >> yearS;
                
                dateSecondDose.setYear(yearS);

                if(calcDays(dateExposed, dateSecondDose) >= 14){
                    fullVac = true;
                }
                else{
                    fullVac = false;
                }

                if(fullVac){
                cout << "Test result: negative" << endl;
                cout << "Exposed to positive case: Yes" << endl;
                cout << "Date exposed to positive case: " << dateExposed.showDate() << endl;
                cout << "Second vaccination dose recieved: Yes" << endl;
                cout << "Date second vaccination dose recieved: " << dateSecondDose.showDate() << endl;
                cout << "Vacctionation status at time of exposure: fully vaccinated" << endl;
                cout << "Length of isolation: 5 days";
                }
                else if(!fullVac){
                    cout << "Test result: negative" << endl;
                    cout << "Exposed to positive case: Yes" << endl;
                    cout << "Date exposed to positive case: " << dateExposed.showDate() << endl;
                    cout << "Second vaccination dose recieved: Yes" << endl;
                    cout << "Date second vaccination dose received: " << dateSecondDose.showDate() << endl;
                    cout << "Vacctionation status at time of exposure: not fully vaccinated" << endl;
                    cout << "Length of isolation: 10 days";
                }
            }
            else if(tolower(secondVac) == 'n'){
                cout << "Test result: negative" << endl;
                cout << "Exposed to positive case: Yes" << endl;
                cout << "Date exposed to positive case: " << dateExposed.showDate() << endl;
                cout << "Second vaccination dose recieved: No" << endl;
                cout << "Vacctionation status at time of exposure: not fully vaccinated" << endl;
                cout << "Length of isolation: 10 days";
            }
        }
        else{
            cout << "Test result: negative" << endl;
            cout << "Exposed to positive case: No" << endl;
            cout << "Length of isolation: 0 days";
        }
        
        
    }
    return 0;

}