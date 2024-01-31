// This program demonstrates the Length class's overloaded
// prefix ++, postfix ++, and stream operators.

// the postfix ++ is broken - figure out why - google this to learn the syntax difference between prefix and postfix

#include <iostream>
using namespace std;

class Length
{
private:
    int len_inches;
public:
    Length(int feet, int inches)
    {
        setLength(feet, inches);
    }
    Length(int inches){ len_inches = inches; }
    int getFeet() const { return len_inches / 12; }
    int getInches() const { return len_inches % 12; }
    void setLength(int feet, int inches)
    {
        len_inches = 12 *feet + inches;
    }
    // Overloaded arithmetic and relational operators
    friend Length operator+(Length a, Length b);
    friend Length operator-(Length a, Length b);
    friend bool operator<(Length a, Length b);
    friend bool operator==(Length a, Length b);
    Length operator++(); // prefix
    Length operator++(int); // postfix - google the notation for postfix

    // Overloaded stream input and output operators
    friend ostream &operator<<(ostream &out, Length a);
    friend istream &operator>>(istream &in, Length &a);
};

//**********************************************
// Overloaded stream extraction operator >>    *
//**********************************************
istream &operator>>(istream &in, Length &a)
{
    // Prompt for and read the object data
    int feet,  inches;
    cout << "Enter feet: ";
    in >> feet;
    cout << "Enter inches: ";
    in >> inches;

    // Modify the object a with the data and return
    a.setLength(feet, inches);
    return in;
}

//*********************************************
// Overloaded stream insertion operator <<    *
//*********************************************
ostream &operator<<(ostream& out, Length a)
{
    out << a.getFeet() << " feet, " << a.getInches() << " inches";
    return out;
}

//***********************************
// Overloaded prefix ++ operator    *
//***********************************
Length Length::operator++()
{
    len_inches ++;
    return *this;
}

//***********************************
// Overloaded postfix ++ operator   *
//***********************************
Length Length::operator++(int)
{
    Length temp = *this;
    len_inches ++;
    return temp;
}

//*************************************
// Overloaded operator -              *
//*************************************
Length operator+(Length a, Length b)
{
    return Length(a.len_inches + b.len_inches);
}

//*************************************
// Overloaded  operator -             *
//*************************************
Length operator-(Length a, Length b)
{
    return Length(a.len_inches - b.len_inches);
}

//************************************
// Overloaded operator ==            *
//************************************
bool operator==(Length a, Length b)
{
    return a.len_inches == b.len_inches;
}

//************************************
// Overloaded operator <             *
//************************************
bool operator<(Length a, Length b)
{
    return a.len_inches < b.len_inches;
}

int main()
{
    Length first(0), second(1, 9), c(0);

    cout << "Demonstrating prefix ++ operator and output operator.\n";
    for (int count = 0; count < 4; count++)
    {
        first = ++second;
        cout << "First: " << first <<  ". Second: " << second << ".\n";
    }
    cout << "\nDemonstrating postfix ++ operator and output operator.\n";
    for (int count = 0; count < 4; count++)
    {
        first = second++;
        cout << "First: " << first <<  ". Second: " << second << ".\n";
    }

  return 0;
}