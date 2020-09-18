/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on 9/17/2020 at 3:00pm
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;

    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

bool inRange(const char digits[],unsigned short &unShort){
    int compare=0;
    int num=0;
    int tens=1;
    
    if(strlen(digits)>5) //Values in array cannot exceed a total 2^16 as a short int, so more than 5 digits is too large
        return 0;
    for(int i=(strlen(digits)-1);i>=0;i--){
        num=digits[i]; //Decrement by i for calculation on line 74
        if(num>47&&num<58)
            num-=48; //Subtracting ASCII decimal location from num to get integer value
        else
            return 0; //If num is not between decimal values of 47 and 58, then it is not a number
            
        compare=compare + (num*tens); //Multiply numbers from right to left by tens power increment, store in compare
        tens*=10; //perform 10^x
    }

    if(compare<0||compare>65535) //If integer stored in compare is not within range of unsigned short, return 0
        return 0;
        
    unShort=compare; //unsigned short = compare
    return 1; //Return 1 for true
}

bool reverse(unsigned short unShort,signed short &snShort){
    int holdNum=0;
    int calc;
    int divide=100000;
    int mult=1;
    
    for(int i=0;i<5;i++){
        calc=0;
        calc=(unShort%divide-unShort%(divide/10))/(divide/10); //Operation to turn unsigned short into 5 single digit numbers

        holdNum+=calc*mult; //Reverse multiply by 10^x, store into integer holdnum
        divide/=10; //Decrement division operator
        mult*=10; //Increment multiplication operator
    }

    if(holdNum<-32768||holdNum>32767) //If value of holdNum not in range of signed short, return 0
        return 0;
    
    snShort=holdNum; //Signed short = holdNum
        
    return 1; //Return 1 for true
}

short subtrct(signed short snShort,int n){
    snShort-=n; //Subtract n (999) from signed short
    return snShort; //Return value after subtraction
}