#include <variant>
#include <iostream>
#include <string>

class test_class {
    private:
    std::variant<int, bool, std::string> value;
    std::string type;
    
    public:
    void set(std::variant<int, bool, std::string> val, std::string t) {
        value = val;
        type = t;
    }
    
    int get_num() { return std::get<int>(value) }
    bool get_bool() { return std::get<bool>(value) }
    std::string get_string() { return std::get<std::string>(value) }
};


std::variant<int, bool, std::string> test_func(std::variant<int, bool, std::string> val) {
    // int value = std::get<int>(val);
    std::variant<int, bool, std::string> value = val;

    return value;
}

int main() {
    std::variant<int, bool, std::string> var, var2;
    var = std::string("Hello ");
    var2 = std::string("World");

    std::string newstr = std::get<std::string>(var) + std::get<std::string>(var2);

    std::cout << newstr << std::endl;

    bool b1, b2;

    b1 = false;
    b2 = false;

    bool b3 = b1 + b2;

    std::cout << "The add of bools is " << b3 << std::endl;

    std::string tempy = "Hello";

    std::variant<int, bool, std::string> new_tempy = test_func(tempy);

    std::cout << "The value is " << std::get<std::string>(new_tempy) << std::endl;


    return 0;
}