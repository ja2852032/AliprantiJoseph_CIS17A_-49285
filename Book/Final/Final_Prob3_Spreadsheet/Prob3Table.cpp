/* 
 * File:   Prob3Table.cpp
 * Author: Joseph Alipranti
 * Created on December 16th, 2020, 7:35 AM
 * Purpose: Functions for Prob3Table class
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> //I/O Manipulator
#include <fstream> //File library

using namespace std;

//User Libraries
#include "Prob3Table.h"

template<class T>
Prob3Table<T>::Prob3Table(string file,int r,int c){
    rows=r;
    cols=c;
    table=new T[rows*cols];
    rowSum=new T[rows];
    colSum=new T[cols];
    grandTotal=0;
    int i=0;
    ifstream inFile;
    inFile.open(file,ios::in);
    
    while(!inFile.eof()){
        inFile>>table[i];
        i++;
    }
    
    
}

template<class T>
void Prob3Table<T>::calcTable(){
    int sumR=0;
    int sumC=0;
    
    for(int j=0;j<rows;j++){
        for(int k=0;k<cols;k++)
            sumR+=table[j*10+k];
        rowSum[j]=sumR; 
        sumR=0; 
    }
    
    for(int j=0;j<cols;j++){
        for(int k=0;k<rows;k++)
            sumC+=table[k*10+j];
        colSum[j]=sumC; 
        sumC=0; 
    }
}
