/* 
 * NAME: Ezra Guinmapang
 * DATE: April 23, 2014
 * PURPOSE: Build a Battleship game
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

//Class definitions
typedef char (*map)[10]; //typedefs can make things more readable with such awkward types
class Grid{
    private:
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
    public:
        map GetGrid();
};
class Player{
    private:
        vector<string> Shots;   //stores the shots fired
        char p_Grid[10][10] = {
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
        };             //placement grid for player's ships
        char s_Grid[10][10] = {
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
        };             //shot grid for player's shots
        short posx, posy;               //coordinates
    public:
        Player();               //constructor for player instance
        ~Player();              //destructor for player instance
        map P_Grid();                                           //access the ship placement grid
        map S_Grid();                                           //access the shot placement grid
        void Populate(char[][10]);                              //populates the grid
        bool GetCoord(short &, short &);                                //input coordinates
        void C_Ships(short &, short &, char[][10]);                    //choose ships to place
        void PlaceIt(short, short &, short &, char[][10], char);        //place ships on placement grid
        bool Volley(short &, short &, char[][10]);                      //fire a shot
        void Display(char[][10]);                                       //display grid
};
//Global variables and constants

//Function prototypes
//bool GetCoord(short &, short &);
void Populate(short &, short &, char[][10]);
void PlaceIt(short, short &, short &, char[][10], char);
bool Volley(short &, short &, char[][10]);
//void Display(char[][10]);

//Execution begins HERE
int main(int argc, char** argv){
    //Declare variables
    char (*b_Ground)[10];
    short posx, posy;
    Player *Ez = new Player();
    cout << &b_Ground[10] << endl << endl;
    b_Ground = Ez-> P_Grid();
    cout << &b_Ground[10] << endl << endl;
    Ez-> Display(b_Ground);
    Ez-> C_Ships(posx, posy, b_Ground);
    char mChoice;
    do{
        b_Ground = Ez->S_Grid();
        Ez-> Display(b_Ground);
        Ez-> Volley(posx, posy, b_Ground);
        Ez-> Display(b_Ground);
        cout << "Continue(y/n)? ";
        cin >> mChoice;
    }while(mChoice == 'y'||mChoice == 'Y');
    //Execution ends HERE
    return 0;
}
//Function definitions
map Grid::GetGrid(){
    return Grid;
}

//Input coordinates
Player::Player(){
    //initializing code here
}
Player::~Player(){
    //cleanup code here
}
map Player::P_Grid(){
    return p_Grid;
}
map Player::S_Grid(){
    return s_Grid;
}
bool Player::GetCoord(short &posx, short &posy){
    bool isValid = false;
    char x_Coord;
    cin >> x_Coord >> posy;
    switch(x_Coord){
        case 'A': posx = 0; break;
        case 'B': posx = 1; break;
        case 'C': posx = 2; break;
        case 'D': posx = 3; break;
        case 'E': posx = 4; break;
        case 'F': posx = 5; break;
        case 'G': posx = 6; break;
        case 'H': posx = 7; break;
        case 'I': posx = 8; break;
        case 'J': posx = 9; break;
        default: cout << "Err..\n"; break;
    }
    if((posx >= 0)&&(posx < 10)&&(posy >= 0)&&(posy < 10)) isValid = true;
    else{
        cout << "Invalid coordinates! Try again.\n";
    }
    return isValid;
}
//Populate the grids
void Player::Populate(char Grid[][10]){
    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 10; row++){
            Grid[row][col] = '_';
        }
    }    
}
//Populate the board
void Player::C_Ships(short &posx, short &posy, char p_Grid[][10]){
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
                    PlaceIt(hp, posx, posy, p_Grid, pos);
                    Display(p_Grid);
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
                    PlaceIt(hp, posx, posy, p_Grid, pos);
                    Display(p_Grid);
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
                    PlaceIt(hp, posx, posy, p_Grid, pos);
                    Display(p_Grid);
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
void Player::PlaceIt(short hp, short &posx, short &posy, char p_Grid[][10], char pos){
    bool isValid = false;
    do{
        cout << "Enter the coordinates to place your ship: ";
        isValid = GetCoord(posx, posy);
    }while(!isValid);
    for(short p_Ship = 0; p_Ship < hp; p_Ship++){
        if(pos == 'V'){
            if(posx < hp) p_Grid[posx + p_Ship][posy] = '@';
            else p_Grid[posx - p_Ship][posy] = '@';
        }
        else if(pos == 'H'){
            if(posy < hp) p_Grid[posx][posy + p_Ship] = '@';
            else p_Grid[posx][posy - p_Ship] = '@';
        }
    }
}
//Shoot at coordinates
bool Player::Volley(short &posx, short &posy, char s_Grid[][10]){
    bool isValid = false, isFinal = false;
    char choice;
    do{
        do{
            cout << "Enter the coordinates to shoot at: ";
            isValid = GetCoord(posx, posy);
        }while(!isValid);
        Display(s_Grid);
        cout << "Final choice? ";
        cin >> choice;
        if(choice == 'y' || choice == 'Y'){
            isFinal = true;
            if(s_Grid[posx][posy] == '@'){
                s_Grid[posx][posy] = 'X';
                Display(s_Grid);
            }
            else if(s_Grid[posx][posy] == '_'){
                s_Grid[posx][posy] = '-';            
                Display(s_Grid);
            }
        }
        else{
            s_Grid[posx][posy] = '_';
            Display(s_Grid);
        }
    }while(!isFinal);
    return isFinal;
}
//Display Board
void Player::Display(char Grid[][10]){
    char x_Coord;
    cout << "Displaying the grid:\n\n";
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
    for(short ctr = 0; ctr < 10; ctr++){
        switch(ctr){
            case 0: x_Coord = 'A'; break;
            case 1: x_Coord = 'B'; break;
            case 2: x_Coord = 'C'; break;
            case 3: x_Coord = 'D'; break;
            case 4: x_Coord = 'E'; break;
            case 5: x_Coord = 'F'; break;
            case 6: x_Coord = 'G'; break;
            case 7: x_Coord = 'H'; break;
            case 8: x_Coord = 'I'; break;
            case 9: x_Coord = 'J'; break;
            default: cout << "Err..\n"; break;
        }
        cout << x_Coord << " ";
        for(short ctr2 = 0; ctr2 < 10; ctr2++){
            cout << Grid[ctr][ctr2] << "|";
        }
        cout << endl;
    }
    cout << endl;
}