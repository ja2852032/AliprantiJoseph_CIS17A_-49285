/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on 9/17/2020 at 6:50pm
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    cout<<"Input a table and output the Augment row,col and total sums."<<endl;
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int array[][COLMAX],int &row,int &col){
    cout<<"First input the number of rows and cols. <20 for each"<<endl;
    cin>>row>>col; //Read in both rows and columns
    cout<<"Now input the table."<<endl;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>array[i][j]; //Read integers into 2-D array
}

void sum(const int array[][COLMAX],int row,int col,int augAry[][COLMAX]){
    int sumR=0,
        sumC=0,
        sum=0; // Variables to count the sum of the rows, columns, and everything together
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            augAry[i][j]=array[i][j]; // Copy the array into the same positions of the augmented array
            sum+=array[i][j]; // Sum each row and column
        }
    }
    augAry[row][col]=sum; // Place sum of each row and column into the last row and column of augmented array
            
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            sumR+=array[i][j]; // Sum all the rows
        augAry[i][col]=sumR; // Place the sum of each i'th row into the i'th row of augmented array
        sumR=0; // Clear sumR for the next row
    }
    
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++)
            sumC+=array[j][i]; // Sum all of the columns
        augAry[row][i]=sumC; // Place the sum of each i'th column in the i'th column of augmented array
        sumC=0; // Clear sumC for next column
    }
}

void print(const int array[][COLMAX],int row,int col,int n){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<setw(n)<<array[i][j]; // Cout all of the columns and rows, separated by n spaces in a table format
    cout<<endl;
    }
}