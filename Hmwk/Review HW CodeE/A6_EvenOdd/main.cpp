/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created 9/15/2020 at 7:00pm
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    even.clear();
    odd.clear();
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd){
    int total, num;
    cout<<"Input the number of integers to input."<<endl;
    cin>>total; // Read in total amount of numbers to receive
    cout<<"Input each number."<<endl;
    for(int i=0;i<total;i++){
        cin>>num; // Read in 1 number at a time
        if(num%2==0) // If number is divisible by 2, it is even
            even.push_back (num); // Add even number to vector, while adding an element
        else // If not divisible by 2, then it is odd
            odd.push_back (num); // Add odd number to vector, while adding an element
    }
}

void copy(vector<int> even, vector<int> odd,int array[][COLMAX]){
    int rows=even.size(); // Default size of row to either vector size (in this case, even)
    if(odd.size()>rows) // Compare size of row to the other vector (in this case, odd)
        rows=odd.size();
    for(int i=0;i<rows;i++){
        array[i][COLMAX-1]=even[i]; // Read in even numbers into the first column of the array
        array[i][COLMAX]=odd[i]; // Read in odd numbers into the second column of the array
    }
}

void prntVec(vector<int> even, vector<int> odd,int n){
    int largest=even.size(); // Same as previous function, set default size of largest to size of even
    if(odd.size()>largest) // Compare odd size to largest, and if greater, set largest to size of odd
        largest=odd.size();
       
    cout<<"    Vector      Even"<<setw(n)<<"Odd"<<endl;
    for(int i=0;i<largest;i++){
        cout<<setw(20);
        if(i<even.size())
            cout<<even[i]<<setw(n); // For as many elements that vector even has, output the values
        else
            cout<<" "<<setw(n); // If counter i is GE to the size of vector even, output a space
        if(i<odd.size())
            cout<<odd[i]<<endl; // For as many elements that vector odd has, output the values
        else
            cout<<" "<<endl; // If counter i is GE to the size of vector odd, output a space
    }
}

void prntAry(const int array[][COLMAX],int even,int odd,int n){
    cout<<"     Array      Even"<<setw(n)<<"Odd"<<endl;
    int largest=even; // Same initialization of integer largest as previous functions
    if(odd>largest)
        largest=odd;
        
    for(int i=0;i<largest;i++){
        cout<<setw(20);
        if(i<even)
            cout<<array[i][COLMAX-1]<<setw(n); // For as many elements that array has in first column, output the values
        else
            cout<<" "<<setw(n); // If counter i is GE to the size of first column of array, output a space
        if(i<odd)
            cout<<array[i][COLMAX]<<endl; // For as many elements that array has in second column, output the values
        else
            cout<<" "<<endl; // If counter i is GE to the size of second column of array, output a space
    }
}