/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 11th, 2020, 8:50 PM
 * Purpose:  Store weather data in a structure, and use the data stored
 *           to calculate desired information
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
struct Weather
{
    string name;
    float tot,
          high,
          low;
};

void showTmp(Weather [], const int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare/Initialize all variables for this function
    const int MONTHS=12;
    Weather month[MONTHS];
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    showTmp(month,MONTHS);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void showTmp(Weather month[], const int num){
    float tRain=0,
          tTemp=0,
          avRain=0,
          avTemp=0,
          high=-100,
          low=140;
    int j=0,
        k=0;
    
    for(int i=0;i<num;i++){
        cin>>month[i].name>>month[i].tot>>month[i].low>>month[i].high;
        tRain+=month[i].tot;
        tTemp+=(month[i].low+month[i].high);
        
        if(month[i].high>high){
            high=month[i].high;
            j=i;
        }
        if(month[i].low<low){
            low=month[i].low;
            k=i;
        }
    }
    
    avRain=tRain/num;
    cout<<setprecision(1)<<fixed<<"Average Rainfall "<<avRain<<" inches/month"<<endl;
    cout<<setprecision(0)<<"Lowest  Temperature "<<month[k].name<<"  "<<low<<" Degrees Fahrenheit"<<endl;
    cout<<"Highest Temperature "<<month[j].name<<"  "<<high<<" Degrees Fahrenheit"<<endl;
    avTemp=tTemp/(num*2);
    cout<<"Average Temperature for the year "<<avTemp<<" Degrees Fahrenheit"<<endl;
}