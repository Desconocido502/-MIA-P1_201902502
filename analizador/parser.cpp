/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ASintactico.y"

    #include <iostream>
    #include <stdlib.h>
    #include "scanner.h"
    #include "../nodo.h"

    using namespace std;

    extern int yylineno;
    extern char *yytext;
    extern int yyfila;
    extern int yycolum;
    extern Nodo *raiz; //raiz del arbol

    int yyerror(const char* mensaje){
        cout<<yytext<<" "<<mensaje<<" "<<yyfila<<" "<<yycolum<<std::endl;
        return 0;
    }

    Nodo* getRaiz(){
        return raiz;
    }

#line 95 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_mkdisk = 3,                     /* mkdisk  */
  YYSYMBOL_rep = 4,                        /* rep  */
  YYSYMBOL_execute = 5,                    /* execute  */
  YYSYMBOL_fdisk = 6,                      /* fdisk  */
  YYSYMBOL_mayor = 7,                      /* mayor  */
  YYSYMBOL_path = 8,                       /* path  */
  YYSYMBOL_igual = 9,                      /* igual  */
  YYSYMBOL_entero = 10,                    /* entero  */
  YYSYMBOL_txt = 11,                       /* txt  */
  YYSYMBOL_sizeS = 12,                     /* sizeS  */
  YYSYMBOL_unit = 13,                      /* unit  */
  YYSYMBOL_type = 14,                      /* type  */
  YYSYMBOL_name = 15,                      /* name  */
  YYSYMBOL_caracter = 16,                  /* caracter  */
  YYSYMBOL_identificador = 17,             /* identificador  */
  YYSYMBOL_extension = 18,                 /* extension  */
  YYSYMBOL_ruta = 19,                      /* ruta  */
  YYSYMBOL_cadena = 20,                    /* cadena  */
  YYSYMBOL_exitS = 21,                     /* exitS  */
  YYSYMBOL_fit = 22,                       /* fit  */
  YYSYMBOL_bf = 23,                        /* bf  */
  YYSYMBOL_ff = 24,                        /* ff  */
  YYSYMBOL_wf = 25,                        /* wf  */
  YYSYMBOL_del_ = 26,                      /* del_  */
  YYSYMBOL_add = 27,                       /* add  */
  YYSYMBOL_full = 28,                      /* full  */
  YYSYMBOL_rmdisk = 29,                    /* rmdisk  */
  YYSYMBOL_mount = 30,                     /* mount  */
  YYSYMBOL_unmount = 31,                   /* unmount  */
  YYSYMBOL_id = 32,                        /* id  */
  YYSYMBOL_mkfs = 33,                      /* mkfs  */
  YYSYMBOL_fs = 34,                        /* fs  */
  YYSYMBOL_fs2 = 35,                       /* fs2  */
  YYSYMBOL_fs3 = 36,                       /* fs3  */
  YYSYMBOL_login = 37,                     /* login  */
  YYSYMBOL_logout = 38,                    /* logout  */
  YYSYMBOL_pausa = 39,                     /* pausa  */
  YYSYMBOL_usuario = 40,                   /* usuario  */
  YYSYMBOL_password = 41,                  /* password  */
  YYSYMBOL_pwd = 42,                       /* pwd  */
  YYSYMBOL_rutaRep = 43,                   /* rutaRep  */
  YYSYMBOL_disk = 44,                      /* disk  */
  YYSYMBOL_inode = 45,                     /* inode  */
  YYSYMBOL_journaling = 46,                /* journaling  */
  YYSYMBOL_block = 47,                     /* block  */
  YYSYMBOL_bm_inode = 48,                  /* bm_inode  */
  YYSYMBOL_bm_block = 49,                  /* bm_block  */
  YYSYMBOL_tree = 50,                      /* tree  */
  YYSYMBOL_sb = 51,                        /* sb  */
  YYSYMBOL_fileRep = 52,                   /* fileRep  */
  YYSYMBOL_ls = 53,                        /* ls  */
  YYSYMBOL_mbr = 54,                       /* mbr  */
  YYSYMBOL_mkgrp = 55,                     /* mkgrp  */
  YYSYMBOL_rmgrp = 56,                     /* rmgrp  */
  YYSYMBOL_grp = 57,                       /* grp  */
  YYSYMBOL_mkusr = 58,                     /* mkusr  */
  YYSYMBOL_rmusr = 59,                     /* rmusr  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_INICIO = 61,                    /* INICIO  */
  YYSYMBOL_COMANDO = 62,                   /* COMANDO  */
  YYSYMBOL_MKDISK = 63,                    /* MKDISK  */
  YYSYMBOL_PARAMETRO_MK = 64,              /* PARAMETRO_MK  */
  YYSYMBOL_AJUSTE = 65,                    /* AJUSTE  */
  YYSYMBOL_FDISK = 66,                     /* FDISK  */
  YYSYMBOL_PARAMETRO_FK = 67,              /* PARAMETRO_FK  */
  YYSYMBOL_SCRIPT = 68,                    /* SCRIPT  */
  YYSYMBOL_REP = 69,                       /* REP  */
  YYSYMBOL_PARAMETRO_R = 70,               /* PARAMETRO_R  */
  YYSYMBOL_RMDISK = 71,                    /* RMDISK  */
  YYSYMBOL_MOUNT = 72,                     /* MOUNT  */
  YYSYMBOL_PARAMETRO_M = 73,               /* PARAMETRO_M  */
  YYSYMBOL_UNMOUNT = 74,                   /* UNMOUNT  */
  YYSYMBOL_MKFS = 75,                      /* MKFS  */
  YYSYMBOL_PARAM_MKFS = 76,                /* PARAM_MKFS  */
  YYSYMBOL_LOGIN = 77,                     /* LOGIN  */
  YYSYMBOL_PARAM_LOGIN = 78,               /* PARAM_LOGIN  */
  YYSYMBOL_MKGRP = 79,                     /* MKGRP  */
  YYSYMBOL_RMGRP = 80,                     /* RMGRP  */
  YYSYMBOL_MKUSR = 81,                     /* MKUSR  */
  YYSYMBOL_PARAM_MKUSR = 82,               /* PARAM_MKUSR  */
  YYSYMBOL_RMUSR = 83                      /* RMUSR  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   118,   118,   120,   125,   129,   130,   135,   136,   137,
     138,   143,   148,   153,   154,   155,   156,   157,   161,   164,
     168,   173,   174,   175,   176,   177,   182,   183,   184,   186,
     190,   195,   196,   197,   198,   199,   200,   202,   207,   213,
     217,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   239,   245,   252,
     257,   262,   263,   264,   265,   267,   274,   278,   283,   284,
     285,   286,   288,   293,   299,   300,   301,   302,   303,   304,
     305,   307,   312,   318,   324,   331,   336,   342,   343,   344,
     345,   346,   347,   348,   349,   351,   357
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "mkdisk", "rep",
  "execute", "fdisk", "mayor", "path", "igual", "entero", "txt", "sizeS",
  "unit", "type", "name", "caracter", "identificador", "extension", "ruta",
  "cadena", "exitS", "fit", "bf", "ff", "wf", "del_", "add", "full",
  "rmdisk", "mount", "unmount", "id", "mkfs", "fs", "fs2", "fs3", "login",
  "logout", "pausa", "usuario", "password", "pwd", "rutaRep", "disk",
  "inode", "journaling", "block", "bm_inode", "bm_block", "tree", "sb",
  "fileRep", "ls", "mbr", "mkgrp", "rmgrp", "grp", "mkusr", "rmusr",
  "$accept", "INICIO", "COMANDO", "MKDISK", "PARAMETRO_MK", "AJUSTE",
  "FDISK", "PARAMETRO_FK", "SCRIPT", "REP", "PARAMETRO_R", "RMDISK",
  "MOUNT", "PARAMETRO_M", "UNMOUNT", "MKFS", "PARAM_MKFS", "LOGIN",
  "PARAM_LOGIN", "MKGRP", "RMGRP", "MKUSR", "PARAM_MKUSR", "RMUSR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-22)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    14,    16,    18,    22,   -22,    26,    34,    36,    59,
     100,   -22,   -22,   101,   102,   103,   104,     9,   -22,   -22,
     -22,   -22,   -22,   -22,    49,    14,   -22,    -1,    16,   -22,
     105,   -22,    32,   -22,    22,   -22,   106,     2,    34,   -22,
      83,   -10,    59,   -22,   -21,   100,   -22,    24,    97,     8,
     103,   -22,    77,   -22,   107,   109,   110,   111,   -22,   112,
     113,   114,   115,   -22,   116,   117,   118,   119,   120,   -22,
     121,   122,   123,   -22,   124,   125,   126,   127,   -22,   128,
     129,   130,   -22,   131,   132,   133,   134,   135,   -22,   136,
      31,   137,   138,    45,    76,    28,   139,    78,    80,   141,
      43,   140,   142,    82,    84,    47,   143,   144,   145,    70,
     146,    66,    -5,    67,    68,    72,    -4,    73,    74,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,    13,    14,     0,     0,     0,     0,     0,     2,     8,
       9,    15,    16,    18,     0,     3,    20,     0,     6,    40,
       0,     5,     0,    31,     4,    30,     0,     0,    10,    60,
       0,     0,    11,    67,     0,    12,    73,     0,     0,     0,
      17,    86,     0,     1,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    39,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    59,     0,     0,     0,     0,    66,     0,
       0,     0,    72,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      23,    21,    22,    26,    27,    28,    25,    42,    41,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    46,
      45,    44,    43,    38,    37,    34,    32,    33,    35,    36,
      57,    58,    62,    61,    63,    64,    65,    69,    68,    70,
      71,    80,    74,    75,    76,    77,    79,    78,    81,    82,
      83,    84,    87,    88,    89,    90,    92,    91,    93,    94,
      95,    96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -22,   -22,   -22,   -22,     7,   -22,   -22,   147,   -22,   -22,
     148,   -22,   -22,   108,   -22,   -22,   149,   -22,   150,   -22,
     -22,   -22,    98,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    17,    18,    25,    33,   126,    34,    35,    31,    28,
      29,    19,    38,    39,    20,    42,    43,    45,    46,    21,
      22,    50,    51,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       1,     2,     3,     4,    75,   164,   174,    59,    26,    53,
      71,    79,   165,   175,    60,   166,   176,    72,     5,    80,
      81,    24,    76,    27,    77,    30,     6,     7,     8,    32,
       9,    61,    58,    36,    10,    11,    12,   167,   177,    83,
      54,    37,    62,    40,    55,    56,    65,    66,    85,    86,
     119,   120,    13,    14,    57,    15,    16,    54,    67,    68,
     146,    55,    56,   147,   154,    87,    41,   155,   123,   124,
     125,    57,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   162,   168,   170,   163,   169,   171,   172,
     178,   180,   173,   179,   181,   127,   128,   141,   142,   143,
     144,   150,   151,   152,   153,   159,   160,    44,    47,    48,
      49,    52,    84,    64,    70,    74,    90,    89,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    73,   121,    88,     0,
       0,     0,   149,     0,   122,     0,   140,   145,     0,     0,
     156,     0,   158,   161,     0,     0,     0,     0,   148,     0,
       0,     0,   157,     0,     0,     0,    63,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,    82
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,    14,    10,    10,     8,     1,     0,
       8,    32,    17,    17,    15,    20,    20,    15,    21,    40,
      41,     7,    32,     7,    34,     7,    29,    30,    31,     7,
      33,    32,    25,     7,    37,    38,    39,    42,    42,    15,
       8,     7,    43,     7,    12,    13,    14,    15,    40,    41,
      19,    20,    55,    56,    22,    58,    59,     8,    26,    27,
      17,    12,    13,    20,    17,    57,     7,    20,    23,    24,
      25,    22,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    17,    17,    17,    20,    20,    20,    17,
      17,    17,    20,    20,    20,    19,    20,    19,    20,    19,
      20,    19,    20,    19,    20,    35,    36,     7,     7,     7,
       7,     7,    15,     8,     8,    32,     9,    40,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,    38,    10,    50,    -1,
      -1,    -1,    10,    -1,    16,    -1,    17,    16,    -1,    -1,
      17,    -1,    17,    17,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    21,    29,    30,    31,    33,
      37,    38,    39,    55,    56,    58,    59,    61,    62,    71,
      74,    79,    80,    83,     7,    63,    64,     7,    69,    70,
       7,    68,     7,    64,    66,    67,     7,     7,    72,    73,
       7,     7,    75,    76,     7,    77,    78,     7,     7,     7,
      81,    82,     7,     0,     8,    12,    13,    22,    64,     8,
      15,    32,    43,    70,     8,    14,    15,    26,    27,    67,
       8,     8,    15,    73,    32,    14,    32,    34,    76,    32,
      40,    41,    78,    15,    15,    40,    41,    57,    82,    40,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,    19,
      20,    10,    16,    23,    24,    25,    65,    19,    20,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      17,    19,    20,    19,    20,    16,    17,    20,    28,    10,
      19,    20,    19,    20,    17,    20,    17,    28,    17,    35,
      36,    17,    17,    20,    10,    17,    20,    42,    17,    20,
      17,    20,    17,    20,    10,    17,    20,    42,    17,    20,
      17,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    75,    75,    76,    76,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     2,     1,     2,
       1,     4,     4,     4,     4,     4,     1,     1,     1,     2,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     2,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     5,     2,
       1,     4,     4,     4,     4,     5,     2,     1,     4,     4,
       4,     4,     2,     1,     4,     4,     4,     4,     4,     4,
       4,     5,     5,     5,     5,     2,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     5,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* INICIO: COMANDO  */
#line 118 "ASintactico.y"
               { raiz = (yyval.nodo); }
#line 1560 "parser.cpp"
    break;

  case 3: /* COMANDO: mkdisk MKDISK  */
#line 121 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKDISK", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1569 "parser.cpp"
    break;

  case 4: /* COMANDO: fdisk FDISK  */
#line 125 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("FDISK", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1578 "parser.cpp"
    break;

  case 5: /* COMANDO: execute SCRIPT  */
#line 129 "ASintactico.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1584 "parser.cpp"
    break;

  case 6: /* COMANDO: rep REP  */
#line 131 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REP", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1593 "parser.cpp"
    break;

  case 7: /* COMANDO: exitS  */
#line 135 "ASintactico.y"
           { (yyval.nodo) = new Nodo("EXIT", ""); }
#line 1599 "parser.cpp"
    break;

  case 8: /* COMANDO: RMDISK  */
#line 136 "ASintactico.y"
            { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1605 "parser.cpp"
    break;

  case 9: /* COMANDO: UNMOUNT  */
#line 137 "ASintactico.y"
             { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1611 "parser.cpp"
    break;

  case 10: /* COMANDO: mount MOUNT  */
#line 139 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MOUNT", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1620 "parser.cpp"
    break;

  case 11: /* COMANDO: mkfs MKFS  */
#line 144 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKFS", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1629 "parser.cpp"
    break;

  case 12: /* COMANDO: login LOGIN  */
#line 149 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("LOGIN", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1638 "parser.cpp"
    break;

  case 13: /* COMANDO: logout  */
#line 153 "ASintactico.y"
            { (yyval.nodo) = new Nodo("LOGOUT", ""); }
#line 1644 "parser.cpp"
    break;

  case 14: /* COMANDO: pausa  */
#line 154 "ASintactico.y"
           { (yyval.nodo) = new Nodo("PAUSE", ""); }
#line 1650 "parser.cpp"
    break;

  case 15: /* COMANDO: MKGRP  */
#line 155 "ASintactico.y"
           { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1656 "parser.cpp"
    break;

  case 16: /* COMANDO: RMGRP  */
#line 156 "ASintactico.y"
           { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1662 "parser.cpp"
    break;

  case 17: /* COMANDO: mkusr MKUSR  */
#line 157 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("MKUSR", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1671 "parser.cpp"
    break;

  case 18: /* COMANDO: RMUSR  */
#line 161 "ASintactico.y"
            { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1677 "parser.cpp"
    break;

  case 19: /* MKDISK: MKDISK PARAMETRO_MK  */
#line 164 "ASintactico.y"
                            {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1686 "parser.cpp"
    break;

  case 20: /* MKDISK: PARAMETRO_MK  */
#line 168 "ASintactico.y"
                   {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1695 "parser.cpp"
    break;

  case 21: /* PARAMETRO_MK: mayor sizeS igual entero  */
#line 173 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("size", (yyvsp[0].text)); }
#line 1701 "parser.cpp"
    break;

  case 22: /* PARAMETRO_MK: mayor unit igual caracter  */
#line 174 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("unit", (yyvsp[0].text)); }
#line 1707 "parser.cpp"
    break;

  case 23: /* PARAMETRO_MK: mayor path igual cadena  */
#line 175 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1713 "parser.cpp"
    break;

  case 24: /* PARAMETRO_MK: mayor path igual ruta  */
#line 176 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1719 "parser.cpp"
    break;

  case 25: /* PARAMETRO_MK: mayor fit igual AJUSTE  */
#line 177 "ASintactico.y"
                            {
        (yyval.nodo) = new Nodo("fit", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1728 "parser.cpp"
    break;

  case 26: /* AJUSTE: bf  */
#line 182 "ASintactico.y"
           { (yyval.nodo) = new Nodo("ajuste", "bf"); }
#line 1734 "parser.cpp"
    break;

  case 27: /* AJUSTE: ff  */
#line 183 "ASintactico.y"
         { (yyval.nodo) = new Nodo("ajuste", "ff"); }
#line 1740 "parser.cpp"
    break;

  case 28: /* AJUSTE: wf  */
#line 184 "ASintactico.y"
         { (yyval.nodo) = new Nodo("ajuste", "wf"); }
#line 1746 "parser.cpp"
    break;

  case 29: /* FDISK: FDISK PARAMETRO_FK  */
#line 186 "ASintactico.y"
                          {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1755 "parser.cpp"
    break;

  case 30: /* FDISK: PARAMETRO_FK  */
#line 190 "ASintactico.y"
                   {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1764 "parser.cpp"
    break;

  case 31: /* PARAMETRO_FK: PARAMETRO_MK  */
#line 195 "ASintactico.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1770 "parser.cpp"
    break;

  case 32: /* PARAMETRO_FK: mayor name igual identificador  */
#line 196 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1776 "parser.cpp"
    break;

  case 33: /* PARAMETRO_FK: mayor name igual cadena  */
#line 197 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1782 "parser.cpp"
    break;

  case 34: /* PARAMETRO_FK: mayor type igual caracter  */
#line 198 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("type", (yyvsp[0].text)); }
#line 1788 "parser.cpp"
    break;

  case 35: /* PARAMETRO_FK: mayor del_ igual full  */
#line 199 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("delete", "full"); }
#line 1794 "parser.cpp"
    break;

  case 36: /* PARAMETRO_FK: mayor add igual entero  */
#line 200 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("add", (yyvsp[0].text)); }
#line 1800 "parser.cpp"
    break;

  case 37: /* SCRIPT: mayor path igual cadena  */
#line 202 "ASintactico.y"
                                {
        (yyval.nodo) = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*path);
    }
#line 1810 "parser.cpp"
    break;

  case 38: /* SCRIPT: mayor path igual ruta  */
#line 207 "ASintactico.y"
                            {
        (yyval.nodo) = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*path);
    }
#line 1820 "parser.cpp"
    break;

  case 39: /* REP: REP PARAMETRO_R  */
#line 213 "ASintactico.y"
                    {
    (yyval.nodo) = (yyvsp[-1].nodo);
    (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1829 "parser.cpp"
    break;

  case 40: /* REP: PARAMETRO_R  */
#line 217 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1838 "parser.cpp"
    break;

  case 41: /* PARAMETRO_R: mayor path igual cadena  */
#line 222 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1844 "parser.cpp"
    break;

  case 42: /* PARAMETRO_R: mayor path igual ruta  */
#line 223 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1850 "parser.cpp"
    break;

  case 43: /* PARAMETRO_R: mayor rutaRep igual cadena  */
#line 224 "ASintactico.y"
                                { (yyval.nodo) = new Nodo("ruta", (yyvsp[0].text)); }
#line 1856 "parser.cpp"
    break;

  case 44: /* PARAMETRO_R: mayor rutaRep igual ruta  */
#line 225 "ASintactico.y"
                              { (yyval.nodo) = new Nodo("ruta", (yyvsp[0].text)); }
#line 1862 "parser.cpp"
    break;

  case 45: /* PARAMETRO_R: mayor id igual identificador  */
#line 226 "ASintactico.y"
                                  { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 1868 "parser.cpp"
    break;

  case 46: /* PARAMETRO_R: mayor name igual mbr  */
#line 227 "ASintactico.y"
                          { (yyval.nodo) = new Nodo("name","mbr"); }
#line 1874 "parser.cpp"
    break;

  case 47: /* PARAMETRO_R: mayor name igual disk  */
#line 228 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("name","disk"); }
#line 1880 "parser.cpp"
    break;

  case 48: /* PARAMETRO_R: mayor name igual inode  */
#line 229 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("name", "inode"); }
#line 1886 "parser.cpp"
    break;

  case 49: /* PARAMETRO_R: mayor name igual journaling  */
#line 230 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("name", "journaling"); }
#line 1892 "parser.cpp"
    break;

  case 50: /* PARAMETRO_R: mayor name igual block  */
#line 231 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("name", "block"); }
#line 1898 "parser.cpp"
    break;

  case 51: /* PARAMETRO_R: mayor name igual bm_inode  */
#line 232 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("name", "bm_inode"); }
#line 1904 "parser.cpp"
    break;

  case 52: /* PARAMETRO_R: mayor name igual bm_block  */
#line 233 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("name", "bm_block"); }
#line 1910 "parser.cpp"
    break;

  case 53: /* PARAMETRO_R: mayor name igual tree  */
#line 234 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("name", "tree"); }
#line 1916 "parser.cpp"
    break;

  case 54: /* PARAMETRO_R: mayor name igual sb  */
#line 235 "ASintactico.y"
                         { (yyval.nodo) = new Nodo("name", "sb"); }
#line 1922 "parser.cpp"
    break;

  case 55: /* PARAMETRO_R: mayor name igual fileRep  */
#line 236 "ASintactico.y"
                              { (yyval.nodo) = new Nodo("name", "file"); }
#line 1928 "parser.cpp"
    break;

  case 56: /* PARAMETRO_R: mayor name igual ls  */
#line 237 "ASintactico.y"
                         { (yyval.nodo) = new Nodo("name", "ls"); }
#line 1934 "parser.cpp"
    break;

  case 57: /* RMDISK: rmdisk mayor path igual ruta  */
#line 240 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*ruta);
    }
#line 1944 "parser.cpp"
    break;

  case 58: /* RMDISK: rmdisk mayor path igual cadena  */
#line 246 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*ruta);
    }
#line 1954 "parser.cpp"
    break;

  case 59: /* MOUNT: MOUNT PARAMETRO_M  */
#line 253 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1963 "parser.cpp"
    break;

  case 60: /* MOUNT: PARAMETRO_M  */
#line 257 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1972 "parser.cpp"
    break;

  case 61: /* PARAMETRO_M: mayor path igual cadena  */
#line 262 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1978 "parser.cpp"
    break;

  case 62: /* PARAMETRO_M: mayor path igual ruta  */
#line 263 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1984 "parser.cpp"
    break;

  case 63: /* PARAMETRO_M: mayor name igual identificador  */
#line 264 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1990 "parser.cpp"
    break;

  case 64: /* PARAMETRO_M: mayor name igual cadena  */
#line 265 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1996 "parser.cpp"
    break;

  case 65: /* UNMOUNT: unmount mayor id igual identificador  */
#line 268 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("UNMOUNT", "");
        Nodo *n = new Nodo("id", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2006 "parser.cpp"
    break;

  case 66: /* MKFS: MKFS PARAM_MKFS  */
#line 274 "ASintactico.y"
                      {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2015 "parser.cpp"
    break;

  case 67: /* MKFS: PARAM_MKFS  */
#line 278 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2024 "parser.cpp"
    break;

  case 68: /* PARAM_MKFS: mayor id igual identificador  */
#line 283 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 2030 "parser.cpp"
    break;

  case 69: /* PARAM_MKFS: mayor type igual full  */
#line 284 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("type", "full"); }
#line 2036 "parser.cpp"
    break;

  case 70: /* PARAM_MKFS: mayor fs igual fs2  */
#line 285 "ASintactico.y"
                        { (yyval.nodo) = new Nodo("fs", "2fs"); }
#line 2042 "parser.cpp"
    break;

  case 71: /* PARAM_MKFS: mayor fs igual fs3  */
#line 286 "ASintactico.y"
                        { (yyval.nodo) = new Nodo("fs", "3fs"); }
#line 2048 "parser.cpp"
    break;

  case 72: /* LOGIN: LOGIN PARAM_LOGIN  */
#line 289 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2057 "parser.cpp"
    break;

  case 73: /* LOGIN: PARAM_LOGIN  */
#line 294 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2066 "parser.cpp"
    break;

  case 74: /* PARAM_LOGIN: mayor usuario igual identificador  */
#line 299 "ASintactico.y"
                                              { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2072 "parser.cpp"
    break;

  case 75: /* PARAM_LOGIN: mayor usuario igual cadena  */
#line 300 "ASintactico.y"
                                { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2078 "parser.cpp"
    break;

  case 76: /* PARAM_LOGIN: mayor password igual entero  */
#line 301 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2084 "parser.cpp"
    break;

  case 77: /* PARAM_LOGIN: mayor password igual identificador  */
#line 302 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2090 "parser.cpp"
    break;

  case 78: /* PARAM_LOGIN: mayor password igual pwd  */
#line 303 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2096 "parser.cpp"
    break;

  case 79: /* PARAM_LOGIN: mayor password igual cadena  */
#line 304 "ASintactico.y"
                                  { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2102 "parser.cpp"
    break;

  case 80: /* PARAM_LOGIN: mayor id igual identificador  */
#line 305 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 2108 "parser.cpp"
    break;

  case 81: /* MKGRP: mkgrp mayor name igual identificador  */
#line 307 "ASintactico.y"
                                            {
                                        (yyval.nodo) = new Nodo("MKGRP","");
                                        Nodo *n = new Nodo("name",(yyvsp[0].text));
                                        (yyval.nodo)->add(*n);
                                      }
#line 2118 "parser.cpp"
    break;

  case 82: /* MKGRP: mkgrp mayor name igual cadena  */
#line 312 "ASintactico.y"
                                       {
                                    (yyval.nodo) = new Nodo("MKGRP","");
                                    Nodo *n = new Nodo("name",(yyvsp[0].text));
                                    (yyval.nodo)->add(*n);
                                 }
#line 2128 "parser.cpp"
    break;

  case 83: /* RMGRP: rmgrp mayor name igual identificador  */
#line 319 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMGRP","");
        Nodo *n = new Nodo("name", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2138 "parser.cpp"
    break;

  case 84: /* RMGRP: rmgrp mayor name igual cadena  */
#line 325 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMGRP", "");
        Nodo *n = new Nodo("name",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2148 "parser.cpp"
    break;

  case 85: /* MKUSR: MKUSR PARAM_MKUSR  */
#line 332 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2157 "parser.cpp"
    break;

  case 86: /* MKUSR: PARAM_MKUSR  */
#line 337 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2166 "parser.cpp"
    break;

  case 87: /* PARAM_MKUSR: mayor usuario igual identificador  */
#line 342 "ASintactico.y"
                                              { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2172 "parser.cpp"
    break;

  case 88: /* PARAM_MKUSR: mayor usuario igual cadena  */
#line 343 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2178 "parser.cpp"
    break;

  case 89: /* PARAM_MKUSR: mayor password igual entero  */
#line 344 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2184 "parser.cpp"
    break;

  case 90: /* PARAM_MKUSR: mayor password igual identificador  */
#line 345 "ASintactico.y"
                                                { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2190 "parser.cpp"
    break;

  case 91: /* PARAM_MKUSR: mayor password igual pwd  */
#line 346 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2196 "parser.cpp"
    break;

  case 92: /* PARAM_MKUSR: mayor password igual cadena  */
#line 347 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2202 "parser.cpp"
    break;

  case 93: /* PARAM_MKUSR: mayor grp igual identificador  */
#line 348 "ASintactico.y"
                                           { (yyval.nodo) = new Nodo("group", (yyvsp[0].text)); }
#line 2208 "parser.cpp"
    break;

  case 94: /* PARAM_MKUSR: mayor grp igual cadena  */
#line 349 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("group",(yyvsp[0].text)); }
#line 2214 "parser.cpp"
    break;

  case 95: /* RMUSR: rmusr mayor usuario igual identificador  */
#line 352 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMUSR","");
        Nodo *n = new Nodo("user",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2224 "parser.cpp"
    break;

  case 96: /* RMUSR: rmusr mayor usuario igual cadena  */
#line 358 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMUSR", "");
        Nodo *n = new Nodo("user",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2234 "parser.cpp"
    break;


#line 2238 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

