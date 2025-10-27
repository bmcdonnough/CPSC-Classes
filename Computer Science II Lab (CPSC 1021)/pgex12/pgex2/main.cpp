#include "stats.h"


int main(int argc, char* argv[]){
    Stats stat (argv[1]);

    std::cout << stat.avgAll() << std::endl;
    std::cout << std::endl;
    std::cout << stat.avgEven() << std::endl;
    std::cout << stat.countOdd() << std::endl;
    std::cout << stat.avgOdd() << std::endl;

    std::cout << stat.countFib() << std::endl;

}