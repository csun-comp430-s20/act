
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

static int g_time = 0;
static int g_age = 0;

unique_ptr<State> life::nextState() {
    if(g_time == 0) {
        return make_unique<work>(o_work);
    } else {
        return make_unique<life>(o_life);
    }
}

unique_ptr<State> work::nextState() {
    if(g_age == 100) {
        cout << "Exiting!" << endl;
        exit(0);
    } else if(g_time == 17) {
        g_time = g_time + 1;
        return make_unique<rest>(o_rest);
    } else {
        g_time = g_time + 1;
        return make_unique<work>(o_work);
    }
}

unique_ptr<State> rest::nextState() {
    if(g_time == 24) {
        g_time = 0;
        g_age = g_age + 1;
        return make_unique<work>(o_work);
    } else {
        g_time = g_time + 1;
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