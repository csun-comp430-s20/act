#include "lexercore.hpp"

namespace act {

LexerCore::LexerCore(std::string const& input)
    : _input(&input)
    , _input_pos(0)
{}

bool LexerCore::eof() const {
    return _input_pos >= _input->size();
}

size_t LexerCore::pos() const {
    return _input_pos;
}

char LexerCore::cur() const {
    if (eof()) {
        return 0;
    }
    else {
        return _input->at(_input_pos);
    }
}

char LexerCore::get() {
    auto c = cur();
    next();
    return c;
}

void LexerCore::next() {
    if (!eof()) {
        ++_input_pos;
    }
}

void LexerCore::skip_ws() {
    while (isspace(cur())) {
        next();
    }
}

PosReverter LexerCore::save_pos() {
    return PosReverter(this, _input_pos);
}

PosReverter::PosReverter(LexerCore* lexer, size_t pos)
    : _lexer(lexer)
    , _pos(pos)
{}

PosReverter::~PosReverter() {
    if (_lexer) {
        _lexer->_input_pos = _pos;
    }
}

void PosReverter::disable() {
    _lexer = nullptr;
}

} // namespace act
