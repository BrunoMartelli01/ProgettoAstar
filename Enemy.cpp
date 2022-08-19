//
// Created by bruno on 31/07/2022.
//

#include "Enemy.h"

Enemy::Enemy(int tileWidth, int tileHeight) : Character(30, 16,
                                                        R"(C:\Users\bruno\CLionProjects\ProgettoAstar\Sprites\enemy.png)",
                                                        1, 0.96, 32, 33, 48, 32, tileWidth, tileHeight, 31 * 30,
                                                        31 * 16) {


}


bool Enemy::move(Dungeon *d, const sf::Vector2i position, const sf::Event event) {


    AStarSearch <MapSearchNode> astarsearch;

    // Create a start state
    MapSearchNode endNode(d);
    endNode.x = position.x;
    endNode.y = position.y;

    // Define the goal state
    MapSearchNode startNode(d);
    startNode.x = Character::getPosition().x;
    startNode.y = Character::getPosition().y;


    // Set Start and goal states

    astarsearch.SetStartAndGoalStates(startNode, endNode);

    if (startNode.x == endNode.x && startNode.y == endNode.y)
        return false;


    unsigned int SearchState;
    unsigned int SearchSteps = 0;

    do {

        SearchState = astarsearch.SearchStep();
        SearchSteps++;
    } while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

    if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {

        MapSearchNode *node = astarsearch.GetSolutionStart();

        MapSearchNode *succNode;
        succNode = astarsearch.GetSolutionNext();

        int x = node->x - succNode->x;
        int y = node->y - succNode->y;

        if (x == 0)
            if (y < 0)
                this->moveDown();
            else
                this->moveUp();
        else if (x < 0)
            this->moveRight();
        else
            this->moveLeft();

        if (succNode->x == position.x && succNode->y == position.y)
            return false;

        MapSearchNode *controlNode = astarsearch.GetSolutionNext();
        if (controlNode->x == position.x && controlNode->y == position.y)
            return false;

        // Once you're done with the solution you can free the nodes up
        astarsearch.FreeSolutionNodes();

    } else if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED) {

        astarsearch.EnsureMemoryFreed();
        return false;
    }

    // Display the number of loops the search went through


    astarsearch.EnsureMemoryFreed();
    return true;


}
