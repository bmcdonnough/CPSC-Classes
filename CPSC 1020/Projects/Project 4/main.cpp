#include "BookRecommender.h"

int main(int argc, char* argv[]){
    BookRecommender recommender(argv[1]);
    
    std::string option;

    do
    {
        std::cin >> option;

        if(option == "recommend"){
            std::string name;
            std::cin >> name;

            recommender.printRecommend(name);
        }
        else if(option == "averages"){
            recommender.printAverages();
        }
    } while (option != "quit");
    
}