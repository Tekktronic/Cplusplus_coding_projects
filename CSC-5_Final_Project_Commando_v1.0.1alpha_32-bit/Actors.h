/* 
 * File:   Actors.h
 * Author: Ezra Guinmapang
 *
 * Created on June 9, 2014, 1:12 PM
 */

#ifndef ACTORS_H
#define	ACTORS_H
#include "TileObj.h"
using namespace std;

typedef TileObj *tile;
class Actor{
    protected:
        int posx, posy;         //stores the x- and the y-coordinates as integers
    public:
        Actor();                //default constructor for actor instance
        Actor(int, int);                //default constructor for actor instance
        ~Actor();               //destructor for actor instance
        virtual tile FindTile(tile**, int&, int&, Actor*) = 0;        //find a match in the tile object array
        virtual void Occupy(tile**, int&, int&); //virtual function to override
        virtual bool Move(tile**, int&, int&);    //virtual function to override
        virtual int ret_X();            //virtual function to override
        virtual int ret_Y();            //virtual function to override
};
class Player: public Actor{
    private:
        bool isAlive;                   //Player's state
        string p_Name;                  //Player's name
        char c_ID;                      //stores the unique character representing the player instance
        tile t_obj;                     //pointer to a tile instance
        vector<T_Type*> i_list;         //vector of pointers to items
    public:
        Player();               //default constructor for player instance
        Player(tile**, int&, int&, string, int, int);         //constructor for player instance
        ~Player();              //destructor for player instance
        tile FindTile(tile**, int&, int&, Actor*);        //find a match in the tile object array
        void Occupy(tile**, int&, int&);           //occupy a tile
        bool Move(tile**, int&, int&);            //move the player instance to another tile
        bool GetItem();
        bool UseItem();
        bool Shoot();
        string ret_Name();
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool ret_St();
};
class Robot: public Actor{
    private:
        bool isAlive;                   //Robot's state
        string p_Name;                  //Robot's name
        char c_ID;                      //stores the unique character representing the player instance
        tile t_obj;                     //pointer to a tile instance
    public:
        Robot();               //default constructor for player instance
        Robot(int, int);
        Robot(tile**, int&, int&, string, int, int);         //constructor for player instance
        ~Robot();              //destructor for player instance
        tile FindTile(tile**, int&, int&, Actor*);        //find a match in the tile object array
        void Occupy(tile**, int&, int&);           //occupy a tile
        bool Move(tile**,int&, int&);            //move the player instance to another tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
};

#endif	/* ACTORS_H */

