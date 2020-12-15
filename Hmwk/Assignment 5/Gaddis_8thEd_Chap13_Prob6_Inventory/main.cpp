/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 12th, 2020, 7:15 PM
 * Purpose: Create a class that holds the details about an item in a retail store
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>  //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "InventoryClass.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    Inventory a(7,14,28.95);
    int itemNum;
    int units;
    float cost;
    float totCost;
    
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    a.setItemNumber(7);
    a.setQuantity(14);
    a.setCost(28.95);
    
    //Display the Inputs/Outputs
    itemNum=a.getItemNumber();
    units=a.getQuantity();
    cost=a.getCost();
    totCost=a.getTotalCost();
    
    cout<<"Item number: "<<itemNum<<endl;
    cout<<"Item quantity: "<<units<<endl;
    cout<<"Item cost: $"<<cost<<endl;
    cout<<setprecision(2)<<fixed<<"Total cost: $"<<totCost<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations