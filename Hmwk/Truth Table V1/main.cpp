/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on: 9/13/2020 at 12:40pm
 * Purpose:  To tell the Truth
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x,y;
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
          
    
    //All four rows in a loop
    while(cin>>x>>y)
    {
        cout<<(x?'T':'F')
            <<setw(2)<<(y?'T':'F') 
            <<setw(3)<<(!x?'T':'F') 
            <<setw(3)<<(!y?'T':'F') 
            <<setw(4)<<(x&&y?'T':'F') 
            <<setw(5)<<(x||y?'T':'F') 
            <<setw(4)<<(x^y?'T':'F') 
            <<setw(5)<<(x^(y^x)?'T':'F') 
            <<setw(6)<<(x^(y^y)?'T':'F') 
            <<setw(8)<<(!(x&&y)?'T':'F') 
            <<setw(7)<<(!x||!y?'T':'F') 
            <<setw(9)<<(!(x||y)?'T':'F') 
            <<setw(7)<<(!x&&!y?'T':'F') 
            <<endl;
    }
    
    cout<<endl;

    //Exit
    return 0;
}