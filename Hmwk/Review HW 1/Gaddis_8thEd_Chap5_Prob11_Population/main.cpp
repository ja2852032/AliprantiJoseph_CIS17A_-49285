/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 7th, 2020, 3:30 PM
 * Purpose:  Predict the size of a population with looping
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
    //Declaring integers for number of organisms, days, and average increase
    int org, days, incrs;
    //Declaring float to account for non-integer increase in population 
    float nOrg;
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    
    //Retrieve input for population size
    cout<<"Please enter the starting population size of the organisms: ";
    cin>>org;
    //Validate the input for population size, must be 2 or more
    while(org<2){
        cout<<"Invalid input.  Please enter a number 2 or greater: ";
        cin>>org;
    }
    
    //Retrieve input for percent increase
    cout<<"Please enter the average percent increase in the population: ";
    cin>>incrs;
    //Validate the input for percent increase, must be greater than 0
    while(incrs<0){
        cout<<"Invalid input.  Please enter a number greater than 0: ";
        cin>>incrs;
    }
    
    //Retrieve input for number of days
    cout<<"Please enter the amount of days the population will multiply: ";
    cin>>days;
    //Validate input for number of days, must be 1 or more
    while(days<1){
        cout<<"Invalid input.  Please enter a number 1 or greater: ";
        cin>>days;
    }
    
    //Output day 1 and the starting population
    cout<<"Day 1: "<<org<<" organisms"<<endl; 
    //Initialize nOrg to have the same value of org for the first day
    nOrg=org;
    
    //loop through the amount of days
    for(int i=1; i<days; i++){
        //Counter nOrg to equal itself plus its percent increase
        nOrg=nOrg+(nOrg*(incrs/100.0));
        //Display the day and number of organisms as an integer
        cout<<"Day "<<i+1<<": "<<static_cast<int>(nOrg)<<" organisms"<<endl;
    }
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations