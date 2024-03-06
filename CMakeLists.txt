cmake_minimum_required(VERSION 3.27)
project(virus_hw1_advanced)

set(CMAKE_CXX_STANDARD 11)

add_executable(virus_hw1_advanced main.cpp
        Simulation.h
        Simulation.cpp
        Covid.h
        Covid.cpp
        XBB.h
        XBB.cpp
        CH.h
        CH.cpp
        BQ.h
        BQ.cpp
        Factory.h
        Factory.cpp
        CovidPtr.cpp
        CovidPtr.h)
