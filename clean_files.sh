#!/bin/bash
cd src

FILES=("lex.yy.cpp" "lex.yy.h" "parser.cpp" "parser.hpp" "parser.output" "runner.cpp" "runner.out")
for f in "${FILES[@]}"
do
    if [ -f "$f" ]; then
        rm "$f"
    fi
done