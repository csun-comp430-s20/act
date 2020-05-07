#pragma once

#include "token.hpp"
#include "parse_result.hpp"
#include "vector.hpp"

namespace act {

class Input;

// Automatically rolls back input if its destructor is called before it's canceled.
// Create it at the beginning of a parse function with Input::mark_rollback(),
//   and cancel it just before returning a good value.
class InputRollback {
    Input& _input;
    size_t _rollback;
    bool   _canceled;

    public:
        InputRollback(Input&, size_t rollback);
        ~InputRollback();
        void cancel();
};

// Input state for parsing.
class Input {
    friend class InputRollback;

    Vector<Token> _tokens;
    size_t _pos;

    public:
    Input(Vector<Token> tokens)
        : _tokens(std::move(tokens))
        , _pos(0)
    {}

    size_t pos() const {
        return _pos;
    }

    bool at_end() const {
        return _pos >= _tokens.size();
    }

    InputRollback mark_rollback() {
        return InputRollback(*this, _pos);
    }

    // If next token is T, advance and return true.
    // Otherwise, return false.
    template <typename T>
    bool match() {
        if (at_end()) {
            return false;
        }
        else if (std::holds_alternative<T>(_tokens[_pos])) {
            _pos++;
            return true;
        }
        else {
            return false;
        }
    }

    template <typename T>
    bool check_done() {
        if (at_end()) {
            return true;
        }

        return std::holds_alternative<T>(_tokens[_pos]);
    }

    // If next token is T, advance and return a valueless non-error.
    // Otherwise, return an error.
    template <typename T>
    Parsed_ expect() {
        if (at_end()) {
            return ParseError{ "expect: no more tokens" };
        }
        else if (std::holds_alternative<T>(_tokens[_pos])) {
            _pos++;
            return Parsed_::ok();
        }
        else {
            return ParseError{ "expect: unexpected" };
        }
    }
    
    // If next token is T, advance and return it.
    // Otherwise, return an error.
    template <typename T>
    Parsed<T> get() {
        if (at_end()) {
            return ParseError{ "get: no more tokens" };
        }
        else {
            T* t = std::get_if<T>(&_tokens[_pos]);

            if (t) {
                _pos++;
                return *t;
            }
            else {
                return ParseError{ "expect: unexpected" };
            }
        }
    }
};

} // namespace act
