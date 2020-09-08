/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 7th, 2020, 2:15 PM
 * Purpose:  Write a program that converts Celsius
 *          temperatures to Fahrenheit
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
    
    //Declaring Celsius and Fahrenheit variables
    float ctemp;
    float ftemp;
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    
    //Retrieve input from user, store in ctemp variable
    cout<<"Enter a temperature in Celsius: ";
    cin>>ctemp;
    //Calculate Fahrenheit, store in ftemp variable, output results
    ftemp=((9.0/5.0)*ctemp)+32;
    cout<<ctemp<<" degrees Celsius is "<<ftemp<<" degrees Fahrenheit."<<endl;
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations