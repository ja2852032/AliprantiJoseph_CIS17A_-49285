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

RetailItem::RetailItem(string desc, int units, float cost){
    description=desc;
    unitsOnHand=units;
    price=cost;
}

void RetailItem::prnData(int n){
    cout<<setprecision(2)<<fixed<<"\t"<<description<<setw(12-n)<<unitsOnHand<<setw(19)<<price<<endl;
}