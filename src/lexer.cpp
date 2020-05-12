#include <iostream>
#include "lexer.hpp"
#include "print.hpp"
#include "logger.hpp"
#include "config.hpp"

namespace act {

Token lookup_keyword(MapKeywords const& map, String const& key) {
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
        String value;
        
        if (!isalpha(cur()) && cur() != '_') {
            return LexerError{ pos(), "Not alpha" };
        }

        do {
            value.push_back(get());
        } 
        while (isalpha(cur()) || isdigit(cur()) || cur() == '_' || cur() == '-');

        // If keyword token not found return a name token
        return lookup_keyword(keywords, value);
    };
    
    auto num = [&]() -> LexerToken {
        String s;

        if (!isdigit(cur())) {
            return LexerError{ pos(), "Not digit" };
        }

        do {
            s.push_back(get());
        } 
        while (isdigit(cur()));

        try {
            return TokenIntVal(stoi(s));
        }
        catch (std::exception const&) {
            return LexerError{ pos(), "Exception returning TokenIntVal" };
        }
    };

    auto str = [&]() -> LexerToken {
        if (get() != '"') {
            return LexerError{ pos(), "Not string" };
        }

        String value;
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

        // next();
        return TokenStringVal(value);
    };

    auto single = [&]() -> LexerToken {
        switch (get()) {
            case '{':   return TokenLBrace();
            case '}':   return TokenRBrace();
            case '(':   return TokenLPar();
            case ')':   return TokenRPar();
            case ',':   return TokenComma();
            case ';':   return TokenSemi();
            case '=':
                if(cur() == '=') {
                    next();
                    return TokenEqual();
                } else {
                    return TokenAssign();
                }                    
            case '+':   return TokenPlus();
            case '<':   return TokenLess();
            case '>':   return TokenGreater();
            default: return LexerError{ pos(), "Not single" };
        }
    };

    while (!eof()) {
        if (t(name_or_keyword)
        || t(num)
        || t(str)
        || t(single)) {
            // Ok.
        }
        else {
            return LexerError{ pos(), "something" };
        }
    }

    return tokens;
}

LexerResult lex(String const& input) {
    Lexer l(input);
    return l.run();
}

LexerResult lexify(String const& input) {

    setLogger(config::logFileName, config::logLevel);
    L_(ldebug) << "input: " << input << "\n";
    
    if (LexerResult result = lex(input)) {
        String str_tokens = "The tokens are:\n";
        for (Token const& t : result.value()) {
            str_tokens += print_token(t);
        }

        str_tokens += "\n\n";
        L_(ldebug) << str_tokens;

        return result;
    }
    else {
        LexerError e = result.error();
        L_(lerror) << "Lexer Error: " << e.what << " at " << e.where << "\n";
        return e;
    }
}

} // namespace act