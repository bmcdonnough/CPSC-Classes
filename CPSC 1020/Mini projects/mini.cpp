#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>

int main(int n, char* argv[]){
    //Read in the input file and make sure that it can open.
    std::ifstream inFile("cities.txt");
    if(!inFile.is_open()){
        std::cout << "File failed to open." << std::endl;
        return 0;
    }

    //Create the variables to store all of the states/cities into a vector full of pairs
    std::string state, city, line;
    std::vector<std::pair<std::string, std::string>> places;

    //Get all of the state/city pairs fromt the input file
    while (std::getline(inFile, line)){
        std::stringstream ss(line);
        std::getline(ss, state, ',');
        std::getline(ss, city, ',');
        places.push_back(std::make_pair(state, city));
    }

    //Create a vector that will hold the number of times a state is repeated 
    //in the input file.
    //Also, create a counter variable to count the number of repeats
    std::vector<int> numCities;
    int counter = 0;

    //Loop through the amount of command line arguments and then through the state/city pairs
    for(int i = 1; i < n; i++){
        //Reset the counter to zero for each command line argument
        counter = 0;
        for(auto iter : places){
            if(argv[i] == iter.first){
                counter++;
            }
        }
        //Add the counter variable to the numCities vector
        numCities.push_back(counter);
    }

    //Loop through the numStates vector and print the number of cities in that state
    for (int i = 0; i < numCities.size(); i++){
        std::cout << numCities[i] << std::endl;
    }
    
    return 0;
}