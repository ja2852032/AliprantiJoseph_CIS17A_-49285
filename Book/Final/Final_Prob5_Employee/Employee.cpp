/* 
 * File:   Employee.cpp
 * Author: Joseph Alipranti
 * Created on December 16th, 2020, 7:10 PM
 * Purpose: Functions for Employee class
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> //I/O Manipulator
#include <string>
using namespace std;

//User Libraries
#include "Employee.h"

Employee::Employee(char name[],char title[],float rate){
    for(int i=0;i<sizeof(MyName);i++)
        MyName[i]=name[i];
    for(int i=0;i<sizeof(MyName);i++)
        JobTitle[i]=title[i];
    HourlyRate=rate;
    
    HoursWorked=0;
    GrossPay=0;
    NetPay=0;
}

float Employee::CalculatePay(float rate,int hours){
    return getNetPay(getGrossPay(setHourlyRate(rate)
		,setHoursWorked(hours)));
}

float Employee::getGrossPay(float pay,int hours){
    if(hours<=40)
        GrossPay=hours*pay;
    else if(hours>40&&hours<=50)
        GrossPay=(40*pay)+((hours-40)*(pay*1.5));
    else
        GrossPay=(40*pay)+(10*(pay*1.5))+((hours-50)*(pay*2));
    
    return GrossPay;
}

float Employee::getNetPay(float){
    NetPay=Tax(GrossPay);
    return NetPay;
}

void Employee::toString(){
    int h;
    float r;
    
    try{
        h=checkHours(HoursWorked);
    }
    catch(string strng1){
        cout<<strng1<<endl;
    }
    try{
        r=checkRate(HourlyRate);
        cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl
            <<" Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked<<" Gross Pay = "<<GrossPay<<" Net Pay = "<<NetPay<<endl;
    }
    catch(string strng2){
        cout<<strng2<<endl;
    }
}

int Employee::setHoursWorked(int hours){
    HoursWorked=hours;
    return HoursWorked;
}

float Employee::setHourlyRate(float rate){
    HourlyRate=rate;
    return HourlyRate;
}

double Employee::Tax(float pay){
    float net;
    
    if(pay<=500)
        net=pay-(pay*0.1);
    else if(pay>500&&pay<=1000)
        net=((pay-500)-(pay-500)*0.2)+450;
    else
        net=((pay-1000)-(pay-1000)*0.3)+850;
    
    return net;
}

int Employee::checkHours(int h){
    if(h<0||h>84){
        string strng1 = "Unacceptable Hours Worked";
        throw strng1;
    }
    else
        return h;
}

float Employee::checkRate(float r){
    if(r<0||r>200){
        string strng2 = "Unacceptable Hourly Rate";
        throw strng2;
    }
    else
        return r;
}