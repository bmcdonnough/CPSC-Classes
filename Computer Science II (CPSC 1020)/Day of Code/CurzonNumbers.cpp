#include <iostream>
#include <cmath>
using namespace std;

bool isCurzon(const int &);
int main(int argc, char *argv[]){
    long int number = stoi(argv[1]);
    if(isCurzon(number)){
        cout << number << " is a Curzon number" << endl;
    }
    else{
        cout << number << " is not a Curzon number" << endl;
    }
}

bool isCurzon(const int &num){
    bool curzon;
    long int numerator = (pow(2, num) + 1);
    long int denominator = ((2 * num) + 1);
    
    if((numerator % denominator) == 0){
        curzon = true;
    } 
    else {
        curzon = false;
    }
    return curzon;
}