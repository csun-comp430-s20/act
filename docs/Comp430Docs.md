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

## Code Generation Example
Code generation utilizes the concept of a state pattern:
```cpp
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class State {
    public:
    virtual unique_ptr<State> nextState() {
        return make_unique<State>(*this);
    }
};

class life: public State {
	public:
	unique_ptr<State> nextState();
};
class work: public State {
	public:
	unique_ptr<State> nextState();
};
class rest: public State {
	public:
	unique_ptr<State> nextState();
};

static life o_life;
static work o_work;
static rest o_rest;

static int g_age = 0;
static int g_time = 0;

unique_ptr<State> life::nextState() {
	if(g_time==0) {

		return make_unique<work>(o_work);
	}
}
unique_ptr<State> work::nextState() {
	if(g_age==100) {
		exit(0);
		return make_unique<life>(o_life);
	} else if(g_time==17) {
		g_time = g_time+1;

		return make_unique<rest>(o_rest);
	} else {
		g_time = g_time+1;

		return make_unique<work>(o_work);
	}
}
unique_ptr<State> rest::nextState() {
	if(g_time==24) {
		g_time = 0;
		g_age = g_age+1;

		return make_unique<work>(o_work);
	} else {
		g_time = g_time+1;

		return make_unique<rest>(o_rest);
	}
}

int main() {
    unique_ptr<State> state = make_unique<life>(o_life);

    while(true) {
        state = state->nextState();
    }

    return 0;
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
