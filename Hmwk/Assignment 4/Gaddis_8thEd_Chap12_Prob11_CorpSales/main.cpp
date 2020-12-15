/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 18th, 2020, 6:55 PM
 * Purpose: Calculate the sales of different company divisions over 4 quarters,
 *          sending the data to a binary file, as well as a text file to confirm
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> //I/O Manipulation
#include <fstream> //File Stream Library
using namespace std;

//User Libraries
#include "Company.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void sale(Sales &,fstream &,fstream &);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare/Initialize all variables for this function
    fstream binFile,
            txtFile;
    binFile.open("data.bin",ios::out|ios::binary); //Open binFile for binary output
    txtFile.open("test.txt",ios::out); //Open test file for text input to test valid data
    const int SIZE = 4;
    
    //Initialize branch name and quarters for the structure variables
    Sales north = {"North",{1,2,3,4}};
    Sales east = {"East",{1,2,3,4}};
    Sales south = {"South",{1,2,3,4}};
    Sales west = {"West",{1,2,3,4}};
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    sale(east,binFile,txtFile);
    sale(west,binFile,txtFile);
    sale(north,binFile,txtFile);
    sale(south,binFile,txtFile);

    //Clean up the code, close files, deallocate memory, etc....
    binFile.close();
    txtFile.close();
    
    //Exit stage right
    return 0;
}

//Function Implementations
void sale(Sales &name,fstream &binFile,fstream &txtFile){
    int index=4; //Index of 4 elements for 4 quarters
    string numQ; 
    
    cout<<name.branch<<endl;
    
    for(int i=0;i<index;i++){
        //Determine the quarter with a nested ternary operator
        numQ=name.quarter[i]==1?"first":name.quarter[i]==2?"second":name.quarter[i]==3?"third":"fourth";
        
        cout<<"Enter "<<numQ<<"-quarter sales:"<<endl;
        cin>>name.qSales[i];
        if(name.qSales[i]<0){ //If number entered is a negative, repeat input
            while(name.qSales[i]<0){
                cout<<"Must be a positive number. Enter "<<numQ<<"-quarter sales:"<<endl;
                cin>>name.qSales[i];
            }
        }
    }
    cout<<endl;
    
    //Write the name of the branch to binary file
    binFile.write(reinterpret_cast<char *>(&name.branch),sizeof(string));
    //Write the amount of quarters, and the quarter data to binary file
    binFile.write(reinterpret_cast<char *>(&index),sizeof(int));
    binFile.write(reinterpret_cast<char *>(name.quarter),index*sizeof(float));
    //Write the amount of sales, and the sales data to binary file
    binFile.write(reinterpret_cast<char *>(&index),sizeof(int));
    binFile.write(reinterpret_cast<char *>(name.qSales),index*sizeof(float));
    
    txtFile<<name.branch<<endl; //Send name of branch to text file
    for(int i=0;i<index;i++){ //Send quarters and sales data to text file
        txtFile<<"Quarter "<<name.quarter[i]<<": $"<<
                setprecision(2)<<showpoint<<fixed<<name.qSales[i]<<endl;
    }
    txtFile<<endl;
    
}