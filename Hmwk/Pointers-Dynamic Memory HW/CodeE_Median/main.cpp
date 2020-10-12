/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 30th, 2020, 11:30 AM
 * Purpose:  Find the median of an array using
 *           dynamic memory allocation
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int *getData(int &);       //Return the array size and the array
void prntDat(int *,int);   //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int aSize=0;
    int *array=getData(aSize);
    
    //Display the Inputs/Outputs
    prntDat(array, aSize);
    
    float *medAry=median(array,aSize);
    
    prntMed(medAry);

    //Clean up the code, close files, deallocate memory, etc....
    delete []array;
    delete []medAry;
    //Exit stage right
    return 0;
}

int *getData(int &size){
    int num;
    int i=0;
    cin>>size; //cin size of array
    
    int *arr=new int[size];  //create a dynamic array
    while(i<size){
        cin>>num;
        arr[i]=num; //enter numbers into dynamic array
        i++;
    }
    
    return arr; //return array
}

void prntDat(int *array,int size){
    for(int i=0;i<size-1;i++)  //Print numbers while stepping through array, print values
        cout<<array[i]<<" ";
    cout<<array[size-1]<<endl;
}

float *median(int *array,int size){
    float median;
    int found,
        n;
    if(size%2==0){ //If size of array is even
        n=size/2;
        found=array[n-1]+array[n]; //Add both numbers below and above the middle
        median=static_cast<float>(found)/2; //Cast the sum of the numbers to a float, dividide by 2
    }
    else{ //else size must be odd
        n=size/2;
        found=array[n]; //Set found to the middle value
        median=static_cast<float>(found); //Cast found as a float
    }
    
    float *arr=new float[size+2];  //Create dynamic array, two sizes greater than the original array
    arr[0]=static_cast<float>(size)+2.0;
    arr[1]=median;
    
    for(int i=2;i<size+2;i++){
        arr[i]=static_cast<float>(array[i-2]);  //Copy contents of first array into new dynamic array
    }
    
    return arr;
}

void prntMed(float *array){
    cout<<array[0];
    for(int i=1;i<array[0];i++){
        cout<<setprecision(2)<<fixed<<showpoint<<" "<<array[i];  //Print second dynamic array
    }
}