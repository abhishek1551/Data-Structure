#ifndef DATE_
#define DATE_

#include <iostream>
using namespace std;

class Date {
    public:
            // Constructors 

            // mon = month, day = day, and year = year
            // @post: A new Date object is created with month, day, and year components initialized to 0.
            // @param: None
        Date ();


    
            /**  Constructs a new Date object with the specified month, day, and year values.
        @pre None.
        @post A new Date object is created with month, day, and year components initialized to the given values.
        @param mon An integer representing the month of the date (1-12).
        @param day An integer representing the day of the date (1-31).
        @param year An integer representing the year of the date.
        */
        Date (int mon, int day, int year);
        
            // METHODS


            /**
            Retrieves the value of the month component of the Date object.
            @pre None.
            @post The value of the month component of the Date object is returned.
            @return An integer representing the month of the date (1-12).
            */
        int getMonth () const;



        /**
        Retrieves the value of the day component of the Date object.
        @pre None.
        @post The value of the day component of the Date object is returned.
        @return An integer representing the day of the date (1-31).
        */
        int getDay () const;


        /**
        Retrieves the value of the year component of the Date object.
        @pre None.
        @post The value of the year component of the Date object is returned.
        @return An integer representing the year of the date.
        */
        int getYear () const;
        

        // Modification Methods



            /**
            Sets the value of the month component of the Date object to the given value.
            @pre None.
            @post The value of the month component of the Date object is set to the given value.
            @param m An integer representing the month of the date (1-12).
            @return True if the set operation is successful, false otherwise.
            */  
        bool setMonth (int m);  


        /**
        Sets the value of the day component of the Date object to the given value.
        @pre None.
        @post The value of the day component of the Date object is set to the given value.
        @param d An integer representing the day of the date (1-31).
        @return True if the set operation is successful, false otherwise.
        */

        bool setDay (int d);


        /**
        Sets the value of the year component of the Date object to the given value.
        @pre None.
        @post The value of the year component of the Date object is set to the given value.
        @param y An integer representing the year of the date.
        @return True if the set operation is successful, false otherwise.
        */
        bool setYear (int y);
        
        
            // Friend Functions
        friend istream& operator >> (istream& in, Date& d);
    
    private:
        int month, day, year; // Used to store the date
};

    // Non member funcs
bool operator == (const Date& date1, const Date& date2);
bool operator != (const Date& date1, const Date& date2);
ostream& operator << (ostream& out, const Date& d);

#include "Date.cpp"
#endif