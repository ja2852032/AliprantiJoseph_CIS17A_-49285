/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on September 7th, 2020, 7:00 PM
 * Purpose:  Sort the array of strings, then search through
 *          it using a Binary Search
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string> //String Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int bSearch(string[], int, string);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    //Number of elements in the array
    const int NUM = 20;
    //String of names stored in array called "names"
    string names[NUM] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                               "James, Jean", "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };
    
    //Variables for the selection sort algorithm
    int scan, min;
    //String variable to store name for sorting
    string minVal;
    //String variable for user input
    string search;
    //Integer variable to receive results from binary search
    int checked;
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Beginning of selection sort
    for(scan=0;scan<(NUM-1);scan++)
    {
        min=scan; //Set min to current iteration of scan, starting at element 0
        minVal=names[scan]; //Store name residing in current element
        for(int index=scan +1;index<NUM;index++)
        {
            if (names[index]<minVal) //Compare current name to current value
            {
                minVal=names[index]; //Send lowest string to the front
                min=index;
            }
        }
        names[min]=names[scan];
        names[scan]=minVal;
    }
    
    //Display the Inputs/Outputs
    //Retrieve string input for name
    cout<<"Enter the name of the person you are searching for: ";
    getline(cin, search); //cin the line, including whitespace until new line
    
    checked=bSearch(names, NUM, search); //Call the binary search function, pass parameters
    
    if (checked == -1) //If name not found
	cout<<"The name "<<search<<" is not in the list"<<endl;
    else //Name found on the list, output the name and element it was found in
	cout<<"The name "<<search<<" is in position number "
            <<checked + 1<< " of the list"<<endl;
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
int bSearch(string array[], int elem, string name)
{
    int first = 0;  // First element of list
    int last = elem - 1;  // last element of the list
    int middle; //current middle value
    
    while (first <= last)
    {
        middle = (first + last) / 2;

        if (array[middle] == name)
            return middle;  // if name found in middle, function is complete

        else if (array[middle] > name)
            last = middle - 1;	//cut off second half of the array, search the first half

        else
            first = middle + 1;	//cut off first half of array, search the second half
    }

    return -1;	//Name not in array, return -1
}