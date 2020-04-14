#!/bin/bash
cd src
TEST_FILE=$1
FILES=("lex.yy.cpp" "lex.yy.h" "parser.cpp" "parser.hpp" "parser.output" "runner.cpp" "runner.out" "a.out")
for f in "${FILES[@]}"
do
    if [ -f "$f" ]; then
        rm "$f"
    fi
done

bison -v --defines=parser.hpp --output=parser.cpp parserspec.yxx
reflex --header-file lexerspec.l
cxxtestgen --error-printer -o runner.cpp $TEST_FILE
g++ -std=c++17 -o runner.out -I "/home/dan/Projects/Compilers/act/libs/cxxtest-4.3/" *.cpp -lreflex
./runner.out