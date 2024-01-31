// This program demonstrates an application
// of pure virtual functions.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Encryption {
protected:
   ifstream inFile;
   ofstream outFile;
public:
   Encryption(const string& inFileName, const string& outFileName);
  ~Encryption();
   // Pure virtual function
   virtual char transform(char ch) const = 0;
   // Do the actual work.
   virtual void encrypt() final;
   void display(const string& fn);
};

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(const string& inFileName, const string& outFileName) {
   inFile.open(inFileName);
   outFile.open(outFileName);
   if (!inFile) {
      cout << "The file " << inFileName
         << " cannot be opened.";
      exit(1);
   }
   if (!outFile) {
      cout << "The file " << outFileName
         << " cannot be opened.";
      exit(1);
   }
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption::~Encryption() {
   inFile.close();
   outFile.close();
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//*****************************************************
void Encryption::encrypt() {
   char ch;
   char transCh;
   while (inFile.get(ch)) {
      transCh = transform(ch);
      outFile.put(transCh);
   }
}

//****************************************************
// display contents of encrypted file
//****************************************************
void Encryption::display(const string& fn) {
    char ch;
    inFile.close();
    outFile.close();
    inFile.open(fn);
    inFile.get(ch);
    while (!inFile.fail()) {
         cout << ch;
         inFile.get(ch);
    }
}

// The subclass simply overides the virtual
// transformation function
class SimpleEncryption : public Encryption {
public:
   char transform(char ch) const {
      return ch + 1;
   }
   SimpleEncryption(const string& inFileName, const string& outFileName)
      : Encryption(inFileName, outFileName) {}
};

int main() {
   string inFileName, outFileName;
   cout << "Enter name of file to encrypt: ";
   cin >> inFileName;
   cout << "Enter name of file to receive "
      << "the encrypted text: ";
   cin >> outFileName;
   SimpleEncryption obfuscate(inFileName, outFileName);
   obfuscate.encrypt();
     obfuscate.display(outFileName);
   return 0;
}