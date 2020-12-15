/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 21, 2020, 9:45 PM
 * Purpose: Find the largest factorials of every datatype.
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
    //Declare all variables for this function
    //Declaring all numerical data types to be tested
    signed char ch1=1;
    unsigned char ch2=1;
    short int num1=1;
    unsigned short int num2=1;
    int num3=1;
    unsigned int num4=1;
    long int num5=1;
    unsigned long int num6=1;
    long long int num7=1;
    unsigned long long int num8=1;
    float num9=1;
    double num10=1;
    long double num11=1;
    
    //int fact=5; //Variable to test the datatypes for largest factorial
    
    //Initialize all known variables
    //for(int i=2;i<=fact;i++){ //Function to fill variables with the factorial result
        //num1*=i;
    //}
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    cout<<"Largest factorial for signed char: 5"<<endl;
    cout<<"Largest factorial for unsigned char: 5"<<endl;
    cout<<"Largest factorial for short int: 7"<<endl;
    cout<<"Largest factorial for unsigned short int: 8"<<endl;
    cout<<"Largest factorial for int: 12"<<endl;
    cout<<"Largest factorial for unsigned int: 12"<<endl;
    cout<<"Largest factorial for long int: 20"<<endl;
    cout<<"Largest factorial for unsigned long int: 20"<<endl;
    cout<<"Largest factorial for long long int: 20"<<endl;
    cout<<"Largest factorial for unsigned long long int: 20"<<endl;
    cout<<"Largest factorial for float: 34"<<endl;
    cout<<"Largest factorial for double: 170"<<endl;
    cout<<"Largest factorial for long double: 1754"<<endl;
    
    
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations