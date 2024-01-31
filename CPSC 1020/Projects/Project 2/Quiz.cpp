//Adds all of the logic to the funcitons in the quiz class
#include "Quiz.h"

int Quiz::score = 0;

Quiz::Quiz(std::string q, std::string a) : question(q), answer(a) {}

std::string Quiz::getQuestion(){
    return question;
}

std::string Quiz::getAnswer(){
    return answer;
}

int Quiz::getScore(){
    return score;
}

void Quiz::updateScore(int val){
    //Checks to make sure that the score will not be less than zero, then 
    //
    if(!((score + val) < 0)){
        score += val;
    }
}