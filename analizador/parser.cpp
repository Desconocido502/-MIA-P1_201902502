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
    #include <string>
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

#line 96 "parser.cpp"

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
  YYSYMBOL_mkfile = 64,                    /* mkfile  */
  YYSYMBOL_cont = 65,                      /* cont  */
  YYSYMBOL_cat = 66,                       /* cat  */
  YYSYMBOL_removeR = 67,                   /* removeR  */
  YYSYMBOL_edit = 68,                      /* edit  */
  YYSYMBOL_renameR = 69,                   /* renameR  */
  YYSYMBOL_Rmkdir = 70,                    /* Rmkdir  */
  YYSYMBOL_destino = 71,                   /* destino  */
  YYSYMBOL_copyR = 72,                     /* copyR  */
  YYSYMBOL_moveR = 73,                     /* moveR  */
  YYSYMBOL_recovery = 74,                  /* recovery  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_INICIO = 76,                    /* INICIO  */
  YYSYMBOL_COMANDO = 77,                   /* COMANDO  */
  YYSYMBOL_MKDISK = 78,                    /* MKDISK  */
  YYSYMBOL_PARAMETRO_MK = 79,              /* PARAMETRO_MK  */
  YYSYMBOL_AJUSTE = 80,                    /* AJUSTE  */
  YYSYMBOL_FDISK = 81,                     /* FDISK  */
  YYSYMBOL_PARAMETRO_FK = 82,              /* PARAMETRO_FK  */
  YYSYMBOL_SCRIPT = 83,                    /* SCRIPT  */
  YYSYMBOL_REP = 84,                       /* REP  */
  YYSYMBOL_PARAMETRO_R = 85,               /* PARAMETRO_R  */
  YYSYMBOL_RMDISK = 86,                    /* RMDISK  */
  YYSYMBOL_MOUNT = 87,                     /* MOUNT  */
  YYSYMBOL_PARAMETRO_M = 88,               /* PARAMETRO_M  */
  YYSYMBOL_UNMOUNT = 89,                   /* UNMOUNT  */
  YYSYMBOL_MKFS = 90,                      /* MKFS  */
  YYSYMBOL_PARAM_MKFS = 91,                /* PARAM_MKFS  */
  YYSYMBOL_LOGIN = 92,                     /* LOGIN  */
  YYSYMBOL_PARAM_LOGIN = 93,               /* PARAM_LOGIN  */
  YYSYMBOL_MKGRP = 94,                     /* MKGRP  */
  YYSYMBOL_RMGRP = 95,                     /* RMGRP  */
  YYSYMBOL_MKUSR = 96,                     /* MKUSR  */
  YYSYMBOL_PARAM_MKUSR = 97,               /* PARAM_MKUSR  */
  YYSYMBOL_RMUSR = 98,                     /* RMUSR  */
  YYSYMBOL_CHMOD = 99,                     /* CHMOD  */
  YYSYMBOL_PARAM_CHMOD = 100,              /* PARAM_CHMOD  */
  YYSYMBOL_MKFILE = 101,                   /* MKFILE  */
  YYSYMBOL_PARAM_MKFILE = 102,             /* PARAM_MKFILE  */
  YYSYMBOL_CAT = 103,                      /* CAT  */
  YYSYMBOL_LTS_FILE = 104,                 /* LTS_FILE  */
  YYSYMBOL_REMOVE = 105,                   /* REMOVE  */
  YYSYMBOL_EDIT = 106,                     /* EDIT  */
  YYSYMBOL_PARAM_EDIT = 107,               /* PARAM_EDIT  */
  YYSYMBOL_RENAME = 108,                   /* RENAME  */
  YYSYMBOL_PARAM_RENAME = 109,             /* PARAM_RENAME  */
  YYSYMBOL_MKDIR = 110,                    /* MKDIR  */
  YYSYMBOL_PARAM_MKDIR = 111,              /* PARAM_MKDIR  */
  YYSYMBOL_COPY = 112,                     /* COPY  */
  YYSYMBOL_PARAM_COPY = 113,               /* PARAM_COPY  */
  YYSYMBOL_MOVE = 114,                     /* MOVE  */
  YYSYMBOL_RECOVERY = 115                  /* RECOVERY  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  90
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   152,   157,   161,   162,   167,   168,   169,
     170,   175,   180,   185,   186,   187,   188,   189,   193,   194,
     199,   204,   209,   210,   215,   220,   225,   230,   235,   238,
     242,   247,   248,   249,   250,   251,   256,   257,   258,   260,
     264,   269,   270,   271,   272,   273,   274,   276,   281,   287,
     291,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   313,   319,   326,
     331,   336,   337,   338,   339,   341,   348,   352,   357,   358,
     359,   360,   362,   367,   373,   374,   375,   376,   377,   378,
     379,   381,   386,   392,   398,   405,   410,   416,   417,   418,
     419,   420,   421,   422,   423,   425,   431,   438,   443,   449,
     450,   451,   452,   454,   459,   465,   466,   467,   468,   469,
     470,   472,   477,   483,   484,   486,   492,   498,   505,   510,
     516,   517,   518,   520,   525,   531,   532,   533,   539,   541,
     546,   552,   553,   554,   556,   561,   567,   568,   569,   570,
     571,   572,   574,   579,   585
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
  "ugo", "Rchmod", "directorioA", "mkfile", "cont", "cat", "removeR",
  "edit", "renameR", "Rmkdir", "destino", "copyR", "moveR", "recovery",
  "$accept", "INICIO", "COMANDO", "MKDISK", "PARAMETRO_MK", "AJUSTE",
  "FDISK", "PARAMETRO_FK", "SCRIPT", "REP", "PARAMETRO_R", "RMDISK",
  "MOUNT", "PARAMETRO_M", "UNMOUNT", "MKFS", "PARAM_MKFS", "LOGIN",
  "PARAM_LOGIN", "MKGRP", "RMGRP", "MKUSR", "PARAM_MKUSR", "RMUSR",
  "CHMOD", "PARAM_CHMOD", "MKFILE", "PARAM_MKFILE", "CAT", "LTS_FILE",
  "REMOVE", "EDIT", "PARAM_EDIT", "RENAME", "PARAM_RENAME", "MKDIR",
  "PARAM_MKDIR", "COPY", "PARAM_COPY", "MOVE", "RECOVERY", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-17)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    14,    16,    25,    42,   -17,    47,    53,    67,    89,
      91,   -17,   -17,   132,   144,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   166,   167,    90,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,    87,    14,   -17,     7,
      16,   -17,    39,   -17,    79,   -17,    42,   -17,   168,     9,
      53,   -17,   -16,     6,    89,   -17,    72,    91,   -17,   169,
     170,    40,   157,   -17,   138,    23,   159,   -17,    17,   160,
     -17,   171,   161,   -17,   172,     3,   163,   -17,    29,   164,
     -17,    -2,   165,   -17,     2,   166,   -17,   -17,   166,   145,
     -17,   173,   174,   177,   178,   -17,   180,   181,   182,   183,
     -17,   184,   185,   186,   187,   188,   -17,   189,   190,   191,
     -17,   192,   193,   194,   195,   -17,   196,   197,   198,   -17,
     199,   200,   201,   202,   203,   -17,   204,   205,   -17,   206,
     -17,   207,   208,   -17,   209,   -17,   210,   -17,   211,   212,
     213,   -17,   214,   215,   -17,   216,   -17,   -17,   217,   218,
     -17,   -17,   219,    22,   220,   221,   119,    83,    70,   222,
      88,   126,   224,    26,   147,   223,   128,   130,   108,   225,
     151,   226,   117,   227,   109,    68,   110,   114,   115,    69,
     116,   120,    -1,   228,   135,   231,   137,   139,   -15,   141,
     229,   143,   121,    13,   -12,    -6,   230,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   232,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,    13,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     8,
       9,    15,    16,    18,    22,    28,     0,     3,    30,     0,
       6,    50,     0,     5,     0,    41,     4,    40,     0,     0,
      10,    70,     0,     0,    11,    77,     0,    12,    83,     0,
       0,     0,    17,    96,     0,     0,    19,   108,     0,    20,
     114,     0,    21,   122,     0,     0,    23,   129,     0,    24,
     134,     0,    25,   140,     0,    26,   145,   153,    27,     0,
       1,     0,     0,     0,     0,    29,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,    39,     0,     0,     0,
      69,     0,     0,     0,     0,    76,     0,     0,     0,    82,
       0,     0,     0,     0,     0,    95,     0,     0,   112,     0,
     107,     0,     0,   120,     0,   113,     0,   121,     0,     0,
       0,   128,     0,     0,   133,     0,   143,   139,     0,     0,
     144,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    33,    31,
      32,    36,    37,    38,    35,    52,    51,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    56,    55,    54,
      53,    48,    47,    44,    42,    43,    45,    46,    67,    68,
      72,    71,    73,    74,    75,    79,    78,    80,    81,    90,
      84,    85,    86,    87,    89,    88,    91,    92,    93,    94,
      97,    98,    99,   100,   102,   101,   103,   104,   105,   106,
     109,   110,   111,   115,   116,   117,   118,   119,   123,   124,
     125,   126,   127,   130,   131,   132,   135,   136,     0,   138,
     142,   141,   146,   147,   148,   149,   150,   151,   154,   137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -17,   -17,   -17,   -17,     8,   -17,   -17,   233,   -17,   -17,
     234,   -17,   -17,   131,   -17,   -17,   175,   -17,   179,   -17,
     -17,   -17,   235,   -17,   -17,   236,   -17,   176,   -17,   237,
     -17,   -17,   155,   -17,   153,   -17,   152,   -17,   -13,   -17,
     -17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    27,    28,    37,    45,   204,    46,    47,    43,    40,
      41,    29,    50,    51,    30,    54,    55,    57,    58,    31,
      32,    62,    63,    33,    66,    67,    69,    70,    72,    73,
      34,    76,    77,    79,    80,    82,    83,    85,    86,    88,
      35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       1,     2,     3,     4,   270,   271,   145,   282,   283,    38,
     148,   139,    87,   285,   286,    96,   111,   108,     5,   260,
     112,    36,    97,    39,   109,   131,     6,     7,     8,   132,
       9,   127,    42,   280,    10,    11,    12,   142,   113,    98,
     114,   197,   198,   224,   143,    95,   225,   101,   272,    44,
      99,   284,    13,    14,    48,    15,    16,   287,   146,    17,
      49,    18,   261,    19,    20,    21,    22,    23,   140,    24,
      25,    26,   150,   149,    52,   151,   281,   133,   242,   252,
     122,   123,   134,   128,   129,   243,   253,    91,   244,   254,
      90,    92,    93,   102,   103,    91,    53,   124,    56,    92,
      93,    94,   205,   206,   116,   104,   105,   219,   220,    94,
     245,   255,   117,   118,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   232,   240,   246,   233,   241,
     247,   248,   250,   256,   249,   251,   257,   258,   278,    59,
     259,   279,   201,   202,   203,   221,   222,   228,   229,   230,
     231,    60,   237,   238,   263,   264,   266,   267,   268,   269,
     273,   274,   276,   277,    61,    64,    65,    68,    71,    74,
      75,    78,    81,    84,    89,   226,   107,   152,   126,   235,
     138,   110,   153,   154,   120,   121,   155,   156,   136,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   115,
     199,   141,   144,   227,   147,     0,   119,   200,   262,   218,
     223,   265,   234,   236,   239,   135,     0,   288,     0,   275,
     289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,     0,   130,     0,     0,     0,     0,     0,     0,   137
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,    19,    20,     8,    19,    20,     1,
       8,     8,    25,    19,    20,     8,    32,     8,    21,    20,
      14,     7,    15,     7,    15,     8,    29,    30,    31,    12,
      33,     8,     7,    20,    37,    38,    39,     8,    32,    32,
      34,    19,    20,    17,    15,    37,    20,     8,    63,     7,
      43,    63,    55,    56,     7,    58,    59,    63,    60,    62,
       7,    64,    63,    66,    67,    68,    69,    70,    65,    72,
      73,    74,    85,    71,     7,    88,    63,    60,    10,    10,
      40,    41,    65,    60,    61,    17,    17,     8,    20,    20,
       0,    12,    13,    14,    15,     8,     7,    57,     7,    12,
      13,    22,    19,    20,    32,    26,    27,    19,    20,    22,
      42,    42,    40,    41,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    17,    17,    17,    20,    20,
      20,    17,    17,    17,    20,    20,    20,    17,    17,     7,
      20,    20,    23,    24,    25,    19,    20,    19,    20,    19,
      20,     7,    35,    36,    19,    20,    19,    20,    19,    20,
      19,    20,    19,    20,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,    28,     8,    32,    40,    28,
       8,    50,     9,     9,    15,    15,     9,     9,    17,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,    54,
      10,    76,    79,    10,    82,    -1,    57,    16,    10,    17,
      16,    10,    17,    17,    17,    69,    -1,    17,    -1,    20,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    21,    29,    30,    31,    33,
      37,    38,    39,    55,    56,    58,    59,    62,    64,    66,
      67,    68,    69,    70,    72,    73,    74,    76,    77,    86,
      89,    94,    95,    98,   105,   115,     7,    78,    79,     7,
      84,    85,     7,    83,     7,    79,    81,    82,     7,     7,
      87,    88,     7,     7,    90,    91,     7,    92,    93,     7,
       7,     7,    96,    97,     7,     7,    99,   100,     7,   101,
     102,     7,   103,   104,     7,     7,   106,   107,     7,   108,
     109,     7,   110,   111,     7,   112,   113,   113,   114,     7,
       0,     8,    12,    13,    22,    79,     8,    15,    32,    43,
      85,     8,    14,    15,    26,    27,    82,     8,     8,    15,
      88,    32,    14,    32,    34,    91,    32,    40,    41,    93,
      15,    15,    40,    41,    57,    97,    40,     8,    60,    61,
     100,     8,    12,    60,    65,   102,    17,   104,     8,     8,
      65,   107,     8,    15,   109,     8,    60,   111,     8,    71,
     113,   113,    32,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,    19,    20,    10,
      16,    23,    24,    25,    80,    19,    20,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    17,    19,
      20,    19,    20,    16,    17,    20,    28,    10,    19,    20,
      19,    20,    17,    20,    17,    28,    17,    35,    36,    17,
      17,    20,    10,    17,    20,    42,    17,    20,    17,    20,
      17,    20,    10,    17,    20,    42,    17,    20,    17,    20,
      20,    63,    10,    19,    20,    10,    19,    20,    19,    20,
      19,    20,    63,    19,    20,    20,    19,    20,    17,    20,
      20,    63,    19,    20,    63,    19,    20,    63,    17,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      78,    79,    79,    79,    79,    79,    80,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    89,    90,    90,    91,    91,
      91,    91,    92,    92,    93,    93,    93,    93,    93,    93,
      93,    94,    94,    95,    95,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   100,   101,   101,   102,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   105,   105,   105,   106,   106,
     107,   107,   107,   108,   108,   109,   109,   109,   109,   110,
     110,   111,   111,   111,   112,   112,   113,   113,   113,   113,
     113,   113,   114,   114,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     2,
       1,     4,     4,     4,     4,     4,     1,     1,     1,     2,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     2,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     5,     2,
       1,     4,     4,     4,     4,     5,     2,     1,     4,     4,
       4,     4,     2,     1,     4,     4,     4,     4,     4,     4,
       4,     5,     5,     5,     5,     2,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     5,     5,     2,     1,     4,
       4,     4,     2,     2,     1,     4,     4,     4,     4,     4,
       2,     2,     1,     4,     4,     5,     5,     5,     2,     1,
       4,     4,     4,     2,     1,     4,     4,     5,     4,     2,
       1,     4,     4,     2,     2,     1,     4,     4,     4,     4,
       4,     4,     2,     1,     5
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
#line 150 "ASintactico.y"
               { raiz = (yyval.nodo); }
#line 1673 "parser.cpp"
    break;

  case 3: /* COMANDO: mkdisk MKDISK  */
#line 153 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKDISK", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1682 "parser.cpp"
    break;

  case 4: /* COMANDO: fdisk FDISK  */
#line 157 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("FDISK", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1691 "parser.cpp"
    break;

  case 5: /* COMANDO: execute SCRIPT  */
#line 161 "ASintactico.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1697 "parser.cpp"
    break;

  case 6: /* COMANDO: rep REP  */
#line 163 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REP", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1706 "parser.cpp"
    break;

  case 7: /* COMANDO: exitS  */
#line 167 "ASintactico.y"
           { (yyval.nodo) = new Nodo("EXIT", ""); }
#line 1712 "parser.cpp"
    break;

  case 8: /* COMANDO: RMDISK  */
#line 168 "ASintactico.y"
            { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1718 "parser.cpp"
    break;

  case 9: /* COMANDO: UNMOUNT  */
#line 169 "ASintactico.y"
             { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1724 "parser.cpp"
    break;

  case 10: /* COMANDO: mount MOUNT  */
#line 171 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MOUNT", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1733 "parser.cpp"
    break;

  case 11: /* COMANDO: mkfs MKFS  */
#line 176 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKFS", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1742 "parser.cpp"
    break;

  case 12: /* COMANDO: login LOGIN  */
#line 181 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("LOGIN", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1751 "parser.cpp"
    break;

  case 13: /* COMANDO: logout  */
#line 185 "ASintactico.y"
            { (yyval.nodo) = new Nodo("LOGOUT", ""); }
#line 1757 "parser.cpp"
    break;

  case 14: /* COMANDO: pausa  */
#line 186 "ASintactico.y"
           { (yyval.nodo) = new Nodo("PAUSE", ""); }
#line 1763 "parser.cpp"
    break;

  case 15: /* COMANDO: MKGRP  */
#line 187 "ASintactico.y"
           { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1769 "parser.cpp"
    break;

  case 16: /* COMANDO: RMGRP  */
#line 188 "ASintactico.y"
           { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1775 "parser.cpp"
    break;

  case 17: /* COMANDO: mkusr MKUSR  */
#line 189 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("MKUSR", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1784 "parser.cpp"
    break;

  case 18: /* COMANDO: RMUSR  */
#line 193 "ASintactico.y"
           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1790 "parser.cpp"
    break;

  case 19: /* COMANDO: Rchmod CHMOD  */
#line 195 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("CHMOD", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1799 "parser.cpp"
    break;

  case 20: /* COMANDO: mkfile MKFILE  */
#line 200 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKFILE","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1808 "parser.cpp"
    break;

  case 21: /* COMANDO: cat CAT  */
#line 205 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("CAT", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1817 "parser.cpp"
    break;

  case 22: /* COMANDO: REMOVE  */
#line 209 "ASintactico.y"
            { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1823 "parser.cpp"
    break;

  case 23: /* COMANDO: edit EDIT  */
#line 211 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("EDIT","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1832 "parser.cpp"
    break;

  case 24: /* COMANDO: renameR RENAME  */
#line 216 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RENAME","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1841 "parser.cpp"
    break;

  case 25: /* COMANDO: Rmkdir MKDIR  */
#line 221 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKDIR","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1850 "parser.cpp"
    break;

  case 26: /* COMANDO: copyR COPY  */
#line 226 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("COPY","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1859 "parser.cpp"
    break;

  case 27: /* COMANDO: moveR MOVE  */
#line 231 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MOVE","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1868 "parser.cpp"
    break;

  case 28: /* COMANDO: RECOVERY  */
#line 235 "ASintactico.y"
              { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1874 "parser.cpp"
    break;

  case 29: /* MKDISK: MKDISK PARAMETRO_MK  */
#line 238 "ASintactico.y"
                            {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1883 "parser.cpp"
    break;

  case 30: /* MKDISK: PARAMETRO_MK  */
#line 242 "ASintactico.y"
                   {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1892 "parser.cpp"
    break;

  case 31: /* PARAMETRO_MK: mayor sizeS igual entero  */
#line 247 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("size", (yyvsp[0].text)); }
#line 1898 "parser.cpp"
    break;

  case 32: /* PARAMETRO_MK: mayor unit igual caracter  */
#line 248 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("unit", (yyvsp[0].text)); }
#line 1904 "parser.cpp"
    break;

  case 33: /* PARAMETRO_MK: mayor path igual cadena  */
#line 249 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1910 "parser.cpp"
    break;

  case 34: /* PARAMETRO_MK: mayor path igual ruta  */
#line 250 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1916 "parser.cpp"
    break;

  case 35: /* PARAMETRO_MK: mayor fit igual AJUSTE  */
#line 251 "ASintactico.y"
                            {
        (yyval.nodo) = new Nodo("fit", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1925 "parser.cpp"
    break;

  case 36: /* AJUSTE: bf  */
#line 256 "ASintactico.y"
           { (yyval.nodo) = new Nodo("ajuste", "bf"); }
#line 1931 "parser.cpp"
    break;

  case 37: /* AJUSTE: ff  */
#line 257 "ASintactico.y"
         { (yyval.nodo) = new Nodo("ajuste", "ff"); }
#line 1937 "parser.cpp"
    break;

  case 38: /* AJUSTE: wf  */
#line 258 "ASintactico.y"
         { (yyval.nodo) = new Nodo("ajuste", "wf"); }
#line 1943 "parser.cpp"
    break;

  case 39: /* FDISK: FDISK PARAMETRO_FK  */
#line 260 "ASintactico.y"
                          {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1952 "parser.cpp"
    break;

  case 40: /* FDISK: PARAMETRO_FK  */
#line 264 "ASintactico.y"
                   {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1961 "parser.cpp"
    break;

  case 41: /* PARAMETRO_FK: PARAMETRO_MK  */
#line 269 "ASintactico.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1967 "parser.cpp"
    break;

  case 42: /* PARAMETRO_FK: mayor name igual identificador  */
#line 270 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1973 "parser.cpp"
    break;

  case 43: /* PARAMETRO_FK: mayor name igual cadena  */
#line 271 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1979 "parser.cpp"
    break;

  case 44: /* PARAMETRO_FK: mayor type igual caracter  */
#line 272 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("type", (yyvsp[0].text)); }
#line 1985 "parser.cpp"
    break;

  case 45: /* PARAMETRO_FK: mayor del_ igual full  */
#line 273 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("delete", "full"); }
#line 1991 "parser.cpp"
    break;

  case 46: /* PARAMETRO_FK: mayor add igual entero  */
#line 274 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("add", (yyvsp[0].text)); }
#line 1997 "parser.cpp"
    break;

  case 47: /* SCRIPT: mayor path igual cadena  */
#line 276 "ASintactico.y"
                                {
        (yyval.nodo) = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*path);
    }
#line 2007 "parser.cpp"
    break;

  case 48: /* SCRIPT: mayor path igual ruta  */
#line 281 "ASintactico.y"
                            {
        (yyval.nodo) = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*path);
    }
#line 2017 "parser.cpp"
    break;

  case 49: /* REP: REP PARAMETRO_R  */
#line 287 "ASintactico.y"
                    {
    (yyval.nodo) = (yyvsp[-1].nodo);
    (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2026 "parser.cpp"
    break;

  case 50: /* REP: PARAMETRO_R  */
#line 291 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2035 "parser.cpp"
    break;

  case 51: /* PARAMETRO_R: mayor path igual cadena  */
#line 296 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2041 "parser.cpp"
    break;

  case 52: /* PARAMETRO_R: mayor path igual ruta  */
#line 297 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2047 "parser.cpp"
    break;

  case 53: /* PARAMETRO_R: mayor rutaRep igual cadena  */
#line 298 "ASintactico.y"
                                { (yyval.nodo) = new Nodo("ruta", (yyvsp[0].text)); }
#line 2053 "parser.cpp"
    break;

  case 54: /* PARAMETRO_R: mayor rutaRep igual ruta  */
#line 299 "ASintactico.y"
                              { (yyval.nodo) = new Nodo("ruta", (yyvsp[0].text)); }
#line 2059 "parser.cpp"
    break;

  case 55: /* PARAMETRO_R: mayor id igual identificador  */
#line 300 "ASintactico.y"
                                  { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 2065 "parser.cpp"
    break;

  case 56: /* PARAMETRO_R: mayor name igual mbr  */
#line 301 "ASintactico.y"
                          { (yyval.nodo) = new Nodo("name","mbr"); }
#line 2071 "parser.cpp"
    break;

  case 57: /* PARAMETRO_R: mayor name igual disk  */
#line 302 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("name","disk"); }
#line 2077 "parser.cpp"
    break;

  case 58: /* PARAMETRO_R: mayor name igual inode  */
#line 303 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("name", "inode"); }
#line 2083 "parser.cpp"
    break;

  case 59: /* PARAMETRO_R: mayor name igual journaling  */
#line 304 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("name", "journaling"); }
#line 2089 "parser.cpp"
    break;

  case 60: /* PARAMETRO_R: mayor name igual block  */
#line 305 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("name", "block"); }
#line 2095 "parser.cpp"
    break;

  case 61: /* PARAMETRO_R: mayor name igual bm_inode  */
#line 306 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("name", "bm_inode"); }
#line 2101 "parser.cpp"
    break;

  case 62: /* PARAMETRO_R: mayor name igual bm_block  */
#line 307 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("name", "bm_block"); }
#line 2107 "parser.cpp"
    break;

  case 63: /* PARAMETRO_R: mayor name igual tree  */
#line 308 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("name", "tree"); }
#line 2113 "parser.cpp"
    break;

  case 64: /* PARAMETRO_R: mayor name igual sb  */
#line 309 "ASintactico.y"
                         { (yyval.nodo) = new Nodo("name", "sb"); }
#line 2119 "parser.cpp"
    break;

  case 65: /* PARAMETRO_R: mayor name igual fileRep  */
#line 310 "ASintactico.y"
                              { (yyval.nodo) = new Nodo("name", "file"); }
#line 2125 "parser.cpp"
    break;

  case 66: /* PARAMETRO_R: mayor name igual ls  */
#line 311 "ASintactico.y"
                         { (yyval.nodo) = new Nodo("name", "ls"); }
#line 2131 "parser.cpp"
    break;

  case 67: /* RMDISK: rmdisk mayor path igual ruta  */
#line 314 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*ruta);
    }
#line 2141 "parser.cpp"
    break;

  case 68: /* RMDISK: rmdisk mayor path igual cadena  */
#line 320 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*ruta);
    }
#line 2151 "parser.cpp"
    break;

  case 69: /* MOUNT: MOUNT PARAMETRO_M  */
#line 327 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2160 "parser.cpp"
    break;

  case 70: /* MOUNT: PARAMETRO_M  */
#line 331 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2169 "parser.cpp"
    break;

  case 71: /* PARAMETRO_M: mayor path igual cadena  */
#line 336 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2175 "parser.cpp"
    break;

  case 72: /* PARAMETRO_M: mayor path igual ruta  */
#line 337 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2181 "parser.cpp"
    break;

  case 73: /* PARAMETRO_M: mayor name igual identificador  */
#line 338 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 2187 "parser.cpp"
    break;

  case 74: /* PARAMETRO_M: mayor name igual cadena  */
#line 339 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 2193 "parser.cpp"
    break;

  case 75: /* UNMOUNT: unmount mayor id igual identificador  */
#line 342 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("UNMOUNT", "");
        Nodo *n = new Nodo("id", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2203 "parser.cpp"
    break;

  case 76: /* MKFS: MKFS PARAM_MKFS  */
#line 348 "ASintactico.y"
                      {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2212 "parser.cpp"
    break;

  case 77: /* MKFS: PARAM_MKFS  */
#line 352 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2221 "parser.cpp"
    break;

  case 78: /* PARAM_MKFS: mayor id igual identificador  */
#line 357 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 2227 "parser.cpp"
    break;

  case 79: /* PARAM_MKFS: mayor type igual full  */
#line 358 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("type", "full"); }
#line 2233 "parser.cpp"
    break;

  case 80: /* PARAM_MKFS: mayor fs igual fs2  */
#line 359 "ASintactico.y"
                        { (yyval.nodo) = new Nodo("fs", "2fs"); }
#line 2239 "parser.cpp"
    break;

  case 81: /* PARAM_MKFS: mayor fs igual fs3  */
#line 360 "ASintactico.y"
                        { (yyval.nodo) = new Nodo("fs", "3fs"); }
#line 2245 "parser.cpp"
    break;

  case 82: /* LOGIN: LOGIN PARAM_LOGIN  */
#line 363 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2254 "parser.cpp"
    break;

  case 83: /* LOGIN: PARAM_LOGIN  */
#line 368 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2263 "parser.cpp"
    break;

  case 84: /* PARAM_LOGIN: mayor usuario igual identificador  */
#line 373 "ASintactico.y"
                                              { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2269 "parser.cpp"
    break;

  case 85: /* PARAM_LOGIN: mayor usuario igual cadena  */
#line 374 "ASintactico.y"
                                { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2275 "parser.cpp"
    break;

  case 86: /* PARAM_LOGIN: mayor password igual entero  */
#line 375 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2281 "parser.cpp"
    break;

  case 87: /* PARAM_LOGIN: mayor password igual identificador  */
#line 376 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2287 "parser.cpp"
    break;

  case 88: /* PARAM_LOGIN: mayor password igual pwd  */
#line 377 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2293 "parser.cpp"
    break;

  case 89: /* PARAM_LOGIN: mayor password igual cadena  */
#line 378 "ASintactico.y"
                                  { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2299 "parser.cpp"
    break;

  case 90: /* PARAM_LOGIN: mayor id igual identificador  */
#line 379 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 2305 "parser.cpp"
    break;

  case 91: /* MKGRP: mkgrp mayor name igual identificador  */
#line 381 "ASintactico.y"
                                            {
                                        (yyval.nodo) = new Nodo("MKGRP","");
                                        Nodo *n = new Nodo("name",(yyvsp[0].text));
                                        (yyval.nodo)->add(*n);
                                      }
#line 2315 "parser.cpp"
    break;

  case 92: /* MKGRP: mkgrp mayor name igual cadena  */
#line 386 "ASintactico.y"
                                       {
                                    (yyval.nodo) = new Nodo("MKGRP","");
                                    Nodo *n = new Nodo("name",(yyvsp[0].text));
                                    (yyval.nodo)->add(*n);
                                 }
#line 2325 "parser.cpp"
    break;

  case 93: /* RMGRP: rmgrp mayor name igual identificador  */
#line 393 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMGRP","");
        Nodo *n = new Nodo("name", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2335 "parser.cpp"
    break;

  case 94: /* RMGRP: rmgrp mayor name igual cadena  */
#line 399 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMGRP", "");
        Nodo *n = new Nodo("name",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2345 "parser.cpp"
    break;

  case 95: /* MKUSR: MKUSR PARAM_MKUSR  */
#line 406 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2354 "parser.cpp"
    break;

  case 96: /* MKUSR: PARAM_MKUSR  */
#line 411 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2363 "parser.cpp"
    break;

  case 97: /* PARAM_MKUSR: mayor usuario igual identificador  */
#line 416 "ASintactico.y"
                                              { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2369 "parser.cpp"
    break;

  case 98: /* PARAM_MKUSR: mayor usuario igual cadena  */
#line 417 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2375 "parser.cpp"
    break;

  case 99: /* PARAM_MKUSR: mayor password igual entero  */
#line 418 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2381 "parser.cpp"
    break;

  case 100: /* PARAM_MKUSR: mayor password igual identificador  */
#line 419 "ASintactico.y"
                                                { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2387 "parser.cpp"
    break;

  case 101: /* PARAM_MKUSR: mayor password igual pwd  */
#line 420 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2393 "parser.cpp"
    break;

  case 102: /* PARAM_MKUSR: mayor password igual cadena  */
#line 421 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2399 "parser.cpp"
    break;

  case 103: /* PARAM_MKUSR: mayor grp igual identificador  */
#line 422 "ASintactico.y"
                                           { (yyval.nodo) = new Nodo("group", (yyvsp[0].text)); }
#line 2405 "parser.cpp"
    break;

  case 104: /* PARAM_MKUSR: mayor grp igual cadena  */
#line 423 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("group",(yyvsp[0].text)); }
#line 2411 "parser.cpp"
    break;

  case 105: /* RMUSR: rmusr mayor usuario igual identificador  */
#line 426 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMUSR","");
        Nodo *n = new Nodo("user",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2421 "parser.cpp"
    break;

  case 106: /* RMUSR: rmusr mayor usuario igual cadena  */
#line 432 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMUSR", "");
        Nodo *n = new Nodo("user",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2431 "parser.cpp"
    break;

  case 107: /* CHMOD: CHMOD PARAM_CHMOD  */
#line 439 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2440 "parser.cpp"
    break;

  case 108: /* CHMOD: PARAM_CHMOD  */
#line 444 "ASintactico.y"
    {
       (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2449 "parser.cpp"
    break;

  case 109: /* PARAM_CHMOD: mayor path igual cadena  */
#line 449 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2455 "parser.cpp"
    break;

  case 110: /* PARAM_CHMOD: mayor path igual directorioA  */
#line 450 "ASintactico.y"
                                          { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2461 "parser.cpp"
    break;

  case 111: /* PARAM_CHMOD: mayor ugo igual entero  */
#line 451 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("ugo",(yyvsp[0].text)); }
#line 2467 "parser.cpp"
    break;

  case 112: /* PARAM_CHMOD: mayor r  */
#line 452 "ASintactico.y"
                     { (yyval.nodo) = new Nodo("r",""); }
#line 2473 "parser.cpp"
    break;

  case 113: /* MKFILE: MKFILE PARAM_MKFILE  */
#line 455 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2482 "parser.cpp"
    break;

  case 114: /* MKFILE: PARAM_MKFILE  */
#line 459 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2491 "parser.cpp"
    break;

  case 115: /* PARAM_MKFILE: mayor path igual ruta  */
#line 465 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2497 "parser.cpp"
    break;

  case 116: /* PARAM_MKFILE: mayor path igual cadena  */
#line 466 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2503 "parser.cpp"
    break;

  case 117: /* PARAM_MKFILE: mayor sizeS igual entero  */
#line 467 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("size",(yyvsp[0].text)); }
#line 2509 "parser.cpp"
    break;

  case 118: /* PARAM_MKFILE: mayor cont igual ruta  */
#line 468 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("cont",(yyvsp[0].text)); }
#line 2515 "parser.cpp"
    break;

  case 119: /* PARAM_MKFILE: mayor cont igual cadena  */
#line 469 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("cont",(yyvsp[0].text)); }
#line 2521 "parser.cpp"
    break;

  case 120: /* PARAM_MKFILE: mayor r  */
#line 470 "ASintactico.y"
                     { (yyval.nodo) = new Nodo("r",""); }
#line 2527 "parser.cpp"
    break;

  case 121: /* CAT: CAT LTS_FILE  */
#line 473 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2536 "parser.cpp"
    break;

  case 122: /* CAT: LTS_FILE  */
#line 478 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2545 "parser.cpp"
    break;

  case 123: /* LTS_FILE: mayor identificador igual ruta  */
#line 483 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo((yyvsp[-2].text), (yyvsp[0].text)); }
#line 2551 "parser.cpp"
    break;

  case 124: /* LTS_FILE: mayor identificador igual cadena  */
#line 484 "ASintactico.y"
                                          { (yyval.nodo) = new Nodo((yyvsp[-2].text), (yyvsp[0].text)); }
#line 2557 "parser.cpp"
    break;

  case 125: /* REMOVE: removeR mayor path igual ruta  */
#line 487 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REMOVE", "");
        Nodo *n = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2567 "parser.cpp"
    break;

  case 126: /* REMOVE: removeR mayor path igual cadena  */
#line 493 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REMOVE", "");
        Nodo *n = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2577 "parser.cpp"
    break;

  case 127: /* REMOVE: removeR mayor path igual directorioA  */
#line 499 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REMOVE", "");
        Nodo *n = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2587 "parser.cpp"
    break;

  case 128: /* EDIT: EDIT PARAM_EDIT  */
#line 506 "ASintactico.y"
        {
            (yyval.nodo) = (yyvsp[-1].nodo);
            (yyval.nodo)->add(*(yyvsp[0].nodo));
        }
#line 2596 "parser.cpp"
    break;

  case 129: /* EDIT: PARAM_EDIT  */
#line 511 "ASintactico.y"
        {
            (yyval.nodo) = new Nodo("PARAMETRO","");
            (yyval.nodo)->add(*(yyvsp[0].nodo));
        }
#line 2605 "parser.cpp"
    break;

  case 130: /* PARAM_EDIT: mayor path igual ruta  */
#line 516 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2611 "parser.cpp"
    break;

  case 131: /* PARAM_EDIT: mayor path igual cadena  */
#line 517 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2617 "parser.cpp"
    break;

  case 132: /* PARAM_EDIT: mayor cont igual cadena  */
#line 518 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("cont", (yyvsp[0].text)); }
#line 2623 "parser.cpp"
    break;

  case 133: /* RENAME: RENAME PARAM_RENAME  */
#line 521 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2632 "parser.cpp"
    break;

  case 134: /* RENAME: PARAM_RENAME  */
#line 526 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2641 "parser.cpp"
    break;

  case 135: /* PARAM_RENAME: mayor path igual ruta  */
#line 531 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2647 "parser.cpp"
    break;

  case 136: /* PARAM_RENAME: mayor path igual cadena  */
#line 532 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2653 "parser.cpp"
    break;

  case 137: /* PARAM_RENAME: mayor name igual identificador extension  */
#line 534 "ASintactico.y"
        {
            (yyval.nodo) = new Nodo("name","");
            Nodo *n = new Nodo((yyvsp[-1].text),(yyvsp[0].text));
            (yyval.nodo)->add(*n);
        }
#line 2663 "parser.cpp"
    break;

  case 138: /* PARAM_RENAME: mayor name igual cadena  */
#line 539 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("name",(yyvsp[0].text)); }
#line 2669 "parser.cpp"
    break;

  case 139: /* MKDIR: MKDIR PARAM_MKDIR  */
#line 542 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2678 "parser.cpp"
    break;

  case 140: /* MKDIR: PARAM_MKDIR  */
#line 547 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2687 "parser.cpp"
    break;

  case 141: /* PARAM_MKDIR: mayor path igual directorioA  */
#line 552 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2693 "parser.cpp"
    break;

  case 142: /* PARAM_MKDIR: mayor path igual cadena  */
#line 553 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2699 "parser.cpp"
    break;

  case 143: /* PARAM_MKDIR: mayor r  */
#line 554 "ASintactico.y"
                     { (yyval.nodo) = new Nodo("r",""); }
#line 2705 "parser.cpp"
    break;

  case 144: /* COPY: COPY PARAM_COPY  */
#line 557 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2714 "parser.cpp"
    break;

  case 145: /* COPY: PARAM_COPY  */
#line 562 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2723 "parser.cpp"
    break;

  case 146: /* PARAM_COPY: mayor path igual ruta  */
#line 567 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2729 "parser.cpp"
    break;

  case 147: /* PARAM_COPY: mayor path igual cadena  */
#line 568 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2735 "parser.cpp"
    break;

  case 148: /* PARAM_COPY: mayor path igual directorioA  */
#line 569 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2741 "parser.cpp"
    break;

  case 149: /* PARAM_COPY: mayor destino igual ruta  */
#line 570 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("destino",(yyvsp[0].text)); }
#line 2747 "parser.cpp"
    break;

  case 150: /* PARAM_COPY: mayor destino igual cadena  */
#line 571 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("destino",(yyvsp[0].text)); }
#line 2753 "parser.cpp"
    break;

  case 151: /* PARAM_COPY: mayor destino igual directorioA  */
#line 572 "ASintactico.y"
                                           { (yyval.nodo) = new Nodo("destino",(yyvsp[0].text)); }
#line 2759 "parser.cpp"
    break;

  case 152: /* MOVE: MOVE PARAM_COPY  */
#line 575 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2768 "parser.cpp"
    break;

  case 153: /* MOVE: PARAM_COPY  */
#line 580 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2777 "parser.cpp"
    break;

  case 154: /* RECOVERY: recovery mayor id igual identificador  */
#line 586 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RECOVERY","");
        Nodo *n = new Nodo("id",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2787 "parser.cpp"
    break;


#line 2791 "parser.cpp"

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

