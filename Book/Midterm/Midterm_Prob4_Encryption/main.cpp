/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 21st, 2020, 7:50 PM
 * Purpose:  Encrypt and decrypt data for a company in octal
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int encrypt(int);
int decrypt(int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int data;
    int encData;
    int decData;
    
    //Initialize all known variables
    cout<<"Please enter a 4 digit integer: ";
    cin>>data;
    if(data>9999){
        while(data>9999){
            cout<<"Bad input.  Please enter a 4 digit integer: ";
            cin>>data;
        }
    }
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    encData=encrypt(data);
    cout<<endl<<"Encrypted data: "<<encData<<endl;
    
    decData=decrypt(encData);
    cout<<"Decrypted data: "<<decData;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
int encrypt(int data){
    int newData=0;
    int sum1=0;
    int sum2=0;
    int max=4;
    int divide=10000;
    int mult;
    int holdNum;
    
    mult=1000;
    for(int i=0;i<max;i++){
        holdNum=(data%divide-data%(divide/10))/(divide/10);
        divide/=10;
        
        if(holdNum>7){
            cout<<"A digit exceeding 7 has been detected. Please run the program again"<<
                    " and ignore the output.";
            return 0;
        }
        
        holdNum=(holdNum+5)%8;
        newData+=holdNum*mult;
        mult/=10;
    }
    
    divide=10000;
    holdNum=0;
    mult=10;
    for(int i=0;i<2;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        
        sum1+=holdNum*mult;
        mult*=100;
        divide/=100;
    }
    divide=1000;
    holdNum=0;
    mult=1;
    for(int i=0;i<2;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        
        sum2+=holdNum*mult;
        mult*=100;
        divide/=100;
    }
    
    newData=sum1+sum2;
    return newData;
}

int decrypt(int data){
    int newData=data;
    int n2Data=0;
    int sum1=0;
    int sum2=0;
    int max=4;
    int divide;
    int mult;
    int holdNum;
    
    divide=10000;
    holdNum=0;
    mult=10;
    for(int i=0;i<2;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        
        sum1+=holdNum*mult;
        mult*=100;
        divide/=100;
    }
    divide=1000;
    holdNum=0;
    mult=1;
    for(int i=0;i<2;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        
        sum2+=holdNum*mult;
        mult*=100;
        divide/=100;
    }
    
    newData=sum1+sum2;
    
    divide=10000;
    mult=1000;
    for(int i=0;i<max;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        divide/=10;
        
        if(holdNum>7){
            cout<<"A digit exceeding 7 has been detected. Please run the program again";
            return 0;
        }
        
        holdNum=(holdNum+11)%8;
        n2Data+=holdNum*mult;
        mult/=10;
    }
    
    return n2Data;
}