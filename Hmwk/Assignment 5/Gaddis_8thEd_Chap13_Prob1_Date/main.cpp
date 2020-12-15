/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 11th, 2020, 7:20 PM
 * Purpose: Pass integer data to class functions, return in different formats
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string> //String Library
using namespace std;

//User Libraries
#include "DateClass.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    Date a;
    int month,
        day,
        year;
    
    //Initialize all known variables
    cout<<"Please enter a month (1-12): ";
    cin>>month;
    if(month>12||month<1){
        while(month>12||month<1){
            cout<<"Not a valid number. Please enter a number 1 through 12: ";
            cin>>month;
        }
    }
    
    cout<<"Please enter a day (1-31): ";
    cin>>day;
    if(day>31||day<1){
        while(day>31||day<1){
            cout<<"Not a valid number. Please enter a number 1 through 31: ";
            cin>>day;
        }
    }
    
    cout<<"Enter a year: ";
    cin>>year;
    cout<<endl;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    a.getData(month,day,year);
    
    //Display the Inputs/Outputs
    a.print1();
    a.print2();
    a.print3();

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations