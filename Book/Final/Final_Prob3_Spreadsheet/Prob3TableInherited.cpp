/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> //I/O Manipulator
#include <fstream> //File library
using namespace std;

//User Libraries
#include "Prob3TableInherited.h"

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(string file,int r,int c){
    //Prob3Table<T> a(file,r,c);
    Prob3Table<T> a;
    
    T *rowS=a.getRowSum();

    T *colS=a.getColSum();
    
    augTable=new T[(r+1)*(c+1)];
    
    for(int i=0;i<r;i++)
        augTable[i*10+c]=rowS[i];
    
    for(int i=0;i<c;i++)
        augTable[c*10+i]=colS[i];
    
    delete []rowS;
    delete []colS;
}

