#include "lexer.hpp"
#include "map.hpp"

namespace act {

static 
const Map<std::string, Token> keywords {
    { "if",   TokenIf() },
    { "else", TokenElse() },
};

char escape(char c) {
    switch (c) {
        case 'n': return '\n';
        default: return c;
    }
}

class Lexer : private LexerCore {
    public:
        explicit Lexer(std::string const& input)
            : LexerCore(input)
        {}

        LexerResult run();
};

LexerResult Lexer::run() {
    Vector<Token> tokens;

    skip_ws();

    auto t = [&](auto&& f) {
        PosReverter p = save_pos();

        if (std::optional<Token> result = f()) {
            tokens.push_back(result.value());
            skip_ws();
            p.disable();
            return true;
        }
        
        return false;
    };

    auto name_or_keyword = [&]() -> std::optional<Token> {
        std::string value;
        
        if (!isalpha(cur())) {
            return failure;
        }

        do {
            value.push_back(get());
        } 
        while (isalpha(cur()) || isdigit(cur()));

        if (std::optional<Token> keyword = lookup(keywords, value)) {
            return keyword;
        }
    
        return TokenName(value);
    };
    
    auto num = [&]() -> std::optional<Token> {
        std::string s;

        if (!isdigit(cur())) {
            return failure;
        }

        do {
            s.push_back(get());
        } 
        while (isdigit(cur()));

        try {
            return TokenNum(stoi(s));
        }
        catch (std::exception const&) {
            return failure;
        }
    };

    auto str = [&]() -> std::optional<Token> {
        if (get() != '"') {
            return failure;
        }

        std::string value;
        char c = get();

        while (c != '"') {
            if (c == '\\') {
                c = get();
                value += escape(c);
            }
            else {
                value += c;
            }

            c = get();
        }
 
        next();
        return TokenStr(value);
    };

    auto single = [&]() -> std::optional<Token> {
        switch (get()) {
            case '(': return TokenLPar();
            case ')': return TokenRPar();
            case ',': return TokenComma();
            default: return failure;
        }
    };

    while (!eof()) {
        if (t(name_or_keyword)
         || t(num)
         || t(str)
         || t(single)
         ) {
            // Ok.
        }
        else {
            return LexerError{pos(), "something"};
        }
    }

    return tokens;
}

LexerResult lex(std::string const& input) {
    Lexer l(input);
    return l.run();
}

} // namespace act
