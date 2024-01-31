#include "BookRecommender.h"

/* This is a sorter function to be used to sort the vectors later 
*  in the program. 
*
*  While sorting, check if the first rating is equal to the second rating.
*  If they are equal, then compare the first string to the second string
*  to put them in alphabetical order.
*
*  If the first and second rating are not equal, then sort them highest
*  to lowest.*/
bool sorter(const std::pair<double, std::string> &a, 
            const std::pair<double, std::string> &b)
{

    if(a.first == b.first)
        return a.second.compare(b.second) < 0;
    else
        return a.first > b.first;
}

BookRecommender::BookRecommender(std::string filename){

    //Open the file with all of the information needed
    std::ifstream inFile(filename);
    if(!inFile.is_open()){
        std::cout << "File failed to open." << std::endl;
    }

    std::string bookTitle, userName, ratingStr;
    std::set<std::string> bookNames;
    std::set<std::string> userNames;
    

    /* Loop through the file to get the userNames and the bookTitles
    *  and put them into sets to ensure that there are no copies */
    while(!inFile.eof()){
        std::getline(inFile, userName);
        std::getline(inFile, bookTitle);
        std::getline(inFile, ratingStr);

        //Make sure to remove the '\r' character from each line
        userName = removeNewLine(userName);
        bookTitle = removeNewLine(bookTitle);
        ratingStr = removeNewLine(ratingStr);


        if(userName.size() > 1){
            userNames.insert(userName);
            bookNames.insert(bookTitle);
        }
    }
    
    //Close and reopen the file so that it can 
    //loop back through from the beginning
    inFile.close();
    inFile.clear();
    inFile.open(filename);

    //Take the sets of bookNames and userNames and 
    //turn them into vectors
    for(auto it : bookNames){
        books.push_back(it);
    }

    for(auto it : userNames){
        users.push_back(it);
    }

    /* For each user, create a vector to hold their ratings. 
    *  Then, loop through the file and, check if the userName 
    *  in the file is the same as the user from the users vector.
    *  If they are the same, then loop through the books vector and 
    *  check if the bookTitle from the inFile and the book in the
    *  book vector are the same. If they are, then add that rating
    *  to the ratings vector at the same position as the book.
    *  
    *  After checking all of that, add the user and the ratings 
    *  vectors to the ratedBooks map and move on to the next user. */
    for(int i = 0; i < users.size(); i++){
        std::vector<double> ratings(books.size(), 0);
        while(!inFile.eof()){
            std::getline(inFile, userName);
            std::getline(inFile, bookTitle);
            std::getline(inFile, ratingStr);

            userName = removeNewLine(userName);
            bookTitle = removeNewLine(bookTitle);
            ratingStr = removeNewLine(ratingStr);

            if(users[i] == userName){
                for(int j = 0; j < books.size(); j++){
                    if(books[j] == bookTitle){
                        ratings[j] = std::stod(ratingStr);
                    }
                }
            }
        }

        ratedBooks.insert({users[i], ratings});

        //Close and reopen the file so that it can 
        //loop back through from the beginning
        inFile.close();
        inFile.clear();
        inFile.open(filename);
    }


    /* Loop through all of the books in the books vector. 
    *  For each book, loop through the ratedBooks map. 
    *  Add the value from the ratings vector in the map
    *  that is at the same position as the book in the books vector.
    *  
    *  If that rating is not zero, increment the counter variable 
    *  by 1. After looping through the rated books map, check if the 
    *  counter variable to make sure that there were some ratings that are
    *  not zero. If counter is greater than 0, divide the sum of 
    *  the ratings (avg) by the number of ratigns (counter).
    * 
    *  Then, insert the avg of the ratings and the name of the book
    *  to the averages map.
    *  Do this for all of the books in the books vector. */
    for (int i = 0; i < books.size(); i++){
        int counter = 0;
        double avg = 0.0;

        for(auto iter : ratedBooks){
            //iter.second is the rating of the book in the rated books map 
            avg += iter.second[i];

            if(iter.second[i] != 0){
                counter++;
            }
        }

        if(counter > 0){
            avg /= counter;
        }

        averages.insert({books[i], avg});
    }    
}


/* Finds the similarities between the user given as the argument and 
*  ever other user. These values along with the user the argument user
*  is being compared against are added to a list. 
*
*  The list is sorted, 
*  the user given as the argument is removed, along with everyone but 
*  the three users with the highest similarity to the user given in the
*  argument.
*
*  The average ratings of these three users and the name of the 
*  respective book are then created for ever book
*  and added to a list. 
*
*  The list is then sorted through and the names of the books and the values
*  of the average ratings for the respective books are then printed */
void BookRecommender::printRecommend(std::string userName){
    bool nameInFile;

    for(auto iter : users){
        if(userName == iter)
            nameInFile = true;
    }

    if(nameInFile){
        USER_AVG_LIST userSims;
        BOOK_AVG_LIST topThreeBooks;
        

        for(auto it : users){
            userSims.push_back(make_pair(getSimilarity(userName, it), it));
        }

        sort(userSims.begin(), userSims.end());

        userSims.erase(userSims.begin() + userSims.size() - 1);

        std::vector<double> topThreeRate(books.size(), 0);

        for(int i = 0; i < topThreeRate.size(); i++){
            double addTopThree = 0.0;
            int counter = 0;
            for(auto iter : userSims){
                addTopThree += getUserBookRating(iter.second, books[i]);
                
                if(getUserBookRating(iter.second, books[i]) != 0){
                    counter++;
                }
            }

            if(counter != 0){
                addTopThree /= counter;
            }
 
            topThreeBooks.push_back(make_pair(addTopThree, books[i]));
        }

        sort(topThreeBooks.begin(), topThreeBooks.end(), sorter);
        
        for(auto& iter : topThreeBooks){
            if(iter.first > 0){
                std::cout << iter.second << " ";
                std::cout << std::fixed << std::setprecision(2) << iter.first;
                std::cout << std::endl;
            }
        }
    }
    else{
        printAverages();
    }


}

/* Print out the averages for all of the books by looping through
*  the averages map and storing the value into a vector of pairs.
*  Then sort the vector and print out the averages and the book
*  title */
void BookRecommender::printAverages(){
    BOOK_AVG_LIST bookAvgList;


    for(auto it : averages){
        bookAvgList.push_back(make_pair(it.second, it.first));
    }

    std::sort(bookAvgList.begin(), bookAvgList.end(), sorter);

    
    for(auto it : bookAvgList){
        std::cout << it.second << " ";
        std::cout << std::fixed << std::setprecision(2) << getAverage(it.second);
        std::cout << std::endl;
    }
}

//Loop through the averages map to find the key that is
//the same as the book title argument given when the function is called.
//Returns the average rating for the book argument
double BookRecommender::getAverage(std::string bookTitle){
    double average = 0.0;

    for(auto iter : averages){
        if(iter.first == bookTitle){
            average = iter.second;
        }
    }

    return average;
}

/* Get the similarity between two different users by multiplying the two 
*  users ratings for each book and adding up the results for each 
*  multiplication (dot product). 
*
*  This function returns the final value of the dot product for the 
*  two users.*/
double BookRecommender::getSimilarity(std::string userName1, 
                                      std::string userName2)
{
    double similarityNum = 0.0;
    double multRatings = 0.0;

    for(auto iter : books){
        multRatings = getUserBookRating(userName1, iter) *
                      getUserBookRating(userName2, iter);

        similarityNum += multRatings;
    }

    return similarityNum;
}

//Returns the number of books by looking at the size of the books vector
int BookRecommender::getBookCount(){
    return books.size();
}

//Returns the number of users by looking at the size of the users vector
int BookRecommender::getUserCount(){
    return users.size();
}

/* Looks through all of the ratedBooks map and checks if the key
*  is the same as the userName argument passed. If they are the same, 
*  loop through all of the books. If the book title argument is the same
*  as the title of the book at postion i, then return the value of the rating
*  at the same position in the ratedBooks map.

*  Return 0.0 if there is no book with the same title.*/
double BookRecommender::getUserBookRating(std::string userName, 
                                          std::string bookTitle) 
{
    double rating = 0.0;
    auto userRating = ratedBooks.find(userName);

    for(int i = 0; i < books.size(); i++){
        if (bookTitle == books.at(i))
        {
            rating = userRating->second[i];
        }
        
    }

    return rating;
}

//Funtion to remove the '\r' from the end of a string.
//Then return the string without the '\r'
std::string BookRecommender::removeNewLine(std::string line){
    if(line[line.length() - 1] == '\r'){
        line.erase(line.length() - 1);
    }

    return line;
}

