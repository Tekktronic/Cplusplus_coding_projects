/* 
 * NAME: Ezra Guinmapang
 * DATE: April 23, 2014
 * PURPOSE: Build a Battleship game
 */
/*
//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

//Class definitions
typedef char (*map)[10];        //typedef for a pointer to an array of arrays of characters
class Player{
    private:
        string P_Name;
        vector<string> Shots;           //stores the shots fired
        char p_Grid[10][10] = {         //placement grid for player's ships
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
        char s_Grid[10][10] = {         //shot grid for player's shots
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
        short S_Count;              //number of ships still afloat
        short posx, posy;               //coordinates
    public:
        Player();               //default constructor for player instance
        Player(string);         //constructor for player instance
        ~Player();              //destructor for player instance
        map P_Grid();                                           //access the ship placement grid
        map S_Grid();                                           //access the shot placement grid
        bool GetCoord(short &, short &);                                //input coordinates
        void C_Ships(short &, short &, char[][10]);                    //choose ships to place
        void PlaceIt(short, short &, short &, char[][10], char);        //place ships on placement grid
        bool Volley(short &, short &, char[][10]);                      //fire a shot
        void Display(char[][10]);                                       //display grid
        bool isTurn(char[][10]);                                        //generate 1 full turn
};
//Global variables and constants

//Function prototypes

//void Display(char[][10]);

//Execution begins HERE
int main(int argc, char** argv){
    //Declare variables
    char (*b_Ground)[10];
    short posx, posy;
    Player *Ez = new Player("Ezra");
    Player *Some = new Player();
    b_Ground = Ez-> P_Grid();
    Ez-> Display(b_Ground);
    Ez-> C_Ships(posx, posy, b_Ground);
    b_Ground = Some-> P_Grid();
    Some-> Display(b_Ground);
    Some-> C_Ships(posx, posy, b_Ground);
    
    char mChoice;
    do{
        b_Ground = Ez-> S_Grid();
        Ez-> Display(b_Ground);
        Ez-> Volley(posx, posy, Some->P_Grid());
        Ez-> Display(b_Ground);
        cout << "Continue(y/n)? ";
        cin >> mChoice;
    }while(mChoice == 'y'||mChoice == 'Y');
    delete Ez;
    delete Some;
    //Execution ends HERE
    return 0;
}
//Input coordinates
Player::Player(){
    //initializing code here
}
Player::Player(string Name){
    S_Count = 5;
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
    string Coords;
    cin >> Coords;
    switch(Coords[0]){
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
        default: break;
    }    
    switch(Coords[1]){
        case '0': posy = 0; break;
        case '1': posy = 1; break;
        case '2': posy = 2; break;
        case '3': posy = 3; break;
        case '4': posy = 4; break;
        case '5': posy = 5; break;
        case '6': posy = 6; break;
        case '7': posy = 7; break;
        case '8': posy = 8; break;
        case '9': posy = 9; break;
        default: break;
    }
    if((Coords[0] >= 'A')&&(Coords[0] <= 'J')&&(Coords[1] >= '0')&&(Coords[1] <= '9') && Coords.size() == 2){
        isValid = true;
    }
    else{
        cout << "Invalid coordinates! Try again.\n";
    }
    return isValid;
}
//Populate the board
void Player::C_Ships(short &posx, short &posy, char p_Grid[][10]){
    char pos = '0', s_type = '0';
    short ac_left = 1, bs_left = 1, ds_left = 1, sb_left = 1, pb_left = 1;
    short hp = 0, n_Ships = 0;
    do{
        cout << "Enter the type of ship to place:\n";
        cout << "A. Aircraft Carrier (" << ac_left << " available)\n";
        cout << "B. Battleship (" << bs_left << " available)\n";
        cout << "C. Destroyer (" << ds_left << " available)\n";
        cout << "D. Submarine (" << sb_left << " available)\n";
        cout << "E. Patrol boat (" << pb_left << " available)\n";
        cout << "Enter your choice: ";
        cin >> s_type;
        switch(s_type){
            case 'A':{
                if(ac_left > 0){
                    hp = 5;
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
                if(bs_left > 0){
                    hp = 4;
                    do{
                        cout << "Place vertically or horizontally(V/H)? ";
                        cin >> pos;
                        if(pos != 'H' && pos != 'V') cout << "Invalid placement! Try again.\n";
                    }while(pos != 'H' && pos != 'V');
                    PlaceIt(hp, posx, posy, p_Grid, pos);
                    Display(p_Grid);
                    bs_left--;
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
                    hp = 3;
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
            case 'D': {
                if(sb_left > 0){
                    hp = 3;
                    do{
                        cout << "Place vertically or horizontally(V/H)? ";
                        cin >> pos;
                        if(pos != 'H' && pos != 'V') cout << "Invalid placement! Try again.\n";
                    }while(pos != 'H' && pos != 'V');
                    PlaceIt(hp, posx, posy, p_Grid, pos);
                    Display(p_Grid);
                    sb_left--;
                    n_Ships++;
                    break;
                }
                else{
                    cout << "None available! Pick again.\n";
                    break;
                }
            }
            case 'E': {
                if(pb_left > 0){
                    hp = 2;
                    do{
                        cout << "Place vertically or horizontally(V/H)? ";
                        cin >> pos;
                        if(pos != 'H' && pos != 'V') cout << "Invalid placement! Try again.\n";
                    }while(pos != 'H' && pos != 'V');
                    PlaceIt(hp, posx, posy, p_Grid, pos);
                    Display(p_Grid);
                    pb_left--;
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
    }while(n_Ships < 1);//5);
}
//Place your ships
void Player::PlaceIt(short hp, short &posx, short &posy, char p_Grid[][10], char pos){
    bool isValid = false, isFinal = false;
    char choice;
    do{
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
        Display(p_Grid);
        cout << "Final choice? ";
        cin >> choice;
        if(choice == 'Y' || choice == 'y') isFinal = true;
        else{
            for(short p_Ship = 0; p_Ship < hp; p_Ship++){
                if(pos == 'V'){
                    if(posx < hp) p_Grid[posx + p_Ship][posy] = '_';
                    else p_Grid[posx - p_Ship][posy] = '_';
                }
                else if(pos == 'H'){
                    if(posy < hp) p_Grid[posx][posy + p_Ship] = '_';
                    else p_Grid[posx][posy - p_Ship] = '_';
                }
            }
            isFinal = false;
            Display(p_Grid);
        }
    }while(!isFinal);
}
//Shoot at coordinates
bool Player::Volley(short &posx, short &posy, char Grid[][10]){
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
            if(Grid[posx][posy] == '@'){
                s_Grid[posx][posy] = 'X';
                Display(s_Grid);
            }
            else if(Grid[posx][posy] == '_'){
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
}*/