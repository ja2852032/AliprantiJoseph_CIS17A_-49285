/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 30th, 2020, 5:55 PM
 * Purpose:  Dynamically allocate values from one array into
 *           an augmented array with an extra element
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
int *getData(int &);            //Read the array
int *augment(const int *,int);  //Augment and copy the original array
void prntAry(const int *,int);  //Print the array

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int aSize;
    int *array=getData(aSize);

    int *augAry=augment(array,aSize);
    //Display the Inputs/Outputs
    prntAry(array,aSize);
    cout<<endl;
    prntAry(augAry,aSize+1);
    
    //Clean up the code, close files, deallocate memory, etc....
    delete []array;
    delete []augAry;
    //Exit stage right
    return 0;
}

int *getData(int &size){
    int num;
    int i=0;
    cin>>size;  //Read in size of array
    
    int *arr=new int[size];  //Create dynamic array
    while(i<size){
        cin>>num;
        arr[i]=num;  //input numbers into array
        i++;
    }
    
    return arr;  //Return array
}

int *augment(const int *array,int size){
    int *augAry=new int[size+1];  //Create dynamic augmented array
    augAry[0]=0;  //Set value of the first element to 0
    
    for(int i=1;i<size+1;i++)
        augAry[i]=array[i-1];  //Copy the array passed to function into the augmented array, shifted over 1 element each
        
    return augAry;
}

void prntAry(const int *array,int size){
    for(int i=0;i<size-1;i++)
        cout<<array[i]<<" ";  //Print array
    cout<<array[size-1];
}