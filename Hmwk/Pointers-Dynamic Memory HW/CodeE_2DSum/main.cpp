/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 30th, 2020, 5:10 PM
 * Purpose:  Total the elements in a 2-D array
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int **getData(int &,int &);               //Return the 2-D array and its size.
void prntDat(const int* const *,int,int); //Print the 2-D Array
void destroy(int **,int);                 //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int rows=0,
        cols=0;
    
    int **array=getData(rows,cols);

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    prntDat(array,rows,cols);

    int total=sum(array,rows,cols);
    cout<<total; //Print the total sum of the 2-D array
    
    //Clean up the code, close files, deallocate memory, etc....
    destroy(array,rows);
    
    //Exit stage right
    return 0;
}

int **getData(int &rows,int &cols){
    int num;

    cin>>rows>>cols;  //Read in rows and columns for array
    
    int **arr=new int*[rows];  //Create dynamic 2-D array
    for(int r=0;r<rows;r++)
        arr[r]=new int[cols];  //Create the dynamic array of columns to reside in the 2-D array
    
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            cin>>num;
            arr[r][c]=num; //Input numbers into the 2-D array
        }
    }
    
    return arr; //Return the array
}

void prntDat(const int* const *array,int rows,int cols){
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols-1;c++){
            cout<<array[r][c]<<" "; //Print the 2-D array's values up to the value at the end of the row
        }
        cout<<array[r][cols-1]<<endl; //Print value at the end of the row, and end line
    }
}

int sum(const int * const *array,int rows,int cols){
    int total=0;
    
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            total+=array[r][c]; //Increment the sum of each value in the 2-D array
        }
    }
    
    return total; //Return the sum
}

void destroy(int **array,int rows){
    for(int r=0;r<rows;r++)
        delete []array[r]; //Delete the data from the array created for columns
        
    delete []array; //Delete the leftover data in the main array
}