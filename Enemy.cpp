//
// Created by bruno on 31/07/2022.
//

#include "Enemy.h"
Enemy::Enemy(std::string sourceCharacter): Character(30, 16,sourceCharacter) {
    spriteCharacter.setTexture(textureCharacter);
    spriteCharacter.scale(1, 0.96);


    spriteCharacter.setPosition(Character::getPosition().x*31 , Character::getPosition().y*31  );
    // spriteCharacter.setOrigin(27.0f, 27.0f);

    textureRect = sf::IntRect(0,0, 32,33);
    spriteCharacter.setTextureRect( textureRect);
    frame = 0;

}
void Enemy::moveUp() {

    sf::Vector2i position(0,-1);
    framePosition.x = 0;
    framePosition.y = -7.35f;
    Character::setPosition(Character::getPosition()+position);
    textureRect=sf::IntRect(0,48, 32,33);
    return;
}

void Enemy::moveDown() {
    sf::Vector2i position(0,1);
    framePosition.x = 0;
    framePosition.y = 7.35f;
    Character::setPosition(Character::getPosition()+position);
    textureRect=sf::IntRect(0,0, 32,33);
    return ;



}

void Enemy::moveRight() {
    framePosition.y = 0;
    framePosition.x = 7.35f;
    sf::Vector2i position(1,0);
    Character::setPosition(Character::getPosition()+position);
    textureRect=sf::IntRect(0,48*3, 32,33);

    return;
}

void Enemy::moveLeft() {
    framePosition.y = 0;
    framePosition.x = -7.35f;

    sf::Vector2i position(-1,0);
    Character::setPosition(Character::getPosition()+position);
    textureRect = sf::IntRect(0,48*2, 32,33);

    return ;
}

bool Enemy::nextFrame() {
    if (frame == 4){
        frame =0;
        textureRect.left= frame*32;
        spriteCharacter.setPosition(Character::getPosition().x*31,Character::getPosition().y*31);
        spriteCharacter.setTextureRect(textureRect);
        return  false ;
    }

    spriteCharacter.move(framePosition);
    textureRect.left= frame*32;
    spriteCharacter.setTextureRect(textureRect);
    frame++;

    return true;
}

bool Enemy::moveEnemy(Dungeon *d,const sf::Vector2i heroPosition ) {


        AStarSearch<MapSearchNode> astarsearch;


        // Create a start state
        MapSearchNode endNode(d);
        endNode.x = heroPosition.x;
        endNode.y = heroPosition.y;

        // Define the goal state
        MapSearchNode startNode(d);
        startNode.x = Character::getPosition().x;
        startNode.y =Character::getPosition().y;


        // Set Start and goal states

        astarsearch.SetStartAndGoalStates(startNode, endNode );
        cout<<Character::getPosition().x<<" "<<Character::getPosition().y<<endl;
        if(startNode.x == endNode.x && startNode.y == endNode.y)
            return false;


        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do
        {

            SearchState = astarsearch.SearchStep();
            SearchSteps++;
        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED ) {
            cout << "Search found goal state\n";

            MapSearchNode *node = astarsearch.GetSolutionStart();

            MapSearchNode * succNode;
            succNode= astarsearch.GetSolutionNext();

            cout<<heroPosition.x<<":x  y: "<<heroPosition.y<<endl;
            cout<<succNode->x<<":xS  Sy: "<<succNode->y<<endl;



            int x = node->x-succNode->x;
            int y = node->y-succNode->y;

            if(x==0)
                if(y<0)
                    this->moveDown();
                else
                    this->moveUp();
            else if(x<0)
                this->moveRight();
            else
                this->moveLeft();

            if( succNode->x == heroPosition.x && succNode->y == heroPosition.y  )
                return  false;

            MapSearchNode  *controlNode= astarsearch.GetSolutionNext();
            if( controlNode->x == heroPosition.x && controlNode->y == heroPosition.y  )
                return false;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();

        }
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED ) {
            cout << "Search terminated. Did not find goal state\n";

            astarsearch.EnsureMemoryFreed();
            return false;
        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";

    astarsearch.EnsureMemoryFreed();
        return true;





}

