#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

bool isOdd(int n);
int len3nplus1(int value);
int sumSeq3nPlus1(int value);
int longestSequence(int max);

int main(){
    cout << longestSequence(5) << endl;

    return 0;
}

bool isOdd(int value){
    bool odd = false;

    if (value % 2 == 0){
        odd = false;
    }
    else{
        odd = true;
    }

    return odd;

}

int len3nplus1(int value){
    int counter = 1;

    while (value != 1)
    {
        if (!isOdd(value))
        {
            value /= 2;
            counter++;

        }
        else{
            value = value * 3 + 1;
            counter++;

        }
        
    }
    return counter;
}

int sumSeq3nPlus1(int value){
    int sum = 1;

    while (value != 1)
    {
        sum += value;
        if (!isOdd(value))
        {
            value /= 2;
        }
        else{
            value = (3 * value) + 1;
        }
        
    }
    return sum;
}


int longestSequence(int max)
{
    int counters[max];
    int counter = 1;
    int biggest = 0;
    int value = 0;
    int which;

    for(int i = 0; i < max; i++){
        value = i + 1;
        counter = 1;
        while (value != 1)
        {
            if (!isOdd(value))
            {
                value /= 2;
                counter++;
            }
            else{
                value = value * 3 + 1;
                counter++;
            }
            
        }
        counters[i] = counter;
    }

    for(int j = 0; j < max; j++){
        if(counters[j] > biggest){
            biggest = counters[j];
        }
    }

    for(int j = 0; j < max; j++){
        if(biggest == counters[j]){
            which = j + 1;
        }
    }
    return which;
}