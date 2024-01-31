#include "stats.h"

Stats::Stats(std::string file){
    std::ifstream inFile(file);

    while (!inFile.eof())
    {
        std::string num;
        getline(inFile, num);

        if(num[num.length()-1] == '\r'){
            num = num.erase(num.length() - 1);
        }
        

        nums.push_back(std::stoi(num));
    }
}


int Stats::countEven(){
    int counter = 0;
    for(auto iter : nums){
        if(iter % 2 == 0){
            counter++;
        }
    }
    return counter;
}

int Stats::countOdd(){
    int counter = 0;
    for(auto iter : nums){
        if(iter % 2 != 0){
            counter++;
        }
    }

    return counter;
}

int Stats::countFib(){
    int counter = 0;
    fibNums[0] = 0;
    fibNums[1] = 1;

    for(int i = 2; i < 50; i++){
        fibNums[i] = fibNums[i - 1] + fibNums[i - 2];
    }

    for(auto iter : nums){
        for(auto it : fibNums){
            if((unsigned long long) iter == it){
                counter++;
            }
        }
    }
    counter++;

    return counter;
}

float Stats::avgAll(){
    float avg = 0.0;

    for(auto iter : nums){
        avg += (float) iter;
    }

    if(count() > 0){
        avg /= count();
        return avg;
    }
    else
        return 0.0;
}

float Stats::avgEven(){
    float avg = 0.0;
    int counter = 0;

    for(auto iter : nums){
        if(iter % 2 == 0){
            avg += (float) iter;
            //std::cout << iter << std::endl;
        }
    }

    if(countEven() > 0){
        avg /= countEven();
    }
    else
        avg = 0.0;

    return (float) avg;
}

float Stats::avgOdd(){
    float avg = 0.0;
    int counter = 0;

    for(auto iter : nums){
        if(iter % 2 != 0){
            avg += (float) iter;
            counter++;
        }
    }

    if(counter > 0){
        avg /= counter;
    }
    else
        avg = 0.0;

    return avg;
}

float Stats::avgFib(){
    fibNums[0] = 0;
    fibNums[1] = 1;

    for(int i = 2; i < 50; i++){
        fibNums[i] = fibNums[i - 1] + fibNums[i - 2];
    }
    
    float avg = 0.0;
    int counter = 0;

    for(auto iter : nums){
        for(auto it : fibNums){
            if((unsigned long long) iter == it){
                avg += iter;
                counter++;
            }
        }
    }
    counter++;

    if(counter > 0){
        avg /= static_cast<float>(counter);
        return avg;
    }
    else{
        return 0.0;
    }
}