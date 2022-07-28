cmake_minimum_required(VERSION 3.22)
project(ProgettoAstar)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProgettoAstar main.cpp Dungeon.cpp Dungeon.h Astar_algorithm/findpath.cpp Astar_algorithm/findpath.h Astar_algorithm/fsa.h Astar_algorithm/stlastar.h TileMap.cpp TileMap.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(c:/SFML/include)
target_link_libraries(ProgettoAstar sfml-system sfml-window sfml-graphics sfml-audio )
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw32/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
