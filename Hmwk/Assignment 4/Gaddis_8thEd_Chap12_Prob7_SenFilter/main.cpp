/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 15th, 2020, 4:35 PM
 * Purpose: Open an input and output file, and transfer sentences from one file to
 *          the other with slight character modifications
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream> //File Stream Library
#include <cctype> //C-String Library
#include <string> //String Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    string inName,
           outName;
    char letter;
    ifstream inF; //File for input
    ofstream outF; //File for output
    
    //Initialize all known variables
    cout<<"Enter a file name for input: ";
    cin>>inName; //Get name of file for input
    cout<<"Enter a file name for output: ";
    cin>>outName; //Get name of file for output
    
    inF.open(inName);
    outF.open(outName);
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    
    if(inF){ //If file is opened
        inF.get(letter);
        do{
            if(isspace(letter)){ //If space detected, send to file and get next character
                outF.put(letter);
                inF.get(letter);
            }
            outF.put(toupper(letter)); //Output the capitalized first letter of sentence
            while(letter!='.'){ //Loop until period is detected
                inF.get(letter);
                outF.put(tolower(letter)); //Output lowercase letters
            }
            inF.get(letter);
        }while(inF); //While file is read
    }
    else
        cout<<"Cannot open an input file by that name.";

    //Clean up the code, close files, deallocate memory, etc....
    inF.close();
    outF.close();
    //Exit stage right
    return 0;
}

//Function Implementations