/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

/* 
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16
#include"stack.h"
#include"optype.h"
#include"code.h"
extern int yylineno;
extern char *yytext;
enum FLAG {GLOBAL,LOCAL,PROC,FUNC};
enum FLAG flag=GLOBAL; 
FILE *fp;
static int currentstack=0;
static int startstack=0;
static int opnumber=0;
static int procvarnumber=0;
static char procnamebuffer[256];
static int ifneedreturn=0;
void generate(int opcode,REG base,REG index,REG address);
void backpatch(int a,REG b);
void yyerror(char *s);

#line 91 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SBEGIN = 258,
    DO = 259,
    ELSE = 260,
    SEND = 261,
    FOR = 262,
    FORWARD = 263,
    FUNCTION = 264,
    IF = 265,
    PROCEDURE = 266,
    PROGRAM = 267,
    READ = 268,
    THEN = 269,
    TO = 270,
    VAR = 271,
    WHILE = 272,
    WRITE = 273,
    PLUS = 274,
    MINUS = 275,
    MULT = 276,
    DIV = 277,
    EQ = 278,
    NEQ = 279,
    LE = 280,
    LT = 281,
    GE = 282,
    GT = 283,
    LPAREN = 284,
    RPAREN = 285,
    LBRACKET = 286,
    RBRACKET = 287,
    COMMA = 288,
    SEMICOLON = 289,
    COLON = 290,
    INTERVAL = 291,
    PERIOD = 292,
    ASSIGN = 293,
    NUMBER = 294,
    IDENT = 295
  };
#endif
/* Tokens.  */
#define SBEGIN 258
#define DO 259
#define ELSE 260
#define SEND 261
#define FOR 262
#define FORWARD 263
#define FUNCTION 264
#define IF 265
#define PROCEDURE 266
#define PROGRAM 267
#define READ 268
#define THEN 269
#define TO 270
#define VAR 271
#define WHILE 272
#define WRITE 273
#define PLUS 274
#define MINUS 275
#define MULT 276
#define DIV 277
#define EQ 278
#define NEQ 279
#define LE 280
#define LT 281
#define GE 282
#define GT 283
#define LPAREN 284
#define RPAREN 285
#define LBRACKET 286
#define RBRACKET 287
#define COMMA 288
#define SEMICOLON 289
#define COLON 290
#define INTERVAL 291
#define PERIOD 292
#define ASSIGN 293
#define NUMBER 294
#define IDENT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "parser.y" /* yacc.c:355  */

    int num;
    char ident[MAXLENGTH+1];

#line 216 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    51,    55,    55,    55,    58,    60,    64,
      65,    69,    73,    74,    78,    79,    83,    83,    87,    87,
      89,    89,    91,    91,    94,    94,   100,   104,   108,   108,
     112,   113,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   129,   140,   140,   140,   140,   143,   145,   149,   149,
     154,   156,   153,   162,   163,   163,   171,   179,   183,   187,
     191,   194,   199,   200,   201,   202,   203,   204,   208,   209,
     210,   211,   212,   216,   217,   218,   222,   223,   224,   228,
     238,   238,   246,   247,   252,   253,   257,   262,   262,   266,
     267
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SBEGIN", "DO", "ELSE", "SEND", "FOR",
  "FORWARD", "FUNCTION", "IF", "PROCEDURE", "PROGRAM", "READ", "THEN",
  "TO", "VAR", "WHILE", "WRITE", "PLUS", "MINUS", "MULT", "DIV", "EQ",
  "NEQ", "LE", "LT", "GE", "GT", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "COMMA", "SEMICOLON", "COLON", "INTERVAL", "PERIOD",
  "ASSIGN", "NUMBER", "IDENT", "$accept", "program", "$@1", "outblock",
  "$@2", "$@3", "var_decl_part", "var_decl_list", "var_decl",
  "subprog_decl_part", "subprog_decl_list", "subprog_decl", "$@4",
  "proc_decl", "$@5", "$@6", "$@7", "$@8", "proc_name", "func_name",
  "inblock", "$@9", "statement_list", "statement", "assignment_statement",
  "if_statement", "$@10", "$@11", "$@12", "else_statement",
  "while_statement", "$@13", "for_statement", "$@14", "$@15",
  "proc_call_statement", "$@16", "proc_call_name",
  "proc_call_name_with_var", "block_statement", "read_statement",
  "write_statement", "null_statement", "condition", "expression", "term",
  "factor", "var_name", "$@17", "arg_list", "id_list", "label",
  "prog_arg_list", "$@18", "prog_id_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -58

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -95,     6,    12,   -95,    22,    39,    66,    25,     5,   -95,
      50,   -95,   -95,    52,   -95,   -95,    66,    43,    32,   -95,
     -95,   -95,    53,   -95,    49,     8,    32,    46,    51,   -95,
       8,    55,     0,    60,   -95,    63,   -26,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,    65,   -95,   -95,   -95,   -95,   -95,
     -95,    -6,   -95,    45,     2,   -95,    59,    -2,    -2,     0,
     -95,    67,    69,   -95,    44,    54,   -95,   -95,    61,     0,
       0,     0,   -95,   -95,   -95,   -95,   -95,   -95,     8,     0,
      54,    54,    27,   -95,   -95,    -2,    -2,     0,     0,     0,
       0,     0,     0,    -2,    -2,    70,   -95,    31,    58,   -95,
      62,    66,    62,    66,   -95,    58,   -95,   -95,    85,    54,
      54,    58,    58,    58,    58,    58,    58,   -95,   -95,   -95,
     -95,   -95,    74,     0,   -95,   -23,   -95,   -95,    26,   -95,
      90,    76,     8,   104,   -95,    58,    79,    75,    73,     8,
      82,   -95,   -95,   -95,     8,     0,    66,   -95,   -95,    66,
       0,   -95,   -95,    58,   -95,   -95,    58,   -95,   -95,   112,
     114,     8,   -95,     8,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     7,     0,     0,     4,
       0,    10,    84,    11,     3,    86,     8,     0,    13,     9,
      85,     5,     0,    15,     0,    61,    12,     0,     0,    17,
      61,     0,     0,     0,    86,     0,    56,     6,    32,    33,
      34,    35,    36,    53,     0,    38,    39,    40,    37,    14,
      27,     0,    26,     0,     0,    31,     0,     0,     0,     0,
      77,    79,     0,    42,     0,    68,    73,    76,     0,     0,
       0,     0,    54,    24,    22,    20,    18,    58,    61,     0,
      69,    70,     0,    80,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,    41,    87,
       0,     7,     0,     7,    30,    50,    78,    87,     0,    71,
      72,    62,    63,    65,    64,    67,    66,    74,    75,    59,
      86,    60,     0,     0,    89,     0,    28,    23,     0,    19,
       0,     0,    61,     0,    55,    82,    88,     0,     0,    61,
       0,    86,    81,    43,    61,     0,     7,    90,    29,     7,
       0,    86,    49,    83,    25,    21,    51,    44,    86,    46,
       0,    61,    45,    61,    47,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -95,   -95,   -95,   -95,   116,   -95,   107,   -95,
     -95,    94,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -94,   -95,   -95,   -29,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -25,   -95,
     -95,   -95,   -95,    56,   -57,   -41,   -13,   -95,   -95,   -95,
     -95,   -30,    17,   -95,    24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,    15,    25,   126,    10,    11,    21,
      22,    23,    24,    29,   103,   102,   101,   100,    53,    51,
     127,   139,    54,    37,    38,    39,    84,   151,   159,   162,
      40,   120,    41,   130,   158,    42,    99,    43,    62,    45,
      46,    47,    48,    63,    64,    65,    66,    67,   107,   136,
      13,    18,   122,   123,   125
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    55,    82,   -57,    69,    44,     3,   137,    77,   129,
     138,    30,    71,    97,    98,    31,    80,    81,    32,    57,
      58,    33,   105,    73,     4,    34,    35,    59,    74,    59,
     111,   112,   113,   114,   115,   116,    78,    60,    61,    60,
      61,   -16,    14,   -16,   109,   110,    85,    86,    36,   104,
      85,    86,   154,    44,   108,   155,   140,   106,    27,   138,
      28,   121,     5,    85,    86,    12,   135,    87,    88,    89,
      90,    91,    92,     6,    75,    93,    94,    85,    86,    76,
     117,   118,     7,    20,    16,    17,    50,    26,   153,    68,
     133,    52,    70,   156,    72,    56,   -57,    79,    83,   132,
     119,    95,   124,   143,   134,   141,   142,    44,   144,   146,
     148,   150,   145,   147,    44,   152,   149,   161,   163,    44,
      49,   157,     9,    19,   131,    96,   128,     0,   160,     0,
       0,     0,   164,     0,   165,     0,    44,     0,    44
};

static const yytype_int16 yycheck[] =
{
      25,    30,    59,    29,    34,    30,     0,    30,     6,   103,
      33,     3,    38,    70,    71,     7,    57,    58,    10,    19,
      20,    13,    79,    29,    12,    17,    18,    29,    34,    29,
      87,    88,    89,    90,    91,    92,    34,    39,    40,    39,
      40,     9,    37,    11,    85,    86,    19,    20,    40,    78,
      19,    20,   146,    78,    84,   149,    30,    30,     9,    33,
      11,    30,    40,    19,    20,    40,   123,    23,    24,    25,
      26,    27,    28,    34,    29,    21,    22,    19,    20,    34,
      93,    94,    16,    40,    34,    33,    40,    34,   145,    29,
     120,    40,    29,   150,    29,    40,    29,    38,    29,    14,
      30,    40,    40,   132,    30,    15,    30,   132,     4,    34,
     139,   141,    33,    40,   139,   144,    34,     5,     4,   144,
      26,   151,     6,    16,   107,    69,   102,    -1,   158,    -1,
      -1,    -1,   161,    -1,   163,    -1,   161,    -1,   163
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,    12,    40,    34,    16,    44,    47,
      48,    49,    40,    91,    37,    45,    34,    33,    92,    49,
      40,    50,    51,    52,    53,    46,    34,     9,    11,    54,
       3,     7,    10,    13,    17,    18,    40,    64,    65,    66,
      71,    73,    76,    78,    79,    80,    81,    82,    83,    52,
      40,    60,    40,    59,    63,    64,    40,    19,    20,    29,
      39,    40,    79,    84,    85,    86,    87,    88,    29,    92,
      29,    38,    29,    29,    34,    29,    34,     6,    34,    38,
      86,    86,    85,    29,    67,    19,    20,    23,    24,    25,
      26,    27,    28,    21,    22,    40,    84,    85,    85,    77,
      58,    57,    56,    55,    64,    85,    30,    89,    92,    86,
      86,    85,    85,    85,    85,    85,    85,    87,    87,    30,
      72,    30,    93,    94,    40,    95,    47,    61,    95,    61,
      74,    93,    14,    92,    30,    85,    90,    30,    33,    62,
      30,    15,    30,    64,     4,    33,    34,    40,    64,    34,
      92,    68,    64,    85,    61,    61,    85,    92,    75,    69,
      92,     5,    70,     4,    64,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    43,    42,    45,    46,    44,    47,    47,    48,
      48,    49,    50,    50,    51,    51,    53,    52,    55,    54,
      56,    54,    57,    54,    58,    54,    59,    60,    62,    61,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    67,    68,    69,    66,    70,    70,    72,    71,
      74,    75,    73,    76,    77,    76,    78,    79,    80,    81,
      82,    83,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    87,    88,
      89,    88,    90,    90,    91,    91,    92,    94,    93,    95,
      95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     0,     0,     6,     0,     2,     3,
       1,     2,     2,     0,     3,     1,     0,     2,     0,     5,
       0,     8,     0,     5,     0,     8,     1,     1,     0,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     0,     0,    10,     0,     2,     0,     7,
       0,     0,    12,     1,     0,     5,     1,     1,     3,     4,
       4,     0,     3,     3,     3,     3,     3,     3,     1,     2,
       2,     3,     3,     1,     3,     3,     1,     1,     3,     1,
       0,     5,     1,     3,     1,     3,     0,     0,     2,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 51 "parser.y" /* yacc.c:1646  */
    {fp=fopen("result.code","wb");}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "parser.y" /* yacc.c:1646  */
    {fclose(fp);alldelete();}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 55 "parser.y" /* yacc.c:1646  */
    {generate(JMP,0,0,0);/*backpatch*/}
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 55 "parser.y" /* yacc.c:1646  */
    {backpatch((yyvsp[-1].num)-1,opnumber);}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 83 "parser.y" /* yacc.c:1646  */
    {currentstack=0;}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 87 "parser.y" /* yacc.c:1646  */
    {flag=LOCAL;}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 87 "parser.y" /* yacc.c:1646  */
    {flag=GLOBAL;
	stack_delete();generate(RTN,0,0,0);}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 89 "parser.y" /* yacc.c:1646  */
    {flag=LOCAL;procvarnumber=0;}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 89 "parser.y" /* yacc.c:1646  */
    {flag=GLOBAL;
	stack_delete();generate(RTN,0,0,0);}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 91 "parser.y" /* yacc.c:1646  */
    {flag=LOCAL;}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 91 "parser.y" /* yacc.c:1646  */
    {
		flag=GLOBAL;
		stack_delete(); generate(RTN,0,0,0);}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 94 "parser.y" /* yacc.c:1646  */
    {flag=LOCAL;procvarnumber=0;}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 100 "parser.y" /* yacc.c:1646  */
    {stack_insert((yyvsp[0].ident),PROC,opnumber);}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 104 "parser.y" /* yacc.c:1646  */
    {stack_insert((yyvsp[0].ident),FUNC,opnumber);}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 108 "parser.y" /* yacc.c:1646  */
    {generate(INT,0,0,procvarnumber);}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 129 "parser.y" /* yacc.c:1646  */
    {
		if(type_lookup((yyvsp[-2].ident),flag)!=3){ /*if not return statement*/
			generate(STO,type_lookup((yyvsp[-2].ident),flag),0,stack_lookup((yyvsp[-2].ident))); 
		}else{
			generate(STO,LOCAL,0,-5); /*return*/
			generate(RTN,0,0,0);
		}
	}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 140 "parser.y" /* yacc.c:1646  */
    {generate(JPC,0,0,0);/*backpatch*/}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 140 "parser.y" /* yacc.c:1646  */
    {generate(JMP,0,0,0);/*backpatch*/}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 140 "parser.y" /* yacc.c:1646  */
    {backpatch((yyvsp[-4].num)-1,opnumber);}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 140 "parser.y" /* yacc.c:1646  */
    {backpatch((yyvsp[-2].num)-1,opnumber);}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 149 "parser.y" /* yacc.c:1646  */
    {generate(JPC,0,0,0);/*backpatch*/}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 149 "parser.y" /* yacc.c:1646  */
    {generate(JMP,0,0,(yyvsp[-5].num));backpatch((yyvsp[-2].num)-1,opnumber);}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 154 "parser.y" /* yacc.c:1646  */
    {generate(STO,type_lookup((yyvsp[-2].ident),flag),0,stack_lookup((yyvsp[-2].ident)));}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 156 "parser.y" /* yacc.c:1646  */
    {generate(LOD,type_lookup((yyvsp[-6].ident),flag),0,stack_lookup((yyvsp[-6].ident)));generate(OPR,0,0,10); generate(JPC,0,0,0);/*backpatch*/}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 158 "parser.y" /* yacc.c:1646  */
    {/*インクリメント*/generate(LIT,0,0,1);generate(LOD,type_lookup((yyvsp[-10].ident),flag),0,stack_lookup((yyvsp[-10].ident)));generate(OPR,0,0,1);generate(STO,type_lookup((yyvsp[-10].ident),flag),0,stack_lookup((yyvsp[-10].ident))); generate(JMP,0,0,(yyvsp[-5].num)); backpatch((yyvsp[-2].num)-1,opnumber);}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 163 "parser.y" /* yacc.c:1646  */
    {ifneedreturn=(type_lookup(procnamebuffer,flag)==3);}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 163 "parser.y" /* yacc.c:1646  */
    {
		if(type_lookup(procnamebuffer,flag)==3){
			generate(INT,0,0,1);
		}
		generate(CAL,0,0,stack_lookup(procnamebuffer));}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 171 "parser.y" /* yacc.c:1646  */
    {
		if(type_lookup((yyvsp[0].ident),flag)==3){
			generate(INT,0,0,1);
		}
		generate(CAL,0,0,stack_lookup((yyvsp[0].ident)));}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 179 "parser.y" /* yacc.c:1646  */
    {strcpy(procnamebuffer,(yyvsp[0].ident));}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 187 "parser.y" /* yacc.c:1646  */
    {generate(GET,0,0,0);generate(STO,type_lookup((yyvsp[-1].ident),flag),0,stack_lookup((yyvsp[-1].ident)));}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 191 "parser.y" /* yacc.c:1646  */
    {generate(PUT,0,0,0);}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 199 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,5);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 200 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,6);}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 201 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,7);}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 202 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,8);}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 203 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,9);}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 204 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,10);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 210 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,0);}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 211 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,1);}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 212 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,2);}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 217 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,3);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 218 "parser.y" /* yacc.c:1646  */
    {generate(OPR,0,0,4);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 223 "parser.y" /* yacc.c:1646  */
    {generate(LIT,0,0,(yyvsp[0].num));}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 228 "parser.y" /* yacc.c:1646  */
    {
		if(type_lookup((yyvsp[0].ident),flag)!=3){
			generate(LOD,type_lookup((yyvsp[0].ident),flag),0,stack_type_lookup((yyvsp[0].ident),flag));
		}else{
			if(type_lookup((yyvsp[0].ident),flag)==3){
				generate(INT,0,0,1);
			}
			generate(CAL,0,0,stack_lookup((yyvsp[0].ident)));
		}
	}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 238 "parser.y" /* yacc.c:1646  */
    {ifneedreturn=1;}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 238 "parser.y" /* yacc.c:1646  */
    {
		if(type_lookup(procnamebuffer,flag)==3){
			generate(INT,0,0,1);
		}
		generate(CAL,0,0,stack_lookup(procnamebuffer));}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 246 "parser.y" /* yacc.c:1646  */
    {procvarnumber++;}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 247 "parser.y" /* yacc.c:1646  */
    {procvarnumber++;}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 252 "parser.y" /* yacc.c:1646  */
    {stack_insert((yyvsp[0].ident),flag,currentstack);currentstack++; generate(LIT,0,0,0);}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 253 "parser.y" /* yacc.c:1646  */
    {stack_insert((yyvsp[0].ident),flag,currentstack);currentstack++; generate(LIT,0,0,0);}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.num) = opnumber;}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 262 "parser.y" /* yacc.c:1646  */
    {generate(INT,0,0,4+ifneedreturn); procvarnumber=0;}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 262 "parser.y" /* yacc.c:1646  */
    {generate(INT,0,0,-(procvarnumber+4+ifneedreturn));}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 266 "parser.y" /* yacc.c:1646  */
    {stack_insert((yyvsp[0].ident),flag,currentstack);currentstack++;procvarnumber++;}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 267 "parser.y" /* yacc.c:1646  */
    {stack_insert((yyvsp[0].ident),flag,currentstack);currentstack++;procvarnumber++;}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1792 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 272 "parser.y" /* yacc.c:1906  */
 
void yyerror(char *s)
{

  fprintf(stderr, "L%d:%s %s\n",yylineno,yytext, s);
}

void generate(int opcode,REG base,REG index,REG address){

	OPCODE item;
	item.opcode=opcode;
	item.basereg=base;
	item.indexreg=index;
	item.address=address;

	//DEBAG
	printf("L%d code: %d %d %d %d  (%s)\n",yylineno,item.opcode,item.basereg,item.indexreg,item.address,yytext);
	//ENDDEBAG

	fwrite(&item,sizeof(OPCODE),1,fp);

	opnumber++;

}

void backpatch(int a,REG b){

	fseek(fp,(long)(a*sizeof(OPCODE)),0);
	fseek(fp,(long)(sizeof(int)+sizeof(REG)*2),1);
	fwrite(&b,sizeof(REG),1,fp);
	fseek(fp,(long)0,2);

	printf("backpatch: op = %d, REG = %d\n",a,b);
}
