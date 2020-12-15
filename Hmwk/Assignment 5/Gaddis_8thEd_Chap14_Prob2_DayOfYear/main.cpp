/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 12th, 2020, 9:50 PM
 * Purpose: Print Month and Day of Month from a class after receiving an integer from user
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>  //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "DoY.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare/Initialize all known variables
    int day;
    
    cout<<"Enter a day between 1 and 365: ";
    cin>>day;
    if(day<1||day>365){
        while(day<1||day>365){
            cout<<"Invalid entry.  Enter an integer between 1 and 365: ";
            cin>>day;
        }
    }
    
    DayOfYear a(day);

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    a.print();

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations