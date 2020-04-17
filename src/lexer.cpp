#include "lexer.hpp"
// #include "map.hpp"

namespace act {

static 
const MapKeywords keywords {
    { "if",   TokenIf() },
    { "else", TokenElse() },
};

Token lookup_keyword(MapKeywords const& map, std::string const& key) {
    auto it = map.find(key);

    // Have to be explicit here. std::optional<any> didn't work.
    if (it == map.end()) {
        return TokenName(key);
    }
    else {
        return it->second;
    }
}

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

        if (LexerToken result = f()) {
            tokens.push_back(result.value());
            skip_ws();
            p.disable();
            return true;
        }
        
        return false;
    };

    auto name_or_keyword = [&]() -> LexerToken {
        std::string value;
        
        if (!isalpha(cur())) {
            return LexerError{ pos(), "Not alpha" };
        }

        do {
            value.push_back(get());
        } 
        while (isalpha(cur()) || isdigit(cur()));

        // if (LexerToken keyword = lookup_keyword(keywords, value)) {
        //     return keyword;
        // }

        // If keyword token not found return a name token
        return lookup_keyword(keywords, value);
    };
    
    auto num = [&]() -> LexerToken {
        std::string s;

        if (!isdigit(cur())) {
            return LexerError{ pos(), "Not digit" };
        }

        do {
            s.push_back(get());
        } 
        while (isdigit(cur()));

        try {
            return TokenNum(stoi(s));
        }
        catch (std::exception const&) {
            return LexerError{ pos(), "Exception returning TokenNum" };
        }
    };

    auto str = [&]() -> LexerToken {
        if (get() != '"') {
            return LexerError{ pos(), "Not string" };
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

    auto single = [&]() -> LexerToken {
        switch (get()) {
            case '(': return TokenLPar();
            case ')': return TokenRPar();
            case ',': return TokenComma();
            default: return LexerError{ pos(), "Error getting single" };
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
            return LexerError{ pos(), "something" };
        }
    }

    return tokens;
}

LexerResult lex(std::string const& input) {
    Lexer l(input);
    return l.run();
}

} // namespace act
