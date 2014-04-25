/* 
 * File:   main.cpp
 * Author: Ezra Guinmapang
 *
 * Created on April 22, 2014, 1:16 AM
 */

#include <iostream>
#include <cmath>
using namespace std;

//Function prototypes
bool isPrime(int);
int main(int argc, char** argv) {
    //declare variables
    int term = 0; //nth term to be determined
    int n_term = 1; //number of term
    int ctr = 1; //counter
    int exp; //exponent counter
    do{
        term = ctr;
        do{
            if(term % 2 == 0) term /= 2;
            else if(term % 3 == 0) term /= 3;
            else if(term % 5 == 0) term /= 5;
            else break;
        }while(!isPrime(term));
        if(term <= 5){
            cout << ctr << endl;
            n_term++;
        }
        if(n_term > 1475) break;
        ctr++;
    }while(ctr > 0);
    cout << "The " << n_term - 1 << "'th term is " << ctr << endl;
    return 0;
}
//Function definitions
bool isPrime(int num){
    bool isPrime = true;
    for(int ctr = 2; ctr <= num/2; ctr++){
        if(num % ctr == 0) isPrime = false;
    }
    return isPrime;
}