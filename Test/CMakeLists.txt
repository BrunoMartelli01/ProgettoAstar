cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp DungeonTest.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES} ../Dungeon.cpp ../Dungeon.h ../Astar_algorithm/findpath.cpp ../Astar_algorithm/findpath.h ../Astar_algorithm/fsa.h ../Astar_algorithm/stlastar.h ../TileMap.cpp ../TileMap.h ../Hero.cpp ../Hero.h ../Character.h ../Character.cpp ../Enemy.cpp ../Enemy.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(c:/SFML/include)
target_link_libraries(runAllTests gtest gtest_main core sfml-system sfml-window sfml-graphics sfml-audio)