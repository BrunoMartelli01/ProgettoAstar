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

    Dungeon d;
    std::string correctPath = R"(C:\Users\bruno\CLionProjects\ProgettoAstar\Test\correctPath.txt)";

};


TEST_F(TestDungeon, setDungeon) {
    EXPECT_EQ(32, d.getXsize());
    ASSERT_EQ(18, d.getYsize());
}


TEST_F(TestDungeon, AstarTest) {

    fstream path;
    path.open(correctPath, ios::in);
    sf::Vector2i start = sf::Vector2i(1, 1);
    std::string pos;
    Enemy e;

    int x;
    int y;
    if (path.is_open())
        while (getline(path, pos)) {

            x = pos[0] - '0';
            y = pos[1] - '0';

        }


}
