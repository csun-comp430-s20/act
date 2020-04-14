#pragma once

#include "string.hpp"

namespace act {

class LexerCore;

class PosReverter {
    LexerCore* _lexer;
    size_t _pos; 

    public:
        PosReverter(LexerCore*, size_t pos);
        ~PosReverter();
        void disable();
};

class LexerCore {
    String const* _input;
    size_t _input_pos;

    friend class PosReverter;

    public:
        explicit LexerCore(String const&);
    
        bool eof() const;
        size_t pos() const;
        char cur() const;
        char get();
        void next();
        void skip_ws();

        [[nodiscard]] 
        PosReverter save_pos();
};  

} // namespace act
