//
// Created by bruno on 08/08/2022.
//
#include "gtest/gtest.h"
#include "../Dungeon.h"
#include "../Astar_algorithm/findpath.h"

class TestDungeon : public ::testing::Test {
protected:
    virtual void SetUp() {
        d.createDungeon(32, 18, 50);
    }

    Dungeon d;
};

bool findPath(Dungeon *d) {
    AStarSearch<MapSearchNode> astarsearch;
    // Create a start state
    MapSearchNode endNode(d);
    endNode.x = d->getXsize() - 2;
    endNode.y = d->getYsize() - 2;
    // Define the goal state
    MapSearchNode startNode(d);
    startNode.x = 1;
    startNode.y = 1;

    // Set Start and goal states
    astarsearch.SetStartAndGoalStates(startNode, endNode);

    unsigned int SearchState;
    unsigned int SearchSteps = 0;

    do {

        SearchState = astarsearch.SearchStep();
        SearchSteps++;
    } while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);


    if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
        // cout << "strada trovata" << endl;
        astarsearch.FreeSolutionNodes();

        astarsearch.EnsureMemoryFreed();
        return true;
    } else
        astarsearch.EnsureMemoryFreed();
    //cout << "strada NON trovata" << endl;

    return false;
}

TEST_F(TestDungeon, setDungeon) {
    EXPECT_EQ(32, d.getXsize());
    ASSERT_EQ(18, d.getYsize());
}

TEST_F(TestDungeon, ExistPath) {
    ASSERT_EQ(findPath(&d), true);
}
