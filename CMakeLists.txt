cmake_minimum_required(VERSION 3.12)
project(Go_Fish_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Go_Fish_
        card.cpp
        card.h
        card_demo.cpp
        deck.cpp
        deck.h
        go_fish.cpp
        player.cpp
        player.h)
