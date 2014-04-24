/* 
 * NAME: Ezra Guinmapang
 * DATE: April 23, 2014
 * PURPOSE: Build a Battleship game
 */

//Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Global variables and constants

//Function prototypes
bool Volley(short, short, char[][10]);
void Display(char[][10]);

//Execution begins HERE
int main(int argc, char** argv){
    //Declare variables
    char Grid[10][10] = {
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
    };
    short posx, posy;
    char mChoice;
    do{
        Display(Grid);
        Volley(posx, posy, Grid);
        Display(Grid);
        cout << "Continue(y/n)? ";
        cin >> mChoice;
    }while(mChoice == 'y'||mChoice == 'Y');
    //Execution ends HERE
    return 0;
}
//Function definitions
//Pick a peg to move
bool Volley(short posx, short posy, char Grid[][10]){
    bool isValid = false, isFinal = false;
    char choice;
    do{
        do{
            cout << "Enter the coordinates of the peg separated by a space: ";
            cin >> posx >> posy;
            if((posx >= 0)&&(posx < 10)&&(posy >= 0)&&(posy < 10)) isValid = true;
            else{
                cout << "Invalid move! Try again.\n";
                isValid = false;
            }
        }while(!isValid);
        Grid[posx][posy] = 'O';
        Display(Grid);
        cout << "Final choice? ";
        cin >> choice;
        if(choice == 'y' || choice == 'Y'){
            isFinal = true;
            if(Grid[posx][posy] == '@'){
                Grid[posx][posy] = 'X';
                Display(Grid);
            }
            else if(Grid[posx][posy] == '_'){
                Grid[posx][posy] = '-';            
                Display(Grid);
            }
        }
        else{
            Grid[posx][posy] = '_';
            Display(Grid);
        }
    }while(!isFinal);
    return isFinal;
}
//Display Board
void Display(char Grid[][10]){
    cout << "Displaying the grid:\n\n";
    for(short ctr = 0; ctr < 10; ctr++){
        for(short ctr2 = 0; ctr2 < 10; ctr2++){
            cout << Grid[ctr][ctr2];
        }
        cout << endl;
    }
    cout << endl;
}
