#include <variant>
#include <iostream>
#include <string>

template <typename T>
class exp_data {
    private:
    T data;

    public:
    void set(T data) {
        this->data = data;
    }

    T get() { return this->data; }
};

// class exp_node {
//     private:
//     std::variant<int, bool, std::string> value;
//     exp_data data;
//     std::string type;

//     public:
//     void set(std::variant<int, bool, std::string> val, std::string t) {
//         value = val;
//         type = t;
//     }
// };

int main() {
    std::string temp = "Hello";

    exp_data<std::string> exp;
    exp.set(temp);

    std::cout << exp.get() << std::endl;


    return 0;
}