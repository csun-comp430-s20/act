#pragma once

#include "token.hpp"
#include "vector.hpp"

using namespace act;

// Convenience function for making Token vectors to test against.
template <typename... Ts>
act::Vector<act::TokenPtr> tokens(Ts&&... in)
{
    act::Vector<act::TokenPtr> out;
    (out.push_back(std::make_unique<Ts>(in)), ...);
    return out;
}

