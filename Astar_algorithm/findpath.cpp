////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// STL A* Search implementation
// (C)2001 Justin Heyes-Jones
//
// Finding a path on a simple grid maze
// This shows how to do shortest path finding using A*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stlastar.h" // See header for copyright and usage information

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "findpath.h"

#define DEBUG_LISTS 0
#define DEBUG_LIST_LENGTHS_ONLY 0

using namespace std;

// Global data

// The world map


// map helper functions

int GetMap(int x, int y, Dungeon *d) {
    if (x < 0 ||
        x >= d->getXsize() ||
        y < 0 ||
        y >= d->getYsize()
            ) {
        return 9;
    }

    return d->getCell(x, y);
}



// Definitions


bool MapSearchNode::IsSameState(MapSearchNode &rhs) {

    // same state in a maze search is simply when (x,y) are the same
    if ((x == rhs.x) &&
        (y == rhs.y)) {
        return true;
    } else {
        return false;
    }

}

void MapSearchNode::PrintNodeInfo() {
    char str[100];
    sprintf(str, "Node position : (%d,%d)\n", x, y);

    cout << str;
}

// Here's the heuristic function that estimates the distance from a Node
// to the Goal. 

float MapSearchNode::GoalDistanceEstimate(MapSearchNode &nodeGoal) {
    return abs(x - nodeGoal.x) + abs(y - nodeGoal.y);
}

bool MapSearchNode::IsGoal(MapSearchNode &nodeGoal) {

    if ((x == nodeGoal.x) &&
        (y == nodeGoal.y)) {
        return true;
    }

    return false;
}

// This generates the successors to the given Node. It uses a helper function called
// AddSuccessor to give the successors to the AStar class. The A* specific initialisation
// is done for each node internally, so here you just set the state information that
// is specific to the application
bool MapSearchNode::GetSuccessors(AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node) {

    int parent_x = -1;
    int parent_y = -1;

    if (parent_node) {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }

    if (dungeon == nullptr)
        return false;
    MapSearchNode NewNode;

    // push each possible move except allowing the search to go backwards

    if ((GetMap(x - 1, y, dungeon) < 9)
        && !((parent_x == x - 1) && (parent_y == y))
            ) {
        NewNode = MapSearchNode(x - 1, y, dungeon);
        astarsearch->AddSuccessor(NewNode);
    }

    if ((GetMap(x, y - 1, dungeon) < 9)
        && !((parent_x == x) && (parent_y == y - 1))
            ) {
        NewNode = MapSearchNode(x, y - 1, dungeon);
        astarsearch->AddSuccessor(NewNode);
    }

    if ((GetMap(x + 1, y, dungeon) < 9)
        && !((parent_x == x + 1) && (parent_y == y))
            ) {
        NewNode = MapSearchNode(x + 1, y, dungeon);
        astarsearch->AddSuccessor(NewNode);
    }


    if ((GetMap(x, y + 1, dungeon) < 9)
        && !((parent_x == x) && (parent_y == y + 1))
            ) {
        NewNode = MapSearchNode(x, y + 1, dungeon);
        astarsearch->AddSuccessor(NewNode);
    }

    return true;
}

// given this node, what does it cost to move to successor. In the case
// of our map the answer is the map terrain value at this node since that is 
// conceptually where we're moving

float MapSearchNode::GetCost(MapSearchNode &successor) {
    return (float) GetMap(x, y, dungeon);

}


// Main


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
