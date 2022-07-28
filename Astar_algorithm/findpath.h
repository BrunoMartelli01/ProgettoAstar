//
// Created by bruno on 27/07/2022.
//

#ifndef TESTASTAR_FINDPATH_H
#define TESTASTAR_FINDPATH_H
class MapSearchNode
{
public:
    int x;	 // the (x,y) positions of the node
    int y;

    MapSearchNode() { x = y = 0; }
    MapSearchNode( int px, int py ) { x=px; y=py; }

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );

    void PrintNodeInfo();


};
int GetMap( int x, int y );
#endif //TESTASTAR_FINDPATH_H
