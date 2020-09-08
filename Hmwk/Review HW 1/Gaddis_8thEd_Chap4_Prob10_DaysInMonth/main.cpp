/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 7th, 2020, 2:55 PM
 * Purpose:  Output the number of days in a month
 *          that the user indicates, accounting for leap years
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    //Declaring variables month and year
    int month;
    int year;
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    //Retrieve input for month and year from the user
    cout<<"Enter a month (1-12): ";
    cin>>month;
    cout<<"Enter a year: ";
    cin>>year;
    
    //Output "31 days" if month is any of the 7 months that have 31 days
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        cout<<"31 days"<<endl;
    //Output "30 days" if month is any of the 4 months that have 30 days
    else if(month==4||month==6||month==9||month==11)
        cout<<"30 days"<<endl;
    //Output "29 days" if user inputs month 2, and a leap year
    else if(month==2 && year%100==0 && year%400==0)
        cout<<"29 days"<<endl;
    else if(month==2 && year%4==0)
        cout<<"29 days"<<endl;
    //Output "28 days" if user inputs month 2 and a non leap year
    else if(month==2)
        cout<<"28 days"<<endl;
    //Output if user does not enter the directed numbers
    else
        cout<<"Faulty input.  Please run again."<<endl;
        
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations