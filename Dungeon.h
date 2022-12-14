/*
 * Dungeon.h
 *
 *  Created on: 12/apr/2012
 *  Updated on: 13/mar/2018
 *  Author: bertini
 *
 *  Original dungeon building Java code from:
 *  http://roguebasin.roguelikedevelopment.org/index.php?title=Dungeon-Building_Algorithm
 */

#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <iostream>
#include <SFML/System/Vector2.hpp>


enum class TileType {
    Unused = 0, DirtWall, DirtFloor, StoneWall, Corridor, Door, UpStairs, DownStairs, Chest
};

class Dungeon {
public:
    Dungeon();

    Dungeon(TileType *dungeon, int x, int y, int obj);

    ~Dungeon();

    bool createDungeon(int inx, int iny, int inobj = 10);

    bool createDungeon(std::string file, int sizeX, int sizeY);

    TileType getTile(int x, int y) const;


    int getTileInt(int x, int y) const;

    TileType intToTile(char t) const;

    int getCell(int x, int y) const;

    int getXsize() const;

    void setXsize(int xsize);

    int getYsize() const;

    void setYsize(int ysize);

    bool isLegalCell(sf::Vector2i position) const;

    bool isLegalMove(int x, int y, const sf::Vector2i position) const;

    std::string toString() const;
private:
    bool findPath();

    bool makeCorridor(int x, int y, int lenght, int direction);

    bool makeRoom(int x, int y, int xlength, int ylength, int direction);

    int getRand(int min, int max);

    void setCell(int x, int y, TileType tile);

    TileType *dungeonMap;
    //size of the map
    int xsize, ysize;

    //max size of the map
    const int xmax; //80 columns
    const int ymax; //25 rows

    //number of "objects" to generate on the map
    int objects;

    //the old seed from the RNG is saved in this one
    long oldseed;
    //define the chance to generate either a room or a corridor on the map
    //BTW, rooms are 1st priority so actually it's enough to just define the chance
    //of generating a room
    const int chanceRoom;
    const int chanceCorridor;
    const int minRoomWidth;
    const int minRoomHeight;
};


#endif // DUNGEON_H_
