/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on December 16th, 2020, 5:50 AM
 * Purpose:  Augment the table input by the user with the sum of all rows
 *           and columns
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
#include "Prob3TableInherited.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Execution of Code Begins Here
int main(int argc, char** argv) {
    
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    
    for(int i=0;i<rows;i++)
    {
	for(int j=0;j<cols;j++)
	{
            cout<<naugT[i*cols+j]<<" ";
	}
	cout<<endl;
    }
    cout<<endl;
    
    const int *augT=tab.getAugTable();
    
    for(int i=0;i<=rows;i++)
    {
	for(int j=0;j<=cols;j++)
	{
            cout<<augT[i*(cols+1)+j]<<" ";
	}
	cout<<endl;
    }
    
    return 0;
}