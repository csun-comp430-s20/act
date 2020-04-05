#include <variant>
#include <iostream>
#include <string>

int main() {
    std::variant<int, bool, std::string> var, var2;
    var = std::string("Hello ");
    var2 = std::string("World");

    std::string newstr = std::get<std::string>(var) + std::get<std::string>(var2);

    std::cout << newstr << std::endl;

    return 0;
}