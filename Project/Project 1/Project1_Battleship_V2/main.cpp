/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 16th, 2020, 4:25 PM
 * Purpose:  Create a game of Battleship between the user and the computer
 * 
 * Version 2: Use the computer's grid that the user cannot see, for the user
 *            to get feedback on their attempts of sinking the computer's ships.
 *            Take a guess from the user and the computer to begin the framework
 *            for the primary operation of the game.  Display if either player hit 
 *            or missed, to be looped through in the following version. Also perform
 *            basic input validation for the guesses.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>  //File Stream Library
#include <string.h> //Char Array Manipulation Library
#include <cctype> //For toupper operation
#include <ctime> //For rand operation
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants
const int COLS = 11;

//Function Prototypes
void mkGrids(char [][COLS],const int); //Create the grid framework
void intro(char [][COLS],char [][COLS],char [],const int); //Display intro text
void prnGrid(char [][COLS],char [],const int); //Print grids
void plShips(char [][COLS],const int,ifstream &); //Place the ships on the grids
int conv(char &); //Convert char input into integer to search through arrays
char revConv(int &); //Reverse convert int input into char to display guess
int match(const int [],const int,const int); //P1 of matching input for ship placement
int match2(const char [][COLS],const int,const int,const int); //P2 of matching input for ship placement
void play(char [][COLS],char [][COLS],char [][COLS],const int); //Function stepping through game
int hitOrNo(char [][COLS],const int,const int); //Determine if hit or miss


//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    
    //Declare all variables for this function
    ifstream inFile;
    const int MAX = 10;
    char topGrid[MAX]={'A','B','C','D','E','F','G','H','I','J'}; //x-axis of grid
    char usrGrid[MAX][COLS]; //Define user grid
    char comGrid[MAX][COLS]; //Define computer grid
    char tarGrid[MAX][COLS]; //Define target grid
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    mkGrids(usrGrid,MAX);
    mkGrids(comGrid,MAX);
    mkGrids(tarGrid,MAX);
    
    //Display the Inputs/Outputs
    intro(usrGrid,comGrid,topGrid,MAX);
    
    cout<<"My Grid"<<endl;
    plShips(usrGrid,MAX,inFile);
    plShips(comGrid,MAX,inFile);
    prnGrid(usrGrid,topGrid,MAX);
    cout<<endl<<"Target Grid"<<endl;
    prnGrid(tarGrid,topGrid,MAX);
    cout<<endl;

    play(usrGrid,tarGrid,comGrid,MAX);

    //Cout updated grids to check for desired performance
    cout<<"My Grid"<<endl;
    prnGrid(usrGrid,topGrid,MAX);
    cout<<endl<<"Target Grid"<<endl;
    prnGrid(tarGrid,topGrid,MAX);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void mkGrids(char grid[][COLS],const int rows){
    int lBound=47, //Set to ASCII decimal of the char before 0
        first=0;
    for(int r=0;r<rows;r++){
        lBound++;
        grid[r][first]=lBound; //y-axis of grid made up of numbers in the char array
        for(int c=1;c<COLS;c++){
            grid[r][c]='+'; //Fill rest of grid with +'s
        }
    }
}

void intro(char usrGrid[][COLS],char comGrid[][COLS],char topGrid[],const int MAX){
    //Introductory comments, displaying basic rules and objectives of the game
    //and how it will run
    cout<<"Welcome to the game of Battleship!"<<endl<<endl<<
            "Here you will play against a computer, taking turns guessing where"<<endl<<
            "eachother's opponent has placed their ships, with the objective of sinking"<<endl<<
            "each ship. A ship is sank when every grid point that the ship resides"<<endl<<
            "on has been hit. Whichever player sinks the entirety of the opponent's"<<endl<<
            "fleet wins the game. Your ships will be marked with o's, and every time"<<endl<<
            "a part of your ship is hit, it will be marked as an x. Your guesses will"<<endl<<
            "come up as an x if you made a hit, or an m if you missed your opponent."<<endl<<endl;

    //Comments leading to the display of the starting version of user's grid
    //and target grid
    cout<<"Here is your grid ('My Grid'), as well as the grid where you guess the"<<endl<<
            "location of your opponent's ships ('Target Grid'). You both will have"<<endl<<
            "your ships set up on the grid randomly, so you may begin playing."<<endl<<endl;
    
}

void prnGrid(char grid[][COLS],char top[],const int rows){
    cout<<" ";
    for(int i=0;i<rows;i++)
        cout<<" "<<top[i]; //Format the top x-axis of the grid
    cout<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<COLS;j++){
            cout<<grid[i][j]<<" "; //Format the rest of the grid below
        }
        cout<<endl;
    }
}

void plShips(char grid[][COLS], const int rows, ifstream &file){
    file.open("ships.txt");
    int max=6, //Max length of char array if including null terminator
        ships=5, //Number of ships used for game
        size=0, //Size of ship, determined when read from file
        r=0, //Initializing rows
        c=0, //Initializing columns
        j=0, //Initializing increment variable for 1st part of if/else
        k=0; //Initializing increment variable for 2nd part of if/else
    int test,
        test1;
    int *rTaken=new int[max-1]; //1D Dynamic Array to hold random row designations as they come
    for(int i=0;i<(max-1);i++)
        rTaken[i]=0; //Fill array with 0's to be out of range of the flag
    char ship[max]; //Char array to get input from file

    
    if(file){
        for(int i=0;i<ships;i++){
            file.getline(ship,max); //Read line from file
            size=strlen(ship);  //Determine size of line to get the size of ship
            if(size>3){
                r=rand()%9+0; //Random row from 0 to 9 to avoid exceeding grid
                test=match(rTaken,(max-1),r); //Compare coordinate to array to avoid overlapping ships
                if(test==-1){
                    while(test==-1){
                        r=rand()%9+0; //Repeat of lines 143/144 until open to place ship on grid
                        test=match(rTaken,(max-1),r);
                    }
                }
                rTaken[j]=r; //Update the dynamic array with a new value to compare with after each iteration
                c=rand()%6+1; //Random column from 1 to 6 to stay within grid
                for(int i=c;i<(c+size);i++)
                    grid[r][i]='o'; //Add current ship to the grid
                j++;
            }
            else{
                c=rand()%10+1; //Random column from 1 to 10 to stay within grid
                r=rand()%7+0; //Random row from 0 to 7 to stay within grid
                test=match2(grid,rows,r,c); //Compare random coordinates to coordinates already occupied
                if(test==-1){
                    while(test==-1||test1==-1){
                        c=rand()%10+1; //Repeat lines 158/159/160
                        r=rand()%7+0;
                        test=match2(grid,rows,r,c);
                    }
                }
                for(int i=r;i<(r+size);i++)
                    grid[i][c]='o'; //Add current ship to the grid
                k++;
            }
        }
    }
    file.close(); //Close file
    delete []rTaken; //Deallocate memory from dynamic array
}

int conv(char &a){
    char b=toupper(a); //Make every character capitalized
    int r=static_cast<int>(b-64); //Subtract from decimal ASCII value to get grid axis
    return r;
}

char revConv(int &a){
    int b=a+64; //Add 64 to find char correspondent
    char r=static_cast<char>(b); //Cast the decimal int as a char
    return r;
}

int match(const int array[],const int tot,const int n){
    int ret=n;
    for(int i=0;i<tot;i++){
        if(n==array[i])
            ret=-1;  //If random coordinate already used/placed in array, return -1
    }
    return ret;
}

int match2(const char grid[][COLS],const int max,const int r,const int c){
    int ret=0;
    if(grid[r-1][c]=='o'||grid[r][c]=='o'||grid[r+1][c]=='o'||grid[r+2][c]=='o'||grid[r+3][c]=='o')
        ret=-1;  //If random coordinates are already used/placed in array, return -1
    if(grid[r-1][c+1]=='o'||grid[r][c+1]=='o'||grid[r+1][c+1]=='o'||grid[r+2][c+1]=='o'||grid[r+3][c+1]=='o')
        ret=-1;  //If random coordinates are already used/placed in array, return -1
    if(grid[r-1][c-1]=='o'||grid[r][c-1]=='o'||grid[r+1][c-1]=='o'||grid[r+2][c-1]=='o'||grid[r+3][c-1]=='o')
        ret=-1;  //If random coordinates are already used/placed in array, return -1
    return ret;
}

void play(char uGrid[][COLS],char tGrid[][COLS],char cGrid[][COLS],const int rows){
    int r, //Row input
        c, //Column input
        hit; //Get return from hitOrMiss
    char cChar; //Hold char to switch between integer values
    
    cout<<"User starts. Guess the location of an enemy ship!"<<endl<<
            "Enter the x-coordinate (Letter A through J, not case sensitive): ";
    cin>>cChar;
    if(cChar<65||cChar>74&&cChar<97||cChar>106){ //If char received is not decimal representation of A to J
        while(cChar<65||cChar>74&&cChar<97||cChar>106){
            cout<<"Not a valid x-coordinate. Please enter a letter A through J: ";
            cin>>cChar;
        }
    }
    c=conv(cChar); //Convert char to integer
    cout<<"Enter the y-coordinate (Number 0 through 9): ";
    cin>>r;
    if(r<0||r>9){ //If integer received is not between 0 and 9
        while(r<0||r>9){
            cout<<"Not a valid y-coordinate. Please enter a number 0 through 9: ";
            cin>>r;
        }
    }
    
    cout<<endl;
    hit=hitOrNo(cGrid,r,c); //Call function to determine if guess is a hit or not
    if(hit!=-1){
        cout<<"You have hit an enemy boat at ("<<cChar<<
                ","<<r<<")!"<<endl;
        tGrid[r][c]='x'; //Mark x for hit in target grid
    }
    else{
        cout<<"You missed at ("<<cChar<<","<<r<<")."<<endl;
        tGrid[r][c]='m'; //Mark m for miss in target grid
    }
    
    c=rand()%10+1; //Computer picks random y-axis between 1 and 10
    cChar=revConv(c); //Convert y-axis integer to char
    r=rand()%9+0; //Computer picks random x-axis between 0 and 9
    
    hit=hitOrNo(uGrid,r,c); //Call to determine if guess is hit or miss
    if(hit!=-1){
        cout<<"The computer has hit your boat at ("<<cChar<<
                ","<<r<<")!"<<endl;
        uGrid[r][c]='x'; //Mark x in user's grid if user ship is hit
    }
    else
        cout<<"The computer missed at ("<<cChar<<","<<r<<")."<<endl<<endl;
}

int hitOrNo(char grid[][COLS],const int row,const int col){
    int ret=1;
    if(grid[row][col]=='o') //If part of ship resides in the guessed coordinate
        grid[row][col]=='x'; //Mark x in grid if ship is hit
    else
        ret=-1; //Return -1 if miss
    return ret;
}
