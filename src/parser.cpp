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
      case 17: // "moveto"
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
      case 17: // "moveto"
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
      case 17: // "moveto"
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
      case 17: // "moveto"
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


  const signed char parser::yypact_ninf_ = -64;

  const signed char parser::yytable_ninf_ = -39;

  const signed char
  parser::yypact_[] =
  {
      34,    -9,     3,    10,    44,   -64,   -64,   -64,    69,   -64,
      33,   -64,    63,   -64,    66,    46,   -64,    37,   -64,    70,
     -64,    76,     2,     7,     7,    64,   -64,   -64,   -64,    65,
      13,   -64,   -64,   -64,   -64,   -10,    58,    60,   -64,   -64,
     -64,    14,    71,    67,   -64,    -5,   -64,    31,    21,   -64,
     -64,    41,    45,    37,     7,    68,   -64,   -64,   -64,     2,
      31,   -64,   -64,   -64,    83,   -64,   -64,     7,   -64,   -64,
     -64,   -64,   -64,    14,    72,    73,    59,   -64,    49,    40,
      75,    14,   -64,   -64,   -64,   -64,   -64,    40,    40,    77,
      37,    78,    74,   -64,    79,    80,    82,   -64,   -64,    40,
     -64,   -64,   -64,   -64,    84,   -64
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,     0,     0,     0,     0,    59,    60,    61,     0,     3,
       8,     9,     7,    12,    14,     6,    22,     5,    25,     2,
      54,     0,     0,     0,     0,     0,     1,    10,    13,     0,
      15,    17,    23,    26,    55,     0,    43,    41,    42,    45,
      46,     0,     0,    30,    31,    29,    36,     0,    44,    43,
      41,     0,     0,     0,     0,     0,    18,    16,    27,     0,
       0,    44,    24,    35,     0,    47,    48,     0,    51,    52,
      49,    50,    53,     0,     0,     0,     0,    57,     0,     4,
       0,     0,    34,    33,    32,    37,    39,     4,     4,     0,
       0,     0,     0,    28,     0,     0,     0,    56,    58,     4,
      21,    40,    19,    11,     0,    20
  };

  const signed char
  parser::yypgoto_[] =
  {
     -64,   -64,   -63,   -64,    85,   -64,    91,   -64,   -64,    86,
     -64,   -64,    90,   -64,    89,    38,   -64,    48,   -64,   -20,
      43,   -41,   -40,   -64,    53,   -64,    95,   -64,   -51
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     8,     9,    10,    11,    12,    13,    30,    14,    31,
      57,    15,    16,    17,    18,    42,    43,    44,    64,    45,
      46,    47,    48,    67,    73,    19,    20,    76,    21
  };

  const signed char
  parser::yytable_[] =
  {
      60,    61,    77,    51,    52,    36,    37,    38,    39,    40,
      49,    50,    38,    39,    40,    58,    92,    49,    50,    38,
      39,    40,    29,    55,    95,    96,    65,    66,    59,    22,
      41,    23,    86,    61,    78,    41,   104,     1,    24,    98,
      94,    61,     2,     1,     3,     3,   -38,    25,     2,     1,
     -38,     3,   -38,   -38,     4,     5,     6,     7,     5,     6,
       7,     5,     6,     7,    68,    69,    70,    71,    72,    26,
      74,     2,    65,    66,    75,    29,    65,    66,    91,    35,
      65,    66,   -34,   -34,   -33,   -33,    82,    83,    89,    90,
       4,    63,    53,    54,    79,    27,    62,    80,    87,    88,
      93,   100,    97,    28,    99,    32,    33,   102,   101,   103,
      85,   105,    84,    81,    34,     0,    56
  };

  const signed char
  parser::yycheck_[] =
  {
      41,    41,    53,    23,    24,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    25,    79,     3,     4,     5,
       6,     7,     9,    10,    87,    88,    31,    32,    38,    38,
      28,    28,    73,    73,    54,    28,    99,     3,    28,    90,
      81,    81,     8,     3,    11,    11,    25,     3,     8,     3,
      29,    11,    31,    32,    20,    21,    22,    23,    21,    22,
      23,    21,    22,    23,    33,    34,    35,    36,    37,     0,
      29,     8,    31,    32,    29,     9,    31,    32,    29,     3,
      31,    32,    24,    25,    24,    25,     3,     4,    29,    30,
      20,    24,    28,    28,    26,    10,    25,    59,    26,    26,
      25,    27,    25,    12,    26,    15,    17,    27,    29,    27,
      67,    27,    64,    60,    19,    -1,    30
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     8,    11,    20,    21,    22,    23,    40,    41,
      42,    43,    44,    45,    47,    50,    51,    52,    53,    64,
      65,    67,    38,    28,    28,     3,     0,    43,    45,     9,
      46,    48,    51,    53,    65,     3,     3,     4,     5,     6,
       7,    28,    54,    55,    56,    58,    59,    60,    61,     3,
       4,    58,    58,    28,    28,    10,    48,    49,    25,    38,
      60,    61,    25,    24,    57,    31,    32,    62,    33,    34,
      35,    36,    37,    63,    29,    29,    66,    67,    58,    26,
      54,    63,     3,     4,    56,    59,    60,    26,    26,    29,
      30,    29,    41,    25,    60,    41,    41,    25,    67,    26,
      27,    29,    27,    27,    41,    27
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    39,    40,    40,    41,    41,    41,    41,    41,    42,
      42,    43,    44,    44,    45,    45,    45,    46,    46,    47,
      48,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    64,    64,    65,    66,    66,    67,
      67,    67
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     0,     1,     1,     1,     1,     1,
       2,     7,     1,     2,     1,     2,     3,     1,     2,     7,
       7,     4,     1,     2,     4,     1,     2,     3,     5,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     6,     1,     3,     1,
       1,     1
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
  "\"exit\"", "\"on\"", "\"moveto\"", "\"break\"", "\"lambda\"",
  "\"defevent\"", "\"int\"", "\"bool\"", "\"string\"", "\"+\"", "\";\"",
  "\"{\"", "\"}\"", "\"(\"", "\")\"", "\",\"", "\"&&\"", "\"||\"",
  "\"=<\"", "\"=>\"", "\"<\"", "\">\"", "\"==\"", "\"=\"", "$accept",
  "program", "stmts", "while_stmt", "while_term", "if_stmt", "if_terms",
  "elif_block", "if_term", "elif_term", "else_term", "assign_stmt",
  "assign_term", "dec_stmt", "dec_term", "exprs", "add_expr", "add_vals",
  "plus_op", "cond_expr", "cond_term", "logic_terms", "logic_vals",
  "logic_op", "cond", "event_def_header", "event_def_term", "args_term",
  "types", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    66,    66,    66,    68,    68,    68,    68,    68,    70,
      70,    71,    73,    73,    74,    74,    74,    75,    75,    76,
      77,    78,    80,    80,    81,    83,    83,    84,    84,    86,
      86,    88,    88,    89,    89,    90,    92,    92,    93,    93,
      94,    95,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    98,    98,    98,   100,   100,   101,   102,   102,   103,
     103,   103
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
#line 996 "parser.cpp" // lalr1.cc:1217
#line 136 "parserspec.yxx" // lalr1.cc:1218


void yy::parser::error(const std::string& msg)
{
    std::cerr << msg << std::endl;
    if (lexer.size() == 0)      // if token is unknown (no match)
        lexer.matcher().winput(); // skip character
}
