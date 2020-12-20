/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on December 15th, 2020, 4:50 PM
 * Purpose:  Create a class that returns a random number, looped
 *           100,000 times
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
#include "Prob1Random.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Execution of Code Begins Here
int main(int argc, char** argv) {
    
    char n=5;
    char rndseq[]={19,34,57,79,126};
    int ntimes=100000;
    
    Prob1Random a(n,rndseq);
    
    for(int i=1;i<=ntimes;i++)
    {
	a.randFromSet();
    }
    
    int *x=a.getFreq();
    char *y=a.getSet();
    
    for(int i=0;i<n;i++)
    {
	cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;

    return 0;
}