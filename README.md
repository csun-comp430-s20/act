# Act
The Act Language in the future will utilize the concept of an Actor Model paradigm.
Currently it is only planned to support a single actor that supports the creation
of an HSM.

## Grammar

## Assumptions
~ Every state has a unique name for now. <br />
~ 

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
~ [catch2](https://github.com/catchorg/Catch2) <br />
~ [logging](https://www.drdobbs.com/cpp/logging-in-c/201804215)


## Acknowledgements
Big thank you to the following github project: [dflat](https://github.com/csun-comp430-s19/dflat)
