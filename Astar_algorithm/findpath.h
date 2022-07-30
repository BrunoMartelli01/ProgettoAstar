//
// Created by bruno on 27/07/2022.
//

#ifndef TESTASTAR_FINDPATH_H
#define TESTASTAR_FINDPATH_H
#include "..\Dungeon.h"
#include "stlastar.h"
class MapSearchNode
{
public:
    int x;	 // the (x,y) positions of the node
    int y;
    MapSearchNode(Dungeon* d) { x = y = 0; dungeon = d;}
    MapSearchNode() { x = y = 0; dungeon = nullptr;}

    MapSearchNode( int px, int py, Dungeon* d ) { x=px; y=py;  dungeon=d; }

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );

    void PrintNodeInfo();
private:
    Dungeon * dungeon;

};

int GetMap( int x, int y , Dungeon* d);

#endif //TESTASTAR_FINDPATH_H
