# act
The Act Language in the future will utilize the concept of an Actor Model paradigm.
Currently it is only planned to support a single actor that supports the creation
of an HSM.

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


