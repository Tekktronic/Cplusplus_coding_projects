/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on May 7, 2014, 10:15 AM
 */

//Libraries
#include <iostream>
#include <cstring>
using namespace std;

//Global variables and constants
const int SIZE = 20;

//Function prototypes

//Execution begins HERE
int main(int argc, char** argv) {
    //declare variables
    int ctr = SIZE - 1;     //iterator for looping through the array
    char BigNum[SIZE] = {'0'};  //array of 20 characters max
    //Loop through the array
    do{
        cin.get(BigNum, '\n');                                        //stub to display entries into array
        cout << "BigNum[" << ctr << "]: " << BigNum[ctr] << endl;   //*NOTE: Does not display the leftmost digit!!! Refine this!
        ctr--;
    }while(ctr >= 0);
    return 0;
}

