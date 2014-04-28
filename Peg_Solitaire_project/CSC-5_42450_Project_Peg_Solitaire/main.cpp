/* 
 * NAME: Ezra Guinmapang
 * DATE: April 5, 2014
 * PURPOSE: Build a puzzle game 
 */

//Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Global variables and constants
char Grid[7][9] = {
    {'_', '_', '_', '@', '@', '@', '_', '_', '_'},
    {'_', '_', '_', '@', '@', '@', '_', '_', '_'},
    {'_', '@', '@', '@', '@', '@', '@', '@', '_'},
    {'_', '@', '@', '@', '-', '@', '@', '@', '_'},
    {'_', '@', '@', '@', '@', '@', '@', '@', '_'},
    {'_', '_', '_', '@', '@', '@', '_', '_', '_'},
    {'_', '_', '_', '@', '@', '@', '_', '_', '_'},
};
//Function prototypes
bool ChoosePeg(short &, short &);
bool Direction(short, short);
bool JumpTo(short, short, char);
void Display();

//Execution begins HERE
int main(int argc, char** argv){
    //Declare variables
    short posx, posy;
    char mChoice;
    cout << "Let's play PEG SOLITAIRE!\n";
    cout << "Here are the RULES:\n";
    cout << "1. The object of the game is to remove one peg from the board ";
    cout << "by jumping over them with adjacent pegs.\n";
    cout << "2. The game ends when no legal moves may be made. A legal move ";
    cout << "is defined as a peg jumping horizontally or vertically over another peg.\n";
    cout << "3. To indicate the direction in which you want to make the jump, ";
    cout << "use the <w, a, s, and d> keys.\n";
    do{
        Display();
        ChoosePeg(posx, posy);
        Direction(posx, posy);
        Display();
        cout << "Continue(y/n)? ";
        cin >> mChoice;
    }while(mChoice == 'y'||mChoice == 'Y');
    //Execution ends HERE
    return 0;
}
//Function definitions
//Pick a peg to move
bool ChoosePeg(short &posx, short &posy){
    bool isValid = false, isFinal = false;
    char choice;
    do{
        do{
            cout << "Enter the coordinates of the peg separated by a space: ";
            cin >> posx >> posy;
            if((posx >= 0)&&(posx < 7)&&(posy >= 0)&&(posy < 7)){
                if(Grid[posx][posy] == '@'){
                    isValid = true;
                }
                else{
                    cout << "Invalid move! Try again.\n";
                    isValid = false;
                }
            }
        }while(!isValid);
        Grid[posx][posy] = 'x';
        Display();
        cout << "Final choice? ";
        cin >> choice;
        if(choice == 'y' || choice == 'Y'){
            Grid[posx][posy] = 'o';
            isFinal = true;
            Display();
        }
        else{
            Grid[posx][posy] = '@';
            Display();
        }
    }while(!isFinal);
    return isFinal;
}
//Direction of jump
bool Direction(short posx, short posy){
    char d_jump;
    cout << "What direction is the jump (w, a, s, or d)? ";
    cin >> d_jump;
    switch(d_jump){
        case 'w':{
            if((posx > 2)&&((posy > 2)||(posy < 6))){
                Grid[posx][posy] = '-';
                posx -= 1;
                Grid[posx][posy] = '-';
                posx -= 1;
                JumpTo(posx, posy, d_jump);
                return true;
            }
        }
        case 'a':{
            if((posy > 3)&&((posx > 1)||(posx < 5))){
                Grid[posx][posy] = '-';
                posy -= 1;
                Grid[posx][posy] = '-';
                posy -= 1;
                JumpTo(posx, posy, d_jump);
                return true;
            }
        }
        case 's':{
            if((posx < 5)&&((posy > 2)||(posy < 6))){
                Grid[posx][posy] = '-';
                posx += 1;
                Grid[posx][posy] = '-';
                posx += 1;
                JumpTo(posx, posy, d_jump);
                return true;
            }
        }
        case 'd':{
            if((posy < 6)&&((posx > 1)||(posx < 5))){
                Grid[posx][posy] = '-';
                posy += 1;
                Grid[posx][posy] = '-';
                posy += 1;
                JumpTo(posx, posy, d_jump);
                return true;
            }
        }
        default:{
            cout << "Invalid move! Try again.\n";
            Display();
            ChoosePeg(posx, posy);
            Direction(posx, posy);
            return false;
        }
    }
}
//Validate move and execute is valid
bool JumpTo(short posx, short posy, char d_jump){
    if(Grid[posx][posy] == '-'){
        Grid[posx][posy] = '@';
        return true;
    }
    else{
        cout << "Invalid move! Try again.\n";
        switch(d_jump){
            case 'w': {
                posx += 1;
                Grid[posx][posy] = '@';
                posx += 1;
                break;
            }
            case 'a': {
                posy += 1;
                Grid[posx][posy] = '@';
                posy += 1;
                break;
            }
            case 's': {
                posx -= 1;
                Grid[posx][posy] = '@';
                posx -= 1;
                break;
            }
            case 'd': {
                posy -= 1;
                Grid[posx][posy] = '@';
                posy -= 1;
                break;
            }
        }
        Grid[posx][posy] = '@';
        Display();
        ChoosePeg(posx, posy);
        Direction(posx, posy);
        return false;
    }
}
//Display Board
void Display(){
    cout << "Displaying the board:\n\n";
    cout << "  0 1 2 3 4 5 6 7 8" << endl;
    for(short ctr = 0; ctr < 7; ctr++){
        cout << ctr << " ";
        for(short ctr2 = 0; ctr2 < 9; ctr2++){
            cout << Grid[ctr][ctr2] << "|";
        }
        cout << endl;
    }
    cout << endl;
}