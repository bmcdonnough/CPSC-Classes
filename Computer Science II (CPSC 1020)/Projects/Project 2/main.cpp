#include "Quiz.h"
#include "printResult.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

bool readData(std::ifstream &someFile, std::string &q, std::string &a);

int main(int argc, char *argv[]){
    std::ifstream inputFile;
    std::string question;
    std::string answer;
    std::string userAnswer;
    int correct = 0;
    int wrong = 0;

    int counter = 0; 

    std::vector<Quiz> quizVector;

    std::srand(unsigned(std::time(0)));


    //Open the database txt file
    inputFile.open(argv[1]);

    //Check to make sure that the file opened
    if(inputFile.fail()){
        std::cout << "Error opening file";
    }
    else{
        //Sees how many lines are in the input file
        while(readData(inputFile, question, answer)){
            quizVector.push_back(Quiz(question, answer));
            counter++;
        }

        std::random_shuffle(quizVector.begin(), quizVector.end());

        //Loop through all of the questions
        for (int i = 0; i < counter; i++){
            std::cout << quizVector[i].getQuestion() << std::endl;
            std::cout << "Type in your answer: ";

            getline(std::cin, userAnswer);

            answer = quizVector[i].getAnswer();
            answer.erase(answer.length()-1);

            if(userAnswer == answer){
                Quiz::updateScore(1);
                correct++;
                std::cout << "Correct!" << std::endl;
                std::cout << "Current score: " << Quiz::getScore() << std::endl;
                std::cout << std::endl;
            }
            else{
                Quiz::updateScore(-1);
                wrong++;
                std::cout << "Wrong! Correct answer: " << quizVector[i].getAnswer() << std::endl;
                std::cout << "Current score: " << Quiz::getScore() << std::endl;
                std::cout << std::endl;
            }
        }
        std::cout << printResult(counter, correct, wrong);
    }

    return 0;
}

bool readData(std::ifstream &someFile, std::string &q, std::string &a){
    bool foundData = false;;
 
    if(!someFile.eof()){
        getline(someFile, q);
        getline(someFile, a);

        
        
        int pos = a.find(" ");

        a = a.substr(pos + 1);

        if(q.length() > 1){

            foundData = true;

        }
    }

    return foundData;
}
