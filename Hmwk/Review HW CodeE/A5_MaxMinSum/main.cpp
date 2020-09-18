/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on 9/14/2020 at 9:30pm
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

void read(int array[],int size){
    int i=0;
    //Could have done for loop, but decide to experiment w/ while loop input
    while(cin>>array[i]) //While integer read into the i'th element of the array
        i++; //Increment i
}

int stat(const int array[],int size,int &max,int &min){
    int sum=0, //Declare and initialize sum variable
        e=0;
    //Set both max and min to the first element of the array
    max=array[e]; 
    min=array[e];
    
    for(int l=1;l<size;l++) 
        if(array[l]>max) //If integer in l'th element of array is larger than max, set max equal to integer
            max=array[l];
    
    for(int k=1;k<size;k++)
        if(array[k]<min) //If integer in k'th element of array is smaller than min, set min equal to integer
            min=array[k];
    
    for(int i=0;i<size;i++){
        sum=sum+array[i]; //Sum up all the integers by looping through every element of the array, storing in sum
    }
    return sum; //Return sum value to main
}

void print(const int array[],int size,int sum,int max,int min){
    for(int i=0;i<size;i++)
        cout<<"a["<<i<<"] = "<<array[i]<<endl; //Output every integer in array with the element they are found in
        
    cout<<"Min  = "<<min<<endl; //Output min
    cout<<"Max  = "<<max<<endl; //Output max
    cout<<"Sum  = "<<sum<<endl; //Output sum
}