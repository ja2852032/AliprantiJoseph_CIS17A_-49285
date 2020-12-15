/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 18th, 2020, 7:25 PM
 * Purpose:  Determine a customer's account balance with a dynamic array,
 *           and display information with added penalties to the customer's
 *           account if overdrawn
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string> //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "Checking.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
Data *getData(int,int);
void disp(Data *,int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int size=30;
    int cstmrs;
    cout<<"Enter the number of customers: ";
    cin>>cstmrs;
            
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    Data *array=getData(cstmrs,size);

    //Clean up the code, close files, deallocate memory, etc....
    delete []array;
    //Exit stage right
    return 0;
}

//Function Implementations
Data *getData(int numC,int size){
    int j=2,
        k=2;
    float checks=0;
    Data *arr=new Data[numC];
    
    for(int i=0;i<numC;i++){
        cin.ignore();
        cout<<"Enter the name for custumer #"<<(i+1)<<": ";
        getline(cin,arr[i].name);
        cout<<"Enter the address for customer "<<(i+1)<<": ";
        getline(cin,arr[i].address);
        cout<<"Enter the account number for customer "<<(i+1)<<": ";
        cin>>arr[i].accNum;
        if(arr[i].accNum>99999){
            while(arr[i].accNum>99999){
                cout<<"Please enter a 5 digit number for the account: ";
                cin>>arr[i].accNum;
            }
        }
        cout<<"Enter the account balance at the beginning of the month: ";
        cin>>arr[i].balance;
        cout<<"Enter all of the checks written in the past month, enter 0 when finished"<<endl<<
                "Enter check #1: ";
        cin>>arr[i].totChck;
        do{
            cout<<"Enter check #"<<j<<": ";
            cin>>checks;
            arr[i].totChck+=checks;
            j++;
        }while(checks!=0);
        
        cout<<"Enter all of the deposits received in the past month, enter 0 when finished"<<endl<<
                "Enter deposit #1: ";
        cin>>arr[i].totDep;
        do{
            cout<<"Enter deposit #"<<k<<": ";
            cin>>checks;
            arr[i].totDep+=checks;
            k++;
        }while(checks!=0);
        cout<<endl;
        
        disp(arr,i);
    }
    return arr;
}

void disp(Data *a,int index){
    float newBal;
    string ovr=" ";
    
    cout<<a[index].name<<endl;
    cout<<a[index].address<<endl;
    cout<<a[index].accNum<<endl;
    
    newBal=a[index].balance+a[index].totDep-a[index].totChck;
    if(newBal<0){
        ovr="overdrawn";
        newBal=newBal+(newBal*-2);
    }
    cout<<"With your original balance of $"<<setprecision(2)<<fixed<<a[index].balance<<
            ", total checks written of $"<<a[index].totChck<<", and total deposits made of $"<<
            a[index].totDep<<","<<endl;
    cout<<"you now have a balance of $"<<newBal<<" "<<ovr<<endl;
    
    if(ovr=="overdrawn"){
        cout<<"Since your balance is overdrawn, you will be charged $20 as a penalty."<<endl;
        cout<<"Your new balance with the charge is -$"<<(newBal+20)<<"."<<endl;
    }
    cout<<endl;
    
}