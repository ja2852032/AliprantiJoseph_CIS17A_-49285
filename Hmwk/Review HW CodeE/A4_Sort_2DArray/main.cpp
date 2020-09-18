/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on 9/14/2020 at 8:00pm
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char array[][COLMAX],int &row){
    int size;
    int largest=0,
        i=0;
    while(cin>>array[i]){
        size=strlen(array[i]); //Set integer size to the length of the i'th row of the array
        if(size>largest)
            largest=size; //If column size greater than largest integer, set largest value equal to size value
        i++;
    }
    row=i;
    return largest;
}

void sort(char array[][COLMAX],int row,int col){
    int i, cmp, min;
    char element[COLMAX];

    for(i=0;i<(row-1);i++){
        min=i; //Set min to current iteration of i, starting at element 0
        strcpy(element, array[i]); //Store array residing in current element
        for(int index=i+1;index<row;index++){
            cmp=strcmp(array[index],array[i]);
            if (cmp<0){ //Compare current number to first number
                strcpy(element, array[index]); //Send lowest number to the front
                min=index; //Set min to current element for swap
                strcpy(array[min], array[i]); //Swap the current number in array w/ the first number
                strcpy(array[i], element); //Swap the first number w/ the current number in array
            }
        }
    }
}

void print(const char array[][COLMAX],int row,int col){
    for(int i=0;i<row;i++){
        cout<<array[i]<<endl; //Cout the entirety of the array, separated by rows
    }
}