/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 22, 2020, 10:35PM
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream> //I/O Library
#include <string> //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "Checking.h"
#include "Checking1.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();

Data *getData(int,int);
void disp(Data *,int);
void getInfo(Data1 [],const int);
void prnInfo(Data1 [],int);
void numWord(const float);
int encrypt(int);
int decrypt(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='6');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    cout<<"Problem 1"<<endl;
    
    //Declare all variables for this function
    int size=30;
    int cstmrs;
    cout<<"Enter the number of customers: ";
    cin>>cstmrs;
            
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    Data *array=getData(cstmrs,size);

    //Clean up the code, close files, deallocate memory, etc....
    delete []array;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<"Problem 2"<<endl;
    
    //Declare all variables for this function
    int size;
    
    //Initialize all known variables
    cout<<"Enter the number of employees: ";
    cin>>size;
    cin.ignore();
    Data1 array[size];
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    cout<<endl;
    getInfo(array,size);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3"<<endl;
    cout<<"This problem is included in a separate project."<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    cout<<"problem 4"<<endl;
    
    //Declare all variables for this function
    int data;
    int encData;
    int decData;
    
    //Initialize all known variables
    cout<<"Please enter a 4 digit integer: ";
    cin>>data;
    if(data>9999){
        while(data>9999){
            cout<<"Bad input.  Please enter a 4 digit integer: ";
            cin>>data;
        }
    }
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    encData=encrypt(data);
    cout<<endl<<"Encrypted data: "<<encData<<endl;
    
    decData=decrypt(encData);
    cout<<"Decrypted data: "<<decData<<endl;
}

void prblm5(){
    cout<<"problem 5"<<endl;
    
    cout<<"Largest factorial for signed char: 5"<<endl;
    cout<<"Largest factorial for unsigned char: 5"<<endl;
    cout<<"Largest factorial for short int: 7"<<endl;
    cout<<"Largest factorial for unsigned short int: 8"<<endl;
    cout<<"Largest factorial for int: 12"<<endl;
    cout<<"Largest factorial for unsigned int: 12"<<endl;
    cout<<"Largest factorial for long int: 20"<<endl;
    cout<<"Largest factorial for unsigned long int: 20"<<endl;
    cout<<"Largest factorial for long long int: 20"<<endl;
    cout<<"Largest factorial for unsigned long long int: 20"<<endl;
    cout<<"Largest factorial for float: 34"<<endl;
    cout<<"Largest factorial for double: 170"<<endl;
    cout<<"Largest factorial for long double: 1754"<<endl;
}

void prblm6(){
    cout<<"problem 6"<<endl;
    
    cout<<endl<<"2.875 in decimal is:"<<endl<<
            "10.111 in binary, 2.E in hexadecimal, and 2.7 in octal."<<endl;
    cout<<endl<<"0.1796875 in decimal is:"<<endl<<
            "0.0010111 in binary, 0.2E in hexadecimal, and 0.135 in octal."<<endl<<endl;
    
    cout<<"2.875 represented in hexadecimal from the NASA float format is: 5C000002"<<endl;
    cout<<"0.1796875 represented in hexadecimal from the NASA float format is: 5C0000FE"<<endl;
    
    cout<<"-2.875 represented in hexadecimal from the NASA float format is: A7FFFF02"<<endl;
    cout<<"-0.1796875 represented in hexadecimal from the NASA float format is: A7FFFFFE"<<endl<<endl;
    
    cout<<"The float representation of 59999901 converted back to decimal is: 1.39 (the 9 repeating)"<<endl;
    cout<<"The float representation of 59999902 converted back to decimal is: 2.79 (the 9 repeating)"<<endl;
    cout<<"The float representation of A66667FE converted back to decimal is: -0.1749 (the 9 repeating)"<<endl;
}


Data *getData(int numC,int size){
    int j=2,
        k=2;
    float checks=0;
    Data *arr=new Data[numC];
    
    for(int i=0;i<numC;i++){
        cin.ignore();
        cout<<"Enter the name for custumer #"<<(i+1)<<": ";
        getline(cin,arr[i].name);
        cout<<"Enter the address for customer "<<(i+1)<<": ";
        getline(cin,arr[i].address);
        cout<<"Enter the account number for customer "<<(i+1)<<": ";
        cin>>arr[i].accNum;
        if(arr[i].accNum>99999){
            while(arr[i].accNum>99999){
                cout<<"Please enter a 5 digit number for the account: ";
                cin>>arr[i].accNum;
            }
        }
        cout<<"Enter the account balance at the beginning of the month: ";
        cin>>arr[i].balance;
        cout<<"Enter all of the checks written in the past month, enter 0 when finished"<<endl<<
                "Enter check #1: ";
        cin>>arr[i].totChck;
        do{
            cout<<"Enter check #"<<j<<": ";
            cin>>checks;
            arr[i].totChck+=checks;
            j++;
        }while(checks!=0);
        
        cout<<"Enter all of the deposits received in the past month, enter 0 when finished"<<endl<<
                "Enter deposit #1: ";
        cin>>arr[i].totDep;
        do{
            cout<<"Enter deposit #"<<k<<": ";
            cin>>checks;
            arr[i].totDep+=checks;
            k++;
        }while(checks!=0);
        cout<<endl;
        
        disp(arr,i);
    }
    return arr;
}

void disp(Data *a,int index){
    float newBal;
    string ovr=" ";
    
    cout<<a[index].name<<endl;
    cout<<a[index].address<<endl;
    cout<<a[index].accNum<<endl;
    
    newBal=a[index].balance+a[index].totDep-a[index].totChck;
    if(newBal<0){
        ovr="overdrawn";
        newBal=newBal+(newBal*-2);
    }
    cout<<"With your original balance of $"<<setprecision(2)<<fixed<<a[index].balance<<
            ", total checks written of $"<<a[index].totChck<<", and total deposits made of $"<<
            a[index].totDep<<","<<endl;
    cout<<"you now have a balance of $"<<newBal<<" "<<ovr<<endl;
    
    if(ovr=="overdrawn"){
        cout<<"Since your balance is overdrawn, you will be charged $20 as a penalty."<<endl;
        cout<<"Your new balance with the charge is -$"<<(newBal+20)<<"."<<endl;
    }
    cout<<endl;
    
}


void getInfo(Data1 a[],const int size){
    
    for(int i=0;i<size;i++){
        cout<<"Enter the name of employee #"<<(i+1)<<": ";
        getline(cin,a[i].name);
        cout<<"Enter the number of hours employee #"<<(i+1)<<" has worked: ";
        cin>>a[i].hours;
        cout<<"Enter the hourly pay for employee #"<<(i+1)<<": ";
        cin>>a[i].pay;
        cin.ignore();
        
        if(a[i].hours<0||a[i].hours>168){
            cout<<"You have entered an invalid number of hours."<<endl<<
                    "You cannot have negative hours, or exceed 168 hours in a week.";
            i=size;
        }
        if(a[i].pay<0){
            cout<<"You have entered an invalid number for hourly pay.";
            i=size;
        }
        
        if(i<size)
            prnInfo(a,i);
    }
        
}

void prnInfo(Data1 *a,int index){
    float money;
    if(a[index].hours<=40)
        money=a[index].hours*a[index].pay;
    else if(a[index].hours>40&&a[index].hours<=50)
        money=(40*a[index].pay)+((a[index].hours-40)*(a[index].pay*2));
    else
        money=(40*a[index].pay)+(10*(a[index].pay*2))+((a[index].hours-50)*(a[index].pay*3));
    
    
    cout<<endl<<"Big Fluff Inc."<<endl;
    cout<<"5555 University Ave."<<endl;
    cout<<a[index].name<<"   $"<<setprecision(2)<<fixed<<money<<endl;
    numWord(money);
    cout<<endl<<"*"<<a[index].name<<"'s signature*"<<endl<<endl;
}

void numWord(const float n){
    string number;
    int max=4;
    int teen=0;
    int num=static_cast<int>(n);
    int divide=10000;
    int holdNum;
    
    for(int i=0;i<max;i++){
        holdNum=(num%divide-num%(divide/10))/(divide/10);
        divide/=10;
        
        if(i==0){
            number=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(number!="null"){
                cout<<number<<" Thousand ";
            }
        }
        if(i==1){
            number=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(number!="null"){
                cout<<number<<" Hundred ";
            }
        }
        if(i==2){
            number=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(number!="null"){
                if(holdNum==9||holdNum==7||holdNum==6)
                    cout<<number<<"ty ";
                if(holdNum==8)
                    cout<<"Eighty ";
                if(holdNum==5)
                    cout<<"Fifty ";
                if(holdNum==4)
                    cout<<"Forty ";
                if(holdNum==3)
                    cout<<"Thirty ";
                if(holdNum==2)
                    cout<<"Twenty ";
                if(holdNum==1)
                    teen=-1;
            }    
        }
        if(i==3){
            number=holdNum==9?"Nine":holdNum==8?"Eight":holdNum==7?"Seven":holdNum==6?"Six":holdNum==5?"Five"
                :holdNum==4?"Four":holdNum==3?"Three":holdNum==2?"Two":holdNum==1?"One":"null";
            if(number!="null"){
                if(teen==-1){
                    if(holdNum==9||holdNum==7||holdNum==6||holdNum==4)
                        cout<<number<<"teen";
                    if(holdNum==8)
                        cout<<"Eighteen";
                    if(holdNum==5)
                        cout<<"Fifteen";
                    if(holdNum==3)
                        cout<<"Thirteen";
                    if(holdNum==2)
                        cout<<"Twelve";
                    if(holdNum==1)
                        cout<<"Eleven";
                }
                else
                    cout<<number;
            }
        }
    }
    cout<<" and "<<setprecision(0)<<(n-num)*100<<"/100";
}

int encrypt(int data){
    int newData=0;
    int sum1=0;
    int sum2=0;
    int max=4;
    int divide=10000;
    int mult;
    int holdNum;
    
    mult=1000;
    for(int i=0;i<max;i++){
        holdNum=(data%divide-data%(divide/10))/(divide/10);
        divide/=10;
        
        if(holdNum>7){
            cout<<"A digit exceeding 7 has been detected. Please run the program again"<<
                    " and ignore the output.";
            return 0;
        }
        
        holdNum=(holdNum+5)%8;
        newData+=holdNum*mult;
        mult/=10;
    }
    
    divide=10000;
    holdNum=0;
    mult=10;
    for(int i=0;i<2;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        
        sum1+=holdNum*mult;
        mult*=100;
        divide/=100;
    }
    divide=1000;
    holdNum=0;
    mult=1;
    for(int i=0;i<2;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        
        sum2+=holdNum*mult;
        mult*=100;
        divide/=100;
    }
    
    newData=sum1+sum2;
    return newData;
}

int decrypt(int data){
    int newData=data;
    int n2Data=0;
    int sum1=0;
    int sum2=0;
    int max=4;
    int divide;
    int mult;
    int holdNum;
    
    divide=10000;
    holdNum=0;
    mult=10;
    for(int i=0;i<2;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        
        sum1+=holdNum*mult;
        mult*=100;
        divide/=100;
    }
    divide=1000;
    holdNum=0;
    mult=1;
    for(int i=0;i<2;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        
        sum2+=holdNum*mult;
        mult*=100;
        divide/=100;
    }
    
    newData=sum1+sum2;
    
    divide=10000;
    mult=1000;
    for(int i=0;i<max;i++){
        holdNum=(newData%divide-newData%(divide/10))/(divide/10);
        divide/=10;
        
        if(holdNum>7){
            cout<<"A digit exceeding 7 has been detected. Please run the program again";
            return 0;
        }
        
        holdNum=(holdNum+11)%8;
        n2Data+=holdNum*mult;
        mult/=10;
    }
    
    return n2Data;
}