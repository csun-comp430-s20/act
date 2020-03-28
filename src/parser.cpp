// A Bison parser, made by GNU Bison 3.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hpp"


// Unqualified %code blocks.
#line 19 "parserspec.yxx" // lalr1.cc:437

    #include "lex.yy.h"  // header file generated with reflex --header-file
    #undef yylex
    #define yylex lexer.lex

#line 51 "parser.cpp" // lalr1.cc:437


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 127 "parser.cpp" // lalr1.cc:512

  /// Build a parser object.
  parser::parser (yy::Lexer& lexer_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 4: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 3: // "identifier"
      case 5: // "hello"
      case 6: // "true"
      case 7: // "false"
      case 8: // "if"
      case 9: // "elif"
      case 10: // "else"
      case 11: // "while"
      case 12: // "return"
      case 13: // "state"
      case 14: // "entry"
      case 15: // "exit"
      case 16: // "on"
      case 17: // "moveif"
      case 18: // "break"
      case 19: // "lambda"
      case 20: // "defevent"
      case 21: // "int"
      case 22: // "bool"
      case 23: // "string"
      case 24: // "+"
      case 25: // ";"
      case 26: // "{"
      case 27: // "}"
      case 28: // "("
      case 29: // ")"
      case 30: // ","
      case 31: // "&&"
      case 32: // "||"
      case 33: // "=<"
      case 34: // "=>"
      case 35: // "<"
      case 36: // ">"
      case 37: // "=="
      case 38: // "="
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if defined __cplusplus && 201103L <= __cplusplus
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 4: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 3: // "identifier"
      case 5: // "hello"
      case 6: // "true"
      case 7: // "false"
      case 8: // "if"
      case 9: // "elif"
      case 10: // "else"
      case 11: // "while"
      case 12: // "return"
      case 13: // "state"
      case 14: // "entry"
      case 15: // "exit"
      case 16: // "on"
      case 17: // "moveif"
      case 18: // "break"
      case 19: // "lambda"
      case 20: // "defevent"
      case 21: // "int"
      case 22: // "bool"
      case 23: // "string"
      case 24: // "+"
      case 25: // ";"
      case 26: // "{"
      case 27: // "}"
      case 28: // "("
      case 29: // ")"
      case 30: // ","
      case 31: // "&&"
      case 32: // "||"
      case 33: // "=<"
      case 34: // "=>"
      case 35: // "<"
      case 36: // ">"
      case 37: // "=="
      case 38: // "="
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if defined __cplusplus && __cplusplus < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 4: // "number"
        value.move< int > (that.value);
        break;

      case 3: // "identifier"
      case 5: // "hello"
      case 6: // "true"
      case 7: // "false"
      case 8: // "if"
      case 9: // "elif"
      case 10: // "else"
      case 11: // "while"
      case 12: // "return"
      case 13: // "state"
      case 14: // "entry"
      case 15: // "exit"
      case 16: // "on"
      case 17: // "moveif"
      case 18: // "break"
      case 19: // "lambda"
      case 20: // "defevent"
      case 21: // "int"
      case 22: // "bool"
      case 23: // "string"
      case 24: // "+"
      case 25: // ";"
      case 26: // "{"
      case 27: // "}"
      case 28: // "("
      case 29: // ")"
      case 30: // ","
      case 31: // "&&"
      case 32: // "||"
      case 33: // "=<"
      case 34: // "=>"
      case 35: // "<"
      case 36: // ">"
      case 37: // "=="
      case 38: // "="
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if defined __cplusplus && 201103L <= __cplusplus
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 4: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 3: // "identifier"
      case 5: // "hello"
      case 6: // "true"
      case 7: // "false"
      case 8: // "if"
      case 9: // "elif"
      case 10: // "else"
      case 11: // "while"
      case 12: // "return"
      case 13: // "state"
      case 14: // "entry"
      case 15: // "exit"
      case 16: // "on"
      case 17: // "moveif"
      case 18: // "break"
      case 19: // "lambda"
      case 20: // "defevent"
      case 21: // "int"
      case 22: // "bool"
      case 23: // "string"
      case 24: // "+"
      case 25: // ";"
      case 26: // "{"
      case 27: // "}"
      case 28: // "("
      case 29: // ")"
      case 30: // ","
      case 31: // "&&"
      case 32: // "||"
      case 33: // "=<"
      case 34: // "=>"
      case 35: // "<"
      case 36: // ">"
      case 37: // "=="
      case 38: // "="
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {

#line 639 "parser.cpp" // lalr1.cc:906
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -61;

  const signed char parser::yytable_ninf_ = -58;

  const short
  parser::yypact_[] =
  {
       7,   -20,    25,    51,   -61,    34,   -61,    52,     4,   -61,
     -61,    33,    28,    36,    55,    61,    90,   -61,   -61,   -61,
     -61,    68,    81,    18,   -61,    82,   -61,   100,   -61,   108,
     -61,   109,   114,   -61,    26,   -61,   124,    26,     5,    10,
      10,    98,    98,   111,   -61,   102,    18,   106,   -61,   -61,
     -61,   112,    15,   -61,   -61,   -61,    -3,    32,   -61,    12,
      45,   -61,   -61,   -61,    73,   116,   118,   -61,    54,   -61,
      89,    21,   -61,   -61,    76,    83,   117,   119,   126,   -61,
     120,   -61,    10,   122,   -61,   -61,   -61,     5,   125,    26,
      89,   -61,   -61,   -61,    87,   -61,   -61,    10,   -61,   -61,
     -61,   -61,   -61,    73,   123,   127,   -61,   -61,   128,   130,
     134,   -61,    99,    98,   129,   -61,   -61,    73,   -61,   -61,
     -61,   -61,   -61,    98,    98,    10,   -61,   131,    13,   -61,
     132,   133,   -61,   135,   136,   138,   103,    10,   -61,   -61,
      98,   -61,   -61,   -61,   -61,   142,   107,   139,   141,   149,
     -61,    98,   143,   144,    98,   -61,   145,   -61
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     3,     2,    73,    13,     0,     1,
      74,     0,     0,     0,     0,     0,     0,    78,    79,    80,
      10,     0,    13,    13,     8,     9,    18,    17,    28,    16,
      31,    33,    15,    41,    14,    44,     0,     0,     0,     0,
       0,    13,    13,     0,     7,     0,    13,     0,    19,    29,
      32,     0,    34,    37,    42,    45,     0,     0,    76,    62,
      60,    61,    64,    65,     0,     0,    49,    50,    48,    55,
       0,    63,    62,    60,     0,     0,     0,     0,     0,     5,
       0,     6,     0,     0,    38,    35,    46,     0,     0,     0,
       0,    63,    43,    54,     0,    66,    67,     0,    70,    71,
      68,    69,    72,     0,     0,     0,    11,    12,     0,     0,
      21,     4,     0,    13,     0,    75,    77,     0,    53,    52,
      51,    56,    58,    13,    13,     0,    20,     0,    22,    25,
       0,     0,    47,     0,     0,     0,     0,     0,    26,    23,
      13,    40,    59,    36,    30,     0,     0,     0,     0,     0,
      39,    13,     0,     0,    13,    24,     0,    27
  };

  const short
  parser::yypgoto_[] =
  {
     -61,   -61,   155,    -4,   -61,   140,   -41,   -61,   148,   -61,
     -61,   -61,    40,   -61,   147,   -61,   146,   -61,   -61,   137,
      42,   -61,   150,   -61,   151,    74,   -61,    84,   -61,   -37,
      79,   -60,   -59,   -61,    91,   -61,   172,   -61,   -30
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     3,    20,    21,    22,    23,    24,    25,    26,   109,
     110,   128,   129,    27,    28,    29,    30,    31,    52,    53,
      85,    32,    33,    34,    35,    65,    66,    67,    94,    68,
      69,    70,    71,    97,   103,     5,     6,    57,    36
  };

  const short
  parser::yytable_[] =
  {
      76,    77,    74,    75,    90,    91,     7,    58,    59,    60,
      61,    62,    63,    72,    73,    61,    62,    63,    45,    47,
       1,    11,    86,    83,    51,    83,    12,     2,     8,    13,
     127,     1,    37,    64,    16,    87,   -53,   -53,    64,    17,
      18,    19,    80,   122,    91,   112,   -57,    17,    18,    19,
     -57,     9,   -57,   -57,     2,    11,    39,   133,    91,   116,
      12,    88,    89,    13,    40,     1,    14,    15,    16,   -52,
     -52,    38,   131,    17,    18,    19,    72,    73,    61,    62,
      63,    41,   134,   135,    11,    95,    96,    42,   136,    12,
     118,   119,    13,    43,     1,    44,    15,    16,    16,   147,
     146,    11,    17,    18,    19,   104,    12,    95,    96,    13,
     153,    13,   105,   156,    95,    96,    12,    11,    51,    17,
      18,    19,    98,    99,   100,   101,   102,    56,   130,    79,
      95,    96,   145,    81,    95,    96,   149,    78,    95,    96,
      82,    92,    93,   108,   106,   148,   107,   111,   113,   123,
     115,   127,   152,   124,   132,     4,   125,   126,   140,   137,
     141,   114,    46,   143,   142,   144,   150,   151,   138,   154,
     139,   155,   157,    48,    49,    50,   121,    10,   120,     0,
       0,   117,    54,     0,     0,    55,     0,     0,     0,    84
  };

  const short
  parser::yycheck_[] =
  {
      41,    42,    39,    40,    64,    64,    26,    37,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    22,    23,
      13,     3,    25,    10,     9,    10,     8,    20,     3,    11,
      17,    13,    28,    28,    16,    38,    24,    25,    28,    21,
      22,    23,    46,   103,   103,    82,    25,    21,    22,    23,
      29,     0,    31,    32,    20,     3,    28,   117,   117,    89,
       8,    29,    30,    11,    28,    13,    14,    15,    16,    24,
      25,    38,   113,    21,    22,    23,     3,     4,     5,     6,
       7,    26,   123,   124,     3,    31,    32,    26,   125,     8,
       3,     4,    11,     3,    13,    27,    15,    16,    16,   140,
     137,     3,    21,    22,    23,    29,     8,    31,    32,    11,
     151,    11,    29,   154,    31,    32,     8,     3,     9,    21,
      22,    23,    33,    34,    35,    36,    37,     3,    29,    27,
      31,    32,    29,    27,    31,    32,    29,    26,    31,    32,
      28,    25,    24,    17,    27,     3,    27,    27,    26,    26,
      25,    17,     3,    26,    25,     0,    28,    27,    26,    28,
      27,    87,    22,    27,    29,    27,    27,    26,   128,    26,
     128,    27,    27,    25,    27,    29,    97,     5,    94,    -1,
      -1,    90,    32,    -1,    -1,    34,    -1,    -1,    -1,    52
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    13,    20,    40,    41,    74,    75,    26,     3,     0,
      75,     3,     8,    11,    14,    15,    16,    21,    22,    23,
      41,    42,    43,    44,    45,    46,    47,    52,    53,    54,
      55,    56,    60,    61,    62,    63,    77,    28,    38,    28,
      28,    26,    26,     3,    27,    42,    44,    42,    47,    53,
      55,     9,    57,    58,    61,    63,     3,    76,    77,     3,
       4,     5,     6,     7,    28,    64,    65,    66,    68,    69,
      70,    71,     3,     4,    68,    68,    45,    45,    26,    27,
      42,    27,    28,    10,    58,    59,    25,    38,    29,    30,
      70,    71,    25,    24,    67,    31,    32,    72,    33,    34,
      35,    36,    37,    73,    29,    29,    27,    27,    17,    48,
      49,    27,    68,    26,    64,    25,    77,    73,     3,     4,
      66,    69,    70,    26,    26,    28,    27,    17,    50,    51,
      29,    45,    25,    70,    45,    45,    68,    28,    51,    59,
      26,    27,    29,    27,    27,    29,    68,    45,     3,    29,
      27,    26,     3,    45,    26,    27,    45,    27
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    39,    40,    40,    41,    41,    41,    41,    42,    42,
      42,    43,    44,    45,    45,    45,    45,    45,    46,    46,
      47,    48,    48,    48,    49,    50,    50,    51,    52,    52,
      53,    54,    54,    55,    55,    55,    56,    57,    57,    58,
      59,    60,    60,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    75,    76,    76,    77,    77,
      77
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     6,     5,     5,     4,     1,     1,
       1,     4,     4,     0,     1,     1,     1,     1,     1,     2,
       5,     1,     2,     3,     8,     1,     2,     8,     1,     2,
       7,     1,     2,     1,     2,     3,     7,     1,     2,     7,
       4,     1,     2,     4,     1,     2,     3,     5,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     3,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     6,     1,     3,     1,     1,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"identifier\"",
  "\"number\"", "\"hello\"", "\"true\"", "\"false\"", "\"if\"", "\"elif\"",
  "\"else\"", "\"while\"", "\"return\"", "\"state\"", "\"entry\"",
  "\"exit\"", "\"on\"", "\"moveif\"", "\"break\"", "\"lambda\"",
  "\"defevent\"", "\"int\"", "\"bool\"", "\"string\"", "\"+\"", "\";\"",
  "\"{\"", "\"}\"", "\"(\"", "\")\"", "\",\"", "\"&&\"", "\"||\"",
  "\"=<\"", "\"=>\"", "\"<\"", "\">\"", "\"==\"", "\"=\"", "$accept",
  "program", "state_block", "state_stmts", "entry_meth", "exit_meth",
  "stmts", "on_event_block", "on_event_term", "if_event_terms",
  "if_event_term", "elif_event_block", "elif_event_term", "while_stmt",
  "while_term", "if_stmt", "if_terms", "if_term", "elif_block",
  "elif_term", "else_term", "assign_stmt", "assign_term", "dec_stmt",
  "dec_term", "exprs", "add_expr", "add_vals", "plus_op", "cond_expr",
  "cond_term", "logic_terms", "logic_vals", "logic_op", "cond",
  "event_def_header", "event_def_term", "args_term", "types", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    66,    66,    66,    68,    69,    70,    71,    72,    72,
      72,    74,    76,    78,    78,    78,    78,    78,    80,    80,
      81,    83,    83,    84,    85,    87,    87,    88,    91,    91,
      92,    94,    94,    95,    95,    95,    96,    97,    97,    98,
      99,   101,   101,   102,   104,   104,   105,   105,   107,   107,
     109,   109,   110,   110,   111,   113,   113,   114,   114,   115,
     116,   116,   116,   116,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   121,   121,   122,   123,   123,   124,   124,
     124
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1035 "parser.cpp" // lalr1.cc:1217
#line 146 "parserspec.yxx" // lalr1.cc:1218


void yy::parser::error(const std::string& msg)
{
    std::cerr << msg << std::endl;
    if (lexer.size() == 0)      // if token is unknown (no match)
        lexer.matcher().winput(); // skip character
}
