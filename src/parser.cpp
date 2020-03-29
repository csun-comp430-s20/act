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
      case 26: // ":"
      case 27: // "{"
      case 28: // "}"
      case 29: // "("
      case 30: // ")"
      case 31: // ","
      case 32: // "&&"
      case 33: // "||"
      case 34: // "=<"
      case 35: // "=>"
      case 36: // "<"
      case 37: // ">"
      case 38: // "=="
      case 39: // "="
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
      case 26: // ":"
      case 27: // "{"
      case 28: // "}"
      case 29: // "("
      case 30: // ")"
      case 31: // ","
      case 32: // "&&"
      case 33: // "||"
      case 34: // "=<"
      case 35: // "=>"
      case 36: // "<"
      case 37: // ">"
      case 38: // "=="
      case 39: // "="
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
      case 26: // ":"
      case 27: // "{"
      case 28: // "}"
      case 29: // "("
      case 30: // ")"
      case 31: // ","
      case 32: // "&&"
      case 33: // "||"
      case 34: // "=<"
      case 35: // "=>"
      case 36: // "<"
      case 37: // ">"
      case 38: // "=="
      case 39: // "="
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
      case 26: // ":"
      case 27: // "{"
      case 28: // "}"
      case 29: // "("
      case 30: // ")"
      case 31: // ","
      case 32: // "&&"
      case 33: // "||"
      case 34: // "=<"
      case 35: // "=>"
      case 36: // "<"
      case 37: // ">"
      case 38: // "=="
      case 39: // "="
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

#line 643 "parser.cpp" // lalr1.cc:906
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


  const signed char parser::yypact_ninf_ = -116;

  const signed char parser::yytable_ninf_ = -85;

  const short
  parser::yypact_[] =
  {
      61,    -4,    23,    44,  -116,    30,  -116,    57,    37,  -116,
    -116,    46,    47,    60,    73,    97,    89,  -116,  -116,  -116,
    -116,    77,    80,   148,  -116,  -116,   126,  -116,   133,  -116,
     139,  -116,   140,   152,  -116,    41,  -116,   157,    41,     8,
      13,    13,   171,   171,   136,  -116,   134,   148,   147,  -116,
    -116,  -116,   160,    29,  -116,  -116,  -116,   165,    16,   122,
    -116,   172,   175,  -116,  -116,  -116,   166,   127,  -116,   177,
     181,  -116,    78,  -116,   101,   149,  -116,  -116,    54,    76,
     180,   182,   206,  -116,   183,  -116,    13,   185,  -116,  -116,
      22,  -116,    41,     8,   188,    41,    41,   101,  -116,  -116,
    -116,   169,  -116,  -116,    13,  -116,  -116,  -116,  -116,  -116,
     127,   187,   189,  -116,  -116,  -116,   150,  -116,    83,   171,
     173,   212,   192,  -116,  -116,   176,   127,  -116,  -116,  -116,
    -116,  -116,   171,    96,   191,   216,   193,   194,   196,    41,
    -116,  -116,   195,   197,   198,   199,   133,   200,  -116,   139,
     152,    41,   208,  -116,   171,  -116,   155,   226,    25,  -116,
    -116,  -116,  -116,   201,   203,   215,   205,    25,   207,  -116,
     133,   139,   152,    41,  -116,   210,   181,    78,    13,  -116,
     209,    65,  -116,  -116,   214,  -116,  -116,    95,    13,  -116,
    -116,  -116,   231,   158,   213,   234,   171,   217,   218,   171,
    -116,   219,  -116
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     4,     3,    94,    22,     0,     1,
      95,     0,     0,     0,     0,     0,     0,   106,   107,   108,
      12,     0,    22,    22,    11,     9,    10,    27,    26,    38,
      25,    48,    50,    24,    58,    23,    61,     0,   103,     0,
       0,     0,    22,    22,     0,     8,     0,    22,     0,    28,
      39,    49,     0,    51,    54,    59,    62,     0,     0,     0,
     104,    83,    81,    82,    85,    86,     0,     0,    66,     0,
      68,    71,    67,    76,     0,    78,    83,    81,     0,     0,
       0,     0,   100,     6,     0,     7,     0,     0,    55,    52,
       0,    63,    97,     0,     0,     0,    97,     0,    84,    60,
      75,     0,    87,    88,     0,    91,    92,    89,    90,    93,
       0,     0,     0,    13,    14,   101,     0,     5,     0,    22,
       0,     0,     0,    96,   105,     0,     0,    74,    73,    72,
      77,    79,    22,    41,     0,     0,     0,     0,     0,     0,
      98,    64,     0,     0,     0,     0,    45,     0,    46,    44,
      43,    42,     0,   102,    22,    57,    16,     0,     0,    80,
      53,    47,    40,     0,     0,    30,     0,     0,     0,    21,
      20,    19,    18,    17,    99,     0,    70,    69,     0,    29,
       0,    31,    34,    56,     0,    15,    65,     0,     0,    35,
      32,    37,     0,     0,     0,     0,    22,     0,     0,    22,
      33,     0,    36
  };

  const short
  parser::yypgoto_[] =
  {
    -116,  -116,   241,    -1,  -116,   220,  -116,  -116,   -42,  -116,
     222,  -116,  -116,  -116,    62,  -116,  -100,   -24,  -116,  -116,
     -99,   -23,  -116,  -116,   202,    64,   -98,   -27,   -97,   -30,
    -116,   156,    84,  -115,   151,  -116,   -38,   146,   -59,   -57,
    -116,   159,  -116,   248,   161,  -116,  -116,     2
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     3,    20,    21,    22,    23,    24,   168,    25,    26,
      27,   164,   165,   181,   182,   169,    28,    29,   147,   148,
      30,    31,    32,    53,    54,    89,    33,    34,    35,    36,
      68,    69,   175,    70,    71,   101,    72,    73,    74,    75,
     104,   110,     5,     6,   120,   116,    59,    57
  };

  const short
  parser::yytable_[] =
  {
      80,    81,    78,    79,    50,    56,    55,    51,    97,    37,
      98,    61,    62,    63,    64,    65,    76,    77,    63,    64,
      65,    46,    48,     7,    37,    37,     8,    66,    61,    62,
      63,    64,    65,   146,   149,   150,   151,    67,    52,    87,
      60,    91,    67,   176,     9,    92,    84,    91,   118,    37,
       2,   131,   176,    98,    67,    93,   170,   171,   172,   173,
      11,    93,    17,    18,    19,    12,    38,   143,    13,    98,
       1,    14,    15,    16,     1,    87,    40,   137,    17,    18,
      19,     2,   180,    11,   111,    39,   102,   103,    12,    41,
     144,    13,    44,     1,   121,    15,    16,   124,   121,    11,
      42,    17,    18,    19,    12,    45,   112,    13,   102,   103,
     102,   103,   166,   136,   145,   102,   103,    17,    18,    19,
     177,    56,    50,    55,    43,   192,    51,   102,   103,   177,
      76,    77,    63,    64,    65,   105,   106,   107,   108,   109,
     187,   157,    16,    56,    13,    55,    50,    12,    51,    52,
     193,    11,    94,    95,   198,    11,    12,   201,    11,    13,
      58,     1,    83,    12,    16,    82,    13,   167,    90,    17,
      18,    19,   127,   128,    11,    85,    17,    18,    19,    12,
     134,   135,    13,   -84,   -84,   -84,   -84,   -84,   195,    86,
     102,   103,    17,    18,    19,    96,   -74,   -74,   -74,   -73,
     -73,   -73,    99,   138,   139,   100,   142,   139,   113,   115,
     114,   117,   119,   123,   132,   140,   133,   141,   152,   153,
     154,   158,   155,   156,   161,   163,   160,   159,   162,   174,
     178,   179,   180,   183,   194,   185,   186,   197,   188,   191,
     196,     4,    47,   189,   199,   190,   200,   202,    49,   122,
     130,   184,   129,    10,     0,    88,   126,   125
  };

  const short
  parser::yycheck_[] =
  {
      42,    43,    40,    41,    28,    35,    33,    30,    67,     7,
      67,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    22,    23,    27,    22,    23,     3,    19,     3,     4,
       5,     6,     7,   133,   133,   133,   133,    29,     9,    10,
      38,    25,    29,   158,     0,    29,    47,    25,    86,    47,
      20,   110,   167,   110,    29,    39,   156,   156,   156,   156,
       3,    39,    21,    22,    23,     8,    29,   126,    11,   126,
      13,    14,    15,    16,    13,    10,    29,   119,    21,    22,
      23,    20,    17,     3,    30,    39,    32,    33,     8,    29,
     132,    11,     3,    13,    92,    15,    16,    95,    96,     3,
      27,    21,    22,    23,     8,    28,    30,    11,    32,    33,
      32,    33,   154,    30,    18,    32,    33,    21,    22,    23,
     158,   151,   146,   150,    27,    30,   149,    32,    33,   167,
       3,     4,     5,     6,     7,    34,    35,    36,    37,    38,
     178,   139,    16,   173,    11,   172,   170,     8,   171,     9,
     188,     3,    30,    31,   196,     3,     8,   199,     3,    11,
       3,    13,    28,     8,    16,    29,    11,    12,     3,    21,
      22,    23,     3,     4,     3,    28,    21,    22,    23,     8,
      30,    31,    11,    34,    35,    36,    37,    38,    30,    29,
      32,    33,    21,    22,    23,    29,    24,    25,    26,    24,
      25,    26,    25,    30,    31,    24,    30,    31,    28,     3,
      28,    28,    27,    25,    27,     3,    27,    25,    27,     3,
      27,    26,    28,    27,    25,    17,    28,    30,    28,     3,
      29,    28,    17,    28,     3,    28,    26,     3,    29,    25,
      27,     0,    22,   181,    27,   181,    28,    28,    26,    93,
     104,   167,   101,     5,    -1,    53,    97,    96
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    13,    20,    41,    42,    82,    83,    27,     3,     0,
      83,     3,     8,    11,    14,    15,    16,    21,    22,    23,
      42,    43,    44,    45,    46,    48,    49,    50,    56,    57,
      60,    61,    62,    66,    67,    68,    69,    87,    29,    39,
      29,    29,    27,    27,     3,    28,    43,    45,    43,    50,
      57,    61,     9,    63,    64,    67,    69,    87,     3,    86,
      87,     3,     4,     5,     6,     7,    19,    29,    70,    71,
      73,    74,    76,    77,    78,    79,     3,     4,    76,    76,
      48,    48,    29,    28,    43,    28,    29,    10,    64,    65,
       3,    25,    29,    39,    30,    31,    29,    78,    79,    25,
      24,    75,    32,    33,    80,    34,    35,    36,    37,    38,
      81,    30,    30,    28,    28,     3,    85,    28,    76,    27,
      84,    87,    71,    25,    87,    84,    81,     3,     4,    74,
      77,    78,    27,    27,    30,    31,    30,    48,    30,    31,
       3,    25,    30,    78,    48,    18,    56,    58,    59,    60,
      66,    68,    27,     3,    27,    28,    27,    87,    26,    30,
      28,    25,    28,    17,    51,    52,    48,    12,    47,    55,
      56,    60,    66,    68,     3,    72,    73,    76,    29,    28,
      17,    53,    54,    28,    72,    28,    26,    76,    29,    54,
      65,    25,    30,    76,     3,    30,    27,     3,    48,    27,
      28,    48,    28
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    40,    41,    41,    41,    42,    42,    42,    42,    43,
      43,    43,    43,    44,    45,    46,    47,    47,    47,    47,
      47,    47,    48,    48,    48,    48,    48,    49,    49,    50,
      51,    51,    51,    52,    53,    53,    54,    55,    56,    56,
      57,    58,    58,    58,    58,    58,    58,    59,    60,    60,
      61,    61,    61,    62,    63,    63,    64,    65,    66,    66,
      67,    68,    68,    69,    69,    70,    71,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    76,    76,    77,    77,
      77,    78,    78,    78,    78,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    82,    82,    83,    84,    84,    84,
      85,    85,    85,    86,    86,    86,    87,    87,    87
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     1,     1,     6,     5,     5,     4,     1,
       1,     1,     1,     4,     4,     8,     0,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     2,     8,
       1,     2,     3,     8,     1,     2,     8,     3,     1,     2,
       7,     0,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     2,     3,     7,     1,     2,     7,     4,     1,     2,
       4,     1,     2,     3,     5,     7,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     6,     0,     2,     4,
       0,     1,     3,     0,     1,     3,     1,     1,     1
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
  "\":\"", "\"{\"", "\"}\"", "\"(\"", "\")\"", "\",\"", "\"&&\"", "\"||\"",
  "\"=<\"", "\"=>\"", "\"<\"", "\">\"", "\"==\"", "\"=\"", "$accept",
  "program", "state_block", "state_stmts", "entry_meth", "exit_meth",
  "method_def", "method_stmts", "stmts", "on_event_block", "on_event_term",
  "if_event_terms", "if_event_term", "elif_event_block", "elif_event_term",
  "return_stmt", "while_stmt", "while_term", "while_stmts", "break_stmt",
  "if_stmt", "if_terms", "if_term", "elif_block", "elif_term", "else_term",
  "assign_stmt", "assign_term", "dec_stmt", "dec_term", "lambda_def",
  "exprs", "simple_exprs", "add_expr", "add_vals", "plus_op", "cond_expr",
  "cond_term", "logic_terms", "logic_vals", "logic_op", "cond",
  "event_def_header", "event_def_term", "args_type_iden", "args_iden",
  "args_types", "types", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    67,    67,    67,    67,    69,    70,    71,    72,    73,
      73,    73,    73,    75,    77,    79,    81,    81,    81,    81,
      82,    82,    84,    84,    84,    84,    84,    86,    86,    87,
      90,    90,    91,    92,    94,    94,    95,    98,   100,   100,
     101,   102,   102,   102,   102,   102,   102,   103,   105,   105,
     106,   106,   106,   107,   108,   108,   109,   110,   112,   112,
     113,   115,   115,   116,   116,   118,   120,   120,   120,   121,
     121,   123,   123,   124,   124,   125,   127,   127,   128,   128,
     129,   130,   130,   130,   130,   131,   131,   132,   132,   133,
     133,   133,   133,   133,   135,   135,   136,   138,   138,   138,
     139,   139,   139,   140,   140,   140,   141,   141,   141
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
#line 1078 "parser.cpp" // lalr1.cc:1217
#line 143 "parserspec.yxx" // lalr1.cc:1218


void yy::parser::error(const std::string& msg)
{
    std::cerr << msg << std::endl;
    if (lexer.size() == 0)      // if token is unknown (no match)
        lexer.matcher().winput(); // skip character
}
