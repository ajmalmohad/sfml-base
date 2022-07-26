#!/bin/bash
export LD_LIBRARY_PATH=./sfml
g++ -c main.cpp
g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
./main
