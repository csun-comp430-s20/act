#pragma once

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