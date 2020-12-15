/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 12th, 2020, 8:50 PM
 * Purpose: Functions for Numbers class
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>  //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "Nums.h"

Numbers::Numbers(int n){
    number=n;
}

string Numbers::teens[]={"teen","Eighteen","Fifteen","Thirteen","Twelve","Eleven"};

void Numbers::print(){
    string n;
    string k;
    int max=4;
    int teen=0;
    int num=static_cast<int>(number);
    int divide=10000;
    int holdNum;
    
    for(int i=0;i<max;i++){
        holdNum=(num%divide-num%(divide/10))/(divide/10);
        divide/=10;
        
        if(i==0){
            n=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(n!="null"){
                cout<<n<<" Thousand ";
            }
        }
        if(i==1){
            n=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(n!="null"){
                cout<<n<<" Hundred ";
            }
        }
        if(i==2){
            n=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(n!="null"){
                if(holdNum==9||holdNum==7||holdNum==6)
                    cout<<n<<"ty ";
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
            n=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(n!="null"){
                if(teen==-1){
                    if(holdNum==9||holdNum==7||holdNum==6||holdNum==4)
                        cout<<n<<teens[0];
                    if(holdNum==8)
                        cout<<teens[1];
                    if(holdNum==5)
                        cout<<teens[2];
                    if(holdNum==3)
                        cout<<teens[3];
                    if(holdNum==2)
                        cout<<teens[4];
                    if(holdNum==1)
                        cout<<teens[5];
                }
                else
                    cout<<n;
            }
        }
    }
}