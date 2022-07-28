//
// Created by bruno on 28/07/2022.
//

#include "WorldMap.h"

int WorldMap::GetMap(int x, int y) const {
    {
        if( x < 0 ||
            x >= MAP_WIDTH ||
            y < 0 ||
            y >= MAP_HEIGHT
                )
        {
            return 9;
        }

        return world_map[(y*MAP_WIDTH)+x];
    }
}

int WorldMap::GetTile(int x, int y) const{
    if(1 == GetMap(x,y))
        return 0;
    return 1;
}
