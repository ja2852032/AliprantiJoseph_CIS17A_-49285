/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on December 16th, 2020, 6:40PM
 * Purpose:  Menu using Functions,
 *           extend for final
 */

//System Libraries
#include <iostream> //I/O Library
#include <string> //String Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "Prob1Random.h"
#include "Employee.h"

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
            case '0':cout<<"Exiting the Menu"<<endl;break;
            default: cout<<"Invalid Input. Ending Program"<<endl;
        }
    }while(choice>='1'&&choice<='6');
    
    //Exit stage right!
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 0 to exit the program"<<endl<<endl;
}

void prblm1(){
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
}

void prblm2(){
    cout<<"Problem 2 could not be completed"<<endl;
}

void prblm3(){
    cout<<"Problem 3 could not be completed, however, I have attached the my code for Problem 3 in the zip"<<endl
            <<"folder if you wanted to check out the unusual error I was receiving and could not fix"<<endl;
}

void prblm4(){
    cout<<"Problem 4 was not completed (spent too much time trying to fix Problem 3, ran out of time)"<<endl;
}

void prblm5(){
    cout<<"EC: Exception Handling, starting at line 54 of Employee.cpp"<<endl<<endl;
    
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
	Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
	Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
	Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
	Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
	Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
	Mary.setHoursWorked(60));
    Mary.toString();
}

void prblm6(){
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
}