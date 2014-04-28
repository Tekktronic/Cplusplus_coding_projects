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

class Ship{
    private:
        bool isSunk;            //stores the status of the ship
        short hits;             //number of hitpoints left on the ship
        string s_Type;          //stores the type of ship
        vector<string> Range;   //stores the coordinates of the ship on the grid
    public:
        Ship();                         //default constructor for the ship object
        Ship(string);                   //constructor for the ship object
        ~Ship();                        //destructor for the ship object
        bool Sunk();                    //returns the status of a ship
        short R_Size();                 //returns the size of the vector holding the ship's placement coordinates
        vector<string> Occupy();        //returns the Range of the ship
        bool PollRange(string);         //polls the range to see if the ship is hit
        void SetHits(short, short, short, char, string);        //sets the ship's placement coordinates
};
typedef char (*grid)[10];       //typedef for a pointer to an array of arrays of characters
typedef vector<Ship *> (USS);   //typedef for a vector of pointers to a ship instance
class Player{
    friend Ship;
    private:
        char p_Grid[10][10];            //placement grid for player's ships            
        char s_Grid[10][10];            //shot grid for player's shots
        string P_Name;                  //Player's name
        short FleetCT, SunkCT;          //Player's fleet count, and enemy ships sunk, respectively.
        string Coords;                  //string representing the coordinate pair
        short posx, posy;               //stores the x- and the y-coordinates as integers
        vector<string> Shots;           //stores the shots fired by Player
        vector<string> Filled;          //stores coordinates that are occupied
        vector<Ship *> p_Fleet;         //stores the Player's fleet of ships
    public:
        Player();               //default constructor for player instance
        Player(string);         //constructor for player instance
        ~Player();              //destructor for player instance
        grid P_Grid();          //access the ship placement grid
        grid S_Grid();          //access the shot placement grid
        USS Fleet();            //access the player's fleet of ships
        string Shot();          //returns the value of Coords
        short FleetSize();      //returns the size of the player's fleet
        short SunkSize();       //returns the number of enemy ships sunk
        string Name();          //returns the Player's name
        bool GetCoord();        //input coordinates
        void C_Ships(char[][10]);               //choose ships to place
        void PlaceIt(short, char[][10], char);  //place ships on placement grid
        bool Volley(char[][10]);                //fire a shot
        short Impact(string, USS);              //registers hits into the appropriate ship
        void Display(char[][10]);               //display grid
        bool Victory(short);                    //trial function - modify
};
//Global variables and constants

//Function prototypes

//Execution begins HERE
int main(int argc, char** argv){
    char mChoice;
    do{
        //Declare variables
        bool isWinner = false;
        string name;
        char (*b_Ground)[10];
        cout << "***********************\n";
        cout << "* B A T T L E S H I P *\n";
        cout << "***********************\n\n";
        cout << "Player, please enter your name: ";
        cin >> name;
        cout << "Welcome, Admiral " << name << ".\n";
        Player *Player1 = new Player(name);
        cout << "Player, please enter your name: ";
        cin >> name;
        cout << "Welcome, Admiral " << name << ".\n";
        Player *Player2 = new Player(name);
        b_Ground = Player1->P_Grid();
        Player1->Display(b_Ground);
        Player1->C_Ships(b_Ground);
        b_Ground = Player2->P_Grid();
        Player2->Display(b_Ground);
        Player2->C_Ships(b_Ground);
        while(!isWinner){
            cout << Player1->Name() << "'s turn:\n";
            b_Ground = Player1->S_Grid();
            Player1->Display(b_Ground);
            Player1->Volley(Player2->P_Grid());
            Player1->Impact(Player1->Shot(), Player2->Fleet());
            isWinner = Player1->Victory(Player2->SunkSize());
            if(isWinner) break;
            cout << Player2->Name() << "'s turn:\n";
            b_Ground = Player2->S_Grid();
            Player2->Display(b_Ground);
            Player2->Volley(Player1->P_Grid());
            Player1->Impact(Player2->Shot(), Player1->Fleet());
            isWinner = Player2->Victory(Player1->SunkSize());
            if(isWinner) break;
            cout << "Continue(Y/N)? ";
            cin >> mChoice;
            if(toupper(mChoice) != 'Y') break;
        }
        delete Player1;
        delete Player2;
        cout << "Would you like a new game(Y/N)? ";
        cin >> mChoice;
    }while(toupper(mChoice) == 'Y');
    cout << "Exiting Naval Battle Simulator. Goodbye!\n";
    //Execution ends HERE
    return 0;
}
//Function definitions

//Class functions
//Ship class
Ship::Ship(){
    //initialization code here
}
Ship::Ship(string type){
    s_Type = type;
    isSunk = false;
}
Ship::~Ship(){
    //cleanup code here
}
bool Ship::Sunk(){
    return isSunk;
}
short Ship::R_Size(){
    return Range.size();
}
vector<string> Ship::Occupy(){
    return Range;
}
bool Ship::PollRange(string x_y){
    for(short ctr = 0; ctr < Range.size(); ctr++){
        if(x_y.compare(Range.at(ctr)) == 0){
            hits--;            
            if(hits == 0){
                cout << "You have sunk the enemy " << s_Type << "!!!\n\n";
                isSunk = true;
            }
            return true;
        }
    }
    return false;
}
void Ship::SetHits(short posx, short posy, short hp, char f_pos, string Coords){
    hits = hp;
    short ctr = 0;
    string x_y;
    for(char x = Coords[0], y = Coords[1]; ctr < hits; ctr++){
        x_y = x;
        x_y = x_y + y;
        Range.push_back(x_y);
        if(toupper(f_pos) == 'V'){
            if(posx > 10 - hp) x--;
            else x++;
        }
        else if(toupper(f_pos) == 'H'){
            if(posy > 10 - hp) y--;
            else y++;
        }
    }
}
//Player class
Player::Player(){
    //initializing code here
}
Player::Player(string Name){
    P_Name = Name;
    FleetCT = 5;
    SunkCT = 0;
    p_Fleet.push_back(new Ship("Aircraft Carrier"));
    p_Fleet.push_back(new Ship("Battleship"));
    p_Fleet.push_back(new Ship("Destroyer"));  
    p_Fleet.push_back(new Ship("Submarine"));
    p_Fleet.push_back(new Ship("Patrol Boat"));
    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 10; col++){
            p_Grid[row][col] = '_';
            s_Grid[row][col] = '_';
        }
    }
}
Player::~Player(){
    //cleanup code here
}
grid Player::P_Grid(){
    return p_Grid;
}
grid Player::S_Grid(){
    return s_Grid;
}
string Player::Shot(){
    return Coords;
}
string Player::Name(){
    return P_Name;
}
short Player::FleetSize(){
    return FleetCT;
}
short Player::SunkSize(){
    return SunkCT;
}
vector<Ship *> Player::Fleet(){
    return p_Fleet;
}
bool Player::GetCoord(){
    bool isValid = false;
    cin >> Coords;
    switch(toupper(Coords[0])){
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
    if((toupper(Coords[0]) >= 'A')&&(toupper(Coords[0]) <= 'J')&&(Coords[1] >= '0')&&(Coords[1] <= '9') && Coords.size() == 2){
        isValid = true;
    }
    else{
        cout << "Invalid coordinates! Try again.\n";
    }
    return isValid;
}
//Populate the board
void Player::C_Ships(char p_Grid[][10]){
    char pos = '0', s_type = '0';
    short ac_left = 1, bs_left = 1, ds_left = 1, sb_left = 1, pb_left = 1;
    short hp = 0, n_Ships = 1;
    short ctr;
    vector<string> anchor;
    do{
        cout << "Enter the type of ship to place:\n";
        cout << "A. Aircraft Carrier (" << ac_left << " available)\n";
        cout << "B. Battleship (" << bs_left << " available)\n";
        cout << "C. Destroyer (" << ds_left << " available)\n";
        cout << "D. Submarine (" << sb_left << " available)\n";
        cout << "E. Patrol boat (" << pb_left << " available)\n";
        cout << "Enter your choice: ";
        cin >> s_type;
        switch(toupper(s_type)){
            case 'A':{
                if(ac_left > 0){
                    hp = 5;
                    do{
                        cout << "Place vertically or horizontally(V/H)? ";
                        cin >> pos;
                        if(toupper(pos) != 'H' && toupper(pos) != 'V') cout << "Invalid placement! Try again.\n";
                    }while(toupper(pos) != 'H' && toupper(pos) != 'V');
                    PlaceIt(hp, p_Grid, toupper(pos));
                    p_Fleet.at(0)->SetHits(posx, posy, hp, toupper(pos), Coords);
                    anchor = p_Fleet.at(0)->Occupy();
                    for(ctr = 0; ctr < hp; ctr++){
                        Filled.push_back(anchor.at(ctr));
                    }
                    ac_left--;
                    n_Ships++;
                    anchor.clear();
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
                        if(toupper(pos) != 'H' && toupper(pos) != 'V') cout << "Invalid placement! Try again.\n";
                    }while(toupper(pos) != 'H' && toupper(pos) != 'V');
                    PlaceIt(hp,p_Grid, pos);
                    p_Fleet.at(1)->SetHits(posx, posy, hp, toupper(pos), Coords);
                    anchor = p_Fleet.at(1)->Occupy();
                    for(ctr = 0; ctr < hp; ctr++){
                        Filled.push_back(anchor.at(ctr));
                    }
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
                        if(toupper(pos) != 'H' && toupper(pos) != 'V') cout << "Invalid placement! Try again.\n";
                    }while(toupper(pos) != 'H' && toupper(pos) != 'V');
                    PlaceIt(hp, p_Grid, pos);
                    p_Fleet.at(2)->SetHits(posx, posy, hp, toupper(pos), Coords);
                    anchor = p_Fleet.at(2)->Occupy();
                    for(ctr = 0; ctr < hp; ctr++){
                        Filled.push_back(anchor.at(ctr));
                    }
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
                        if(toupper(pos) != 'H' && toupper(pos) != 'V') cout << "Invalid placement! Try again.\n";
                    }while(toupper(pos) != 'H' && toupper(pos) != 'V');
                    PlaceIt(hp, p_Grid, pos);
                    p_Fleet.at(3)->SetHits(posx, posy, hp, toupper(pos), Coords);
                    anchor = p_Fleet.at(3)->Occupy();
                    for(ctr = 0; ctr < hp; ctr++){
                        Filled.push_back(anchor.at(ctr));
                    }
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
                        if(toupper(pos) != 'H' && toupper(pos) != 'V') cout << "Invalid placement! Try again.\n";
                    }while(toupper(pos) != 'H' && toupper(pos) != 'V');
                    PlaceIt(hp, p_Grid, pos);
                    p_Fleet.at(4)->SetHits(posx, posy, hp, toupper(pos), Coords);
                    anchor = p_Fleet.at(4)->Occupy();
                    for(ctr = 0; ctr < hp; ctr++){
                        Filled.push_back(anchor.at(ctr));
                    }
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
    }while(n_Ships <= 5);
}
//Place your ships
void Player::PlaceIt(short hp, char p_Grid[][10], char pos){
    bool isValid = false, isFinal = false;
    char choice;
    string x_y;
    vector<string> Chkpos;
    do{
        do{
            cout << "Enter the coordinates to place your ship: ";
            isValid = GetCoord();
            int ctr = 0;
            for(char x = Coords[0], y = Coords[1]; ctr < hp; ctr++){
                x_y = x;
                x_y = x_y + y;
                Chkpos.push_back(x_y);
                if(toupper(pos) == 'V'){
                    if(posx > 10 - hp) x--;
                    else x++;
                }
                else if(toupper(pos) == 'H'){
                    if(posy > 10 - hp) y--;
                    else y++;
                }
                cout << "In PlaceIt: " << Chkpos.at(ctr) << endl;
            }
            for(int ctr = 0; ctr < Filled.size(); ctr++){
                x_y = Filled.at(ctr);
                for(int ctr2 = 0; ctr2 < Chkpos.size(); ctr2++){
                    if(x_y.compare(Chkpos.at(ctr2)) == 0){
                        isValid = false;
                        cout << "Position occupied! Try again.\n";
                        Chkpos.clear();
                    }
                }
            }
        }while(!isValid);
        Chkpos.clear();
        for(short p_Ship = 0; p_Ship < hp; p_Ship++){
            if(toupper(pos) == 'V'){
                if(posx > 10 - hp) p_Grid[posx - p_Ship][posy] = '@';
                else p_Grid[posx + p_Ship][posy] = '@';
            }
            else if(toupper(pos) == 'H'){
                if(posy > 10 - hp) p_Grid[posx][posy - p_Ship] = '@';
                else p_Grid[posx][posy + p_Ship] = '@';
            }
        }
        Display(p_Grid);
        cout << "Final choice? ";
        cin >> choice;
        if(toupper(choice) == 'Y') isFinal = true;
        else{
            for(short p_Ship = 0; p_Ship < hp; p_Ship++){
                if(toupper(pos) == 'V'){
                    if(posx > 10 - hp) p_Grid[posx - p_Ship][posy] = '_';
                    else p_Grid[posx + p_Ship][posy] = '_';
                }
                else if(toupper(pos) == 'H'){
                    if(posy > 10 - hp) p_Grid[posx][posy - p_Ship] = '_';
                    else p_Grid[posx][posy + p_Ship] = '_';
                }
            }
            isFinal = false;
            Display(p_Grid);
        }
    }while(!isFinal);
}
//Shoot at coordinates
bool Player::Volley(char Grid[][10]){
    bool isValid = false, isFinal = false;
    char choice;
    do{
        do{
            cout << "Enter the coordinates to shoot at: ";
            isValid = GetCoord();
            for(int ctr = 0; ctr < Shots.size(); ctr++){
                if(Coords.compare(Shots.at(ctr)) == 0){
                    cout << "Shot has been fired previously! Try again.\n";
                    isValid = false;
                }        
            }
        }while(!isValid);
        s_Grid[posx][posy] = 'o';
        Display(s_Grid);
        cout << "Final choice? ";
        cin >> choice;
        if(toupper(choice) == 'Y'){
            isFinal = true;
            if(Grid[posx][posy] == '@'){
                Grid[posx][posy] = 'X';
                s_Grid[posx][posy] = 'X';
                Display(s_Grid);
            }
            else if(Grid[posx][posy] == '_'){
                Grid[posx][posy] = 'O';
                s_Grid[posx][posy] = '-';            
                Display(s_Grid);
            }
        }
        else{
            s_Grid[posx][posy] = '_';
            Display(s_Grid);
        }
    }while(!isFinal);
    Shots.push_back(Coords);
    return isFinal;
}
//Display Board
void Player::Display(char Grid[][10]){
    char x_Coord;
    cout << "Displaying " << P_Name <<"'s Shot or Placement grid:\n\n";
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
        cout << x_Coord << "|";
        for(short ctr2 = 0; ctr2 < 10; ctr2++){
            cout << Grid[ctr][ctr2] << "|";
        }
        cout << endl;
    }
    cout << endl;
}
//Resolve hits
short Player::Impact(string x_y, USS o_Fleet){
    short f_Size = 0;
    bool isHit = false;
    for(int ctr = 0; ctr < 5; ctr++){
        if(o_Fleet.at(ctr)->PollRange(x_y)){
            isHit = true;
            cout << "A direct HIT, Admiral! Well Done!\n\n";
            break;
        }
    }
    if(!isHit) cout << "The shot was a MISS, Admiral!\n";
    for(int ctr = 0; ctr < 5; ctr++){
        if(o_Fleet.at(ctr)->Sunk()){
            f_Size++;
        }
    }
    SunkCT = f_Size;
}
bool Player::Victory(short s_Sunk){
    if(FleetCT == s_Sunk){
        cout << "The enemy fleet has been DECIMATED!!!\n";
        cout << "You have achieved a NAVAL VICTORY! Conragtulations,";
        cout << "Admiral " << P_Name << endl;;
        return true;
    }
    return false;
}