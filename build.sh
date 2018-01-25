#!/bin/bash

echo "building..."
cd src
g++ main.cpp -o ../build/main.o -std=c++11
echo "product built."