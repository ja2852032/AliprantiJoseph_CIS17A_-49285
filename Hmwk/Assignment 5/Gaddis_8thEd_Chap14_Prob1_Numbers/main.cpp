/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 12th, 2020, 8:45 PM
 * Purpose: Use a class to convert an integer to english representation of that integer
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>  //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "Nums.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int n;
    
    cout<<"Enter a number between 1 and 9999: ";
    cin>>n;
    if(n<1||n>9999){
        while(n<1||n>9999){
            cout<<"Invalid number. Please enter an integer between 1 and 9999: ";
            cin>>n;
        }
    }
    
    Numbers a(n);
    
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    a.print();

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations