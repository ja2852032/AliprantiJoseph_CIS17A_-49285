/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 7th, 2020, 2:30 PM
 * Purpose:  Convert the US Dollar to Japanese Yen
 *          and Euros
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    //Declaring constant conversion factors
    const float yenUSD=106.28;
    const float euroUSD=0.85;
    //Declaring variables for US dollars, Yen, and Euros
    float USD, yen, euros;
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    //Retrieve input from the user for amount of US dollars
    cout<<"Please enter an amount of US dollars to convert to Yen and Euros: $";
    cin>>USD;
    //Convert US dollars to Yen and Euros, using constant conversion variables
    yen=yenUSD*USD;
    euros=euroUSD*USD;
    //Format the output to always show 2 decimal places
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"$"<<USD<<" is equal to "<<yen<<" Yen and "<<euros<<" Euros."<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations