#ifndef _People_cpp
#define _People_cpp

#include "People.h"

using namespace std;

//Implementation for default constructor
People::People(){
    name = "";
    birthday = Date(); 
}

// Parameterised constructor 
People::People(string n, Date b) {
    name = n;
    birthday = b;
}

// Setter for birthday
void People::setBday(Date d) {
    birthday = d;
}

// Getter for birthday
Date People::getBday() const {
    return birthday;
}

// Setter for name
void People::setName(string n) {
    name = n;
}

// Getter for name
string People::getName() const {
    return name;
}

// Input operator
istream& operator>>(istream& in, People& p) {
    string n;
    Date b;

    // code to read a Date object from input stream 'in'
    in >> n >> b;

    p.setBday (b);
    p.setName (n);
    return in;
}

// Output operator
ostream& operator<<(ostream& out, const People& p) {
    // code to write a Date object to output stream 'out'

    out << p.getName() << " " << p.getBday();
    return out;
}

// Non-member functions for People
bool operator == (const People& p1, const People& p2) {
	return (p1.getName () == p2.getName ()) && (p1.getBday () == p2.getBday ());
}

bool operator != (const People& p1, const People& p2) {
	return (p1.getName () != p2.getName ()) || (p1.getBday () != p2.getBday ());
}

bool operator > (const People& p1, const People& p2) {
	return p1.getName () > p2.getName ();
}

bool operator >= (const People& p1, const People& p2) {
	return p1.getName () >= p2.getName ();
}

bool operator < (const People& p1, const People& p2) {
	return p1.getName () < p2.getName ();
}

bool operator <= (const People& p1, const People& p2) {
	return p1.getName () <= p2.getName ();
}

#endif 



