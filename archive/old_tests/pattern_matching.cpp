#include <variant>
#include <iostream>
#include <string>

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

using var_types = std::variant<std::string, bool, int, std::monostate>;

template <typename T>
class exp_node {
    private:
    T data;

    public:
    exp_node(const var_types& v) {

        std::visit(overloaded {
            [this](const std::string& arg) { data = arg; },
            [this](bool arg) { data = arg; },
            [this](int arg) { data = arg; },
            [this](std::monostate) { std::cout << "Improper data type" << std::endl; },
        }, v);
    }

    T get() { return data; }
    
};


int main() {

    const var_types val = std::string("Hello");

    exp_node<std::string> en = exp_node<std::string>(val);

    std::cout << en.get() << std::endl;

    return 0;
}