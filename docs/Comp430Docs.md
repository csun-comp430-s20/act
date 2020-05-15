# Comp 430 Documentation

## Why this language, and why this language design?
The act language is designed to allow for simple and efficient creation
of an [HSM](https://barrgroup.com/embedded-systems/how-to/introduction-hierarchical-state-machines).

## Code snippets
Definition of Events:
```
defevent TIRED {};
defevent AWAKE {};
defevent EXIT {};
```

Definition of On:
```
on AWAKE {
    goif(time == 0) work {}
}
```

Definition of GoIf:
```
goif(time == 17) rest {}
goelse work {
    time = time + 1;
}
```

Definition of State:
```
defstate life;
defstate work;
defstate rest;
```

Definition of State nesting:
```
state life {

    int time = 0;
    int age = 0;

    on AWAKE {
        goif(time == 0) work {}
    }

    state work {
        on TIRED {
            goif(time == 17) rest {}
            goelse work {
                time = time + 1;
            }
        }
    }

    state rest {
        on AWAKE {
            goif(time == 24) work {
                time = 0;
                age = age + 1;
            }  goelse rest {
                time = time + 1;
            }
        }
    }

    state exit {
        on EXIT {
            goif(age == 10) exit {
                exit()
            }
        }
    }
}
```

## Known Limitations
Refer to Assumptions section in README.md

## What would I do differently?
I would have used other code bases as an example earlier on. <br />
I did not choose to use dflat as a reference until the last month. <br />
In the beginning of the semester I chose to use flex and bison for the <br />
lexer and parser but this proved to be too restrictive so I chose to <br />
refer to dflat's repo. 

## Compile/Run/Grammar
Refer to README.md
