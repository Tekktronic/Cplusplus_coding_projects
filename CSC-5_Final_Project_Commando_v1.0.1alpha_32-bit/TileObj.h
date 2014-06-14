/* 
 * File:   TileObj.h
 * Author: Ezra Guinmapang
 *
 * Created on June 9, 2014, 1:07 PM
 */

//libraries
#ifndef TILEOBJ_H
#define	TILEOBJ_H
#include "Tiletypes.h"

class TileObj{
    protected:
        T_Type *c_tile;         //current terrain tile
        T_Type *c_item;         //curent item tile
        T_Type *c_obst;         //current obstacle tile
        char e_disp;        //stores the default empty tile display
        char c_disp, p_disp;  //stores the current tile  & previous tile display
        int posx, posy;  //set to store the coordinates which objects need to link to
        bool isSet;      //if true, display this tile, otherwise display empty tile
        bool isPass;     //if true, the tile may be occupied by an Actor
        bool isBreak;    //if true, the tile is breakable by an Actor
        bool isItem;     //if true, the tile may be picked up by an Actor
        bool isLock;     //if true, the tile may be opened by an Actor, using an Item
        int s_Coord(int&, int&); //set the coordinates of the instance
    public:
        TileObj();              //default constructor for the tile instance
        TileObj(int&, int&, int, int);  //creates a tile object at coordinates specified
        ~TileObj();             //destructor for tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
        T_Type *takeItm();//return item address?
};

#endif	/* TILEOBJ_H */

