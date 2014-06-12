/* 
 * File:   main.cpp
 * Author: tekktronic
 * Final #4
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

void retrand(int*, int*, const int&, int);
//Execution begins HERE
int main(int argc, char** argv) {
    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    const int n = 5; //size of the array
    int ntimes = 10000; //number of times to loop through
    int numset[n] = {91,51,71,181,208};
    int tally[n] = {0};
    int *rndseq = numset;
    int *freq = tally;
    retrand(rndseq, freq, n, ntimes);
    return 0;
}
void retrand(int *rndseq, int *freq, const int &n, int ntimes){
    int random; //random number to be generated
    for(int idx = 0; idx < ntimes; idx++){
        random = rand() % 5;
        freq[random] += 1;
    }
    for(int idx = 0; idx < n; idx++){
        cout << rndseq[idx] << " occured " << freq[idx] << " times.\n";
    }
}