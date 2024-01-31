#include <string>
#include <vector>
#include <utility>
#include <map>
#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <iomanip>

#ifndef BOOKRECOMMENDER_H
#define BOOKRECOMMENDER_H

#define BOOK_LIST std::vector<std::string>
#define USER_LIST std::vector<std::string>
#define USER_RATINGS_MAP std::map<std::string, std::vector<double>>
#define BOOK_AVG_MAP std::map<std::string, double>
#define BOOK_AVG_LIST std::vector<std::pair<double, std::string>>
#define USER_AVG_LIST std::vector<std::pair<double, std::string>>

class BookRecommender{
    private:
        BOOK_LIST books;
        USER_LIST users;
        USER_RATINGS_MAP ratedBooks;
        BOOK_AVG_MAP averages;

    public:
        BookRecommender() = default;
        BookRecommender(std::string filename);
        void printRecommend(std::string userName);
        void printAverages();
        double getAverage(std::string bookTitle);
        double getSimilarity(std::string userName1, std::string userName2);
        int getBookCount();
        int getUserCount();
        double getUserBookRating(std::string userName, std::string bookTitle);
        std::string removeNewLine(std::string line);
};
#endif