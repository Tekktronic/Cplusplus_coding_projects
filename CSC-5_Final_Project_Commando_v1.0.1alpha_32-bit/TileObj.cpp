//Libraries
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "TileObj.h"
using namespace std;

//TileObj functions
TileObj::TileObj(){     //default constructor for tile instance
    
}
TileObj::TileObj(int &t_posx, int &t_posy, int id, int id2){   //creates a tile instance
    posx = t_posx;
    posy = t_posy;
    int tmp;
    //creates the appropriate tile type according to the map
    switch(id){
        case 0:{
            c_tile = new T_Grnd(posx, posy);
            break;
        }
        case 1:{
            c_tile = new T_Mtn(posx, posy);
            break;
        }
        case 2:{
            c_tile = new T_Wet(posx, posy);
            break;
        }
        default: break; //shouldn''t reach this!
    }
    switch(id2){
        case 0:{
            c_obst = 0;
            break;
        }
        case 1:{
            c_obst = new O_Wall(posx, posy);
            
            break;
        }
        case 2:{
            c_obst = new O_Door(posx, posy);
            break;
        }
        case 3:{
            c_obst = new O_Fnce(posx, posy); break;
        }
        case 4:{
            c_obst = new O_Rock(posx, posy); break;
        }
        default: break; //shouldn't reach this!
    }
    //generate the obstacle at this tile
    //set the TileObj attributes to the appropriate values for the current tile type
    c_disp = c_tile->ret_ID();
    p_disp = c_disp;
    isSet = c_tile->ret_Set();
    if(c_obst != 0){
        c_disp = c_obst->ret_ID();
        isPass = c_obst->ret_Pass();
        switch(c_disp){
            case '/': isLock = c_obst->ret_Lck(); break;
            case '&': isBreak = c_obst->ret_Brk(); break;
            default: break; //shouldn't reach this
        }
    }
    else{
        isLock = c_tile->ret_Lck();
        isPass = c_tile->ret_Pass();
        isBreak = c_tile->ret_Brk();
    }
    //generate the item at this tile
    tmp = rand() % 100;
    if(isPass){
        if(tmp == 0) c_item = new B_Bomb(posx, posy);
        else if(tmp == 1) c_item = new B_Tport(posx, posy);
        else if(tmp  == 2) c_item = new B_Wep(posx, posy);
    }
    else c_item = 0;
    if(c_item != 0){
        c_disp = c_item->ret_ID();
        isItem = c_item->ret_Itm();
    }
}
TileObj::~TileObj(){            //destructor for tile instance
    delete c_tile;
    delete c_item;
    delete c_obst;
}
char TileObj::DispTile(){       //returns the character to display
    cout << c_disp;
}
int TileObj::ret_X(){
    return posx;
}
int TileObj::ret_Y(){
    return posy;
}
bool TileObj::ret_Brk(){
    return isBreak;
}
bool TileObj::ret_Itm(){
    return isItem;
}
bool TileObj::ret_Lck(){
    return isLock;
}
bool TileObj::ret_Pass(){
    return isPass;
}
T_Type* TileObj::takeItm(){
    return c_item;
}
bool TileObj::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void TileObj::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void TileObj::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
bool TileObj::ret_Set(){
    return isSet;
}