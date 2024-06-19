#pragma once

#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;
class People{
    //data memebers
    private:
    string name;
    Date birthday;  
    
    //METHODS

    public:
    // Constructs an empty People object with default values for name and birthday.
// @pre None
// @post A new People object is created with empty string for name and a default Date object for birthday.
// @param None
People(); // Default constructor 

// Parameterized constructor
// @pre: valid string name and Date birthday parameters are passed.
// @post: Creates a new People object with the specified name and birthday.
// @param: n: The name of the person.
//         b: The birthday of the person.
People(string n, Date b);

// Setter for birthday
// @pre: valid Date object is passed
// @post: Sets the birthday of the current People object to the specified date.
// @param: d: The new birthday of the person.
void setBday(Date d);

// Getter for birthday
// @post: Returns the birthday of the current People object.
// @return: The birthday of the person.
Date getBday() const;

// Setter for name
// @pre: valid string name is passed.
// @post: Sets the name of the current People object to the specified name.
// @param: n: The new name of the person.
void setName(string n);

// Getter for name
// @post: Returns the name of the current People object.
// @return: The name of the person.
string getName() const;
    

//input and output operators 

    friend ostream& operator << (ostream& out, const People &person);
    friend istream& operator >> (istream& in, const People &person);
 
};

ostream& operator << (ostream& out, const People& p);

bool operator == (const People & p1, const People & p2);
bool operator != (const People & p1, const People& p2);
bool operator >  (const People & p1, const People& p2);
bool operator >= (const People & p1, const People& p2);
bool operator <  (const People & p1, const People& p2);
bool operator <= (const People & p1, const People& p2);

#include "People.cpp"
#endif
