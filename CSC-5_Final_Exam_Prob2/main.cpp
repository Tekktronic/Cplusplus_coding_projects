/* 
 * File:   main.cpp
 * Author: tekktronic
 * Final #2
 * Created on June 10, 2014, 9:50 PM
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

//Execution begins HERE
int main(int argc, char** argv) {
    //seed the rendom number generator
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    int nguess = 10;    //maximum number of guesses
    int guess;          //stores the user's input
    int random;         //random number to be guessed
    random = rand()%1000 + 1;   //generate a random number between 1 and 1000
    //prompt the user for input until there are no more guesses left,
    //or user guesses the number, whichever comes first
    cout << "I am thinking of a number between 1 and 1000.\n";
    cout << "Can you guess the number? You will have a maximum of\n";
    cout << " " << nguess << " guesses.\n";
    while(nguess > 0 && guess != random){
        cout << "Enter your ";
        switch(nguess){
            case 10: cout << "first guess: "; break;
            case 9: cout << "second guess: "; break;
            case 8: cout << "third guess: "; break;
            case 7: cout << "fourth guess: "; break;
            case 6: cout << "fifth guess: "; break;
            case 5: cout << "sixth guess: "; break;
            case 4: cout << "seventh guess: "; break;
            case 3: cout << "eighth guess: "; break;
            case 2: cout << "ninth guess: "; break;
            case 1: cout << "last guess: "; break;
            default: break;
        }
        cin >> guess;
        if(guess == random){
            cout << "Congratulations! You have guessed the number!!!\n";
            break;
        }
        if(guess < random){
            cout << "Your guess is TOO LOW. ";
            --nguess;
            cout << "You have " << nguess << " guesses left.\n";
        }
        else if(guess > random){
            cout << "Your guess is TOO HIGH.\n";
            --nguess;
            cout << "You have " << nguess << " guesses left.\n";
        }
        if(nguess == 0) cout << "Too many tries. The number was " << random << ". YOU LOSE!!!\n";
    }
    return 0;
}

