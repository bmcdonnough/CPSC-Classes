#include "accum.h"

int main()
{
 
    std:: vector<int> container(4);
    std:: vector<std::string> strings(4, "");
    
    //Enter in the different numbers
    std:: cout << "Enter four numbers: ";
    std::cin >> container[0] >> container[1] >> container[2] >> container[3];

    //Create an Accumulator object withe the numbers vector, combine all of 
    //the numbers using the accum function in the Accumulator class, and
    //print out the stream of numbers
    Accumulator<int> numbers;
    auto sum = numbers.accum(container);
    std::cout << "The sum of the numbers is " << sum << std::endl;

    //Enter in the different numbers    
    std::cout << "Enter four strings: ";
    std::cin >> strings[0] >> strings[1] >> strings[2] >> strings[3];

    //Create an Accumulator object withe the strings vector, combine all of 
    //the strings using the accum function in the Accumulator class, and
    //print out the stream of strings   
    Accumulator<std::string> words;
    std::string sum2 = words.accum(strings);
    std::cout << "The sum of the strings is " << sum2 << std::endl;
return 0;
}