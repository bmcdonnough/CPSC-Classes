//File that contains the class declaration for the class Quiz

#include <string>

#ifndef QUIZ_H
#define QUIZ_H

class Quiz{
    private:
        std::string question;
        std::string answer;
        static int score;

    public:
        Quiz() : question(""), answer("") {};
        Quiz(std::string q, std::string a);
        std::string getQuestion();
        std::string getAnswer();
        static int getScore();
        static void updateScore(int val);

        friend std::string printResult(int questions, int correct, int wrong);
};
#endif