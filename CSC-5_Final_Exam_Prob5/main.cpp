/* 
 * File:   main.cpp
 * Author: tekktronic
 * Final #5
 * Created on June 10, 2014, 8:57 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
//Global variables and constants

//Function prototypes
char **fillAR(int&, int&);      //returns a pointer to a 2D array of characters
void printAR(char**, int&, int&);       //prints the array
char **sortAR(char**, int&, int&);      //sort the array using insertion sort
bool compAR(char*, char*, int&);    //compare 2 arrays
void Destroy(char**, int&, int&);       //deletes the 2d array
//Execution begins HERE
int main(int argc, char** argv) {
    int row = 10; //number of rows
    int col = 15; //number of columns
    char **ar_char;
    //fill the array and set the pointer to the address of the array
    ar_char = fillAR(row, col);
    //print the 2D array
    cout << "\nUnsorted array:\n";
    printAR(ar_char, row, col);
    //sort the 2D array
    cout << "\nSorted array:\n";
    sortAR(ar_char, row, col);
    //print the sorted 2D array
    printAR(ar_char, row, col);
    //delete the 2D array
    Destroy(ar_char, row, col);
    return 0;
}
char **fillAR(int &row, int &col){
    //declare the stream to read the input from a file
    fstream fin;
    //open the file to read
    fin.open("input.dat", ios::in);
    //create the 2d array
    char **ar_char;
    ar_char = new char*[row];
    for(int idx = 0; idx < row; idx++){
        ar_char[idx] = new char[col];
    }
    //read the contents of the file into the 2d array
    cout << "Reading the file:\n";
    for(int idx = 0; idx < row; idx++){
        for(int ctr = 0; ctr < col; ctr++){
            fin >> ar_char[idx][ctr];
        }
    }
    //close the file
    fin.close();
    //return a pointer to the array
    cout << "Done!\n";
    return ar_char;
}
void Destroy(char **ar_char, int &row, int&col){
    for(int idx = 0; idx < row; idx++){
        delete[] ar_char[idx];  //deletes the col array
    }
    delete[] ar_char;   //deletes the row array
}
void printAR(char **ar_char, int &row, int &col){
    for(int idx = 0; idx < row; idx++){
        for(int ctr = 0; ctr < col; ctr++){
            cout << ar_char[idx][ctr];
        }
        cout << endl;
    }
}
char **sortAR(char **ar_char, int &row, int &col){
    for(int idx = 0; idx < row; idx++){
        int pos = idx;    //position in the array being compared against
        int nxt = pos + 1;      //position in the array currently being checked
        //insertion sort
        while(nxt <= row-1 && pos >= 0){
            //compare the strings. if they are out of order, swap them and decrement the markers pos & nxt
            if(strncmp(ar_char[pos], ar_char[nxt], col) < 0){
                for(int ctr = 0; ctr < col; ctr++){
                    char tmp;
                    tmp = ar_char[pos][ctr];
                    ar_char[pos][ctr] = ar_char[nxt][ctr];
                    ar_char[nxt][ctr] = tmp;
                }
                nxt--;
                pos--;
            }
            else break;
        }
    }
}
