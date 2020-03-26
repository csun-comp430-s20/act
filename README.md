# act
The Act Language in the future will utilize the concept of an Actor Model paradigm.
Currently it is only planned to support a single actor that supports the creation
of an HSM.

## Setup

### Include /usr/local/bin to PATH
if [ -d "/usr/local/bin" ] ; then
    PATH="/usr/local/bin:$PATH"
fi

### Include cxxtestgen to PATH
if [ -d "$HOME/Projects/Compilers/act/cxxtest-4.3/bin" ] ; then
    PATH="$HOME/{Path to cxxtest folder}/cxxtest-4.3/bin:$PATH"
fi


## Setup for RE/flex

Clone RE/flex repo one directory above act repo:
```sh
git clone https://github.com/Genivia/RE-flex.git
```

For now run these commands to test the lexer:
```sh
sudo apt update
wget https://ftp.gnu.org/gnu/bison/bison-3.2.tar.gz
tar xvzf bison-3.2.tar.gz
sudo apt install autoconf
autoreconf -fi
./configure --prefix=".../libs/re-flex" && make
```

Then cd into the src directory and run these commands:
```sh
../libs/re-flex/bin/reflex lexerspec.l
c++ -I ../libs/re-flex/include/ lex.yy.cpp -L ../libs/re-flex/lib/ -lreflex
./a.out ../tests/act_example.act
```

## Setup for CAF

Clone CAF repo one directory above act repo:
```sh
git clone https://github.com/DanielTellier/actor-framework.git
```

Run configure script in actor-framework folder and direct install to caf_lib folder.
This will will place include files in .../libs/caf_lib:
```sh
./configure --prefix=".../libs/caf_lib"
cd build
make
make test
make install
```

## Compiling and running Lexer and Parser

```sh
bison -v --defines=parser.hpp --output=parser.cpp parserspec.yxx
reflex --header-file lexerspec.l
c++ lex.yy.cpp parser.cpp -lreflex
./a.out ../tests/{file}
```

The above produces an out file that takes a file as an argument from the tests folder
and turns the file stream into a string and tests if the string is valid.

## Running Unit Tests with CxxTest

Downloaded header files for CxxTest here:
https://sourceforge.net/projects/cxxtest/files/cxxtest/

```sh
cxxtestgen --error-printer -o runner.cpp {test-header-file}
g++ -o runner -I g++ -o runner -I "path-to-cxxtest/cxxtest-4.3/" runner.cpp
./runner
```
