/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 20th, 2020, 7:50 PM
 * Purpose:  Complete the function to find the mean, median, and modes of the arrays.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    int count;
    int freq=0;
    int k=0;
    int set=0;
    float average=0;
    int sum=0;
    float median;
    int found,
        n;
    
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0;
    int nModes=0;
    
    for(int i=0;i<array->size;i++){
        sum+=array->data[i];
    }
    average=(sum*1.0)/(array->size);
    stats->avg=average;
    
    count=0;
    for(int j=k;j<array->size;j++){
        if(array->data[k]==array->data[j]){
            count+=1; //Count the amount of times the first value shows up
        }
    }
    if(count>freq){
        freq=count;  //Set the count to frequency if value shows up more than once
    }
    
    if(freq>1){
        int i=0;
        while(i<array->size){ //While stepping through length of array
            count=0;
            for(int j=i;j<array->size;j++){
                if(array->data[i]==array->data[j]){    //If value appears again, add 1 to count
                    count+=1;
                }
            }
            if(count==freq){  //If count equals frequency, add 1 to the number of modes
                nModes+=1;
            }
            i++;
        }
    }
    
    stats->mode->size=nModes;
    if(nModes!=0)stats->mode->data=new int[nModes];
    stats->modFreq=freq;
    
    if(freq>1){
        int i=0;
        while(i<array->size){  //While stepping through length of array
            count=0;
            for(int j=i;j<array->size;j++){
                if(array->data[i]==array->data[j]){  //If value appears again, add 1 to count
                    count+=1;
                }
            }
            if(count==freq){  //If count equals frequency, add value to mode array
                stats->mode->data[set]=array->data[i];
                set++;  //Increment set for the next possible value to enter mode array
            }
            i++;
        }
    }
    
    if((array->size)%2==0){ //If size of array is even
        n=(array->size)/2; 
        found=array->data[n-1]+array->data[n]; //Add both numbers below and above the middle
        median=static_cast<float>(found)/2; //Cast the sum of the numbers to a float, dividide by 2
    }
    else{  //else size must be odd
        n=(array->size)/2;
        found=array->data[n]; //Set found to the middle value
        median=static_cast<float>(found); //Cast found as a float
    }
    
    stats->median=median;
    return stats;
}