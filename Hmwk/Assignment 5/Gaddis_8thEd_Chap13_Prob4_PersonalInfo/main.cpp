/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 11th, 2020, 8:35 PM
 * Purpose: Design a class that holds personal data, with 3 different instances.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>  //String Library
using namespace std;

//User Libraries
#include "Personal.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    const int SIZE = 3;
    PersonalInfo a[SIZE];
    string name,
           addr,
           person;
    int age;
    long int number;
    
    //Initialize all known variables
    for(int i=0;i<SIZE;i++){
        person=i==0?"first":i==1?"second":"third";
        
        cout<<"Enter the "<<person<<" person's name: ";
        getline(cin,name);
        cout<<"Enter the "<<person<<" person's address: ";
        getline(cin,addr);
        cout<<"Enter the "<<person<<" person's age: ";
        cin>>age;
        cout<<"Enter the "<<person<<" person's phone number: ";
        cin>>number;
        
        a[i].getData(name,addr,age,number);
        cin.ignore();
    }
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    cout<<endl;
    for(int i=0;i<SIZE;i++){
        a[i].prnData();
    }

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations