# Act
The Act Language in the future will utilize the concept of an Actor Model paradigm.
Currently it is only planned to support a single actor that supports the creation
of an HSM.

## Grammar
Program: DefEvent* DefState* State+
State: state NAME '{' Stmt* OnStmt* State* '}'
OnStmt: on NAME '{' GoIfStmt* '}'
Stmt: IfStmt | WhileStmt | DecStmt | AssignStmt
DefEvent: defevent NAME '{' DecStmt* '}' ';'
DefState: defstate NAME ';'
DecStmt: type NAME '=' Expr ';'
type: 'int' | 'string' | 'bool'
GoIfStmt: GoIf GoElIf* | GoIf GoElIf* GoElse
GoIf: 'goif' '(' Expr ')' NAME '{' Stmt* '}'
GoElIf: 'goelif' '(' Expr ')' NAME '{' Stmt* '}'
GoElse: 'goelse' NAME '{' Stmt* '}'
IfStmt: If ElIf* | If ElIf* Else
If: 'if' '(' Expr ')' '{' Stmt* '}'
ElIf: 'elif' '(' Expr ')' '{' Stmt* '}'
Else: 'else' '{' Stmt* '}'
WhileStmt: 'while' '(' Expr ')' '{' Stmt* '}'
Expr: VarExpr | BinOpExpr | IntExpr | StrExpr | BoolExpr | ParenExpr
BinOpExpr: ValExpr op Expr
ParenExpr: '(' Expr ')'
ValExpr: VarExpr | IntExpr | StrExpr | BoolExpr
VarExpr: NAME
IntExpr: NUMBER
StrExpr: STRING
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
~ **For Comp430 Docs refer to docs folder** <br />
~ [catch2](https://github.com/catchorg/Catch2) <br />
~ [logging](https://www.drdobbs.com/cpp/logging-in-c/201804215)

## Acknowledgements
Big thank you to the following github project: [dflat](https://github.com/csun-comp430-s19/dflat)
