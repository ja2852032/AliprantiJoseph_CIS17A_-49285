/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on 9/14/2020 at 6:00pm
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int read(char []);
void sort(char [],int);
void print(const char []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char array[]){
    int size;
    cin>>array;
    size=strlen(array); //Set integer size to the length of the array
    return size;
}

void sort(char array[],int size){
    int i, element, min;

    for(i=0;i<(size-1);i++){
        min=i; //Set min to current iteration of i, starting at element 0
        element=array[i]; //Store array residing in current element
        for(int index=i +1;index<size;index++){
            if (array[index]<element){ //Compare current number to first number
                element=array[index]; //Send lowest number to the front
                min=index; //Set min to current element for swap
            }
        }
        array[min]=array[i]; //Swap the current number in array w/ the first number
        array[i]=element; //Swap the first number w/ the current number in array
    }
}
    
void print(const char array[]){
    cout<<array<<endl; //Cout array
}