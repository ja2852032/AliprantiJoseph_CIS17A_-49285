/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 19th, 2020, 3:50 PM
 * Purpose: Get information from user on a person(s) hours and hourly
 *          pay, and output a check for the worker(s), adjusting for
 *          overtime pay
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string> //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "Checking1.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void getInfo(Data [],const int);
void prnInfo(Data [],int);
void numWord(const float);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int size;
    
    //Initialize all known variables
    cout<<"Enter the number of employees: ";
    cin>>size;
    cin.ignore();
    Data array[size];
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    cout<<endl;
    getInfo(array,size);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void getInfo(Data a[],const int size){
    
    for(int i=0;i<size;i++){
        cout<<"Enter the name of employee #"<<(i+1)<<": ";
        getline(cin,a[i].name);
        cout<<"Enter the number of hours employee #"<<(i+1)<<" has worked: ";
        cin>>a[i].hours;
        cout<<"Enter the hourly pay for employee #"<<(i+1)<<": ";
        cin>>a[i].pay;
        cin.ignore();
        
        if(a[i].hours<0||a[i].hours>168){
            cout<<"You have entered an invalid number of hours."<<endl<<
                    "You cannot have negative hours, or exceed 168 hours in a week.";
            i=size;
        }
        if(a[i].pay<0){
            cout<<"You have entered an invalid number for hourly pay.";
            i=size;
        }
        
        if(i<size)
            prnInfo(a,i);
    }
        
}

void prnInfo(Data *a,int index){
    float money;
    if(a[index].hours<=40)
        money=a[index].hours*a[index].pay;
    else if(a[index].hours>40&&a[index].hours<=50)
        money=(40*a[index].pay)+((a[index].hours-40)*(a[index].pay*2));
    else
        money=(40*a[index].pay)+(10*(a[index].pay*2))+((a[index].hours-50)*(a[index].pay*3));
    
    
    cout<<endl<<"Big Fluff Inc."<<endl;
    cout<<"5555 University Ave."<<endl;
    cout<<a[index].name<<"   $"<<setprecision(2)<<fixed<<money<<endl;
    numWord(money);
    cout<<endl<<"*"<<a[index].name<<"'s signature*"<<endl<<endl;
}

void numWord(const float n){
    string number;
    int max=4;
    int teen=0;
    int num=static_cast<int>(n);
    int divide=10000;
    int holdNum;
    
    for(int i=0;i<max;i++){
        holdNum=(num%divide-num%(divide/10))/(divide/10);
        divide/=10;
        
        if(i==0){
            number=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(number!="null"){
                cout<<number<<" Thousand ";
            }
        }
        if(i==1){
            number=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(number!="null"){
                cout<<number<<" Hundred ";
            }
        }
        if(i==2){
            number=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(number!="null"){
                if(holdNum==9||holdNum==7||holdNum==6)
                    cout<<number<<"ty ";
                if(holdNum==8)
                    cout<<"Eighty ";
                if(holdNum==5)
                    cout<<"Fifty ";
                if(holdNum==4)
                    cout<<"Forty ";
                if(holdNum==3)
                    cout<<"Thirty ";
                if(holdNum==2)
                    cout<<"Twenty ";
                if(holdNum==1)
                    teen=-1;
            }    
        }
        if(i==3){
            number=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(number!="null"){
                if(teen==-1){
                    if(holdNum==9||holdNum==7||holdNum==6||holdNum==4)
                        cout<<number<<"teen";
                    if(holdNum==8)
                        cout<<"Eighteen";
                    if(holdNum==5)
                        cout<<"Fifteen";
                    if(holdNum==3)
                        cout<<"Thirteen";
                    if(holdNum==2)
                        cout<<"Twelve";
                    if(holdNum==1)
                        cout<<"Eleven";
                }
                else
                    cout<<number;
            }
        }
    }
    cout<<" and "<<setprecision(0)<<(n-num)*100<<"/100";
}
