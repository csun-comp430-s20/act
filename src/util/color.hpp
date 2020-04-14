#pragma once

#include "string.hpp"

namespace act {

enum class Color {
    off      = 0,
    default_ = 39,
    black    = 30,
    red      = 31,
    green    = 32,
    yellow   = 33,
    blue     = 34,
    magenta  = 35,
    cyan     = 36,
    grey     = 37,
//90 	Dark gray 	
//91 	Light red 	
//92 	Light green 	
//93 	Light yellow 	
//94 	Light blue 	
//95 	Light magenta 	
//96 	Light cyan 	
    white    = 97,
};

String to_string(Color c) {
    return "\033[" 
		+ to_string(static_cast<int>(c)) 
		+ "m";
}

} //act

