/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 30th, 2020, 3:25 PM
 * Purpose:  Sort a dynamic array in reverse order
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int *getData(int &);           //Fill the array
int *sort(const int *,int);     //Sort smallest to largest
int *reverse(const int *,int); //Sort in reverse order
void prntDat(const int *,int); //Print the array

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int aSize;
    int *array=getData(aSize);
    
    int *sortAry=sort(array, aSize);

    int *revAry=reverse(sortAry, aSize);

    //Display the Inputs/Outputs
    prntDat(sortAry, aSize);
    cout<<endl;
    prntDat(revAry, aSize);

    //Clean up the code, close files, deallocate memory, etc....
    delete []array;
    delete []sortAry;
    delete []revAry;
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
        arr[i]=num;  //Input numbers into dynamic array
        i++;
    }
    
    return arr;  //Return array
}

int *sort(const int *array,int size){
    int i, element, min;
    int *arr=new int[size];  //Create dynamic array

    for(int j=0;j<size;j++)
        arr[j]=array[j];  //Copy contents of array passed to function into the new array

    for(i=0;i<(size-1);i++){
        min=i;  //Set min to current iteration of i, starting at element 0
        element=arr[i];  //Store array residing in current element
        for(int index=i+1;index<size;index++){
            if (arr[index]<element){  //Compare current number to first number
                element=arr[index];  //Send lowest number to the front
                min=index;  //Set min to current element for swap
            }
        }
        arr[min]=arr[i];  //Swap the current number in array w/ the first number
        arr[i]=element;  //Swap the first number w/ the current number in array
    }
    
    return arr;
}

int *reverse(const int *array,int size){
    int *revAry=new int[size];  //Create dynamic array
    int j=size-1;
    
    for(int i=0;i<size;i++){
        revAry[i]=array[j];
        j--;  //Decrement j while i increments to reverse array
    }
    
    return revAry;
}

void prntDat(const int *array,int size){
    for(int i=0;i<size-1;i++)
        cout<<array[i]<<" ";  //Print array
    cout<<array[size-1];
}