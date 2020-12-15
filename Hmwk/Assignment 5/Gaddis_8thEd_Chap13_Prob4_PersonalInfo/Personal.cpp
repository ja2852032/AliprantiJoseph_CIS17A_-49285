/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 11th, 2020, 8:45 PM
 * Purpose: PersonalInfo class functions.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>  //String Library
using namespace std;

//User Libraries
#include "Personal.h"

void PersonalInfo::getData(string n, string add, int a, long int num){
    name=n;
    addr=add;
    age=a;
    number=num;
}

void PersonalInfo::prnData(){
    cout<<"Name: "<<name<<", Address: "<<addr<<", Age: "<<age<<", Phone Number: "<<number<<endl;
}