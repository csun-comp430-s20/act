# Act
The Act Language in the future will utilize the concept of an Actor Model paradigm.
Currently it is only planned to support a single actor that supports the creation
of an HSM.

## Requirements
~ g++ version 7+

## Build & Run
In the project directory:
```sh
mkdir build
cd build
cmake ..
make
./act <input filename>
./tests
```

## Generate Coverage Report
Run ```gen-coverage.sh``` from the project root. Requires gcov+lcov. <br />
Produces a report at coverage/report/index.html.

## Resources


## Acknowledgements
Big thank you to the following github project: [dflat](https://github.com/csun-comp430-s19/dflat)
