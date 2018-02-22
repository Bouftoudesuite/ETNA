cmake_minimum_required(VERSION 3.9)
project(Game)

set(CMAKE_CXX_STANDARD 11)

add_executable(Game
        src/UnitField.hh
        src/Unit.hh
        src/Attack.cpp
        src/Attack.hh
        src/Carrier.cpp
        src/Carrier.hh
        src/Castle.cpp
        src/Castle.hh
        src/CellProperty.cpp
        src/CellProperty.hh
        src/CellType.hh
        src/Corruptor.cpp
        src/Corruptor.hh
        src/Cscreen.hh
        src/Direction.hh
        src/Game.cpp
        src/Game.hh
        src/main.cpp
        src/Map.cpp
        src/Map.hh
        src/Marine.cpp
        src/Marine.hh
        src/Menu.cpp
        src/Menu.hh
        src/Player.cpp
        src/Player.hh
        src/Roach.cpp
        src/Roach.hh
        src/Stalker.cpp
        src/Stalker.hh
        src/Stats.hh
        src/Tank.cpp
        src/Tank.hh
        src/TileMap.cpp
        src/TileMap.hh
        src/Unit.cpp
        src/Ursadon.cpp
        src/Ursadon.hh src/Hero.cpp src/Hero.hh)
