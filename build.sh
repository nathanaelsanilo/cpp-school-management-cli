#!/bin/bash

# Change these as needed
SOURCE_FILE="main.cpp print.cpp"
OUTPUT_FILE="main"
CXX_STANDARD="c++17"

clang++ $SOURCE_FILE -o "$OUTPUT_FILE" -std="$CXX_STANDARD" -Wall -Wextra -g
