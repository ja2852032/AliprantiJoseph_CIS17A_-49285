/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on December 16th, 2020, 1:30 PM
 * Purpose:  Get personal and work information for workers, and
 *           determine how much their pay and taxes are
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
#include "Employee.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

int main(int argc, char** argv) {
    
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
    
    return 0;
}