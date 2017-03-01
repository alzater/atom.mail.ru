#!/bin/bash

cd build

cxxtestgen --error-printer -o runner.cpp ../stack/test_stack.h
g++ -o runner -I"../../../cxxtest-4.4" runner.cpp
./runner
