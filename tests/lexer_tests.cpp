#include "catch2/catch.hpp"
#include "lexertk.hpp"

using namespace std;

TEST_CASE( "Lexer produces correct output", "[lexer]" )
{


    // Test for empty input
    REQUIRE ( tokenize("") == tokens() );
    REQUIRE ( tokenize("//comment\n //anothercomment") == tokens() );
    
    //Tests for single tokens getting tokenized properly
    
    REQUIRE ( tokens(NumberToken(1)) == tokens(
        NumberToken(1)
        ));

    REQUIRE ( tokenize("3") == tokens(
        NumberToken(3)
        ));

    REQUIRE ( tokenize("450") == tokens(
        NumberToken(450)
        ));

    REQUIRE ( tokenize("x") == tokens(
        NameToken("x")
        ));

    REQUIRE ( tokenize("func") == tokens(
        NameToken("func")
        ));

    REQUIRE ( tokenize(";") == tokens(
        SemiToken()
        ));

    REQUIRE ( tokenize("if") == tokens(
        IfToken()
        ));

    REQUIRE ( tokenize("else") == tokens(
        ElseToken()
        ));
    
    REQUIRE ( tokenize("true") == tokens(
        TrueToken()
        ));
    
    REQUIRE ( tokenize("false") == tokens(
        FalseToken()
        ));

    REQUIRE ( tokenize("new") == tokens(
        NewToken()
        ));

    REQUIRE ( tokenize("+") == tokens(
        PlusToken()
        ));

    REQUIRE ( tokenize("-") == tokens(
        MinusToken()
        ));

    REQUIRE ( tokenize("/") == tokens(
        DivisionToken()
        ));

    REQUIRE ( tokenize("*") == tokens(
        MultiplyToken()
        ));

    REQUIRE ( tokenize("=") == tokens(
        AssignToken()
        ));

    REQUIRE ( tokenize("{") == tokens(
        LeftBraceToken()
        ));

    REQUIRE ( tokenize("}") == tokens(
        RightBraceToken()
        ));

    REQUIRE ( tokenize("(") == tokens(
        LeftParenToken()
        ));

    REQUIRE ( tokenize(")") == tokens(
        RightParenToken()
        ));

    REQUIRE ( tokenize(",") == tokens(
        CommaToken()
        ));

    REQUIRE ( tokenize("while") == tokens(
        WhileToken()
        ));

    REQUIRE ( tokenize("!") == tokens(
        NotToken()
        ));

    REQUIRE ( tokenize("||") == tokens(
        OrToken()
        ));

    REQUIRE ( tokenize("&&") == tokens(
        AndToken()
        ));
    
    REQUIRE ( tokenize("==") == tokens(
        EqToken()
        ));
    
    REQUIRE ( tokenize("!=") == tokens(
        NotEqToken()
        ));

    REQUIRE ( tokenize(".") == tokens(
        MemberToken()
        ));

    REQUIRE ( tokenize("return") == tokens(
        ReturnToken()
        ));

    REQUIRE ( tokenize("class") == tokens(
        ClassToken()
        ));

    REQUIRE ( tokenize("extends") == tokens(
        ExtendsToken()
        ));

    REQUIRE ( tokenize("this") == tokens(
        ThisToken()
        ));

    REQUIRE ( tokenize("cons") == tokens(
        ConsToken()
        ));

    REQUIRE ( tokenize("print") == tokens(
        PrintToken()
        ));
    
    //Tests for multiple tokens and special cases being tokenized:
    
    REQUIRE ( tokenize("3    ") == tokens(
        NumberToken(3)
        ));
    
    REQUIRE ( tokenize("    3") == tokens(
        NumberToken(3)
        ));

    REQUIRE ( tokenize("hello") == tokens( 
        NameToken("hello") 
        ));
    
    REQUIRE ( tokenize(" 3 x ") == tokens( 
        NumberToken(3),
        NameToken("x")
        )); 
    
    REQUIRE ( tokenize("3x") == tokens( 
        NumberToken(3),
        NameToken("x")
        )); 
    
    REQUIRE ( tokenize("x3") == tokens( 
        NameToken("x3")
        )); 
    
    REQUIRE ( tokenize("({})") == tokens(
        LeftParenToken(), 
        LeftBraceToken(),
        RightBraceToken(),
        RightParenToken()
        ));
    
    REQUIRE ( tokenize("===") == tokens(
        EqToken(), 
        AssignToken()
        ));

    REQUIRE ( tokenize("var == true") == tokens(
        NameToken("var"), 
        EqToken(),
        TrueToken()
        ));

    REQUIRE ( tokenize("*if+else-/while") == tokens(
        MultiplyToken(),
        IfToken(),
        PlusToken(),
        ElseToken(),
        MinusToken(),
        DivisionToken(),
        WhileToken()
        ));

    REQUIRE ( tokenize("true+false+new+return+this+class+extends") == tokens(
        TrueToken(),
        PlusToken(),
        FalseToken(),
        PlusToken(),
        NewToken(),
        PlusToken(),
        ReturnToken(),
        PlusToken(),
        ThisToken(),
        PlusToken(),
        ClassToken(),
        PlusToken(),
        ExtendsToken()
        ));

    REQUIRE ( tokenize("0 // This is a comment") == tokens(
        NumberToken(0)
        ));
}