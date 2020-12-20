/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on December 16th, 2020, 4:50 PM
 * Purpose:  Convert the given decimal numbers into the requested
 *           numbering and scaled binary systems
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    cout<<"1) 3.75 base 10 is 11.11 base 2, 3.8 base 8, and 3.C base 16"<<endl;
    cout<<"1) 0.7 base 10 is 0.10110 base 2 (0110 repeating), 0.54631 base 8 (4631 repeating),"<<endl
            <<"and 0.B3 base 16 (3 repeating)"<<endl;
    cout<<"1) 89.9 base 10 is 1011001.1110110 base 2 (0110 repeating), 131.73146 base 8 (3146 repeating),"<<endl
            <<"and 59.E6 base 16 (6 repeating)"<<endl;
    cout<<"2) 3.75 base 10 in NASA hex float is 78000002 base 16"<<endl;
    cout<<"2) 0.7 base 10 in NASA hex float is 59999A00 base 16"<<endl;
    cout<<"2) 89.9 base 10 in NASA hex float is 59ECCD07 base 16"<<endl;
    cout<<"No 3) and 4)"<<endl;
    cout<<"5) 3.75 base 10 in IEEE 754 is 40700000 base 16"<<endl;
    cout<<"5) 0.7 base 10 in IEEE 754 float is 3FB33333 base 16"<<endl;
    cout<<"5) 89.9 base 10 in IEEE 754 float is 4033D99A base 16"<<endl;
    
    return 0;
}