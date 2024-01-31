#include "Length.h" 
 
//*************************************
// Overloaded operator +              *
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

ostream &operator<<(ostream& out, Length a)
{
    out << a.getFeet() << " feet, " << a.getInches() << " inches";
    return out;
}

istream &operator| (istream &in, Length &a)
{
    double centimeters;
    cout << "Enter centimeters: ";
    in >> centimeters;

    a.len_inches = centimeters * 0.393701;

    a.setLength(a.len_inches / 12, (a.len_inches % 12));
    return in;
}
