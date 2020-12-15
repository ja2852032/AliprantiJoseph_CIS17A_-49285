/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 12th, 2020, 4:25 PM
 * Purpose: Create a class that holds the details about an item in a retail store
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>  //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "Retail.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    const int SIZE=3;
    RetailItem a[SIZE]={ RetailItem("Jacket",12,59.95),
                         RetailItem("Designer Jeans",40,34.95),
                         RetailItem("Shirt",20,24.95) };
    int n;
    
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    cout<<endl<<"\tDescription\tUnits On Hand\tPrice"<<endl;
    for(int i=0;i<SIZE;i++){
        n=i==0?0:i==1?8:-1;
        
        cout<<"Item #"<<i+1;
        a[i].prnData(n);
    }

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations