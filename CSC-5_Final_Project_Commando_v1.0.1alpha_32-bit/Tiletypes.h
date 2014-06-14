/* 
 * File:   Tiletypes.h
 * Author: Ezra Guinmapang
 *
 * Created on June 9, 2014, 1:10 PM
 */

#ifndef TILETYPES_H
#define	TILETYPES_H

class T_Type{
    protected:
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
        T_Type();              //default constructor for the tile instance
        T_Type(int&, int&);  //creates a tile object at coordinates specified
        ~T_Type();             //destructor for tile instance
        virtual char DispTile();        //display the tile
        virtual int ret_X();            //return posx
        virtual int ret_Y();            //return posy
        virtual bool Match(int, int);   //match coordinates of tile to appropriate object
        virtual void SetDisp(int, int, char);     //sets the display character for the current tile instance
        virtual void SetEmpty();        //sets the tile instance display to an empty tile
        virtual char ret_ID();          //return c_ID
        virtual bool ret_Set();          //return isSet
        virtual bool ret_Itm();         //return isItem
        virtual bool ret_Lck();         //return isLock
        virtual bool ret_Brk();         //return isBreak
        virtual bool ret_Pass();        //return isPass
};
class E_Tile: public T_Type{   //derived class from base class T_Type
    private:
        
    public:
        E_Tile();              //default constructor for the empty tile instance
        E_Tile(int&, int&);  //creates an empty tile object at coordinates specified
        ~E_Tile();             //destructor for empty tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class T_Tile: public T_Type{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        T_Tile();               //default constructor for boost tile instance
        T_Tile(int&, int&);              //creates a boost tile instance at the coordinates specified
        ~T_Tile();              //destructor for boost tile instance
        virtual char DispTile();        //display the tile
        virtual int ret_X();            //return posx
        virtual int ret_Y();            //return posy
        virtual bool Match(int, int);   //match coordinates of tile to appropriate object
        virtual void SetDisp(int, int, char);     //sets the display character for the current tile instance
        virtual void SetEmpty();        //sets the tile instance display to an empty tile
        virtual char ret_ID();          //return c_ID
        virtual bool ret_Set();          //return isSet
        virtual bool ret_Itm();         //return isItem
        virtual bool ret_Lck();         //return isLock
        virtual bool ret_Brk();         //return isBreak
        virtual bool ret_Pass();        //return isPass
};
class T_Mtn: public T_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        T_Mtn();               //default constructor for empty tile
        T_Mtn(int&, int&);      //creates an terrain tile object at coordinates specified
        ~T_Mtn();              //destructor for terrain tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class T_Wet: public T_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        T_Wet();               //default constructor for empty tile
        T_Wet(int&, int&);      //creates an terrain tile object at coordinates specified
        ~T_Wet();              //destructor for terrain tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class T_Grnd: public T_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        T_Grnd();               //default constructor for empty tile
        T_Grnd(int&, int&);      //creates an terrain tile object at coordinates specified
        ~T_Grnd();              //destructor for terrain tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class B_Tile: public T_Type{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        B_Tile();               //default constructor for boost tile instance
        B_Tile(int&, int&);              //creates a boost tile instance at the coordinates specified
        ~B_Tile();              //destructor for boost tile instance
        virtual char DispTile();        //display the tile
        virtual int ret_X();            //return posx
        virtual int ret_Y();            //return posy
        virtual bool Match(int, int);   //match coordinates of tile to appropriate object
        virtual void SetDisp(int, int, char);     //sets the display character for the current tile instance
        virtual void SetEmpty();        //sets the tile instance display to an empty tile
        virtual char ret_ID();          //return c_ID
        virtual bool ret_Set();          //return isSet
        virtual bool ret_Itm();         //return isItem
        virtual bool ret_Lck();         //return isLock
        virtual bool ret_Brk();         //return isBreak
        virtual bool ret_Pass();        //return isPass
};
class B_Bomb: public B_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        B_Bomb();               //default constructor for boost tile instance
        B_Bomb(int&, int&);              //creates a boost tile instance at the coordinates specified
        ~B_Bomb();              //destructor for boost tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class B_Tport: public B_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        B_Tport();               //default constructor for boost tile instance
        B_Tport(int&, int&);              //creates a boost tile instance at the coordinates specified
        ~B_Tport();              //destructor for boost tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class B_Wep: public B_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        B_Wep();               //default constructor for boost tile instance
        B_Wep(int&, int&);              //creates a boost tile instance at the coordinates specified
        ~B_Wep();              //destructor for boost tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class O_Tile: public T_Type{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Tile();               //default constructor for obstacle tile instance
        O_Tile(int&, int&);     //creates an obstacle tile instance at the coordinates specified
        ~O_Tile();              //destructor for the obstacle tile instance
        virtual char DispTile();        //display the tile
        virtual int ret_X();            //return posx
        virtual int ret_Y();            //return posy
        virtual bool Match(int, int);   //match coordinates of tile to appropriate object
        virtual void SetDisp(int, int, char);     //sets the display character for the current tile instance
        virtual void SetEmpty();        //sets the tile instance display to an empty tile
        virtual char ret_ID();          //return c_ID
        virtual bool ret_Set();          //return isSet
        virtual bool ret_Itm();         //return isItem
        virtual bool ret_Lck();         //return isLock
        virtual bool ret_Brk();         //return isBreak
        virtual bool ret_Pass();        //return isPass
};
class O_Door: public O_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Door();               //default constructor for obstacle tile instance
        O_Door(int&, int&);     //creates an obstacle tile instance at the coordinates specified
        ~O_Door();              //destructor for the obstacle tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class O_Rock: public O_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Rock();               //default constructor for obstacle tile instance
        O_Rock(int&, int&);     //creates an obstacle tile instance at the coordinates specified
        ~O_Rock();              //destructor for the obstacle tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class O_Fnce: public O_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Fnce();               //default constructor for obstacle tile instance
        O_Fnce(int&, int&);     //creates an obstacle tile instance at the coordinates specified
        ~O_Fnce();              //destructor for the obstacle tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class O_Wall: public O_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Wall();               //default constructor for obstacle tile instance
        O_Wall(int&, int&);     //creates an obstacle tile instance at the coordinates specified
        ~O_Wall();              //destructor for the obstacle tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};

#endif	/* TILETYPES_H */

