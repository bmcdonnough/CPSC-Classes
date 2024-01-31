// This program illustrates aggregation, composition and object lifetimes.
// Adapted from program pr11-18 in textbook

// Notation:
// In cout, we will use:
// [*] to indicate that an object has been created
// [X] to indicate that an object has been destroyed

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Date
{
private:
  string month;
  int day, year;
  int personID; //ID of person whose birthday this is.

public:
  Date(string m, int d, int y, int id) :
    month(m), day(d), year(y), personID(id)
  {
    cout << "[*] Date object for person " << personID << " created.\n";
  }
  ~Date()
  {
    cout << "[x] Date object for person " << personID << " destroyed.\n";
  }
};

class Country
{
private:
  string name;

public:
  Country(string name) : name(name)
  {
    cout << "[*] Country object created.\n";
  }
  ~Country()
  {
    cout << "[x] Country object destroyed.\n";
  }
};



class Person
{
private:
  string name;
  int personID;
  Date dateOfBirth;
  shared_ptr<Country> pCountry;
  static int uniquePersonID;

public:
  Person(string name, string month, int day, int year, shared_ptr<Country>& pC) :
    name(name),
    personID(Person::uniquePersonID),
    dateOfBirth(month, day, year, Person::uniquePersonID),
    pCountry(pC)
  {
    Person::uniquePersonID++;
    cout << "[*] Person object " << personID << " created.\n";
  }
  ~Person()
  {
    cout << "[x] Person object " << personID << " destroyed.\n";
  }

};

// Define the static class variable
int Person::uniquePersonID = 1;

int main()
{
  // Beginning of program
  cout << "-------------------------------------------------\n";
  cout << "Beginning of main() " << endl;
  cout << "-------------------------------------------------\n";



  // Create a Country object
  shared_ptr<Country> p_usa = make_shared<Country>("USA");
  
  // Create a Person object
  Person p{"Peter Lee", "January", 1, 1985, p_usa};
  
  // Create another Person object
  Person p1{"Eva Gustafson", "May", 15, 1992, p_usa};
  
  // End of program
  cout << "-------------------------------------------------\n";
  cout << "End of main(). Everything will go out of scope." << endl;
  cout << "-------------------------------------------------\n";
  
  return 0;
}

