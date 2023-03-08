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
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_INICIO = 71,                    /* INICIO  */
  YYSYMBOL_COMANDO = 72,                   /* COMANDO  */
  YYSYMBOL_MKDISK = 73,                    /* MKDISK  */
  YYSYMBOL_PARAMETRO_MK = 74,              /* PARAMETRO_MK  */
  YYSYMBOL_AJUSTE = 75,                    /* AJUSTE  */
  YYSYMBOL_FDISK = 76,                     /* FDISK  */
  YYSYMBOL_PARAMETRO_FK = 77,              /* PARAMETRO_FK  */
  YYSYMBOL_SCRIPT = 78,                    /* SCRIPT  */
  YYSYMBOL_REP = 79,                       /* REP  */
  YYSYMBOL_PARAMETRO_R = 80,               /* PARAMETRO_R  */
  YYSYMBOL_RMDISK = 81,                    /* RMDISK  */
  YYSYMBOL_MOUNT = 82,                     /* MOUNT  */
  YYSYMBOL_PARAMETRO_M = 83,               /* PARAMETRO_M  */
  YYSYMBOL_UNMOUNT = 84,                   /* UNMOUNT  */
  YYSYMBOL_MKFS = 85,                      /* MKFS  */
  YYSYMBOL_PARAM_MKFS = 86,                /* PARAM_MKFS  */
  YYSYMBOL_LOGIN = 87,                     /* LOGIN  */
  YYSYMBOL_PARAM_LOGIN = 88,               /* PARAM_LOGIN  */
  YYSYMBOL_MKGRP = 89,                     /* MKGRP  */
  YYSYMBOL_RMGRP = 90,                     /* RMGRP  */
  YYSYMBOL_MKUSR = 91,                     /* MKUSR  */
  YYSYMBOL_PARAM_MKUSR = 92,               /* PARAM_MKUSR  */
  YYSYMBOL_RMUSR = 93,                     /* RMUSR  */
  YYSYMBOL_CHMOD = 94,                     /* CHMOD  */
  YYSYMBOL_PARAM_CHMOD = 95,               /* PARAM_CHMOD  */
  YYSYMBOL_MKFILE = 96,                    /* MKFILE  */
  YYSYMBOL_PARAM_MKFILE = 97,              /* PARAM_MKFILE  */
  YYSYMBOL_CAT = 98,                       /* CAT  */
  YYSYMBOL_LTS_FILE = 99,                  /* LTS_FILE  */
  YYSYMBOL_REMOVE = 100,                   /* REMOVE  */
  YYSYMBOL_EDIT = 101,                     /* EDIT  */
  YYSYMBOL_PARAM_EDIT = 102,               /* PARAM_EDIT  */
  YYSYMBOL_RENAME = 103,                   /* RENAME  */
  YYSYMBOL_PARAM_RENAME = 104              /* PARAM_RENAME  */
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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  255

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   139,   139,   141,   146,   150,   151,   156,   157,   158,
     159,   164,   169,   174,   175,   176,   177,   178,   182,   183,
     188,   193,   198,   199,   204,   211,   215,   220,   221,   222,
     223,   224,   229,   230,   231,   233,   237,   242,   243,   244,
     245,   246,   247,   249,   254,   260,   264,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   286,   292,   299,   304,   309,   310,   311,
     312,   314,   321,   325,   330,   331,   332,   333,   335,   340,
     346,   347,   348,   349,   350,   351,   352,   354,   359,   365,
     371,   378,   383,   389,   390,   391,   392,   393,   394,   395,
     396,   398,   404,   411,   416,   422,   423,   424,   425,   427,
     432,   438,   439,   440,   441,   442,   443,   445,   450,   456,
     457,   459,   465,   471,   478,   483,   489,   490,   491,   493,
     498,   504,   505,   506,   512
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
  "edit", "renameR", "$accept", "INICIO", "COMANDO", "MKDISK",
  "PARAMETRO_MK", "AJUSTE", "FDISK", "PARAMETRO_FK", "SCRIPT", "REP",
  "PARAMETRO_R", "RMDISK", "MOUNT", "PARAMETRO_M", "UNMOUNT", "MKFS",
  "PARAM_MKFS", "LOGIN", "PARAM_LOGIN", "MKGRP", "RMGRP", "MKUSR",
  "PARAM_MKUSR", "RMUSR", "CHMOD", "PARAM_CHMOD", "MKFILE", "PARAM_MKFILE",
  "CAT", "LTS_FILE", "REMOVE", "EDIT", "PARAM_EDIT", "RENAME",
  "PARAM_RENAME", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    13,    18,    24,    26,   -29,    32,    53,    81,   112,
     133,   -29,   -29,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    74,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,    71,    13,   -29,     0,    18,   -29,   144,   -29,    63,
     -29,    26,   -29,   145,    43,    53,   -29,   122,    10,   112,
     -29,     5,   133,   -29,   146,   147,   -28,   136,   -29,   116,
       9,   138,   -29,     2,   139,   -29,   148,   140,   -29,   149,
       3,   142,   -29,    65,   143,   -29,   -29,   150,   151,   154,
     155,   -29,   157,   158,   159,   160,   -29,   161,   162,   163,
     164,   165,   -29,   166,   167,   168,   -29,   169,   170,   171,
     172,   -29,   173,   174,   175,   -29,   176,   177,   178,   179,
     180,   -29,   181,   182,   -29,   183,   -29,   184,   185,   -29,
     186,   -29,   187,   -29,   188,   189,   190,   -29,   191,   192,
     -29,    62,   193,   194,    -2,    67,    50,   195,    72,   103,
     197,    37,   123,   196,   105,   107,    88,   198,   127,   199,
      93,   200,    89,    -1,    90,    94,    95,    30,    96,   100,
     -14,   201,   111,   204,   113,   115,   -15,   117,   202,   119,
     101,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   203,   -29,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,    13,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     8,     9,    15,    16,    18,
      22,     0,     3,    26,     0,     6,    46,     0,     5,     0,
      37,     4,    36,     0,     0,    10,    66,     0,     0,    11,
      73,     0,    12,    79,     0,     0,     0,    17,    92,     0,
       0,    19,   104,     0,    20,   110,     0,    21,   118,     0,
       0,    23,   125,     0,    24,   130,     1,     0,     0,     0,
       0,    25,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,    35,     0,     0,     0,    65,     0,     0,     0,
       0,    72,     0,     0,     0,    78,     0,     0,     0,     0,
       0,    91,     0,     0,   108,     0,   103,     0,     0,   116,
       0,   109,     0,   117,     0,     0,     0,   124,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    29,    27,    28,    32,    33,    34,    31,    48,
      47,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    52,    51,    50,    49,    44,    43,    40,    38,    39,
      41,    42,    63,    64,    68,    67,    69,    70,    71,    75,
      74,    76,    77,    86,    80,    81,    82,    83,    85,    84,
      87,    88,    89,    90,    93,    94,    95,    96,    98,    97,
      99,   100,   101,   102,   105,   106,   107,   111,   112,   113,
     114,   115,   119,   120,   121,   122,   123,   126,   127,   128,
     131,   132,     0,   134,   133
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -29,   -29,   -29,   -29,     6,   -29,   -29,   205,   -29,   -29,
     206,   -29,   -29,   207,   -29,   -29,   109,   -29,   152,   -29,
     -29,   -29,   208,   -29,   -29,   209,   -29,   156,   -29,   210,
     -29,   -29,   131,   -29,   153
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,    32,    40,   178,    41,    42,    38,    35,
      36,    25,    45,    46,    26,    49,    50,    52,    53,    27,
      28,    57,    58,    29,    61,    62,    64,    65,    67,    68,
      30,    71,    72,    74,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       1,     2,     3,     4,   244,   245,   234,    33,    82,   216,
     117,   125,   108,   109,   118,    83,   217,   113,     5,   218,
      31,   175,   176,   177,    98,    34,     6,     7,     8,   110,
       9,    37,    84,    39,    10,    11,    12,   102,    81,    43,
     226,   219,    99,    85,   100,   103,   104,   227,   246,   235,
     228,    94,    13,    14,   198,    15,    16,   199,    95,    17,
      44,    18,   119,    19,    20,    21,    22,   120,   126,   114,
     115,    77,   229,   128,    76,    78,    79,    88,    89,    77,
     129,   171,   172,    78,    79,    80,   179,   180,    47,    90,
      91,   193,   194,    80,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   206,   214,   220,   207,   215,
     221,   222,   224,   230,   223,   225,   231,   232,   252,    48,
     233,   253,   195,   196,   202,   203,   204,   205,   211,   212,
     237,   238,   240,   241,   242,   243,   247,   248,   250,   251,
      51,    54,    55,    56,    59,    60,    63,    66,    69,    70,
      73,   200,    87,    93,    97,   209,   112,   124,   101,   131,
     132,   106,   107,   133,   134,   122,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   127,   173,   105,     0,   201,     0,     0,     0,
     174,   236,   192,   197,   239,   208,   210,   213,     0,     0,
     121,   254,   249,     0,     0,     0,     0,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,     0,     0,     0,    92,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,   123
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,    19,    20,    20,     1,     8,    10,
       8,     8,    40,    41,    12,    15,    17,     8,    21,    20,
       7,    23,    24,    25,    14,     7,    29,    30,    31,    57,
      33,     7,    32,     7,    37,    38,    39,    32,    32,     7,
      10,    42,    32,    43,    34,    40,    41,    17,    63,    63,
      20,     8,    55,    56,    17,    58,    59,    20,    15,    62,
       7,    64,    60,    66,    67,    68,    69,    65,    65,    60,
      61,     8,    42,     8,     0,    12,    13,    14,    15,     8,
      15,    19,    20,    12,    13,    22,    19,    20,     7,    26,
      27,    19,    20,    22,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    17,    17,    17,    20,    20,
      20,    17,    17,    17,    20,    20,    20,    17,    17,     7,
      20,    20,    19,    20,    19,    20,    19,    20,    35,    36,
      19,    20,    19,    20,    19,    20,    19,    20,    19,    20,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,    28,     8,     8,    32,    28,    40,     8,    49,     9,
       9,    15,    15,     9,     9,    17,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,    71,    10,    52,    -1,    10,    -1,    -1,    -1,
      16,    10,    17,    16,    10,    17,    17,    17,    -1,    -1,
      64,    18,    20,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    21,    29,    30,    31,    33,
      37,    38,    39,    55,    56,    58,    59,    62,    64,    66,
      67,    68,    69,    71,    72,    81,    84,    89,    90,    93,
     100,     7,    73,    74,     7,    79,    80,     7,    78,     7,
      74,    76,    77,     7,     7,    82,    83,     7,     7,    85,
      86,     7,    87,    88,     7,     7,     7,    91,    92,     7,
       7,    94,    95,     7,    96,    97,     7,    98,    99,     7,
       7,   101,   102,     7,   103,   104,     0,     8,    12,    13,
      22,    74,     8,    15,    32,    43,    80,     8,    14,    15,
      26,    27,    77,     8,     8,    15,    83,    32,    14,    32,
      34,    86,    32,    40,    41,    88,    15,    15,    40,    41,
      57,    92,    40,     8,    60,    61,    95,     8,    12,    60,
      65,    97,    17,    99,     8,     8,    65,   102,     8,    15,
     104,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,    19,    20,    10,    16,    23,    24,    25,    75,    19,
      20,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    17,    19,    20,    19,    20,    16,    17,    20,
      28,    10,    19,    20,    19,    20,    17,    20,    17,    28,
      17,    35,    36,    17,    17,    20,    10,    17,    20,    42,
      17,    20,    17,    20,    17,    20,    10,    17,    20,    42,
      17,    20,    17,    20,    20,    63,    10,    19,    20,    10,
      19,    20,    19,    20,    19,    20,    63,    19,    20,    20,
      19,    20,    17,    20,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    74,
      74,    74,    75,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    82,    82,    83,    83,    83,
      83,    84,    85,    85,    86,    86,    86,    86,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    94,    94,    95,    95,    95,    95,    96,
      96,    97,    97,    97,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   101,   101,   102,   102,   102,   103,
     103,   104,   104,   104,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     2,     1,     4,     4,     4,
       4,     4,     1,     1,     1,     2,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     2,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     5,     2,     1,     4,     4,     4,
       4,     5,     2,     1,     4,     4,     4,     4,     2,     1,
       4,     4,     4,     4,     4,     4,     4,     5,     5,     5,
       5,     2,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     5,     2,     1,     4,     4,     4,     2,     2,
       1,     4,     4,     4,     4,     4,     2,     2,     1,     4,
       4,     5,     5,     5,     2,     1,     4,     4,     4,     2,
       1,     4,     4,     5,     4
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
#line 139 "ASintactico.y"
               { raiz = (yyval.nodo); }
#line 1638 "parser.cpp"
    break;

  case 3: /* COMANDO: mkdisk MKDISK  */
#line 142 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKDISK", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1647 "parser.cpp"
    break;

  case 4: /* COMANDO: fdisk FDISK  */
#line 146 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("FDISK", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1656 "parser.cpp"
    break;

  case 5: /* COMANDO: execute SCRIPT  */
#line 150 "ASintactico.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1662 "parser.cpp"
    break;

  case 6: /* COMANDO: rep REP  */
#line 152 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REP", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1671 "parser.cpp"
    break;

  case 7: /* COMANDO: exitS  */
#line 156 "ASintactico.y"
           { (yyval.nodo) = new Nodo("EXIT", ""); }
#line 1677 "parser.cpp"
    break;

  case 8: /* COMANDO: RMDISK  */
#line 157 "ASintactico.y"
            { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1683 "parser.cpp"
    break;

  case 9: /* COMANDO: UNMOUNT  */
#line 158 "ASintactico.y"
             { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1689 "parser.cpp"
    break;

  case 10: /* COMANDO: mount MOUNT  */
#line 160 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MOUNT", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1698 "parser.cpp"
    break;

  case 11: /* COMANDO: mkfs MKFS  */
#line 165 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKFS", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1707 "parser.cpp"
    break;

  case 12: /* COMANDO: login LOGIN  */
#line 170 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("LOGIN", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1716 "parser.cpp"
    break;

  case 13: /* COMANDO: logout  */
#line 174 "ASintactico.y"
            { (yyval.nodo) = new Nodo("LOGOUT", ""); }
#line 1722 "parser.cpp"
    break;

  case 14: /* COMANDO: pausa  */
#line 175 "ASintactico.y"
           { (yyval.nodo) = new Nodo("PAUSE", ""); }
#line 1728 "parser.cpp"
    break;

  case 15: /* COMANDO: MKGRP  */
#line 176 "ASintactico.y"
           { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1734 "parser.cpp"
    break;

  case 16: /* COMANDO: RMGRP  */
#line 177 "ASintactico.y"
           { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1740 "parser.cpp"
    break;

  case 17: /* COMANDO: mkusr MKUSR  */
#line 178 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("MKUSR", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1749 "parser.cpp"
    break;

  case 18: /* COMANDO: RMUSR  */
#line 182 "ASintactico.y"
           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1755 "parser.cpp"
    break;

  case 19: /* COMANDO: Rchmod CHMOD  */
#line 184 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("CHMOD", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1764 "parser.cpp"
    break;

  case 20: /* COMANDO: mkfile MKFILE  */
#line 189 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("MKFILE","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1773 "parser.cpp"
    break;

  case 21: /* COMANDO: cat CAT  */
#line 194 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("CAT", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1782 "parser.cpp"
    break;

  case 22: /* COMANDO: REMOVE  */
#line 198 "ASintactico.y"
            { (yyval.nodo)=(yyvsp[0].nodo); }
#line 1788 "parser.cpp"
    break;

  case 23: /* COMANDO: edit EDIT  */
#line 200 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("EDIT","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1797 "parser.cpp"
    break;

  case 24: /* COMANDO: renameR RENAME  */
#line 205 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REN","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1806 "parser.cpp"
    break;

  case 25: /* MKDISK: MKDISK PARAMETRO_MK  */
#line 211 "ASintactico.y"
                            {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1815 "parser.cpp"
    break;

  case 26: /* MKDISK: PARAMETRO_MK  */
#line 215 "ASintactico.y"
                   {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1824 "parser.cpp"
    break;

  case 27: /* PARAMETRO_MK: mayor sizeS igual entero  */
#line 220 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("size", (yyvsp[0].text)); }
#line 1830 "parser.cpp"
    break;

  case 28: /* PARAMETRO_MK: mayor unit igual caracter  */
#line 221 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("unit", (yyvsp[0].text)); }
#line 1836 "parser.cpp"
    break;

  case 29: /* PARAMETRO_MK: mayor path igual cadena  */
#line 222 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1842 "parser.cpp"
    break;

  case 30: /* PARAMETRO_MK: mayor path igual ruta  */
#line 223 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1848 "parser.cpp"
    break;

  case 31: /* PARAMETRO_MK: mayor fit igual AJUSTE  */
#line 224 "ASintactico.y"
                            {
        (yyval.nodo) = new Nodo("fit", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1857 "parser.cpp"
    break;

  case 32: /* AJUSTE: bf  */
#line 229 "ASintactico.y"
           { (yyval.nodo) = new Nodo("ajuste", "bf"); }
#line 1863 "parser.cpp"
    break;

  case 33: /* AJUSTE: ff  */
#line 230 "ASintactico.y"
         { (yyval.nodo) = new Nodo("ajuste", "ff"); }
#line 1869 "parser.cpp"
    break;

  case 34: /* AJUSTE: wf  */
#line 231 "ASintactico.y"
         { (yyval.nodo) = new Nodo("ajuste", "wf"); }
#line 1875 "parser.cpp"
    break;

  case 35: /* FDISK: FDISK PARAMETRO_FK  */
#line 233 "ASintactico.y"
                          {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1884 "parser.cpp"
    break;

  case 36: /* FDISK: PARAMETRO_FK  */
#line 237 "ASintactico.y"
                   {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1893 "parser.cpp"
    break;

  case 37: /* PARAMETRO_FK: PARAMETRO_MK  */
#line 242 "ASintactico.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1899 "parser.cpp"
    break;

  case 38: /* PARAMETRO_FK: mayor name igual identificador  */
#line 243 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1905 "parser.cpp"
    break;

  case 39: /* PARAMETRO_FK: mayor name igual cadena  */
#line 244 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 1911 "parser.cpp"
    break;

  case 40: /* PARAMETRO_FK: mayor type igual caracter  */
#line 245 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("type", (yyvsp[0].text)); }
#line 1917 "parser.cpp"
    break;

  case 41: /* PARAMETRO_FK: mayor del_ igual full  */
#line 246 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("delete", "full"); }
#line 1923 "parser.cpp"
    break;

  case 42: /* PARAMETRO_FK: mayor add igual entero  */
#line 247 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("add", (yyvsp[0].text)); }
#line 1929 "parser.cpp"
    break;

  case 43: /* SCRIPT: mayor path igual cadena  */
#line 249 "ASintactico.y"
                                {
        (yyval.nodo) = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*path);
    }
#line 1939 "parser.cpp"
    break;

  case 44: /* SCRIPT: mayor path igual ruta  */
#line 254 "ASintactico.y"
                            {
        (yyval.nodo) = new Nodo("EXECUTE", "");
        Nodo *path = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*path);
    }
#line 1949 "parser.cpp"
    break;

  case 45: /* REP: REP PARAMETRO_R  */
#line 260 "ASintactico.y"
                    {
    (yyval.nodo) = (yyvsp[-1].nodo);
    (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1958 "parser.cpp"
    break;

  case 46: /* REP: PARAMETRO_R  */
#line 264 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 1967 "parser.cpp"
    break;

  case 47: /* PARAMETRO_R: mayor path igual cadena  */
#line 269 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1973 "parser.cpp"
    break;

  case 48: /* PARAMETRO_R: mayor path igual ruta  */
#line 270 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 1979 "parser.cpp"
    break;

  case 49: /* PARAMETRO_R: mayor rutaRep igual cadena  */
#line 271 "ASintactico.y"
                                { (yyval.nodo) = new Nodo("ruta", (yyvsp[0].text)); }
#line 1985 "parser.cpp"
    break;

  case 50: /* PARAMETRO_R: mayor rutaRep igual ruta  */
#line 272 "ASintactico.y"
                              { (yyval.nodo) = new Nodo("ruta", (yyvsp[0].text)); }
#line 1991 "parser.cpp"
    break;

  case 51: /* PARAMETRO_R: mayor id igual identificador  */
#line 273 "ASintactico.y"
                                  { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 1997 "parser.cpp"
    break;

  case 52: /* PARAMETRO_R: mayor name igual mbr  */
#line 274 "ASintactico.y"
                          { (yyval.nodo) = new Nodo("name","mbr"); }
#line 2003 "parser.cpp"
    break;

  case 53: /* PARAMETRO_R: mayor name igual disk  */
#line 275 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("name","disk"); }
#line 2009 "parser.cpp"
    break;

  case 54: /* PARAMETRO_R: mayor name igual inode  */
#line 276 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("name", "inode"); }
#line 2015 "parser.cpp"
    break;

  case 55: /* PARAMETRO_R: mayor name igual journaling  */
#line 277 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("name", "journaling"); }
#line 2021 "parser.cpp"
    break;

  case 56: /* PARAMETRO_R: mayor name igual block  */
#line 278 "ASintactico.y"
                            { (yyval.nodo) = new Nodo("name", "block"); }
#line 2027 "parser.cpp"
    break;

  case 57: /* PARAMETRO_R: mayor name igual bm_inode  */
#line 279 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("name", "bm_inode"); }
#line 2033 "parser.cpp"
    break;

  case 58: /* PARAMETRO_R: mayor name igual bm_block  */
#line 280 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("name", "bm_block"); }
#line 2039 "parser.cpp"
    break;

  case 59: /* PARAMETRO_R: mayor name igual tree  */
#line 281 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("name", "tree"); }
#line 2045 "parser.cpp"
    break;

  case 60: /* PARAMETRO_R: mayor name igual sb  */
#line 282 "ASintactico.y"
                         { (yyval.nodo) = new Nodo("name", "sb"); }
#line 2051 "parser.cpp"
    break;

  case 61: /* PARAMETRO_R: mayor name igual fileRep  */
#line 283 "ASintactico.y"
                              { (yyval.nodo) = new Nodo("name", "file"); }
#line 2057 "parser.cpp"
    break;

  case 62: /* PARAMETRO_R: mayor name igual ls  */
#line 284 "ASintactico.y"
                         { (yyval.nodo) = new Nodo("name", "ls"); }
#line 2063 "parser.cpp"
    break;

  case 63: /* RMDISK: rmdisk mayor path igual ruta  */
#line 287 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*ruta);
    }
#line 2073 "parser.cpp"
    break;

  case 64: /* RMDISK: rmdisk mayor path igual cadena  */
#line 293 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMDISK", "");
        Nodo *ruta = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*ruta);
    }
#line 2083 "parser.cpp"
    break;

  case 65: /* MOUNT: MOUNT PARAMETRO_M  */
#line 300 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2092 "parser.cpp"
    break;

  case 66: /* MOUNT: PARAMETRO_M  */
#line 304 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2101 "parser.cpp"
    break;

  case 67: /* PARAMETRO_M: mayor path igual cadena  */
#line 309 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2107 "parser.cpp"
    break;

  case 68: /* PARAMETRO_M: mayor path igual ruta  */
#line 310 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2113 "parser.cpp"
    break;

  case 69: /* PARAMETRO_M: mayor name igual identificador  */
#line 311 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 2119 "parser.cpp"
    break;

  case 70: /* PARAMETRO_M: mayor name igual cadena  */
#line 312 "ASintactico.y"
                             { (yyval.nodo) = new Nodo("name", (yyvsp[0].text)); }
#line 2125 "parser.cpp"
    break;

  case 71: /* UNMOUNT: unmount mayor id igual identificador  */
#line 315 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("UNMOUNT", "");
        Nodo *n = new Nodo("id", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2135 "parser.cpp"
    break;

  case 72: /* MKFS: MKFS PARAM_MKFS  */
#line 321 "ASintactico.y"
                      {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2144 "parser.cpp"
    break;

  case 73: /* MKFS: PARAM_MKFS  */
#line 325 "ASintactico.y"
                 {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2153 "parser.cpp"
    break;

  case 74: /* PARAM_MKFS: mayor id igual identificador  */
#line 330 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 2159 "parser.cpp"
    break;

  case 75: /* PARAM_MKFS: mayor type igual full  */
#line 331 "ASintactico.y"
                           { (yyval.nodo) = new Nodo("type", "full"); }
#line 2165 "parser.cpp"
    break;

  case 76: /* PARAM_MKFS: mayor fs igual fs2  */
#line 332 "ASintactico.y"
                        { (yyval.nodo) = new Nodo("fs", "2fs"); }
#line 2171 "parser.cpp"
    break;

  case 77: /* PARAM_MKFS: mayor fs igual fs3  */
#line 333 "ASintactico.y"
                        { (yyval.nodo) = new Nodo("fs", "3fs"); }
#line 2177 "parser.cpp"
    break;

  case 78: /* LOGIN: LOGIN PARAM_LOGIN  */
#line 336 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2186 "parser.cpp"
    break;

  case 79: /* LOGIN: PARAM_LOGIN  */
#line 341 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2195 "parser.cpp"
    break;

  case 80: /* PARAM_LOGIN: mayor usuario igual identificador  */
#line 346 "ASintactico.y"
                                              { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2201 "parser.cpp"
    break;

  case 81: /* PARAM_LOGIN: mayor usuario igual cadena  */
#line 347 "ASintactico.y"
                                { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2207 "parser.cpp"
    break;

  case 82: /* PARAM_LOGIN: mayor password igual entero  */
#line 348 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2213 "parser.cpp"
    break;

  case 83: /* PARAM_LOGIN: mayor password igual identificador  */
#line 349 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2219 "parser.cpp"
    break;

  case 84: /* PARAM_LOGIN: mayor password igual pwd  */
#line 350 "ASintactico.y"
                               { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2225 "parser.cpp"
    break;

  case 85: /* PARAM_LOGIN: mayor password igual cadena  */
#line 351 "ASintactico.y"
                                  { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2231 "parser.cpp"
    break;

  case 86: /* PARAM_LOGIN: mayor id igual identificador  */
#line 352 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("id", (yyvsp[0].text)); }
#line 2237 "parser.cpp"
    break;

  case 87: /* MKGRP: mkgrp mayor name igual identificador  */
#line 354 "ASintactico.y"
                                            {
                                        (yyval.nodo) = new Nodo("MKGRP","");
                                        Nodo *n = new Nodo("name",(yyvsp[0].text));
                                        (yyval.nodo)->add(*n);
                                      }
#line 2247 "parser.cpp"
    break;

  case 88: /* MKGRP: mkgrp mayor name igual cadena  */
#line 359 "ASintactico.y"
                                       {
                                    (yyval.nodo) = new Nodo("MKGRP","");
                                    Nodo *n = new Nodo("name",(yyvsp[0].text));
                                    (yyval.nodo)->add(*n);
                                 }
#line 2257 "parser.cpp"
    break;

  case 89: /* RMGRP: rmgrp mayor name igual identificador  */
#line 366 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMGRP","");
        Nodo *n = new Nodo("name", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2267 "parser.cpp"
    break;

  case 90: /* RMGRP: rmgrp mayor name igual cadena  */
#line 372 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMGRP", "");
        Nodo *n = new Nodo("name",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2277 "parser.cpp"
    break;

  case 91: /* MKUSR: MKUSR PARAM_MKUSR  */
#line 379 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2286 "parser.cpp"
    break;

  case 92: /* MKUSR: PARAM_MKUSR  */
#line 384 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2295 "parser.cpp"
    break;

  case 93: /* PARAM_MKUSR: mayor usuario igual identificador  */
#line 389 "ASintactico.y"
                                              { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2301 "parser.cpp"
    break;

  case 94: /* PARAM_MKUSR: mayor usuario igual cadena  */
#line 390 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo("usuario", (yyvsp[0].text)); }
#line 2307 "parser.cpp"
    break;

  case 95: /* PARAM_MKUSR: mayor password igual entero  */
#line 391 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2313 "parser.cpp"
    break;

  case 96: /* PARAM_MKUSR: mayor password igual identificador  */
#line 392 "ASintactico.y"
                                                { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2319 "parser.cpp"
    break;

  case 97: /* PARAM_MKUSR: mayor password igual pwd  */
#line 393 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2325 "parser.cpp"
    break;

  case 98: /* PARAM_MKUSR: mayor password igual cadena  */
#line 394 "ASintactico.y"
                                         { (yyval.nodo) = new Nodo("password", (yyvsp[0].text)); }
#line 2331 "parser.cpp"
    break;

  case 99: /* PARAM_MKUSR: mayor grp igual identificador  */
#line 395 "ASintactico.y"
                                           { (yyval.nodo) = new Nodo("group", (yyvsp[0].text)); }
#line 2337 "parser.cpp"
    break;

  case 100: /* PARAM_MKUSR: mayor grp igual cadena  */
#line 396 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("group",(yyvsp[0].text)); }
#line 2343 "parser.cpp"
    break;

  case 101: /* RMUSR: rmusr mayor usuario igual identificador  */
#line 399 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMUSR","");
        Nodo *n = new Nodo("user",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2353 "parser.cpp"
    break;

  case 102: /* RMUSR: rmusr mayor usuario igual cadena  */
#line 405 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("RMUSR", "");
        Nodo *n = new Nodo("user",(yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2363 "parser.cpp"
    break;

  case 103: /* CHMOD: CHMOD PARAM_CHMOD  */
#line 412 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2372 "parser.cpp"
    break;

  case 104: /* CHMOD: PARAM_CHMOD  */
#line 417 "ASintactico.y"
    {
       (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2381 "parser.cpp"
    break;

  case 105: /* PARAM_CHMOD: mayor path igual cadena  */
#line 422 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2387 "parser.cpp"
    break;

  case 106: /* PARAM_CHMOD: mayor path igual directorioA  */
#line 423 "ASintactico.y"
                                          { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2393 "parser.cpp"
    break;

  case 107: /* PARAM_CHMOD: mayor ugo igual entero  */
#line 424 "ASintactico.y"
                                    { (yyval.nodo) = new Nodo("ugo",(yyvsp[0].text)); }
#line 2399 "parser.cpp"
    break;

  case 108: /* PARAM_CHMOD: mayor r  */
#line 425 "ASintactico.y"
                     { (yyval.nodo) = new Nodo("r",""); }
#line 2405 "parser.cpp"
    break;

  case 109: /* MKFILE: MKFILE PARAM_MKFILE  */
#line 428 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2414 "parser.cpp"
    break;

  case 110: /* MKFILE: PARAM_MKFILE  */
#line 432 "ASintactico.y"
                  {
        (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2423 "parser.cpp"
    break;

  case 111: /* PARAM_MKFILE: mayor path igual ruta  */
#line 438 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2429 "parser.cpp"
    break;

  case 112: /* PARAM_MKFILE: mayor path igual cadena  */
#line 439 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2435 "parser.cpp"
    break;

  case 113: /* PARAM_MKFILE: mayor sizeS igual entero  */
#line 440 "ASintactico.y"
                                      { (yyval.nodo) = new Nodo("size",(yyvsp[0].text)); }
#line 2441 "parser.cpp"
    break;

  case 114: /* PARAM_MKFILE: mayor cont igual ruta  */
#line 441 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("cont",(yyvsp[0].text)); }
#line 2447 "parser.cpp"
    break;

  case 115: /* PARAM_MKFILE: mayor cont igual cadena  */
#line 442 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("cont",(yyvsp[0].text)); }
#line 2453 "parser.cpp"
    break;

  case 116: /* PARAM_MKFILE: mayor r  */
#line 443 "ASintactico.y"
                     { (yyval.nodo) = new Nodo("r",""); }
#line 2459 "parser.cpp"
    break;

  case 117: /* CAT: CAT LTS_FILE  */
#line 446 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2468 "parser.cpp"
    break;

  case 118: /* CAT: LTS_FILE  */
#line 451 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO", "");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2477 "parser.cpp"
    break;

  case 119: /* LTS_FILE: mayor identificador igual ruta  */
#line 456 "ASintactico.y"
                                        { (yyval.nodo) = new Nodo((yyvsp[-2].text), (yyvsp[0].text)); }
#line 2483 "parser.cpp"
    break;

  case 120: /* LTS_FILE: mayor identificador igual cadena  */
#line 457 "ASintactico.y"
                                          { (yyval.nodo) = new Nodo((yyvsp[-2].text), (yyvsp[0].text)); }
#line 2489 "parser.cpp"
    break;

  case 121: /* REMOVE: removeR mayor path igual ruta  */
#line 460 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REMOVE", "");
        Nodo *n = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2499 "parser.cpp"
    break;

  case 122: /* REMOVE: removeR mayor path igual cadena  */
#line 466 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REMOVE", "");
        Nodo *n = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2509 "parser.cpp"
    break;

  case 123: /* REMOVE: removeR mayor path igual directorioA  */
#line 472 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("REMOVE", "");
        Nodo *n = new Nodo("path", (yyvsp[0].text));
        (yyval.nodo)->add(*n);
    }
#line 2519 "parser.cpp"
    break;

  case 124: /* EDIT: EDIT PARAM_EDIT  */
#line 479 "ASintactico.y"
        {
            (yyval.nodo) = (yyvsp[-1].nodo);
            (yyval.nodo)->add(*(yyvsp[0].nodo));
        }
#line 2528 "parser.cpp"
    break;

  case 125: /* EDIT: PARAM_EDIT  */
#line 484 "ASintactico.y"
        {
            (yyval.nodo) = new Nodo("PARAMETRO","");
            (yyval.nodo)->add(*(yyvsp[0].nodo));
        }
#line 2537 "parser.cpp"
    break;

  case 126: /* PARAM_EDIT: mayor path igual ruta  */
#line 489 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2543 "parser.cpp"
    break;

  case 127: /* PARAM_EDIT: mayor path igual cadena  */
#line 490 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2549 "parser.cpp"
    break;

  case 128: /* PARAM_EDIT: mayor cont igual cadena  */
#line 491 "ASintactico.y"
                                     { (yyval.nodo) = new Nodo("cont", (yyvsp[0].text)); }
#line 2555 "parser.cpp"
    break;

  case 129: /* RENAME: RENAME PARAM_RENAME  */
#line 494 "ASintactico.y"
    {
        (yyval.nodo) = (yyvsp[-1].nodo);
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2564 "parser.cpp"
    break;

  case 130: /* RENAME: PARAM_RENAME  */
#line 499 "ASintactico.y"
    {
        (yyval.nodo) = new Nodo("PARAMETRO","");
        (yyval.nodo)->add(*(yyvsp[0].nodo));
    }
#line 2573 "parser.cpp"
    break;

  case 131: /* PARAM_RENAME: mayor path igual ruta  */
#line 504 "ASintactico.y"
                                   { (yyval.nodo) = new Nodo("path", (yyvsp[0].text)); }
#line 2579 "parser.cpp"
    break;

  case 132: /* PARAM_RENAME: mayor path igual cadena  */
#line 505 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("path",(yyvsp[0].text)); }
#line 2585 "parser.cpp"
    break;

  case 133: /* PARAM_RENAME: mayor name igual identificador extension  */
#line 507 "ASintactico.y"
        {
            (yyval.nodo) = new Nodo("name","");
            Nodo *n = new Nodo((yyvsp[-1].text),(yyvsp[0].text));
            (yyval.nodo)->add(*n);
        }
#line 2595 "parser.cpp"
    break;

  case 134: /* PARAM_RENAME: mayor name igual cadena  */
#line 512 "ASintactico.y"
                                 { (yyval.nodo) = new Nodo("name",(yyvsp[0].text)); }
#line 2601 "parser.cpp"
    break;


#line 2605 "parser.cpp"

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

