/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 7th, 2020, 5:15 PM
 * Purpose:  Track the weather over a 3 month period, getting the data
 *          from a file
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>  //File Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void total(char[][30]);
void rMonth(char[][30]);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    //Declare dataIn to read in from a file
    ifstream dataIn;
    //Declare and initialize the rows and columns of the array
    const int row=3;
    const int col=30;
    //Character array for the characters read in from the file
    char rcsArr[row][col];
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    //Open up the text file
    dataIn.open("RainOrShine.txt");
    //Loop through the array to read in the characters
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            dataIn>>rcsArr[r][c];
        }
    }
    
    //Display the Inputs/Outputs
    //Call total function, passing rcsArr as an array parameter
    total(rcsArr);
    
    //Call rMonth function, passing rcsArr as an array parameter
    rMonth(rcsArr);
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void total(char array[][30]){
    //Declare/initialize variables
    int rain=0,
        sun=0,
        cloud=0;
    //Loop through the first row of the array to count number of days for June
    for(int i=0;i<30;i++){
        if(array[0][i]=='R')
            rain++; //Counter to count the amount of rainy days
        if(array[0][i]=='C')
            cloud++; //Counter to count the amount of cloudy days
        if(array[0][i]=='S')
            sun++; //Counter to count the amount of sunny days
    }
    //Output the number of each days for the month of June
    cout<<"For June, there was "<<rain<<" rainy days, "<<cloud<<" cloudy days, and "
            <<sun<<" sunny days."<<endl;
    
    //Re-initialize the variables to 0
    rain=0;
    sun=0;
    cloud=0;
    //Loop through the second row of the array to count number of days for June
    for(int i=0;i<30;i++){
        if(array[1][i]=='R')
            rain++; //Counter to count the amount of rainy days
        if(array[1][i]=='C')
            cloud++; //Counter to count the amount of cloudy days
        if(array[1][i]=='S')
            sun++; //Counter to count the amount of sunny days
    }
    //Output the number of each days for the month of July
    cout<<"For July, there was "<<rain<<" rainy days, "<<cloud<<" cloudy days, and "
            <<sun<<" sunny days."<<endl;
    
    //Re-initialize the variables to 0
    rain=0;
    sun=0;
    cloud=0;
    //Loop through the third row of the array to count number of days for June
    for(int i=0;i<30;i++){
        if(array[2][i]=='R')
            rain++; //Counter to count the amount of rainy days
        if(array[2][i]=='C')
            cloud++; //Counter to count the amount of cloudy days
        if(array[2][i]=='S')
            sun++; //Counter to count the amount of sunny days
    }
    //Output the number of each days for the month of August
    cout<<"For August, there was "<<rain<<" rainy days, "<<cloud<<" cloudy days, and "
            <<sun<<" sunny days."<<endl;
    
    //Re-initialize the variables to 0
    rain=0;
    sun=0;
    cloud=0;
    //Loop through the entirety of the array to get the total over all three months
    for(int l=0;l<3;l++){
        for(int i=0;i<30;i++){
            if(array[l][i]=='R')
                rain++; //Counter to count the amount of rainy days
            if(array[l][i]=='C')
                cloud++; //Counter to count the amount of cloudy days
            if(array[l][i]=='S')
                sun++; //Counter to count the amount of sunny days
        }
    }
    //Output the number of each days for all three months
    cout<<"For all 3 months, there was "<<rain<<" rainy days, "<<cloud<<" cloudy days, and "
            <<sun<<" sunny days."<<endl<<endl;
    
}

void rMonth(char array[][30]){
    //Declare/initialize variables
    int r0=0,
        r1=0,
        r2=0;
    //Loop through all three months (rows) separately
    for(int i=0;i<30;i++)
        if(array[0][i]=='R')
            r0++; //Counter to count the amount of rainy days in June
    for(int i=0;i<30;i++)
        if(array[1][i]=='R')
            r1++; //Counter to count the amount of rainy days in July
    for(int i=0;i<30;i++)
        if(array[2][i]=='R')
            r2++; //Counter to count the amount of rainy days in August
    
    //Compare June to July and August
    if(r0>r1 && r0>r2)
        cout<<"June had the most rainy days."<<endl;
    //Compare July to June and August
    else if(r1>r0 && r1>r2)
        cout<<"July had the most rainy days."<<endl;
    //If June or July were not greater than all others, August must be the largest
    else
        cout<<"August had the most rainy days."<<endl;
        
}
