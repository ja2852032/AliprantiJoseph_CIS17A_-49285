/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 11th, 4:50 PM
 * Purpose:  Create enumerated data types to step through an array containing
 *           data on the rainfall and weather of each month
 */

//System Libraries
#include <iostream> //I/O Library
#include <iomanip> //Formatting Library
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Weather
{
    float tot,
          high,
          low,
          ave;
};

enum Month {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE,
            JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

void showTmp(Weather [], const int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare/Initialize Variable Data Types and Constants
    const int MONTHS = 12;
    Weather month[MONTHS];
    
    //Process or map Inputs to Outputs
    
    //Display Outputs
    showTmp(month,MONTHS);

    //Exit stage right!
    return 0;
}

void showTmp(Weather month[], const int n){
    Month name;
    Weather a;
    float sum1=0,
          sum2=0,
          high=-100,
          low=140;
    int total=JANUARY;

    name=JANUARY;
    while(cin>>month[name].tot){
        
        cout<<"Enter the total rainfall for the month:"<<endl;
        cout<<"Enter the high temp:"<<endl;
        cin>>month[name].high;
        if(month[name].high>100)
            return;
        cout<<"Enter the low temp:"<<endl;
        cin>>month[name].low;
        if(month[name].low<-140)
            return;
        
        sum1+=month[name].tot;
        sum2+=(month[name].high+month[name].low);
        if(month[name].high>high)
            high=month[name].high;
        if(month[name].low<low)
            low=month[name].low;
        total++;
        name=static_cast<Month>(name+1);
    }
    
    a.tot=sum1/total;
    cout<<setprecision(2)<<fixed<<"Average monthly rainfall:"<<a.tot<<endl;
    cout<<setprecision(0)<<"High Temp:"<<high<<endl;
    cout<<"Low Temp:"<<low<<endl;
    a.ave=sum2/(total*2);
    cout<<setprecision(1)<<fixed<<"Average Temp:"<<a.ave;
}