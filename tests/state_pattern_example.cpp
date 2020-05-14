#include <string>
#include <memory>

using namespace std;

class State {
    public:
    virtual unique_ptr<State> nextState() = 0;
};

class life;
class work;
class rest;

struct TIRED;
struct AWAKE;

struct TIRED {};
struct AWAKE {};

class life: public State {
    private:
    int time;

    public:
    life(int time) {
        this->time = time;
    }

    unique_ptr<State> nextState() {

    }
}

int main() {

    return 0;
}