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
  YYSYMBOL_r = 60,                         /* r  */
  YYSYMBOL_ugo = 61,                       /* ugo  */
  YYSYMBOL_Rchmod = 62,                    /* Rchmod  */
  YYSYMBOL_directorioA = 63,               /* directorioA  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_INICIO = 65,                    /* INICIO  */
  YYSYMBOL_COMANDO = 66,                   /* COMANDO  */
  YYSYMBOL_MKDISK = 67,                    /* MKDISK  */
  YYSYMBOL_PARAMETRO_MK = 68,              /* PARAMETRO_MK  */
  YYSYMBOL_AJUSTE = 69,                    /* AJUSTE  */
  YYSYMBOL_FDISK = 70,                     /* FDISK  */
  YYSYMBOL_PARAMETRO_FK = 71,              /* PARAMETRO_FK  */
  YYSYMBOL_SCRIPT = 72,                    /* SCRIPT  */
  YYSYMBOL_REP = 73,                       /* REP  */
  YYSYMBOL_PARAMETRO_R = 74,               /* PARAMETRO_R  */
  YYSYMBOL_RMDISK = 75,                    /* RMDISK  */
  YYSYMBOL_MOUNT = 76,                     /* MOUNT  */
  YYSYMBOL_PARAMETRO_M = 77,               /* PARAMETRO_M  */
  YYSYMBOL_UNMOUNT = 78,                   /* UNMOUNT  */
  YYSYMBOL_MKFS = 79,                      /* MKFS  */
  YYSYMBOL_PARAM_MKFS = 80,                /* PARAM_MKFS  */
  YYSYMBOL_LOGIN = 81,                     /* LOGIN  */
  YYSYMBOL_PARAM_LOGIN = 82,               /* PARAM_LOGIN  */
  YYSYMBOL_MKGRP = 83,                     /* MKGRP  */
  YYSYMBOL_RMGRP = 84,                     /* RMGRP  */
  YYSYMBOL_MKUSR = 85,                     /* MKUSR  */
  YYSYMBOL_PARAM_MKUSR = 86,               /* PARAM_MKUSR  */
  YYSYMBOL_RMUSR = 87,                     /* RMUSR  */
  YYSYMBOL_CHMOD = 88,                     /* CHMOD  */
  YYSYMBOL_PARAM_CHMOD = 89                /* PARAM_CHMOD  */
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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   125,   130,   134,   135,   140,   141,   142,
     143,   148,   153,   158,   159,   160,   161,   162,   166,   167,
     174,   178,   183,   184,   185,   186,   187,   192,   193,   194,
     196,   200,   205,   206,   207,   208,   209,   210,   212,   217,
     223,   227,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   249,   255,
     262,   267,   272,   273,   274,   275,   277,   284,   288,   293,
     294,   295,   296,   298,   303,   309,   310,   311,   312,   313,
     314,   315,   317,   322,   328,   334,   341,   346,   352,   353,
     354,   355,   356,   357,   358,   359,   361,   367,   374,   379,
     385,   386,   387,   388
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
  "fileRep", "ls", "mbr", "mkgrp", "rmgrp", "grp", "mkusr", "rmusr", "r",
  "ugo", "Rchmod", "directorioA", "$accept", "INICIO", "COMANDO", "MKDISK",
  "PARAMETRO_MK", "AJUSTE", "FDISK", "PARAMETRO_FK", "SCRIPT", "REP",
  "PARAMETRO_R", "RMDISK", "MOUNT", "PARAMETRO_M", "UNMOUNT", "MKFS",
  "PARAM_MKFS", "LOGIN", "PARAM_LOGIN", "MKGRP", "RMGRP", "MKUSR",
  "PARAM_MKUSR", "RMUSR", "CHMOD", "PARAM_CHMOD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-18)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,     4,    13,    68,    92,   -18,   103,   104,   105,   106,
     107,   -18,   -18,   108,   109,   110,   111,   112,     9,   -18,
     -18,   -18,   -18,   -18,   -18,    58,     4,   -18,    -1,    13,
     -18,    25,   -18,    50,   -18,    92,   -18,    49,     2,   104,
     -18,    88,     7,   106,   -18,    60,   107,   -18,   113,   114,
     -17,   110,   -18,    81,     0,   112,   -18,   -18,   115,   116,
     117,   118,   -18,   121,   122,   123,   124,   -18,   125,   126,
     127,   128,   129,   -18,   130,   131,   132,   -18,   133,   134,
     135,   136,   -18,   137,   138,   139,   -18,   140,   141,   142,
     143,   144,   -18,   145,   146,   -18,   147,   -18,    30,   148,
     149,    44,    54,    37,   150,    59,    83,   152,     5,    94,
     151,    85,    87,    12,   153,    95,   154,    73,   155,    26,
      -5,    28,    34,    76,    -4,    77,    78,   -16,   156,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,    13,    14,     0,     0,     0,     0,     0,     0,     2,
       8,     9,    15,    16,    18,     0,     3,    21,     0,     6,
      41,     0,     5,     0,    32,     4,    31,     0,     0,    10,
      61,     0,     0,    11,    68,     0,    12,    74,     0,     0,
       0,    17,    87,     0,     0,    19,    99,     1,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,    30,     0,     0,     0,    60,     0,     0,
       0,     0,    67,     0,     0,     0,    73,     0,     0,     0,
       0,     0,    86,     0,     0,   103,     0,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      24,    22,    23,    27,    28,    29,    26,    43,    42,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    47,
      46,    45,    44,    39,    38,    35,    33,    34,    36,    37,
      58,    59,    63,    62,    64,    65,    66,    70,    69,    71,
      72,    81,    75,    76,    77,    78,    80,    79,    82,    83,
      84,    85,    88,    89,    90,    91,    93,    92,    94,    95,
      96,    97,   100,   101,   102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -18,   -18,   -18,   -18,    18,   -18,   -18,   157,   -18,   -18,
     158,   -18,   -18,   120,   -18,   -18,   119,   -18,   159,   -18,
     -18,   -18,   160,   -18,   -18,   102
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    18,    19,    26,    34,   136,    35,    36,    32,    29,
      30,    20,    39,    40,    21,    43,    44,    46,    47,    22,
      23,    51,    52,    24,    55,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       1,     2,     3,     4,   192,   174,   184,    63,    94,    57,
      75,    25,   175,   185,    64,   176,   186,    76,     5,    27,
      28,    79,   156,    89,    90,   157,     6,     7,     8,   164,
       9,    65,   165,    68,    10,    11,    12,   177,   187,    80,
      91,    81,    66,   172,    62,   178,   173,   193,   179,   129,
     130,   180,    13,    14,   181,    15,    16,    74,    58,    17,
      95,    96,    59,    60,    69,    70,    58,   133,   134,   135,
      59,    60,    61,   137,   138,    31,    71,    72,   151,   152,
      61,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    83,   182,   188,   190,   183,   189,   191,    33,
      84,    85,   153,   154,   160,   161,   162,   163,   169,   170,
      37,    38,    41,    42,    45,    48,    49,    50,    53,    54,
      78,    93,   158,   167,    98,    99,   100,   101,    87,    88,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    97,   131,    77,
       0,   159,    82,     0,     0,   132,   194,   150,   155,     0,
     166,   168,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,    92
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,    20,    10,    10,     8,     8,     0,
       8,     7,    17,    17,    15,    20,    20,    15,    21,     1,
       7,    14,    17,    40,    41,    20,    29,    30,    31,    17,
      33,    32,    20,     8,    37,    38,    39,    42,    42,    32,
      57,    34,    43,    17,    26,    17,    20,    63,    20,    19,
      20,    17,    55,    56,    20,    58,    59,     8,     8,    62,
      60,    61,    12,    13,    14,    15,     8,    23,    24,    25,
      12,    13,    22,    19,    20,     7,    26,    27,    19,    20,
      22,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    32,    17,    17,    17,    20,    20,    20,     7,
      40,    41,    19,    20,    19,    20,    19,    20,    35,    36,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
      32,    40,    28,    28,     9,     9,     9,     9,    15,    15,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,    55,    10,    39,
      -1,    10,    43,    -1,    -1,    16,    10,    17,    16,    -1,
      17,    17,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    21,    29,    30,    31,    33,
      37,    38,    39,    55,    56,    58,    59,    62,    65,    66,
      75,    78,    83,    84,    87,     7,    67,    68,     7,    73,
      74,     7,    72,     7,    68,    70,    71,     7,     7,    76,
      77,     7,     7,    79,    80,     7,    81,    82,     7,     7,
       7,    85,    86,     7,     7,    88,    89,     0,     8,    12,
      13,    22,    68,     8,    15,    32,    43,    74,     8,    14,
      15,    26,    27,    71,     8,     8,    15,    77,    32,    14,
      32,    34,    80,    32,    40,    41,    82,    15,    15,    40,
      41,    57,    86,    40,     8,    60,    61,    89,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,    19,
      20,    10,    16,    23,    24,    25,    69,    19,    20,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      17,    19,    20,    19,    20,    16,    17,    20,    28,    10,
      19,    20,    19,    20,    17,    20,    17,    28,    17,    35,
      36,    17,    17,    20,    10,    17,    20,    42,    17,    20,
      17,    20,    17,    20,    10,    17,    20,    42,    17,    20,
      17,    20,    20,    63,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    87,    88,    88,
      89,    89,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     2,     1,     2,
       2,     1,     4,     4,     4,     4,     4,     1,     1,     1,
       2,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       2,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     5,
       2,     1,     4,     4,     4,     4,     5,     2,     1,     4,
       4,     4,     4,     2,     1,     4,     4,     4,     4,     4,
       4,     4,     5,     5,     5,     5,     2,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     5,     2,     1,
       4,     4,     4,     2
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
#line 123 "ASintactico.y"
               { raiz = (yyval.nodo); }
#line 1577 "parser.cpp"
    break;

  case 3: /* COMANDO: mkdisk MKDISK  */
#line 126 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKDISK", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1586 "parser.cpp"
    break;

  case 4: /* COMANDO: fdisk FDISK  */
#line 130 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("FDISK", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1595 "parser.cpp"
    break;

  case 5: /* COMANDO: execute SCRIPT  */
#line 134 "ASintactico.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1601 "parser.cpp"
    break;

  case 6: /* COMANDO: rep REP  */
#line 136 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REP", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1610 "parser.cpp"
    break;

  case 7: /* COMANDO: exitS  */
#line 140 "ASintactico.y"
           { (yyval.nodo) = new Nodo("EXIT", ""); }
#line 1616 "parser.cpp"
    break;

  case 8: /* COMANDO: RMDISK  */
#line 141 "ASintactico.y"
            { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1622 "parser.cpp"
    break;

  case 9: /* COMANDO: UNMOUNT  */
#line 142 "ASintactico.y"
             { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1628 "parser.cpp"
    break;

  case 10: /* COMANDO: mount MOUNT  */
#line 144 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MOUNT", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1637 "parser.cpp"
    break;

  case 11: /* COMANDO: mkfs MKFS  */
#line 149 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKFS", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1646 "parser.cpp"
    break;

  case 12: /* COMANDO: login LOGIN  */
#line 154 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("LOGIN", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1655 "parser.cpp"
    break;

  case 13: /* COMANDO: logout  */
#line 158 "ASintactico.y"
            { (yyval.nodo) = new Nodo("LOGOUT", ""); }
#line 1661 "parser.cpp"
    break;

  case 14: /* COMANDO: pausa  */
#line 159 "ASintactico.y"
           { (yyval.nodo) = new Nodo("PAUSE", ""); }
#line 1667 "parser.cpp"
    break;

  case 15: /* COMANDO: MKGRP  */
#line 160 "ASintactico.y"
           { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1673 "parser.cpp"
    break;

  case 16: /* COMANDO: RMGRP  */
#line 161 "ASintactico.y"
           { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1679 "parser.cpp"
    break;

  case 17: /* COMANDO: mkusr MKUSR  */
#line 162 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("MKUSR", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1688 "parser.cpp"
    break;

  case 18: /* COMANDO: RMUSR  */
#line 166 "ASintactico.y"
           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1694 "parser.cpp"
    break;

  case 19: /* COMANDO: Rchmod CHMOD  */
#line 168 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("CHMOD", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1703 "parser.cpp"
    break;

  case 20: /* MKDISK: MKDISK PARAMETRO_MK  */
#line 174 "ASintactico.y"
                            {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1712 "parser.cpp"
    break;

  case 21: /* MKDISK: PARAMETRO_MK  */
#line 178 "ASintactico.y"
                   {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1721 "parser.cpp"
    break;

  case 22: /* PARAMETRO_MK: mayor sizeS igual entero  */
#line 183 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("size", (yyvsp[0].text)); }
#line 1727 "parser.cpp"
    break;

  case 23: /* PARAMETRO_MK: mayor unit igual caracter  */
#line 184 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("unit", (yyvsp[0].text)); }
#line 1733 "parser.cpp"
    break;

  case 24: /* PARAMETRO_MK: mayor path igual cadena  */
#line 185 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1739 "parser.cpp"
    break;

  case 25: /* PARAMETRO_MK: mayor path igual ruta  */
#line 186 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1745 "parser.cpp"
    break;

  case 26: /* PARAMETRO_MK: mayor fit igual AJUSTE  */
#line 187 "ASintactico.y"
                            {
        (yyval.nodo) = new Nodo("fit", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1754 "parser.cpp"
    break;

  case 27: /* AJUSTE: bf  */
#line 192 "ASintactico.y"
           { (yyval.nodo) = new Nodo("ajuste", "bf"); }
#line 1760 "parser.cpp"
    break;

  case 28: /* AJUSTE: ff  */
#line 193 "ASintactico.y"
         { (yyval.nodo) = new Nodo("ajuste", "ff"); }
#line 1766 "parser.cpp"
    break;

  case 29: /* AJUSTE: wf  */
#line 194 "ASintactico.y"
         { (yyval.nodo) = new Nodo("ajuste", "wf"); }
#line 1772 "parser.cpp"
    break;

  case 30: /* FDISK: FDISK PARAMETRO_FK  */
#line 196 "ASintactico.y"
                          {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1781 "parser.cpp"
    break;

  case 31: /* FDISK: PARAMETRO_FK  */
#line 200 "ASintactico.y"
                   {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1790 "parser.cpp"
    break;

  case 32: /* PARAMETRO_FK: PARAMETRO_MK  */
#line 205 "ASintactico.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1796 "parser.cpp"
    break;

  case 33: /* PARAMETRO_FK: mayor name igual identificador  */
#line 206 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1802 "parser.cpp"
    break;

  case 34: /* PARAMETRO_FK: mayor name igual cadena  */
#line 207 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1808 "parser.cpp"
    break;

  case 35: /* PARAMETRO_FK: mayor type igual caracter  */
#line 208 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("type", (yyvsp[0].text)); }
#line 1814 "parser.cpp"
    break;

  case 36: /* PARAMETRO_FK: mayor del_ igual full  */
#line 209 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("delete", "full"); }
#line 1820 "parser.cpp"
    break;

  case 37: /* PARAMETRO_FK: mayor add igual entero  */
#line 210 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("add", (yyvsp[0].text)); }
#line 1826 "parser.cpp"
    break;

  case 38: /* SCRIPT: mayor path igual cadena  */
#line 212 "ASintactico.y"
                                {
        (yyval.nodo) = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*path);
    }
#line 1836 "parser.cpp"
    break;

  case 39: /* SCRIPT: mayor path igual ruta  */
#line 217 "ASintactico.y"
                            {
        (yyval.nodo) = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*path);
    }
#line 1846 "parser.cpp"
    break;

  case 40: /* REP: REP PARAMETRO_R  */
#line 223 "ASintactico.y"
                    {
    (yyval.nodo) = (yyvsp[-1].nodo);
    (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1855 "parser.cpp"
    break;

  case 41: /* REP: PARAMETRO_R  */
#line 227 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1864 "parser.cpp"
    break;

  case 42: /* PARAMETRO_R: mayor path igual cadena  */
#line 232 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1870 "parser.cpp"
    break;

  case 43: /* PARAMETRO_R: mayor path igual ruta  */
#line 233 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1876 "parser.cpp"
    break;

  case 44: /* PARAMETRO_R: mayor rutaRep igual cadena  */
#line 234 "ASintactico.y"
                                { (yyval.nodo) = new Nodo("ruta", (yyvsp[0].text)); }
#line 1882 "parser.cpp"
    break;

  case 45: /* PARAMETRO_R: mayor rutaRep igual ruta  */
#line 235 "ASintactico.y"
                              { (yyval.nodo) = new Nodo("ruta", (yyvsp[0].text)); }
#line 1888 "parser.cpp"
    break;

  case 46: /* PARAMETRO_R: mayor id igual identificador  */
#line 236 "ASintactico.y"
                                  { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 1894 "parser.cpp"
    break;

  case 47: /* PARAMETRO_R: mayor name igual mbr  */
#line 237 "ASintactico.y"
                          { (yyval.nodo) = new Nodo("name","mbr"); }
#line 1900 "parser.cpp"
    break;

  case 48: /* PARAMETRO_R: mayor name igual disk  */
#line 238 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("name","disk"); }
#line 1906 "parser.cpp"
    break;

  case 49: /* PARAMETRO_R: mayor name igual inode  */
#line 239 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("name", "inode"); }
#line 1912 "parser.cpp"
    break;

  case 50: /* PARAMETRO_R: mayor name igual journaling  */
#line 240 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("name", "journaling"); }
#line 1918 "parser.cpp"
    break;

  case 51: /* PARAMETRO_R: mayor name igual block  */
#line 241 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("name", "block"); }
#line 1924 "parser.cpp"
    break;

  case 52: /* PARAMETRO_R: mayor name igual bm_inode  */
#line 242 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("name", "bm_inode"); }
#line 1930 "parser.cpp"
    break;

  case 53: /* PARAMETRO_R: mayor name igual bm_block  */
#line 243 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("name", "bm_block"); }
#line 1936 "parser.cpp"
    break;

  case 54: /* PARAMETRO_R: mayor name igual tree  */
#line 244 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("name", "tree"); }
#line 1942 "parser.cpp"
    break;

  case 55: /* PARAMETRO_R: mayor name igual sb  */
#line 245 "ASintactico.y"
                         { (yyval.nodo) = new Nodo("name", "sb"); }
#line 1948 "parser.cpp"
    break;

  case 56: /* PARAMETRO_R: mayor name igual fileRep  */
#line 246 "ASintactico.y"
                              { (yyval.nodo) = new Nodo("name", "file"); }
#line 1954 "parser.cpp"
    break;

  case 57: /* PARAMETRO_R: mayor name igual ls  */
#line 247 "ASintactico.y"
                         { (yyval.nodo) = new Nodo("name", "ls"); }
#line 1960 "parser.cpp"
    break;

  case 58: /* RMDISK: rmdisk mayor path igual ruta  */
#line 250 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*ruta);
    }
#line 1970 "parser.cpp"
    break;

  case 59: /* RMDISK: rmdisk mayor path igual cadena  */
#line 256 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*ruta);
    }
#line 1980 "parser.cpp"
    break;

  case 60: /* MOUNT: MOUNT PARAMETRO_M  */
#line 263 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1989 "parser.cpp"
    break;

  case 61: /* MOUNT: PARAMETRO_M  */
#line 267 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1998 "parser.cpp"
    break;

  case 62: /* PARAMETRO_M: mayor path igual cadena  */
#line 272 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2004 "parser.cpp"
    break;

  case 63: /* PARAMETRO_M: mayor path igual ruta  */
#line 273 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2010 "parser.cpp"
    break;

  case 64: /* PARAMETRO_M: mayor name igual identificador  */
#line 274 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 2016 "parser.cpp"
    break;

  case 65: /* PARAMETRO_M: mayor name igual cadena  */
#line 275 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 2022 "parser.cpp"
    break;

  case 66: /* UNMOUNT: unmount mayor id igual identificador  */
#line 278 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("UNMOUNT", "");
        Nodo *n = new Nodo("id", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2032 "parser.cpp"
    break;

  case 67: /* MKFS: MKFS PARAM_MKFS  */
#line 284 "ASintactico.y"
                      {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2041 "parser.cpp"
    break;

  case 68: /* MKFS: PARAM_MKFS  */
#line 288 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2050 "parser.cpp"
    break;

  case 69: /* PARAM_MKFS: mayor id igual identificador  */
#line 293 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 2056 "parser.cpp"
    break;

  case 70: /* PARAM_MKFS: mayor type igual full  */
#line 294 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("type", "full"); }
#line 2062 "parser.cpp"
    break;

  case 71: /* PARAM_MKFS: mayor fs igual fs2  */
#line 295 "ASintactico.y"
                        { (yyval.nodo) = new Nodo("fs", "2fs"); }
#line 2068 "parser.cpp"
    break;

  case 72: /* PARAM_MKFS: mayor fs igual fs3  */
#line 296 "ASintactico.y"
                        { (yyval.nodo) = new Nodo("fs", "3fs"); }
#line 2074 "parser.cpp"
    break;

  case 73: /* LOGIN: LOGIN PARAM_LOGIN  */
#line 299 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2083 "parser.cpp"
    break;

  case 74: /* LOGIN: PARAM_LOGIN  */
#line 304 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2092 "parser.cpp"
    break;

  case 75: /* PARAM_LOGIN: mayor usuario igual identificador  */
#line 309 "ASintactico.y"
                                              { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2098 "parser.cpp"
    break;

  case 76: /* PARAM_LOGIN: mayor usuario igual cadena  */
#line 310 "ASintactico.y"
                                { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2104 "parser.cpp"
    break;

  case 77: /* PARAM_LOGIN: mayor password igual entero  */
#line 311 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2110 "parser.cpp"
    break;

  case 78: /* PARAM_LOGIN: mayor password igual identificador  */
#line 312 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2116 "parser.cpp"
    break;

  case 79: /* PARAM_LOGIN: mayor password igual pwd  */
#line 313 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2122 "parser.cpp"
    break;

  case 80: /* PARAM_LOGIN: mayor password igual cadena  */
#line 314 "ASintactico.y"
                                  { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2128 "parser.cpp"
    break;

  case 81: /* PARAM_LOGIN: mayor id igual identificador  */
#line 315 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 2134 "parser.cpp"
    break;

  case 82: /* MKGRP: mkgrp mayor name igual identificador  */
#line 317 "ASintactico.y"
                                            {
                                        (yyval.nodo) = new Nodo("MKGRP","");
                                        Nodo *n = new Nodo("name",(yyvsp[0].text));
                                        (yyval.nodo)->add(*n);
                                      }
#line 2144 "parser.cpp"
    break;

  case 83: /* MKGRP: mkgrp mayor name igual cadena  */
#line 322 "ASintactico.y"
                                       {
                                    (yyval.nodo) = new Nodo("MKGRP","");
                                    Nodo *n = new Nodo("name",(yyvsp[0].text));
                                    (yyval.nodo)->add(*n);
                                 }
#line 2154 "parser.cpp"
    break;

  case 84: /* RMGRP: rmgrp mayor name igual identificador  */
#line 329 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMGRP","");
        Nodo *n = new Nodo("name", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2164 "parser.cpp"
    break;

  case 85: /* RMGRP: rmgrp mayor name igual cadena  */
#line 335 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMGRP", "");
        Nodo *n = new Nodo("name",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2174 "parser.cpp"
    break;

  case 86: /* MKUSR: MKUSR PARAM_MKUSR  */
#line 342 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2183 "parser.cpp"
    break;

  case 87: /* MKUSR: PARAM_MKUSR  */
#line 347 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2192 "parser.cpp"
    break;

  case 88: /* PARAM_MKUSR: mayor usuario igual identificador  */
#line 352 "ASintactico.y"
                                              { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2198 "parser.cpp"
    break;

  case 89: /* PARAM_MKUSR: mayor usuario igual cadena  */
#line 353 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2204 "parser.cpp"
    break;

  case 90: /* PARAM_MKUSR: mayor password igual entero  */
#line 354 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2210 "parser.cpp"
    break;

  case 91: /* PARAM_MKUSR: mayor password igual identificador  */
#line 355 "ASintactico.y"
                                                { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2216 "parser.cpp"
    break;

  case 92: /* PARAM_MKUSR: mayor password igual pwd  */
#line 356 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2222 "parser.cpp"
    break;

  case 93: /* PARAM_MKUSR: mayor password igual cadena  */
#line 357 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2228 "parser.cpp"
    break;

  case 94: /* PARAM_MKUSR: mayor grp igual identificador  */
#line 358 "ASintactico.y"
                                           { (yyval.nodo) = new Nodo("group", (yyvsp[0].text)); }
#line 2234 "parser.cpp"
    break;

  case 95: /* PARAM_MKUSR: mayor grp igual cadena  */
#line 359 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("group",(yyvsp[0].text)); }
#line 2240 "parser.cpp"
    break;

  case 96: /* RMUSR: rmusr mayor usuario igual identificador  */
#line 362 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMUSR","");
        Nodo *n = new Nodo("user",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2250 "parser.cpp"
    break;

  case 97: /* RMUSR: rmusr mayor usuario igual cadena  */
#line 368 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMUSR", "");
        Nodo *n = new Nodo("user",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2260 "parser.cpp"
    break;

  case 98: /* CHMOD: CHMOD PARAM_CHMOD  */
#line 375 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2269 "parser.cpp"
    break;

  case 99: /* CHMOD: PARAM_CHMOD  */
#line 380 "ASintactico.y"
    {
       (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2278 "parser.cpp"
    break;

  case 100: /* PARAM_CHMOD: mayor path igual cadena  */
#line 385 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2284 "parser.cpp"
    break;

  case 101: /* PARAM_CHMOD: mayor path igual directorioA  */
#line 386 "ASintactico.y"
                                          { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2290 "parser.cpp"
    break;

  case 102: /* PARAM_CHMOD: mayor ugo igual entero  */
#line 387 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("ugo",(yyvsp[0].text)); }
#line 2296 "parser.cpp"
    break;

  case 103: /* PARAM_CHMOD: mayor r  */
#line 388 "ASintactico.y"
                     { (yyval.nodo) = new Nodo("r",""); }
#line 2302 "parser.cpp"
    break;


#line 2306 "parser.cpp"

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

