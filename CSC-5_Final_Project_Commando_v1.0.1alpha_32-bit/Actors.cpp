//Libraries
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "Actors.h"
using namespace std;

//Actor member functions
Actor::Actor(){
    
}
Actor::Actor(int x_coord, int y_coord){
    posx = x_coord;
    posy = y_coord;
}
Actor::~Actor(){
    //clean-up code here
}
int Actor::ret_X(){
    return posx;
}
int Actor::ret_Y(){
    return posy;
}
tile Actor::FindTile(tile **grid, int &ROW, int &COL, Actor *c_Actor){      //find a match in the tile object array
    
}      //find a match in the tile object array
void Actor::Occupy(tile **grid, int &ROW, int &COL){
    
}
bool Actor::Move(tile**grid, int &ROW, int &COL){
    
}
//Player member functions
Player::Player(){       //default constructor for Player instance
    
}
Player::Player(tile **grid, int &ROW, int &COL, string name, int x_coord, int y_coord):Actor(x_coord, y_coord){      //creates player object, located at (posx, posy))
    p_Name = name;
    isAlive = true;
    c_ID = '@';
    t_obj = FindTile(grid, ROW, COL, this);
}
Player::~Player(){      //destructor for the player instance

}
int Player::ret_X(){
    return posx;
}
int Player::ret_Y(){
    return posy;
}
string Player::ret_Name(){
    return p_Name;
}
tile Player::FindTile(tile **grid, int &ROW, int &COL, Actor *c_Actor){
    int x_coord = c_Actor->ret_X();
    int y_coord = c_Actor->ret_Y();
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            if(grid[idx][ctr]->Match(x_coord, y_coord)){
                return grid[idx][ctr];
            }
        }
    }
}
void Player::Occupy(tile **grid, int &ROW, int &COL){
        t_obj = FindTile(grid, ROW, COL, this);
        t_obj->SetDisp(posx, posy, c_ID);
}
bool Player::Move(tile **grid, int &ROW, int &COL){
    bool isValid = false;
    int ch_x;
    int ch_y;
    char p_in;          //player's directional input
    while(!isValid){
        ch_x = 0;
        ch_y = 0;
        cout << "Move the player: ";
        cin.get(p_in);
        switch(p_in){
            case 'w':{
                if(posx > 0){
                    ch_x = -1;
                    isValid = true;
                }
                break;
            }
            case 'a':{
                if(posy > 0){
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 's':{
                if(posx < ROW-1){
                    ch_x = 1;
                    isValid = true;
                }
                break;
            }
            case 'd':{
                if(posy < COL-1){
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            case 'q':{
                if(posx > 0 && posy > 0){
                    ch_x = -1;
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 'e':{
                if(posx > 0 && posy < COL-1){
                    ch_x = -1;
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            case 'z':{
                if(posx < ROW-1 && posy > 0){
                    ch_x = 1;
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 'c':{
                if(posx < ROW-1 && posy < COL-1){
                    ch_x = 1;
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            default: cout << "Invalid input! Try again.\n";
        }
        cin.ignore();
        tile nxt_obj;
        nxt_obj = *(*(grid+(posx+ch_x))+(posy+ch_y));    //peeks at the next tile
        if(nxt_obj->ret_Pass()){
            t_obj->SetEmpty();
            posx += ch_x;
            posy += ch_y;
            if(nxt_obj->ret_Itm()){
                i_list.push_back(nxt_obj->takeItm());        //places the item pointer in the inventory
            }
            Occupy(grid, ROW, COL);
        }
        else if(nxt_obj->ret_Lck()){
            cout << "The door is locked. Obtain a key card to open this door.\n";
        }
        else if(nxt_obj->ret_Brk()){
            cout << "The way is blocked. Blast through with explosives or drill a passage through.\n";
        }
        else isValid = false;
    }
}
bool Player::GetItem(){
        
}
bool Player::ret_St(){
    return isAlive;
}
//Robot member functions
Robot::Robot(){       //default constructor for Robot instance
    
}
Robot::Robot(int x_coord, int y_coord){
    posx = x_coord;
    posy = y_coord;
}
Robot::Robot(tile **grid, int &ROW, int &COL, string name, int x_coord, int y_coord):Actor(x_coord, y_coord){      //creates player object, located at (posx, posy))
    p_Name = name;
    c_ID = '?';
    t_obj = FindTile(grid, ROW, COL, this);
}
Robot::~Robot(){      //destructor for the player instance
    //cleanup code here
}
int Robot::ret_X(){
    return posx;
}
int Robot::ret_Y(){
    return posy;
}
tile Robot::FindTile(tile **grid, int &ROW, int &COL, Actor *c_Actor){
    int x_coord = c_Actor->ret_X();
    int y_coord = c_Actor->ret_Y();
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            if(grid[idx][ctr]->Match(x_coord, y_coord)){
                return *(*(grid+idx)+ctr);
            }
        }
    }
}
void Robot::Occupy(tile **grid, int &ROW, int &COL){
        t_obj = FindTile(grid, ROW, COL, this);
        t_obj->SetDisp(posx, posy, c_ID);
}
bool Robot::Move(tile **grid, int &ROW, int &COL){
    t_obj->SetEmpty();
    bool isValid = false;
    int move; 
    while(!isValid){
        int ch_x = 0, ch_y = 0;
        move = (rand()%8) + 1;          //generate the random movement of the Robot
        switch(move){
            case 1:{
                if(posx > 0){
                    ch_x = -1;
                    isValid = true;
                }
                break;
            }
            case 2:{
                if(posy > 0){
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 3:{
                if(posx < ROW-1){
                    ch_x = 1;
                    isValid = true;
                }
                break;
            }
            case 4:{
                if(posy < COL-1){
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            case 5:{
                if(posx > 0 && posy > 0){
                    ch_x = -1;
                    ch_y= -1;
                    isValid = true;
                }
                break;
            }
            case 6:{
                if(posx > 0 && posy < COL-1){
                    ch_x = -1;
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            case 7:{
                if(posx < ROW-1 && posy > 0){
                    ch_x = 1;
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 8:{
                if(posx < ROW-1 && posy < COL-1){
                     ch_x = 1;
                     ch_y = 1;
                     isValid = true;
                }
                break;
            }
            default: continue;
        }
        tile nxt_obj;
        nxt_obj = *(*(grid+(posx+ch_x))+(posy+ch_y));    //peeks at the next tile to see if it is not set
        if(nxt_obj->ret_Pass()){
            t_obj->SetEmpty();
            posx += ch_x;
            posy += ch_y;
            Occupy(grid, ROW, COL);
        }
        else isValid = false;
    }
}
