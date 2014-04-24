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
bool GetCoord(short &, short &);
void Populate(short &, short &, char[][10]);
void PlaceIt(short, short &, short &, char[][10], char);
bool Volley(short &, short &, char[][10]);
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
    Display(Grid);
    Populate(posx, posy, Grid);
    do{        
        Volley(posx, posy, Grid);
        Display(Grid);
        cout << "Continue(y/n)? ";
        cin >> mChoice;
    }while(mChoice == 'y'||mChoice == 'Y');
    //Execution ends HERE
    return 0;
}
//Function definitions
//Input coordinates
bool GetCoord(short &posx, short &posy){
    bool isValid = false;
    cin >> posx >> posy;
    if((posx >= 0)&&(posx < 10)&&(posy >= 0)&&(posy < 10)) isValid = true;
    else{
        cout << "Invalid coordinates! Try again.\n";
    }
    return isValid;
}
//Populate the board
void Populate(short & posx, short &posy, char Grid[][10]){
    char pos = '0', s_type = '0';
    static short ac_left = 1, fr_left = 2, ds_left = 1;
    short hp = 0, n_Ships = 0;
    do{
        cout << "Enter the type of ship to place:\n";
        cout << "A. Aircraft Carrier (1 available)\n";
        cout << "B. Frigate (2 available)\n";
        cout << "C. Destroyer (1 available)\n";
        cout << "Enter your choice: ";
        cin >> s_type;
        switch(s_type){
            case 'A':{
                if(ac_left > 0){
                    hp = 4;
                    do{
                        cout << "Place vertically or horizontally(V/H)? ";
                        cin >> pos;
                        if(pos != 'H' && pos != 'V') cout << "Invalid placement! Try again.\n";
                    }while(pos != 'H' && pos != 'V');
                    PlaceIt(hp, posx, posy, Grid, pos);
                    Display(Grid);
                    ac_left--;
                    n_Ships++;
                    break;
                }
                else{
                    cout << "None available! Pick again.\n";
                    break;
                }
            }
            case 'B': {
                if(fr_left > 0){
                    hp = 3;
                    do{
                        cout << "Place vertically or horizontally(V/H)? ";
                        cin >> pos;
                        if(pos != 'H' && pos != 'V') cout << "Invalid placement! Try again.\n";
                    }while(pos != 'H' && pos != 'V');
                    PlaceIt(hp, posx, posy, Grid, pos);
                    Display(Grid);
                    fr_left--;
                    n_Ships++;
                    break;
                }
                else{
                    cout << "None available! Pick again.\n";
                    break;
                }
            }
            case 'C': {
                if(ds_left > 0){
                    hp = 2;
                    do{
                        cout << "Place vertically or horizontally(V/H)? ";
                        cin >> pos;
                        if(pos != 'H' && pos != 'V') cout << "Invalid placement! Try again.\n";
                    }while(pos != 'H' && pos != 'V');
                    PlaceIt(hp, posx, posy, Grid, pos);
                    Display(Grid);
                    ds_left--;
                    n_Ships++;
                    break;
                }
                else{
                    cout << "None available! Pick again.\n";
                    break;
                }
            }
            default: cout << "Invalid choice! Try again.\n";
        }
    }while(n_Ships < 4);
}
//Place your ships
void PlaceIt(short hp, short &posx, short &posy, char Grid[][10], char pos){
    bool isValid = false;
    do{
        cout << "Enter the coordinates to place your ship: ";
        isValid = GetCoord(posx, posy);
    }while(!isValid);
    for(short p_Ship = 0; p_Ship < hp; p_Ship++){
        if(pos == 'V'){
            if(posx < hp) Grid[posx + p_Ship][posy] = '@';
            else Grid[posx - p_Ship][posy] = '@';
        }
        else if(pos == 'H'){
            if(posy < hp) Grid[posx][posy + p_Ship] = '@';
            else Grid[posx][posy - p_Ship] = '@';
        }
    }
}
//Shoot at coordinates
bool Volley(short &posx, short &posy, char Grid[][10]){
    bool isValid = false, isFinal = false;
    char choice;
    do{
        do{
            cout << "Enter the coordinates to shoot at: ";
            isValid = GetCoord(posx, posy);
        }while(!isValid);
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