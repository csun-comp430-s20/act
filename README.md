# Act
The Act Language in the future will utilize the concept of an Actor Model paradigm.<br />
Currently it is only planned to support a single actor that supports the creation of an HSM.<br />
**For Comp430 Docs refer to docs folder**

## Grammar
Program: DefEvent* DefState* State+ <br />
State: state NAME '{' Stmt* OnStmt* State* '}' <br />
OnStmt: on NAME '{' GoIfStmt* '}' <br />
Stmt: IfStmt | WhileStmt | DecStmt | AssignStmt <br />
DefEvent: defevent NAME '{' DecStmt* '}' ';' <br />
DefState: defstate NAME ';' <br />
DecStmt: type NAME '=' Expr ';' <br />
type: 'int' | 'string' | 'bool' <br />
GoIfStmt: GoIf GoElIf* | GoIf GoElIf* GoElse <br />
GoIf: 'goif' '(' Expr ')' NAME '{' Stmt* '}' <br />
GoElIf: 'goelif' '(' Expr ')' NAME '{' Stmt* '}' <br />
GoElse: 'goelse' NAME '{' Stmt* '}' <br />
IfStmt: If ElIf* | If ElIf* Else <br />
If: 'if' '(' Expr ')' '{' Stmt* '}' <br />
ElIf: 'elif' '(' Expr ')' '{' Stmt* '}' <br />
Else: 'else' '{' Stmt* '}' <br />
WhileStmt: 'while' '(' Expr ')' '{' Stmt* '}' <br />
Expr: VarExpr | BinOpExpr | IntExpr | StrExpr | BoolExpr | ParenExpr <br />
BinOpExpr: ValExpr op Expr <br />
op: '+' | '<' | '>' | '==' | '&&' <br />
ParenExpr: '(' Expr ')' <br />
ValExpr: VarExpr | IntExpr | StrExpr | BoolExpr <br />
VarExpr: NAME <br />
IntExpr: NUMBER <br />
StrExpr: STRING <br />
BoolExpr: BOOL

## Assumptions
~ Every state has a unique name. <br />
~ Every state must have a proper defstate. <br />
~ Needs word mangling in future so unforseen errors do not occur.

## Requirements
~ g++ version 7+ <br />
~ gcov & lcov for coverage report.

## Build & Run
In the project directory:
```sh
mkdir build
cd build
cmake ..
make
./act <--debug, --info> <input filename: *.act> <log filename: *.txt>
./tests <--debug, --info>
```

## Generate Coverage Report
Run ```bash gen-coverage.sh``` from the project root. <br />
Produces a report at coverage/report/index.html.

## Resources
~ [catch2](https://github.com/catchorg/Catch2) <br />
~ [logging](https://www.drdobbs.com/cpp/logging-in-c/201804215)

## Acknowledgements
Big thank you to the following github project: [dflat](https://github.com/csun-comp430-s19/dflat)
