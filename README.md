# act
The Act Language in the future will utilize the concept of an Actor Model paradigm.
Currently it is only planned to support a single actor that supports the creation
of an HSM.

## Setup
### 1) Setup for RE/flex
Clone RE/flex repo one directory above act repo:
```sh
git clone https://github.com/Genivia/RE-flex.git
```

Run configure script in RE-flex directory:
```sh
sudo apt update
sudo apt install autoconf
autoreconf -fi
./configure && make
sudo make install
```

The above command adds a reflex binary file to /usr/local/bin.

### 2) Setup for Bison
Download and unzip Bison directory one directory above act repo:
```sh
wget https://ftp.gnu.org/gnu/bison/bison-3.2.tar.gz
tar xvzf bison-3.2.tar.gz
./configure && make
sudo make install
```

The above command adds a bison binary file to /usr/local/bin.

### 3) Setup for CxxTest
Download CxxTest here one directory above act repo:
https://sourceforge.net/projects/cxxtest/files/cxxtest/

### 4) Include binaries to system profile
Add these lines to ~/.profile (Change {Path to cxxtest folder}):
```sh
if [ -d "/usr/local/bin" ] ; then
    PATH="/usr/local/bin:$PATH"
fi

if [ -d "$HOME/{Path to cxxtest folder}/cxxtest-4.3/bin" ] ; then
    PATH="$HOME/{Path to cxxtest folder}/cxxtest-4.3/bin:$PATH"
fi
```

The above lines allow you to directly call the binaries from your terminal
such as:
```sh
bison --version
```

## Compiling Bison and RE/flex
The following lines create auto generated files for the parser and the lexer:
```sh
bison -v --defines=parser.hpp --output=parser.cpp parserspec.yxx
reflex --header-file lexerspec.l
```

## Running Unit Tests with CxxTest
To run tests call the following commands after compiling (Change {Path to cxxtest folder})
currently one of the test-header-files is called ActTestSuite.hpp:
```sh
cxxtestgen --error-printer -o runner.cpp {test-header-file}
g++ -o runner.out -I "~/{Path to cxxtest folder}/cxxtest-4.3/" runner.cpp lex.yy.cpp parser.cpp -lreflex
./runner.out
```

## Resources/Links
https://github.com/Genivia/RE-flex
https://www.genivia.com/doc/reflex/html/

