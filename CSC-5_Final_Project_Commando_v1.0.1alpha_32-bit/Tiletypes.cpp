//Libraries
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Tiletypes.h"
using namespace std;

//T_Type functions
T_Type::T_Type(){     //default constructor for tile instance
    
}
T_Type::T_Type(int &t_posx, int &t_posy){   //creates a tile instance
    posx = t_posx;
    posy = t_posy;
}
T_Type::~T_Type(){            //destructor for tile instance
    //cleanup code here
}
char T_Type::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Type::ret_X(){
    return posx;
}
int T_Type::ret_Y(){
    return posy;
}
bool T_Type::ret_Brk(){
    return isBreak;
}
bool T_Type::ret_Itm(){
    return isItem;
}
bool T_Type::ret_Lck(){
    return isLock;
}
bool T_Type::ret_Pass(){
    return isPass;
}
bool T_Type::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Type::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Type::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Type::ret_ID(){
    return c_disp;
}
bool T_Type::ret_Set(){
    return isSet;
}
//E_Tile functions
E_Tile::E_Tile(){
    
}
E_Tile::E_Tile(int &t_posx, int &t_posy):T_Type(t_posx, t_posy){   //creates a tile instance
    e_disp = '.';
    c_disp = e_disp;
    isSet = false;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
E_Tile::~E_Tile(){            //destructor for tile instance
    //cleanup code here
}
char E_Tile::DispTile(){       //returns the character to display
    cout << c_disp;
}
int E_Tile::ret_X(){
    return posx;
}
int E_Tile::ret_Y(){
    return posy;
}
bool E_Tile::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void E_Tile::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void E_Tile::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char E_Tile::ret_ID(){
    return c_disp;
}
bool E_Tile::ret_Set(){
    return isSet;
}
bool E_Tile::ret_Brk(){
    return isBreak;
}
bool E_Tile::ret_Itm(){
    return isItem;
}
bool E_Tile::ret_Lck(){
    return isLock;
}
bool E_Tile::ret_Pass(){
    return isPass;
}
//T_Tile functions
T_Tile::T_Tile(){     //default constructor for tile instance
    
}
T_Tile::T_Tile(int &t_posx, int &t_posy):T_Type(t_posx, t_posy){   //creates a tile instance
    e_disp = ',';
    c_disp = e_disp;
    isSet = false;
}
T_Tile::~T_Tile(){            //destructor for tile instance
    //cleanup code here
}
char T_Tile::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Tile::ret_X(){
    return posx;
}
int T_Tile::ret_Y(){
    return posy;
}
bool T_Tile::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Tile::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Tile::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Tile::ret_ID(){
    return c_disp;
}
bool T_Tile::ret_Set(){
    return isSet;
}
bool T_Tile::ret_Brk(){
    return isBreak;
}
bool T_Tile::ret_Itm(){
    return isItem;
}
bool T_Tile::ret_Lck(){
    return isLock;
}
bool T_Tile::ret_Pass(){
    return isPass;
}
//T_Mtn functions
T_Mtn::T_Mtn(){     //default constructor for tile instance
    
}
T_Mtn::T_Mtn(int &t_posx, int &t_posy): T_Tile(t_posx, t_posy){   //creates a tile instance
    delay = 3;
    c_disp = 'M';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
T_Mtn::~T_Mtn(){            //destructor for tile instance
    //cleanup code here
}
char T_Mtn::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Mtn::ret_X(){
    return posx;
}
int T_Mtn::ret_Y(){
    return posy;
}
bool T_Mtn::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Mtn::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Mtn::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Mtn::ret_ID(){
    return c_disp;
}
bool T_Mtn::ret_Set(){
    return isSet;
}
bool T_Mtn::ret_Brk(){
    return isBreak;
}
bool T_Mtn::ret_Itm(){
    return isItem;
}
bool T_Mtn::ret_Lck(){
    return isLock;
}
bool T_Mtn::ret_Pass(){
    return isPass;
}
//T_Wet functions
T_Wet::T_Wet(){     //default constructor for tile instance
    
}
T_Wet::T_Wet(int &t_posx, int &t_posy):T_Tile(t_posx, t_posy){   //creates a tile instance
    delay = 2;
    c_disp = '~';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
T_Wet::~T_Wet(){            //destructor for tile instance
    //cleanup code here
}
char T_Wet::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Wet::ret_X(){
    return posx;
}
int T_Wet::ret_Y(){
    return posy;
}
bool T_Wet::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Wet::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Wet::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Wet::ret_ID(){
    return c_disp;
}
bool T_Wet::ret_Set(){
    return isSet;
}
bool T_Wet::ret_Brk(){
    return isBreak;
}
bool T_Wet::ret_Itm(){
    return isItem;
}
bool T_Wet::ret_Lck(){
    return isLock;
}
bool T_Wet::ret_Pass(){
    return isPass;
}
//T_Grnd functions
T_Grnd::T_Grnd(){     //default constructor for tile instance
    
}
T_Grnd::T_Grnd(int &t_posx, int &t_posy):T_Tile(t_posx, t_posy){   //creates a tile instance
    c_disp = ',';
    p_disp = c_disp;
    isSet = true;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
T_Grnd::~T_Grnd(){            //destructor for tile instance
    //cleanup code here
}
char T_Grnd::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Grnd::ret_X(){
    return posx;
}
int T_Grnd::ret_Y(){
    return posy;
}
bool T_Grnd::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Grnd::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Grnd::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Grnd::ret_ID(){
    return c_disp;
}
bool T_Grnd::ret_Set(){
    return isSet;
}
bool T_Grnd::ret_Brk(){
    return isBreak;
}
bool T_Grnd::ret_Itm(){
    return isItem;
}
bool T_Grnd::ret_Lck(){
    return isLock;
}
bool T_Grnd::ret_Pass(){
    return isPass;
}
//B_Tile functions
B_Tile::B_Tile(){     //default constructor for tile instance
    
}
B_Tile::B_Tile(int &t_posx, int &t_posy):T_Type(t_posx, t_posy){   //creates a tile instance
    e_disp = '^';
    c_disp = e_disp;
    isSet = true;
}
B_Tile::~B_Tile(){            //destructor for tile instance
    //cleanup code here
}
char B_Tile::DispTile(){       //returns the character to display
    cout << c_disp;
}
int B_Tile::ret_X(){
    return posx;
}
int B_Tile::ret_Y(){
    return posy;
}
bool B_Tile::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void B_Tile::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void B_Tile::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char B_Tile::ret_ID(){
    return c_disp;
}
bool B_Tile::ret_Set(){
    return isSet;
}
bool B_Tile::ret_Brk(){
    return isBreak;
}
bool B_Tile::ret_Itm(){
    return isItem;
}
bool B_Tile::ret_Lck(){
    return isLock;
}
bool B_Tile::ret_Pass(){
    return isPass;
}
//B_Bomb functions
B_Bomb::B_Bomb(){     //default constructor for tile instance
    
}
B_Bomb::B_Bomb(int &t_posx, int &t_posy):B_Tile(t_posx, t_posy){   //creates a tile instance
    delay = 5;
    c_disp = 'B';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = true;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
B_Bomb::~B_Bomb(){            //destructor for tile instance
    //cleanup code here
}
char B_Bomb::DispTile(){       //returns the character to display
    cout << c_disp;
}
int B_Bomb::ret_X(){
    return posx;
}
int B_Bomb::ret_Y(){
    return posy;
}
bool B_Bomb::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void B_Bomb::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void B_Bomb::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char B_Bomb::ret_ID(){
    return c_disp;
}
bool B_Bomb::ret_Set(){
    return isSet;
}
bool B_Bomb::ret_Brk(){
    return isBreak;
}
bool B_Bomb::ret_Itm(){
    return isItem;
}
bool B_Bomb::ret_Lck(){
    return isLock;
}
bool B_Bomb::ret_Pass(){
    return isPass;
}
//B_Tport functions
B_Tport::B_Tport(){     //default constructor for tile instance
    
}
B_Tport::B_Tport(int &t_posx, int &t_posy):B_Tile(t_posx, t_posy){   //creates a tile instance
    delay = 0;
    c_disp = '%';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = true;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
B_Tport::~B_Tport(){            //destructor for tile instance
    //cleanup code here
}
char B_Tport::DispTile(){       //returns the character to display
    cout << c_disp;
}
int B_Tport::ret_X(){
    return posx;
}
int B_Tport::ret_Y(){
    return posy;
}
bool B_Tport::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void B_Tport::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void B_Tport::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char B_Tport::ret_ID(){
    return c_disp;
}
bool B_Tport::ret_Set(){
    return isSet;
}
bool B_Tport::ret_Brk(){
    return isBreak;
}
bool B_Tport::ret_Itm(){
    return isItem;
}
bool B_Tport::ret_Lck(){
    return isLock;
}
bool B_Tport::ret_Pass(){
    return isPass;
}
//B_Wep functions
B_Wep::B_Wep(){     //default constructor for tile instance
    
}
B_Wep::B_Wep(int &t_posx, int &t_posy):B_Tile(t_posx, t_posy){   //creates a tile instance
    delay = 0;
    c_disp = ']';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = true;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
B_Wep::~B_Wep(){            //destructor for tile instance
    //cleanup code here
}
char B_Wep::DispTile(){       //returns the character to display
    cout << c_disp;
}
int B_Wep::ret_X(){
    return posx;
}
int B_Wep::ret_Y(){
    return posy;
}
bool B_Wep::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void B_Wep::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void B_Wep::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char B_Wep::ret_ID(){
    return c_disp;
}
bool B_Wep::ret_Set(){
    return isSet;
}
bool B_Wep::ret_Brk(){
    return isBreak;
}
bool B_Wep::ret_Itm(){
    return isItem;
}
bool B_Wep::ret_Lck(){
    return isLock;
}
bool B_Wep::ret_Pass(){
    return isPass;
}
//O_Tile functions
O_Tile::O_Tile(){     //default constructor for tile instance
    
}
O_Tile::O_Tile(int &t_posx, int &t_posy): T_Type(t_posx, t_posy){   //creates a tile instance
    e_disp = '.';
    c_disp = e_disp;
    isSet = true;
}
O_Tile::~O_Tile(){            //destructor for tile instance
    //cleanup code here
}
char O_Tile::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Tile::ret_X(){
    return posx;
}
int O_Tile::ret_Y(){
    return posy;
}
bool O_Tile::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Tile::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Tile::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Tile::ret_ID(){
    return c_disp;
}
bool O_Tile::ret_Set(){
    return isSet;
}
bool O_Tile::ret_Brk(){
    return isBreak;
}
bool O_Tile::ret_Itm(){
    return isItem;
}
bool O_Tile::ret_Lck(){
    return isLock;
}
bool O_Tile::ret_Pass(){
    return isPass;
}
//O_Door functions
O_Door::O_Door(){     //default constructor for tile instance
    
}
O_Door::O_Door(int &t_posx, int &t_posy): O_Tile(t_posx, t_posy){   //creates a tile instance
    delay = 0;
    c_disp = '/';
    p_disp = c_disp;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = true;     //if true, the tile may be opened by an Actor, using an Item
}
O_Door::~O_Door(){            //destructor for tile instance
    //cleanup code here
}
char O_Door::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Door::ret_X(){
    return posx;
}
int O_Door::ret_Y(){
    return posy;
}
bool O_Door::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Door::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Door::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Door::ret_ID(){
    return c_disp;
}
bool O_Door::ret_Set(){
    return isSet;
}
bool O_Door::ret_Brk(){
    return isBreak;
}
bool O_Door::ret_Itm(){
    return isItem;
}
bool O_Door::ret_Lck(){
    return isLock;
}
bool O_Door::ret_Pass(){
    return isPass;
}
//O_Rock functions
O_Rock::O_Rock(){     //default constructor for tile instance
    
}
O_Rock::O_Rock(int &t_posx, int &t_posy): O_Tile(t_posx, t_posy){   //creates a tile instance
    c_disp = '&';
    p_disp = c_disp;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = true;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
O_Rock::~O_Rock(){            //destructor for tile instance
    //cleanup code here
}
char O_Rock::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Rock::ret_X(){
    return posx;
}
int O_Rock::ret_Y(){
    return posy;
}
bool O_Rock::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Rock::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Rock::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Rock::ret_ID(){
    return c_disp;
}
bool O_Rock::ret_Set(){
    return isSet;
}
bool O_Rock::ret_Brk(){
    return isBreak;
}
bool O_Rock::ret_Itm(){
    return isItem;
}
bool O_Rock::ret_Lck(){
    return isLock;
}
bool O_Rock::ret_Pass(){
    return isPass;
}
//O_Fnce functions
O_Fnce::O_Fnce(){     //default constructor for tile instance
    
}
O_Fnce::O_Fnce(int &t_posx, int &t_posy): O_Tile(t_posx, t_posy){   //creates a tile instance
    c_disp = '$';
    p_disp = c_disp;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
O_Fnce::~O_Fnce(){            //destructor for tile instance
    //cleanup code here
}
char O_Fnce::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Fnce::ret_X(){
    return posx;
}
int O_Fnce::ret_Y(){
    return posy;
}
bool O_Fnce::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Fnce::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Fnce::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Fnce::ret_ID(){
    return c_disp;
}
bool O_Fnce::ret_Set(){
    return isSet;
}
bool O_Fnce::ret_Brk(){
    return isBreak;
}
bool O_Fnce::ret_Itm(){
    return isItem;
}
bool O_Fnce::ret_Lck(){
    return isLock;
}
bool O_Fnce::ret_Pass(){
    return isPass;
}
//O_Wall functions
O_Wall::O_Wall(){     //default constructor for tile instance
    
}
O_Wall::O_Wall(int &t_posx, int &t_posy): O_Tile(t_posx, t_posy){   //creates a tile instance
    c_disp = '#';
    p_disp = c_disp;
    isSet = false;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
O_Wall::~O_Wall(){            //destructor for tile instance
    //cleanup code here
}
char O_Wall::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Wall::ret_X(){
    return posx;
}
int O_Wall::ret_Y(){
    return posy;
}
bool O_Wall::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Wall::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Wall::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Wall::ret_ID(){
    return c_disp;
}
bool O_Wall::ret_Set(){
    return isSet;
}
bool O_Wall::ret_Brk(){
    return isBreak;
}
bool O_Wall::ret_Itm(){
    return isItem;
}
bool O_Wall::ret_Lck(){
    return isLock;
}
bool O_Wall::ret_Pass(){
    return isPass;
}