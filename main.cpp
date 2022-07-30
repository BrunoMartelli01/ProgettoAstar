#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>


#include<SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "TileMap.h"
#include "Dungeon.h"
#include <Windows.h>
#include "hero.h"
#include "Astar_algorithm/findpath.h"
#include "Astar_algorithm/stlastar.h"
using namespace std;

bool isLegalCell(int x, int y, const Dungeon &map) {
    switch (map.getTile(x, y)) {
        case TileType::Unused:
            return true;
        case TileType::DirtWall:
            return false;
        case TileType::DirtFloor:
            return true;
        case TileType::StoneWall:
            return false;
        case TileType::Corridor:
            return true;
        case TileType::Door:
            return true;
        case TileType::UpStairs:
            return true;
        case TileType::DownStairs:
            return true;
        case TileType::Chest:
            return true;
        default:
            return false;
    };
}
bool isLegalMove(int x, int y, const Dungeon &map, const Hero &h){
    int newX = h.getPosition().x+ x;
    int newY = h.getPosition().y +y;
    return(isLegalCell(newX,newY, map));
}
bool moveHero(Hero* h,const Dungeon* d, const sf::Event event ){
    switch(event.key.code) {
        case(sf::Keyboard::Right):

            if(isLegalMove(1,0, *d,*h)) {
                h->moveRight();
                return true;
            }
            break;
        case(sf::Keyboard::Left):
            if(isLegalMove(-1,0, *d,*h)) {
                h->moveLeft();
                return true;
            }
            break;

        case(sf::Keyboard::Up):
            if(isLegalMove(0,-1, *d,*h)) {
                h->moveUp();
                return true;
            }
            break;
        case(sf::Keyboard::Down):
            if(isLegalMove(0,1, *d,*h)) {
                h->moveDown();
                return true;
            }
            break;
        default: break;
    }
    return false;
}
bool findPath(Dungeon *d, Hero * h){

    AStarSearch<MapSearchNode> astarsearch;

    unsigned int SearchCount = 0;

    const unsigned int NumSearches = 1;

    while(SearchCount < NumSearches)
    {

        // Create a start state
        MapSearchNode nodeStart(d);
        nodeStart.x = h->getPosition().x;
        nodeStart.y = h->getPosition().y;

        // Define the goal state
        MapSearchNode nodeEnd(d);
        nodeEnd.x = 30;
        nodeEnd.y = 16;

        // Set Start and goal states

        astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do
        {

                SearchState = astarsearch.SearchStep();


            SearchSteps++;

#if DEBUG_LISTS

            cout << "Steps:" << SearchSteps << "\n";

			int len = 0;

			cout << "Open:\n";
			MapSearchNode *p = astarsearch.GetOpenListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				((MapSearchNode *)p)->PrintNodeInfo();
	#endif
				p = astarsearch.GetOpenListNext();

			}

			cout << "Open list has " << len << " nodes\n";

			len = 0;

			cout << "Closed:\n";
			p = astarsearch.GetClosedListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				p->PrintNodeInfo();
	#endif
				p = astarsearch.GetClosedListNext();
			}

			cout << "Closed list has " << len << " nodes\n";
#endif

        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
        {
            cout << "Search found goal state\n";

            MapSearchNode *node = astarsearch.GetSolutionStart();

#if DISPLAY_SOLUTION
            cout << "Displaying solution\n";
#endif
            int steps = 0;

            int MAP_WIDTH = d->getXsize();
            int MAP_HEIGHT = d->getYsize();
            char mapChar [ MAP_WIDTH * MAP_HEIGHT];



            for(int j =0; j< MAP_HEIGHT; j++){
                for(int i = 0; i<MAP_WIDTH; i++){
                    if(GetMap(i,j,d) == 1)
                        mapChar[i+MAP_WIDTH*j] = ' ';
                    if(GetMap(i,j, d) == 9)
                        mapChar[i+MAP_WIDTH*j] = 'X';

                }

            }
            mapChar[nodeStart.x+MAP_WIDTH*nodeStart.y] = 'S';
            mapChar[nodeEnd.x+MAP_WIDTH*nodeEnd.y] = 'E';


            MapSearchNode *precNode = node;
            for( ;; )
            {
                node = astarsearch.GetSolutionNext();

                if( !node )
                {
                    mapChar[precNode->x+MAP_WIDTH*precNode->y] = 'E';
                    break;
                }
                if(node->x == precNode->x)
                    mapChar[node->x+MAP_WIDTH*node->y] = '|';
                if(node->y == precNode->y)
                    mapChar[node->x+MAP_WIDTH*node->y] = '_';
                precNode = node;
                steps ++;

            };

            for(int j =0; j< MAP_HEIGHT; j++) {
                for (int i = 0; i < MAP_WIDTH; i++) {
                    cout<< mapChar[i+MAP_WIDTH*j]<<"  ";

                }
                cout<<endl;
            }
            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();


        }
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
        {
            cout << "Search terminated. Did not find goal state\n";
            return false;
        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";

        SearchCount ++;

        astarsearch.EnsureMemoryFreed();
        return true;
    }



}

int main() {



    sf::RenderWindow window( sf::VideoMode(32*31, 18*31), "Tilemap");
    bool dungeonOk = false;
    Dungeon dungeon;
    std::string sourceCharacter = R"(C:\Users\bruno\CLionProjects\ProgettoAstar\sprites\mage.png)";
    Hero h(sourceCharacter);
    TileMap map;






    while(!dungeonOk) {
        dungeon.createDungeon(32, 18, 50);
        if (!map.load("C:/Users/bruno/CLionProjects/ProgettoAstar/sprites/tilemap.png", sf::Vector2u(62, 62), &dungeon,
                      32, 18))
            return -1;
        if(findPath(&dungeon, &h))
            dungeonOk = true;
    }
    // run the main loop
    sf::Clock timeFrame ;
    sf::Clock timeMove;

    while (window.isOpen()) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            // check the type of the event...
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                        if(moveHero(&h,&dungeon,event))
                                findPath(&dungeon,&h);
                        break;



            }
        }


        window.clear();
        window.draw(map );
        window.draw(h);
        // draw the map


        // draw the map




        /*    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dungeon.getCell(posX,posY) == 1 ){
                // left key is pressed: move our spriteCharacter
                h.moveRight();
                timeMove.restart();

            }else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || dungeon.getCell(posX,posY) == 1) {
                // left key is pressed: move our spriteCharacter  ) {
                // left key is pressed: move our spriteCharacter
                h.moveLeft();
                timeMove.restart();
            }else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                // left key is pressed: move our spriteCharacter
                h.moveUp();

                timeMove.restart();
            }else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                // left key is pressed: move our spriteCharacter
                h.moveDown();


            }
        }*/

        if(timeFrame.getElapsedTime().asMilliseconds() > 250) {

            h.nextFrame();
            timeFrame.restart();
        }


        window.display();

    }

}
