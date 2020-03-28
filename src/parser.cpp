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


  const signed char parser::yypact_ninf_ = -103;

  const signed char parser::yytable_ninf_ = -75;

  const short
  parser::yypact_[] =
  {
      64,     5,    25,  -103,  -103,  -103,    47,  -103,  -103,    43,
    -103,    67,    58,    54,  -103,  -103,    69,    56,    71,    76,
      81,    89,   127,  -103,    65,    80,   128,  -103,  -103,   153,
    -103,   115,  -103,   165,  -103,   129,   174,  -103,   163,  -103,
     178,   163,   163,    11,    18,    18,    34,    34,   164,  -103,
     166,   128,   167,  -103,  -103,  -103,   168,    66,  -103,  -103,
    -103,   188,     2,    82,  -103,    90,   192,   110,   123,  -103,
    -103,  -103,   155,   172,   175,  -103,   122,  -103,   130,    33,
    -103,  -103,    12,   139,   171,   173,   198,  -103,   176,  -103,
      18,   179,  -103,  -103,    -6,  -103,    11,   177,   163,   180,
     163,  -103,   130,  -103,  -103,  -103,   184,  -103,  -103,    18,
    -103,  -103,  -103,  -103,  -103,   155,   181,   182,  -103,  -103,
    -103,   160,  -103,   143,    34,   185,  -103,  -103,   102,   201,
     155,  -103,  -103,  -103,  -103,  -103,    34,   134,   183,   208,
     186,   187,  -103,    11,   189,  -103,   115,   165,   174,   163,
    -103,   190,   191,   195,   115,   194,  -103,   165,   174,   163,
     196,  -103,    34,  -103,   197,  -103,  -103,  -103,  -103,  -103,
     199,   202,   200,   203,  -103,    18,  -103,   204,    19,  -103,
    -103,   147,    18,  -103,  -103,   212,   151,   205,   220,    34,
     207,   209,    34,  -103,   210,  -103
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,   102,   103,   104,     0,     4,     3,     2,
      90,     0,    22,     0,     1,    91,     0,     0,     0,     0,
       0,     0,     0,    12,     0,    22,    22,    11,     9,    10,
      27,    26,    38,    25,    48,    50,    24,    58,    23,    61,
       0,    99,    93,     0,     0,     0,    22,    22,     0,     8,
       0,    22,     0,    28,    39,    49,     0,    51,    54,    59,
      62,     0,     0,     0,   100,     0,     0,    79,    77,    78,
      81,    82,     0,     0,    66,    67,    65,    72,     0,    80,
      79,    77,     0,     0,     0,     0,    96,     6,     0,     7,
       0,     0,    55,    52,     0,    63,     0,     0,     0,     0,
       0,    94,     0,    80,    60,    71,     0,    83,    84,     0,
      87,    88,    85,    86,    89,     0,     0,     0,    13,    14,
      97,     0,     5,     0,    22,     0,    92,   101,    16,     0,
       0,    70,    69,    68,    73,    75,    22,    41,     0,     0,
       0,     0,    64,     0,     0,    21,    20,    19,    18,    17,
      95,     0,     0,     0,    45,     0,    46,    44,    43,    42,
       0,    98,    22,    57,     0,    15,    76,    53,    47,    40,
       0,     0,    30,     0,    37,     0,    29,     0,    31,    34,
      56,     0,     0,    35,    32,     0,     0,     0,     0,    22,
       0,     0,    22,    33,     0,    36
  };

  const short
  parser::yypgoto_[] =
  {
    -103,  -103,   224,   -13,  -103,   213,   225,  -103,   -46,  -103,
     206,  -103,  -103,  -103,    48,  -103,  -102,   -25,  -103,  -103,
     -77,   -29,  -103,  -103,   193,    50,   -39,   -31,   -28,   -27,
     -89,  -103,   133,  -103,   -42,   125,   -63,   -62,  -103,   138,
    -103,   232,  -103,  -103,  -103,     8
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     6,    23,    24,    25,    26,    27,   144,    28,    29,
      30,   171,   172,   178,   179,   145,    31,    32,   155,   156,
      33,    34,    35,    57,    58,    93,    36,    37,    38,    39,
      73,    74,    75,   106,    76,    77,    78,    79,   109,   115,
       9,    10,    65,   121,    63,    61
  };

  const short
  parser::yytable_[] =
  {
      84,    85,    82,    83,    55,    59,    54,   125,    11,   102,
     103,    60,    50,    52,    67,    68,    69,    70,    71,    95,
      40,    80,    81,    69,    70,    71,   146,    95,    13,    91,
      42,    12,    96,    40,    40,   154,   177,    17,    88,    72,
      96,   116,    18,   107,   108,    19,    72,    14,   123,    64,
      66,   147,   135,   103,   164,     3,     4,     5,   -74,    40,
     157,    17,   -74,     2,   -74,   -74,    18,   151,   103,    19,
      16,     1,    20,    21,    22,    56,    91,     1,   141,     3,
       4,     5,    41,    17,     2,     3,     4,     5,    18,   148,
     152,    19,    49,     1,    43,    21,    22,    42,   158,    44,
     149,     3,     4,     5,    45,    17,   127,    46,   129,   159,
      18,    97,    98,    19,   143,    47,   173,    59,    55,    99,
     100,    54,    60,     3,     4,     5,    19,    59,    55,    54,
      48,    17,    60,   181,   -70,   -70,    18,    17,    56,    19,
     186,     1,    18,   191,    22,    19,   194,   -69,   -69,     3,
       4,     5,   153,   107,   108,     3,     4,     5,    80,    81,
      69,    70,    71,   110,   111,   112,   113,   114,   117,    22,
     107,   108,   140,    18,   107,   108,   185,    17,   107,   108,
     188,    62,   107,   108,     3,     4,     5,   131,   132,   138,
     139,    94,    86,    87,    89,   101,    90,   104,   118,   105,
     119,   120,   126,   122,   150,   124,   128,   136,   137,   160,
     142,   161,   162,   170,   163,   187,   165,   177,   167,   166,
     168,   169,   174,   190,     7,     8,   183,   175,   184,   176,
     180,   189,   182,   192,   134,    53,   193,   195,    51,   133,
     130,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      92
  };

  const short
  parser::yycheck_[] =
  {
      46,    47,    44,    45,    33,    36,    31,    96,     0,    72,
      72,    38,    25,    26,     3,     4,     5,     6,     7,    25,
      12,     3,     4,     5,     6,     7,   128,    25,     3,    10,
      28,    26,    38,    25,    26,   137,    17,     3,    51,    28,
      38,    29,     8,    31,    32,    11,    28,     0,    90,    41,
      42,   128,   115,   115,   143,    21,    22,    23,    25,    51,
     137,     3,    29,    20,    31,    32,     8,   130,   130,    11,
       3,    13,    14,    15,    16,     9,    10,    13,   124,    21,
      22,    23,    28,     3,    20,    21,    22,    23,     8,   128,
     136,    11,    27,    13,    38,    15,    16,    28,   137,    28,
     128,    21,    22,    23,    28,     3,    98,    26,   100,   137,
       8,    29,    30,    11,    12,    26,   162,   148,   147,    29,
      30,   146,   149,    21,    22,    23,    11,   158,   157,   154,
       3,     3,   159,   175,    24,    25,     8,     3,     9,    11,
     182,    13,     8,   189,    16,    11,   192,    24,    25,    21,
      22,    23,    18,    31,    32,    21,    22,    23,     3,     4,
       5,     6,     7,    33,    34,    35,    36,    37,    29,    16,
      31,    32,    29,     8,    31,    32,    29,     3,    31,    32,
      29,     3,    31,    32,    21,    22,    23,     3,     4,    29,
      30,     3,    28,    27,    27,     3,    28,    25,    27,    24,
      27,     3,    25,    27,     3,    26,    26,    26,    26,    26,
      25,     3,    26,    17,    27,     3,    27,    17,    27,    29,
      25,    27,    25,     3,     0,     0,   178,    28,   178,    27,
      27,    26,    28,    26,   109,    29,    27,    27,    25,   106,
     102,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    13,    20,    21,    22,    23,    40,    41,    45,    79,
      80,    84,    26,     3,     0,    80,     3,     3,     8,    11,
      14,    15,    16,    41,    42,    43,    44,    45,    47,    48,
      49,    55,    56,    59,    60,    61,    65,    66,    67,    68,
      84,    28,    28,    38,    28,    28,    26,    26,     3,    27,
      42,    44,    42,    49,    56,    60,     9,    62,    63,    66,
      68,    84,     3,    83,    84,    81,    84,     3,     4,     5,
       6,     7,    28,    69,    70,    71,    73,    74,    75,    76,
       3,     4,    73,    73,    47,    47,    28,    27,    42,    27,
      28,    10,    63,    64,     3,    25,    38,    29,    30,    29,
      30,     3,    75,    76,    25,    24,    72,    31,    32,    77,
      33,    34,    35,    36,    37,    78,    29,    29,    27,    27,
       3,    82,    27,    73,    26,    69,    25,    84,    26,    84,
      78,     3,     4,    71,    74,    75,    26,    26,    29,    30,
      29,    47,    25,    12,    46,    54,    55,    59,    65,    67,
       3,    75,    47,    18,    55,    57,    58,    59,    65,    67,
      26,     3,    26,    27,    69,    27,    29,    27,    25,    27,
      17,    50,    51,    47,    25,    28,    27,    17,    52,    53,
      27,    73,    28,    53,    64,    29,    73,     3,    29,    26,
       3,    47,    26,    27,    47,    27
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    39,    40,    40,    40,    41,    41,    41,    41,    42,
      42,    42,    42,    43,    44,    45,    46,    46,    46,    46,
      46,    46,    47,    47,    47,    47,    47,    48,    48,    49,
      50,    50,    50,    51,    52,    52,    53,    54,    55,    55,
      56,    57,    57,    57,    57,    57,    57,    58,    59,    59,
      60,    60,    60,    61,    62,    62,    63,    64,    65,    65,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    76,    76,    77,    77,    78,    78,    78,    78,    78,
      79,    79,    80,    81,    81,    81,    82,    82,    82,    83,
      83,    83,    84,    84,    84
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     6,     5,     5,     4,     1,
       1,     1,     1,     4,     4,     8,     0,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     2,     8,
       1,     2,     3,     8,     1,     2,     8,     3,     1,     2,
       7,     0,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     2,     3,     7,     1,     2,     7,     4,     1,     2,
       4,     1,     2,     3,     5,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     6,     0,     2,     4,     0,     1,     3,     0,
       1,     3,     1,     1,     1
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
  "method_def", "method_stmts", "stmts", "on_event_block", "on_event_term",
  "if_event_terms", "if_event_term", "elif_event_block", "elif_event_term",
  "return_stmt", "while_stmt", "while_term", "while_stmts", "break_stmt",
  "if_stmt", "if_terms", "if_term", "elif_block", "elif_term", "else_term",
  "assign_stmt", "assign_term", "dec_stmt", "dec_term", "exprs",
  "add_expr", "add_vals", "plus_op", "cond_expr", "cond_term",
  "logic_terms", "logic_vals", "logic_op", "cond", "event_def_header",
  "event_def_term", "args_type_iden", "args_iden", "args_types", "types", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    66,    66,    66,    66,    68,    69,    70,    71,    72,
      72,    72,    72,    74,    76,    78,    80,    80,    80,    80,
      81,    81,    83,    83,    83,    83,    83,    85,    85,    86,
      89,    89,    90,    91,    93,    93,    94,    97,    99,    99,
     100,   101,   101,   101,   101,   101,   101,   102,   104,   104,
     105,   105,   105,   106,   107,   107,   108,   109,   111,   111,
     112,   114,   114,   115,   115,   117,   117,   119,   119,   120,
     120,   121,   123,   123,   124,   124,   125,   126,   126,   126,
     126,   127,   127,   128,   128,   129,   129,   129,   129,   129,
     131,   131,   132,   134,   134,   134,   135,   135,   135,   136,
     136,   136,   137,   137,   137
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
#line 1070 "parser.cpp" // lalr1.cc:1217
#line 151 "parserspec.yxx" // lalr1.cc:1218


void yy::parser::error(const std::string& msg)
{
    std::cerr << msg << std::endl;
    if (lexer.size() == 0)      // if token is unknown (no match)
        lexer.matcher().winput(); // skip character
}
