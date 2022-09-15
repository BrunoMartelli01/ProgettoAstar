//
// Created by bruno on 08/08/2022.
//
#include <fstream>
#include <Windows.h>
#include "gtest/gtest.h"
#include "../Dungeon.h"

#include "../Enemy.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include<SFML/Graphics.hpp>

#include <SFML/Graphics/Sprite.hpp>


class TestDungeon : public ::testing::Test {
public:
    virtual void SetUp() {
        d.createDungeon(R"(C:\Users\bruno\CLionProjects\ProgettoAstar\Test\map.txt)", 32, 18);

    }


    int test[32][18];
    Dungeon d;
    std::string correctPath = R"(C:\Users\bruno\CLionProjects\ProgettoAstar\Test\correctPath.txt)";

};


TEST_F(TestDungeon, setDungeon) {
    EXPECT_EQ(32, d.getXsize());
    ASSERT_EQ(18, d.getYsize());
}


TEST_F(TestDungeon, AstarTest) {

    for (int y = 0; y < 18; y++) {
        for (int x = 0; x < 32; x++) {
            test[x][y] = 5;
            if (d.getCell(x, y) == 9)
                std::cout << "x ";
            else std::cout << "  ";
        }
        std::cout << '\n';
    }
    fstream path;
    path.open(correctPath, ios::in);
    sf::Vector2i start = sf::Vector2i(1, 1);
    sf::Event ev;
    std::string correctPos;
    Enemy e;
    sf::Vector2i pos = e.getPos();
    fstream f;


    int x;
    int y;
    if (path.is_open())
        while (getline(path, correctPos)) {


            x = stoi(correctPos);
            EXPECT_EQ(x, pos.x);

            getline(path, correctPos);
            y = stoi(correctPos);

            EXPECT_EQ(y, pos.y);
            e.move(&d, start, ev);
            pos = e.getPos();
            test[x][y] = 0;
        }
    for (int y = 0; y < 18; y++) {
        for (int x = 0; x < 32; x++) {
            if (test[x][y] == 0)
                std::cout << "0 ";
            else if (d.getCell(x, y) == 9)
                std::cout << "x ";
            else std::cout << "  ";

        }
        std::cout << '\n';
    }

}
