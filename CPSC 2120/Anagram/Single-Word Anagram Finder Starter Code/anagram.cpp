/*
 * Name: Benjamin McDonnough
 * Date Submitted: 10/14/23
 * Assignment Name: Single-word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

/*int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}*/

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    unordered_map <string, vector<string>> anagramUMap;

    //Goes through and adds all of the words from wordlist to the unordered_map
    for(int i = 0; i < wordlist.size(); ++i){
        string tempWord = wordlist[i];
        sort(wordlist[i].begin(), wordlist[i].end());
        string key = wordlist[i];
        anagramUMap[key].push_back(tempWord);
    }

    //Create a temp string to be able to "count" the number of times
    //each letter is used in the word
    string tempWord = word;
    sort(tempWord.begin(), tempWord.end());
    vector<string> anagrams;

    //Looks for the word passed into the function in the unordered_map
    //and then prints out the vector that is stored at that key.
    for(auto key : anagramUMap){
        if (tempWord == key.first){
            anagrams = key.second;
        }
    }

    return anagrams;
}