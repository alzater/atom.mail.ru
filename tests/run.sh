#!/bin/bash

cd build

cxxtestgen --error-printer -o runner.cpp ../stack/test_stack.h
g++ -std=c++11 -o runner -I"../../../cxxtest-4.4" runner.cpp
./runner
