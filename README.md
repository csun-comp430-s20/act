# act
The Act Language utilizes the Actor Model paradigm.

## Setup

Clone CAF repo from in one directory above act repo:
```sh
git clone https://github.com/DanielTellier/actor-framework.git
```

Run configure script in actor-framework folder and direct install to caf_lib folder.
This will will place include files in .../caf_lib:
```sh
./configure --prefix="..../caf_lib"
cd build
make
make test
make install
```
