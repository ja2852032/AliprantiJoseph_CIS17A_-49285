/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 30th, 2020, 6:20 PM
 * Purpose:  Dynamically allocate values from one 2-D array into
             a 2-D augmented array with an extra row and column of 0's
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int **getData(int &,int &);                 //Get the Matrix Data
void prntDat(const int * const *,int,int); //Print the Matrix
int **augment(const int * const *,int,int); //Augment the original array
void destroy(int **,int);                   //Destroy the Matrix, i.e., reallocate memory

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int rows=0,
        cols=0;
    
    int **array=getData(rows,cols);
    
    int **augAry=augment(array,rows,cols);
    
    //Display the Inputs/Outputs
    prntDat(array,rows,cols);
    cout<<endl;
    prntDat(augAry,rows+1,cols+1);

    //Clean up the code, close files, deallocate memory, etc....
    destroy(array,rows);
    destroy(augAry,rows+1);
    //Exit stage right
    return 0;
}

int **getData(int &rows,int &cols){
    int num;

    cin>>rows>>cols;  //Read in the rows and columns for 2-D array
    
    int **arr=new int*[rows];  //Create dynamic 2-D array
    for(int r=0;r<rows;r++)
        arr[r]=new int[cols];  //Create the dynamic array of columns to reside in the 2-D array
    
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            cin>>num;
            arr[r][c]=num;  //Read in the numbers into the array
        }
    }
    
    return arr;  //Return the array
}

int **augment(const int * const *array,int rows,int cols){
    int **augAry=new int*[rows+1];  //Create dynamic augnmented 2-D array
    for(int r=0;r<rows+1;r++)
        augAry[r]=new int[cols+1];  //Create the dynamic augmented array of columns to reside in the 2-D array
    
    for(int r=1;r<rows+1;r++){
        for(int c=1;c<cols+1;c++){
            augAry[r][c]=array[r-1][c-1];  //Copy the contents of the passed array into the augmented array, shifted down a row and column
        }
    }
    
    int i=0;
    for(int c=0;c<cols+1;c++)
        augAry[i][c]=0;  //Input 0's into the entire first row of the augmented array (by columns)
    for(int r=0;r<rows+1;r++)
        augAry[r][i]=0;  //Input 0's into the entire first column of the augmented array (by rows)
        
    return augAry;
}

void prntDat(const int* const *array,int rows,int cols){
    int n=0;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols-1;c++){
            cout<<array[r][c]<<" "; //Print the 2-D arrays
        }
        n++;
        cout<<array[r][cols-1]; //Print the last value of each row
        if(n==cols-1)
            return; //If detected the last value of augmented array, return to avoid the last end line
        cout<<endl;
    }
}

void destroy(int **array,int rows){
    for(int r=0;r<rows;r++)
        delete []array[r];  //Delete the data from the array created for columns
        
    delete []array;  //Delete the leftover data in the main array
}