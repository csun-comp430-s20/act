#pragma once

#include <string>

namespace act {

enum class Id {
    off      = 0,
    symbol   = 30,
    keyword  = 31,
    literal  = 32,
    name     = 33,
};

std::string id_to_string(Id i) {
    return "\033[" 
		+ std::to_string(static_cast<int>(i)) 
		+ "m";
}

} //act

