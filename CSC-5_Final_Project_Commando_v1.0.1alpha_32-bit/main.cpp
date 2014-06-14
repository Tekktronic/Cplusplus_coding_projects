/* 
 * NAME: Ezra Guinmapang
 * DATE: May 23, 2014, 5:57 PM
 * PURPOSE: CSC-5 Final Project: Create a program that plays a game called "COMMANDO"
 *          This game is my adaptation of the Unix-BSD game "Robots" This adaptation
 *          will include a "shoot" action that allows a player to kill enemy robots.
 *          This adaptation will also eliminate the "collision" of robots and instead
 *          have robots build obstacles that the player must avoid. All other victory
 *          conditions are the same as the original "Robots" game. This description
 *          may change as subsequent versions are written, coded, and tested, and the
 *          final version may deviate from this original description entirely. This
 *          section will be updated with any changes made to either the gameplay or
 *          the implementation thereof.
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "TileObj.h"
#include "Tiletypes.h"
#include "Actors.h"
using namespace std;

typedef TileObj *tile;
//Global variables and constants

//Function prototypes
void DispMap(tile**, int&, int&, Player*);    //display the map
tile **Populate(int&, int&);   //populate the map
void Destroy(tile**, int&, int&);   //delete the dynamic array
//Exection begins HERE
int main(int argc, char** argv) {
    //declare variables
    srand(static_cast<unsigned int>(time(0)));  //seed the random number generator
    int ROW = 20;         //row size
    int COL = 80;         //column size
    tile **grid;            //2D array of tileobj pointers
    grid = Populate(ROW, COL);       //populates the array with tileobj instances
    Player *Player1 = new Player(grid, ROW, COL, "EzTmp", 1, 1);        //create the player instance
    Player1->Occupy(grid, ROW, COL);
    Robot *Robot1 = new Robot(grid, ROW, COL, "R1", ROW-1, COL-1);      //create the robot instance
    Robot1->Occupy(grid, ROW, COL);
    DispMap(grid, ROW, COL, Player1);       //Display the initial grid
    for(int test = 0; test < 15; test++){
        Player1->Move(grid, ROW, COL);        //tells the player instance to change its position
        Robot1->Move(grid, ROW, COL);        //tells the player instance to change its position
        
        //FindTile(grid, ROW, COL, Player1); //goes through the array and finds the right tile to occupy
        Player1->Occupy(grid, ROW, COL);
        //FindTile(grid, ROW, COL, Robot1); //goes through the array and finds the right tile to occupy
        Robot1->Occupy(grid, ROW, COL);
        DispMap(grid, ROW, COL, Player1);
    }
    //while(Player1->ret_St()) - put this back!!
    Destroy(grid, ROW, COL);
    delete Player1;
    delete Robot1;
    return 0;
}
//Populate the array with tileobj instances
tile **Populate(int &ROW, int &COL){
    fstream file1, file2;
    file1.open("mapgen.dat");
    file2.open("obstacles.dat");
    int tmp1, tmp2;
    float s_Rate = rand()%36/100.0f;     //stores the percentage of the map that is set as special tiles
    tmp2 = rand() % COL;
    tile **grid;
    grid = new tile*[ROW];
    for(int idx = 0; idx < ROW; idx++){
        grid[idx] = new tile[COL];
    }
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            file1 >> tmp1;
            file2 >> tmp2;
            grid[idx][ctr] = new TileObj(idx, ctr, tmp1, tmp2);
        }
    }
    file1.close();
    file2.close();
    return grid;
}
//Display the array of tileobj instances
void DispMap(tile **grid, int &ROW, int &COL, Player *c_Player){
    cout << "--------------------\n";
    cout << "|" << setw(6) << c_Player->ret_Name() << setw(4) << ">\n";
    cout << "--------------------\n";
    cout << "#########################################";
    cout << "#########################################" << setw(12) << c_Player->ret_Name() << "'s Inventory: " << endl;
    for(int idx = 0; idx < ROW; idx++){
        cout << "#";
        for(int ctr = 0; ctr < COL; ctr++){
            grid[idx][ctr]->DispTile();
        }
        cout << "#" << endl;
    }
    cout << "#########################################";
    cout << "#########################################" << endl;
}
//delete the dynamic array
void Destroy(tile **grid, int &ROW, int &COL){
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            delete grid[idx][ctr];
        }
        delete[] grid[COL];
    }
    delete[] grid[ROW];
}