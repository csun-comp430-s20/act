#!/bin/bash
cd src

FILES=("lex.yy.cpp" "lex.yy.h" "parser.cpp" "parser.hpp" "parser.output" "runner.cpp" "runner.out")
for f in "${FILES[@]}"
do
    if [ -f "$f" ]; then
        rm "$f"
    fi
done

# bison -v --defines=parser.hpp --output=parser.cpp parserspec.yxx
# reflex --header-file lexerspec.l
# cxxtestgen --error-printer -o runner.cpp ActTestSuite.hpp
# g++ -o runner.out -I "/home/dan/Projects/Compilers/cxxtest-4.3/" runner.cpp lex.yy.cpp parser.cpp -lreflex
# ./runner.out