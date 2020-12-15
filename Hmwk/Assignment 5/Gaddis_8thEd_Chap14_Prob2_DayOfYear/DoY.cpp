/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 12th, 2020, 10:05 PM
 * Purpose: Functions for DayOfYear
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>  //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "DoY.h"

DayOfYear::DayOfYear(int d){
    day=d;
}

string DayOfYear::month[]={"January","February","March","April","May","June",
                           "July","August","September","October","November","December"};

void DayOfYear::print(){
    int i=0;
    if(day>=1&&day<=31){
        cout<<month[i]<<" "<<day;
    }
    else if(day>=32&&day<=59){
        i=1;
        cout<<month[i]<<" "<<day-31;
    }
    else if(day>=60&&day<=90){
        i=2;
        cout<<month[i]<<" "<<day-59;
    }
    else if(day>=91&&day<=120){
        i=3;
        cout<<month[i]<<" "<<day-90;
    }
    else if(day>=121&&day<=151){
        i=4;
        cout<<month[i]<<" "<<day-120;
    }
    else if(day>=152&&day<=181){
        i=5;
        cout<<month[i]<<" "<<day-151;
    }
    else if(day>=182&&day<=212){
        i=6;
        cout<<month[i]<<" "<<day-181;
    }
    else if(day>=213&&day<=243){
        i=7;
        cout<<month[i]<<" "<<day-212;
    }
    else if(day>=244&&day<=273){
        i=8;
        cout<<month[i]<<" "<<day-243;
    }
    else if(day>=274&&day<=304){
        i=9;
        cout<<month[i]<<" "<<day-273;
    }
    else if(day>=305&&day<=334){
        i=10;
        cout<<month[i]<<" "<<day-304;
    }
    else {
        i=11;
        cout<<month[i]<<" "<<day-334;
    }
}