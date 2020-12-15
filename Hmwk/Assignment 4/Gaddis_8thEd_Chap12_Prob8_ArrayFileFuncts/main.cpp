/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 17th, 2020, 7:35 PM
 * Purpose: //Write an array to a binary file, read back the array from the 
 *            binary file, and output to make sure it works
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream> //File Stream Library
#include <cstring> //Char Manipulation Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void arrayToFile(fstream &,char *,int); //Send the array to binary file
void fileToArray(fstream &,char *,int); //Get data from binary file, store in array

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    fstream binFile; //Initialize the file variable
    int MAX = 20; //Max char count
    int size;
    char array1[MAX], //Array sending data to file
         array2[MAX]; //Array getting data from file
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objective
    
    //Display the Inputs/Outputs
    cout<<"Enter a sentence fewer than 20 characters: ";
    cin.get(array1,MAX);
    size=strlen(array1); //Size = the length of characters entered by user
    
    arrayToFile(binFile,array1,size);
    fileToArray(binFile,array2,size);

    cout<<endl<<array2;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations

void arrayToFile(fstream &binFile,char *arr,int size){
    binFile.open("file.bin",ios::out|ios::binary); //Prime the file for output, binary mode
    
    //First write number of chars to binary file
    binFile.write(reinterpret_cast<char *>(&size),sizeof(int)); 
    //Then send char data to file
    binFile.write(arr,size*sizeof(char));
    binFile.close();
}
void fileToArray(fstream &binFile,char *arr,int size){
    binFile.open("file.bin",ios::in|ios::binary); //Prime the file for input, binary mode
    
    //First read number of chars from binary file
    binFile.read(reinterpret_cast<char *>(&size),sizeof(int));
    //Then get char data from file
    binFile.read(arr,size*sizeof(char));
    binFile.close();
}