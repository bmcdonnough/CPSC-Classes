/*
 * Name: Benjamin McDonnough
 * Date Submitted: 10/09/2023
 * Lab Section: 006
 * Assignment Name: Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 /*int main(int argc, char* argv[])
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }*/
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 void loadStringset(Stringset& words, string filename)
 {
    ifstream infile(filename);
    string word;
    while(getline(infile, word)){
        words.insert(word);
    }     
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
    vector<string> alternatives;

    //Loop through each letter in the word
    for(int i = 0; i < word.length(); i++){
        //Loop through each letter in the alphebet
        for(int j = 0; j <= 25; j++){
            //Change the character by 1
            char c = static_cast<char>(j+97);
            //Make sure that we are not repeating the word passed to the method
            if(word[i] != c){
                //Create a temp string to change the letter
                string temp = word;
                temp[i] = c;
                //If temp is in the stringset, push it to the alternatives vector
                if(words.find(temp)){
                    alternatives.push_back(temp);
                }
            }
        }
    }

    return alternatives;
 }