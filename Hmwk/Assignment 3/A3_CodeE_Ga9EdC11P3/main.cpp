/* 
 * File:  main.cpp 
 * Author: Joseph Alipranti
 * Created on October 11th, 1:00 PM
 * Purpose: Calculate the annual and average sales of different company
 *          divisions using a structure
 */

//System Libraries
#include <iostream> //I/O Library
#include <iomanip> //Formatting Library
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Sales
{
    string branch;
    float qSales;
    float anSales;
    float avSales;
};

void sale(const Sales &, Sales [], const int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare/Initialize Variable Data Types and Constants
    const int SIZE = 4;
    Sales quarter[SIZE];
    
    Sales north = {"North"};
    Sales east = {"East"};
    Sales south = {"South"};
    Sales west = {"West"};
    //Process or map Inputs to Outputs
    
    //Display Outputs
    sale(north, quarter, SIZE);
    sale(west, quarter, SIZE);
    sale(east, quarter, SIZE);
    sale(south, quarter, SIZE);
    
    //Exit stage right!
    return 0;
}

void sale(const Sales &name, Sales quarter[], const int q){
    string numQ;
    float sum=0;
    Sales ann,avg;
    cout<<name.branch<<endl;
    
    for(int i=0;i<q;i++){
        numQ=i==(q-4)?"first":i==(q-3)?"second":i==(q-2)?"third":"fourth";
        
        cout<<"Enter "<<numQ<<"-quarter sales:"<<endl;
        cin>>quarter[i].qSales;
    }
    
    for(int i=0;i<q;i++)
        sum+=quarter[i].qSales;
    
    ann.anSales=sum;
    cout<<setprecision(2)<<showpoint<<fixed<<"Total Annual sales:$"<<ann.anSales<<endl;
    avg.avSales=sum/q;
    if(name.branch=="South")
        cout<<setprecision(2)<<showpoint<<fixed<<"Average Quarterly Sales:$"<<avg.avSales;
    else
        cout<<setprecision(2)<<showpoint<<fixed<<"Average Quarterly Sales:$"<<avg.avSales<<endl;
}