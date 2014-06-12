/* 
 * File:   main.cpp
 * Author: Ezra Guinmapang
 * Final #6
 * Created on June 12, 2014, 3:00 AM
 */

//Libraries
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;
//Global variables and constants

//Function prototypes
void fillVEC(vector< vector<int> >&, int&, int&);       //fill the 2D vector
void printTable(vector< vector<int> >&, int&, int&);      //print the 2D vector
void SumTable(vector< vector<int> >&, vector<int>&, int&, int&);      //print the 2D vector
//Execution begins HERE
int main(int argc, char** argv) {
    //declare variables
    int nrow = 5;        //number of rows
    int ncol = 6;        //number of columns
    int rtotal;         //sums elements from left to right
    //declare vector of ints
    vector<int> cols(ncol);
    //declare vector of vectors
    vector< vector<int> > table;
    for(int idx = 0; idx < nrow; idx++){
        table.push_back(cols);
    }
    //fill the table
    fillVEC(table, nrow, ncol);
    //print the table
    cout << "\nInput Table:\n";
    printTable(table, nrow, ncol);
    //calculate all the sums and append the data to the table
    cout << "Calculating the SUMS...\n";
    SumTable(table, cols, nrow, ncol);
    cout << "Done!\n";
    cout << "Amended Table with Totals:\n";
    //print the augmented table
    printTable(table, nrow, ncol);
    return 0;
}
void fillVEC(vector< vector<int> > &table, int &nrow, int &ncol){
    //declare file streams
    fstream fin;
    //associate file streams with filenames
    fin.open("table.dat", ios::in);
    for(int idx = 0; idx < nrow; idx++){
        for(int ctr = 0; ctr < ncol; ctr++){
            fin >> table.at(idx).at(ctr);
        }
    }
    fin.close();
}
void printTable(vector< vector<int> > &table, int &nrow, int &ncol){
    //declare file streams
    fstream fout;
    //associate file streams with filenames
    fout.open("augtable.dat", ios::out);
    for(int idx = 0; idx < table.size(); idx++){
        for(int ctr = 0; ctr < table.at(idx).size(); ctr++){
            cout << setw(6) << table.at(idx).at(ctr);
            fout << table.at(idx).at(ctr) << " ";
        }
        cout << endl;
        fout << endl;
    }
    fout.close();
}
void SumTable(vector< vector<int> > &table, vector<int> &cols, int &nrow, int &ncol){
    //declare variables
    int rtotal;         //holds the sum of the rows
    table.push_back(cols);       //add another vector for the sums
    for(int idx = 0; idx < table.size(); idx++){
        rtotal = 0;
        for(int ctr = 0; ctr < table.at(idx).size(); ctr++){
            rtotal += table.at(idx).at(ctr);
            if(idx < table.size()-1) table[table.size()-1][ctr] += table[idx][ctr];
        }
        table.at(idx).push_back(rtotal);
    }
}