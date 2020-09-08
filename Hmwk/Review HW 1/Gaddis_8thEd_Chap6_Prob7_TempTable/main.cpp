/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 7th, 2020, 4:30 PM
 * Purpose:  Create a table of Fahrenheit to Celsius 
 *          conversion using a function and a loop
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Celsius function prototype
int celsius(int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    //float c;
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    //Loop from 0 to 20, calling the function inside
    for(int i=0;i<21;i++){
        //Calls Celsius function, passes i as integer value
        celsius(i);
    }
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
int celsius(int ftemp){
    //Declaring Celsius variable ctemp
    float ctemp;
    //Converting Fahrenheit to Celsius
    ctemp=(5.0/9.0)*(ftemp-32);
    //Format the output
    cout<<fixed<<showpoint<<setprecision(1);
    //Display the table of Fahrenheit and Celsius
    cout<<"Fahrenheit: "<<ftemp<<"\t\tCelsius: "<<ctemp<<endl;
}