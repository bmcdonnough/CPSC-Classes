#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>

#ifndef STATS_H
#define STATS_H

class Stats
{
    private:
        std::vector<long long int> nums;
        std::string filename;
        unsigned long long int fibNums[50];
    public:
        Stats() : nums(100), filename("") {};
        Stats(std::string file);
        int capacity() { return nums.capacity(); };
        int count() { return nums.size(); };
        int countEven();
        int countOdd();
        int countFib();
        float avgAll();
        float avgEven();
        float avgOdd();
        float avgFib();

};
#endif
