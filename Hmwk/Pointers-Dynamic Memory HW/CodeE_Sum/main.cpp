/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 30th, 2020, 4:50 PM
 * Purpose:  Create a dynamic parellel array summing up 
 *           the values of the given array respectively
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int *getData(int &);           //Return the array size and the array from the inputs
int *sumAry(const int *,int);  //Return the array with successive sums
void prntAry(const int *,int); //Print the array

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int aSize=0;
    int *array=getData(aSize);

    int *arraySm=sumAry(array, aSize);
    
    //Display the Inputs/Outputs
    prntAry(array, aSize);
    cout<<endl;
    prntAry(arraySm, aSize);

    //Clean up the code, close files, deallocate memory, etc....
    delete []array;
    delete []arraySm;
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
        arr[i]=num;  //Input numbers into array
        i++;
    }
    
    return arr;  //Return array
}

int *sumAry(const int *array,int size){
    int *arraySm=new int[size];  //Create new dynamic array to hold the sums

    for(int i=0;i<size;i++)
        arraySm[i]=array[i];  //Copy the original array into the sum array
    
    for(int i=1;i<size;i++)
        arraySm[i]=arraySm[i]+arraySm[i-1]; //Step through the sum array, adding the current value with the previous value
    
    return arraySm;
}

void prntAry(const int *array,int size){
    for(int i=0;i<size-1;i++)
        cout<<array[i]<<" ";  //Print array
    cout<<array[size-1];
}