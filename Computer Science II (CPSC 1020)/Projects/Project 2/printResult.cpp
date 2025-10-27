#include "printResult.h"

std::string printResult(int questions, int correct, int wrong){
    std::stringstream s;

    //Create the string using stringstream
    s << "Number of questions: " << questions << std::endl;
    s << "Number correct answers: " << correct << std::endl;
    s << "Number wrong answers: " << wrong << std::endl;
    s << "Final score: " <<  Quiz::getScore() << std::endl;

    return s.str();
}