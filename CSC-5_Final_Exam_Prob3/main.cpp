/* 
 * File:   main.cpp
 * Author: tekktronic
 * Final #3
 * Created on June 10, 2014, 8:57 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;
//Global variables and constants

//Function prototypes
void fillVEC(vector<int>&, vector<int>&, int);
void printVEC(vector<int>&, vector<int>&, int);
//Execution begins HERE
int main(int argc, char** argv) {
    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    int size;   //size to be input by user
    bool isValid = false;
    vector<int> e_int;    //declares a vector of integers
    vector<int> o_int;    //declares another vector of integers
    while(!isValid){
        cout << "Enter the number of elements you want to generate: ";
        cin >> size;
        if(size <= 0){
            cout << "Invalid input! Try again.\n";
        }
        else{
            isValid = true;
        }
    }
    fillVEC(e_int, o_int, size);
    printVEC(e_int, o_int, size);
    return 0;
}
//Function definitions
void fillVEC(vector<int> &e_int, vector<int> &o_int, int size){
    int random;
    while(e_int.size() < size || o_int.size() < size){
        random = (rand()%90)+10;    //generate a random 2-digit number
        if(random%2 == 0 && e_int.size() < size) e_int.push_back(random);
        else if(random%2 != 0 && o_int.size() < size) o_int.push_back(random);
        else continue;
    }
}
void printVEC(vector<int> &e_int, vector<int> &o_int, int size){
    int ncol;   //user input - number of columns to print out
    int ctr;    //counter for printing the next line
    bool isValid = false;       //input validation
    while(!isValid){
        cout << "How many columns do you wish to display(maximum of " << size << "): ";
        cin >> ncol;
        if(ncol > size || ncol <= 0){
            cout << "Invalid input! Try again.\n";
        }
        else{
            isValid = true;
        }
    }
    cout << endl;
    cout << "EVEN INTEGERS:\n";
    ctr = 0;
    for(int idx = 0; idx < size; idx++){
        cout << e_int.at(idx) << " ";
        if(ctr++ % ncol == ncol - 1) cout << endl;
    }
    ctr = 0;
    cout << endl;
    cout << "ODD INTEGERS:\n";
    for(int idx = 0; idx < size; idx++){
        cout << o_int.at(idx) << " ";
        if(ctr++ % ncol == ncol - 1) cout << endl;
    }
}