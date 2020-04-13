# Act
The Act Language in the future will utilize the concept of an Actor Model paradigm.
Currently it is only planned to support a single actor that supports the creation
of an HSM.

## Setup
### 1) Setup for RE-flex
Download and unzip RE-flex release in act/libs folder:
```sh
wget https://github.com/Genivia/RE-flex/archive/v1.6.6.tar.gz
tar xvzf v1.6.6.tar.gz
cd RE-flex-1.6.6/
./configure && make
sudo make install
```

The above command adds a reflex binary file to /usr/local/bin.

### 2) Setup for Bison
Download and unzip Bison directory in act/libs folder:
```sh
wget https://ftp.gnu.org/gnu/bison/bison-3.5.tar.gz
tar xvzf bison-3.5.tar.gz
cd bison-3.5/
./configure && make
sudo make install
```

The above command adds a bison binary file to /usr/local/bin.

### 3) Setup for CxxTest
Download CxxTest and place in act/libs folder:
https://sourceforge.net/projects/cxxtest/files/cxxtest/

Create a virtual python environment with python 3.5+:
```sh
python3 -m venv /path/to/new/virtual/environment
source /path/to/new/virtual/environment/bin/activate
pip install ply
```

### 4) Include binaries to system profile
Add these lines to ~/.profile (Change {Path to cxxtest folder}):
```sh
if [ -d "/usr/local/bin" ] ; then
    PATH="/usr/local/bin:$PATH"
fi

if [ -d "$HOME/{Path to cxxtest folder}/act/libs/cxxtest-4.3/bin" ] ; then
    PATH="$HOME/{Path to cxxtest folder}/act/libs/cxxtest-4.3/bin:$PATH"
fi
```

Now source the .profile file in the terminal:
```sh
source ~/.profile
```

The above lines allow you to directly call the binaries from your terminal such as:
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
g++ -std=c++17 -o runner.out -I "~/{Path to cxxtest folder}/act/libs/cxxtest-4.3/" runner.cpp lex.yy.cpp parser.cpp -lreflex
./runner.out
```

## Resources/Links
https://github.com/Genivia/RE-flex <br />
https://www.genivia.com/doc/reflex/html/ <br />
https://web.eecs.utk.edu/~bvanderz/teaching/cs461Sp11/notes/parse_tree/

