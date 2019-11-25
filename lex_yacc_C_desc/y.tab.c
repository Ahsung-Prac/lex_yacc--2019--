#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "hw3.y"
#include<stdio.h>
int yylex();
int count[3] ={0}; /* 2는 int, 1은 char 0은 나머지 */
int T =0;  /* 변수 선언의 개수 저장 */
int P = 0; /* 포인터 선언  개수 저장 */
int A = 0; /* 배열 선언  개수 저장 */
int checkArr = 0;  /* 배열 선언인지 검사 */
int checkFunct = 0; /*함수 선언인지 검사*/
int funct = 0;  /* 함수 선언,호출 개수 저장 */
int op=0;      /* 연산자 개수 저장 */
int selection =0;
int iteration =0;
int return_ =0;
int type = 0; /*count에 저장할 타입을 결정 */
#line 38 "y.tab.c"
#define INCLUDE 257
#define DEFINE 258
#define NUMBER 259
#define IDENTIFIER 260
#define INT 261
#define VOID 262
#define CHAR 263
#define FLOAT 264
#define PP 265
#define MM 266
#define POINTER 267
#define AND 268
#define OR 269
#define DIFF 270
#define SIZE 271
#define EQUAL 272
#define ADDE 273
#define MULE 274
#define DIVE 275
#define QUEE 276
#define SUBE 277
#define RREL 278
#define LREL 279
#define LSHF 280
#define RSHF 281
#define LEFTE 282
#define RIGHTE 283
#define XORE 284
#define ORE 285
#define ELSE 286
#define ANDE 287
#define LITERAL 288
#define CASE 289
#define DEFAULT 290
#define IF 291
#define SWITCH 292
#define WHILE 293
#define DO 294
#define FOR 295
#define GOTO 296
#define CONTINUE 297
#define BREAK 298
#define RETURN 299
#define TYPEDEF 300
#define EXTERN 301
#define STATIC 302
#define AUTO 303
#define REGISTER 304
#define SHORT 305
#define LONG 306
#define SIGNED 307
#define UNSIGNED 308
#define DOUBLE 309
#define CONST 310
#define VOLATILE 311
#define STRUCT 312
#define UNION 313
#define ENUM 314
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    2,    2,    3,    3,    4,    4,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    5,    5,    8,
    8,    8,    8,    8,    8,   10,   10,   10,   12,   12,
   12,   12,   12,   12,    9,    9,   14,   14,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,   11,
   11,   11,   11,   11,   11,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   19,   19,   19,   20,
   20,   21,   21,   17,   17,   22,   22,   23,   23,   25,
   25,   26,   26,   26,   26,   27,   27,   27,   15,   15,
   15,   15,   29,   29,   29,   29,   29,   29,   29,   31,
   31,   32,   32,   30,   30,   28,   28,   28,   33,   33,
   24,   24,   24,   24,   24,   24,   35,   35,   18,   18,
   18,   36,   36,   37,   37,   13,   13,   13,   13,   34,
   34,   34,   34,   34,   39,   39,   39,   39,   39,   39,
   39,   39,   46,   46,   41,   41,   40,   40,   45,   45,
   45,   45,   45,   44,   44,   44,   42,   42,   42,   43,
   43,   43,   43,   38,   47,   47,   47,   48,   49,   49,
    1,    1,    1,    1,    1,
};
short yylen[] = {                                         2,
    1,    2,    1,    3,    1,    3,    1,    5,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    1,    4,    1,
    2,    2,    2,    4,    2,    1,    3,    3,    1,    3,
    4,    4,    2,    2,    1,    2,    1,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    4,    5,    2,    1,
    3,    1,    3,    1,    1,    1,    2,    1,    2,    1,
    3,    1,    3,    3,    2,    1,    2,    1,    1,    2,
    2,    3,    1,    3,    3,    3,    4,    4,    4,    1,
    3,    2,    1,    1,    3,    1,    3,    4,    1,    3,
    1,    2,    1,    2,    1,    2,    1,    1,    2,    4,
    5,    1,    2,    2,    1,    1,    1,    3,    1,    1,
    1,    1,    1,    1,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    3,    2,    1,    2,    3,    2,
    2,    2,    3,    3,    4,    3,    5,    2,    5,    5,
    7,    6,    7,    3,    5,    3,    5,    3,    4,    4,
    2,    1,    1,    1,    1,
};
short yydefred[] = {                                      0,
   67,   69,   66,   68,  140,  141,  142,  143,  144,   71,
   72,   73,   74,   70,   84,   85,  128,  127,    0,  183,
    0,    0,    1,    0,    0,   75,   76,    0,    0,    0,
    0,  182,  184,  185,    0,    0,    0,    0,    2,  124,
  126,  181,  103,    0,    0,    0,    0,    0,   90,    0,
    0,  122,    0,    0,    0,    0,   80,  176,    0,    0,
  137,  136,    0,    0,    0,  139,   61,   62,   63,   60,
    0,   64,   65,   95,    9,    0,   28,    0,    0,    0,
   39,  101,   86,    0,    0,    0,    0,    0,    0,    0,
  174,    0,    0,    0,    0,    0,    0,   77,    0,    0,
  180,  179,    0,   32,   31,    0,   33,    0,    3,    5,
    0,    0,    0,   47,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   35,   43,   44,    0,
    0,  102,   87,  104,   91,    0,   94,    0,  116,   93,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  156,  157,    0,    0,  147,  153,  146,
  148,  149,  150,  151,  152,    0,  114,  105,    0,    0,
    0,  110,  106,    0,  130,    0,    0,  132,  135,   78,
   83,   81,  177,    0,  175,    0,    0,  138,   50,   51,
   52,   53,   54,   55,   56,   58,   57,   59,   49,    0,
    0,   46,   48,   22,   24,   27,   25,   18,   17,   20,
   19,    0,   10,   11,   12,   13,   14,   15,   16,   21,
   23,   26,    0,    0,   40,    0,    0,  119,    0,    0,
  168,    0,    0,    0,    0,    0,    0,    0,    0,  160,
  161,  162,    0,  158,  145,  155,  154,  112,    0,  108,
    0,  109,  107,  134,  131,  133,  178,   34,    4,    6,
   29,    0,   42,   41,    0,  117,  164,    0,  166,    0,
    0,    0,    0,    0,  159,  163,  115,  111,    8,  118,
  120,  165,    0,    0,    0,    0,    0,  167,  169,  170,
    0,    0,    0,    0,  172,    0,  171,  173,
};
short yydgoto[] = {                                      22,
   23,  166,  109,  110,  111,  210,   76,   77,  112,   78,
   79,   80,   81,  113,   47,   24,   25,   26,   27,   56,
   57,   84,  167,   29,   48,   49,   50,  150,   51,  180,
  181,  182,  239,   30,   31,  187,  188,  168,  169,  170,
  171,  172,  173,  174,  175,  176,   33,  100,   34,
};
short yysindex[] = {                                     94,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -101,    0,
 -187,   94,    0, 1170, 1170,    0,    0,  -48,  -17, 1170,
 -207,    0,    0,    0,  -59, -182,  -52, -157,    0,    0,
    0,    0,    0,  601,  -15,   -9,  -25,  103,    0,   37,
    3,    0,   33, -182,  107,   -5,    0,    0,  -69, -150,
    0,    0,  609,  609,  627,    0,    0,    0,    0,    0,
  166,    0,    0,    0,    0, 1062,    0,  -43,  609,  -24,
    0,    0,    0,  -15,  160,    3,  -17,  601,  481,  -33,
    0,  249,  489,  829,   10,  601, -182,    0,   27,  141,
    0,    0,  601,    0,    0,  166,    0,   35,    0,    0,
  557,  171,  176,    0,  594,  601,  601,  601,  601,  601,
  601,  601,  601,  601,  601,  601,  601,  601,  601,  601,
  601,  601,  601,  601,  150,  150,    0,    0,    0,  497,
  601,    0,    0,    0,    0,  105,    0,  481,    0,    0,
  159,   79,  601,  162,  209,  212,  214,   79,  251,   39,
  234,  241,  531,    0,    0,   72,  242,    0,    0,    0,
    0,    0,    0,    0,    0,   23,    0,    0,   -9,  111,
  133,    0,    0,  211,    0,  243, 1116,    0,    0,    0,
    0,    0,    0,   45,    0,  265,  601,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  601,
  601,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   55,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -24,  -24,    0,  134,    4,    0,   15,   79,
    0,  250,   79,  601,  601,  601,   14,  558,  288,    0,
    0,    0,  110,    0,    0,    0,    0,    0,   50,    0,
 1170,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  601,    0,    0,  463,    0,    0,   79,    0,  140,
  142,  144,  308,  558,    0,    0,    0,    0,    0,    0,
    0,    0,   79,   79,   79,  601,  588,    0,    0,    0,
  151,   79,  169,  290,    0,   79,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   43,   86,    0,    0,    0,  292,   92,
    0,    0,    0,    0,  156,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -23,    0,   16,  294,    0,  117,
   47,    0,  181,    0,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -7,    0,  995,    0,  649,
    0,    0,    0,  -12,    0,  121,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1023,    0,  313,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  117,    0,    0,    0,    0,
  900,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  175,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  927,  955,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  337,    1,  427,  -38, 1240,    0,    0,  108,  254,    0,
    0,   58,    0,  246,  -44,   52,  462,    0,    0,  309,
  267,    0,    2,  -11,    0,  275,  -42, -118,  319,    0,
    0,  152,    0,    0,    0,    0,  224,   20, 1159, -204,
  362,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1512
short yytable[] = {                                      73,
   82,   28,  136,   85,   70,   74,   71,   59,   67,   68,
   42,   69,   40,   41,   46,  140,   99,   99,   52,   32,
   99,   36,   46,   28,   45,  165,   45,  100,  100,  238,
   46,  100,   45,    7,   99,   99,    7,   99,   97,  142,
   44,   32,   92,  284,  146,  100,  100,  197,  100,  147,
    7,    7,   53,   97,  184,   73,   98,  191,  275,   98,
   70,   82,   71,   54,   67,   68,  141,   69,  212,   37,
   38,  108,  194,   98,   98,  198,   98,   55,  197,  297,
  179,  165,  123,  123,  123,    7,  123,   96,  193,   90,
   96,  164,   72,   93,   88,  186,  274,   89,  197,   99,
  123,  123,   60,  108,   96,   96,  108,   96,  101,  102,
  100,   73,  272,  189,  242,  197,   70,    7,   71,   98,
   67,   68,  114,   69,  222,  125,  125,  125,   21,  125,
  254,  121,  121,  121,  190,  121,  258,  165,   98,  276,
  236,  237,   82,  125,  125,   90,   87,  256,   72,  121,
  121,  260,   20,  197,  259,   94,  291,  114,   35,   90,
   92,   97,   88,  253,   97,   89,  114,   96,  286,   96,
  104,  105,  107,  262,  273,   92,  261,  197,   97,   97,
  293,   97,  294,  197,  295,  197,  137,  197,  186,  103,
   99,  304,  233,  234,  197,   79,   79,   79,   73,   79,
  144,   90,  195,   70,   72,   71,  189,   67,   68,  306,
   69,  211,  197,   79,   79,  113,  240,   45,  113,  243,
  129,  129,  129,  135,  129,   61,  151,    1,    2,    3,
    4,   63,   64,  289,   43,   58,   99,   65,  129,  129,
  138,  139,   43,   97,  280,  281,  282,  100,  244,  179,
   43,  245,  152,  246,   66,  153,  154,  155,  156,  157,
  158,  159,  160,  161,  162,  163,    5,    6,    7,    8,
    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
   19,   61,  151,    1,    2,    3,    4,   63,   64,  178,
  248,   72,  250,   65,   15,   16,  301,  303,  249,  251,
  255,  264,  123,  263,  267,  268,  283,  278,  152,  287,
   66,  153,  154,  155,  156,  157,  158,  159,  160,  161,
  162,  163,    5,    6,    7,    8,    9,   10,   11,   12,
   13,   14,   15,   16,   17,   18,   19,   61,  151,    1,
    2,    3,    4,   63,   64,  125,  285,  296,  307,   65,
   88,  121,   89,   45,    1,    2,    3,    4,   39,  196,
  213,  145,   95,  192,  152,   86,   66,  153,  154,  155,
  156,  157,  158,  159,  160,  161,  162,  163,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,   19,    5,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   17,   18,   19,   61,   62,
  266,   91,  288,    0,    0,   79,   79,   79,   79,   79,
    0,    0,    0,    0,   61,   62,    1,    2,    3,    4,
   63,   64,    0,    0,    0,    0,   65,   66,    0,    0,
  129,  129,  129,  129,  129,    0,    0,    0,    0,    0,
    0,    0,    0,   66,    0,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,   79,
   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
  129,  129,  129,  129,  129,  129,  129,  129,  129,  129,
  129,  129,  129,  129,  129,   73,    0,    0,    0,    0,
   70,    0,   71,    0,   67,   68,   83,   69,  177,    1,
    2,    3,    4,   73,    0,  149,    0,    0,   70,    0,
   71,   73,   67,   68,    0,   69,   70,    0,   71,   73,
   67,   68,  115,   69,   70,    0,   71,  235,   67,   68,
    0,   69,    0,    0,    0,  143,    0,    0,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,   19,   73,    0,    0,    0,  115,   70,    0,
   71,    0,   67,   68,  149,   69,  115,    0,    0,    0,
    0,  183,    0,    0,    0,  148,    0,  290,   72,  252,
   73,    0,    0,    0,    0,   70,    0,   71,    0,   67,
   68,    0,   69,  148,    0,    0,   72,    0,    0,    0,
    0,    0,    0,    0,   72,    0,  165,  209,    0,    0,
   73,    0,   72,  269,    0,   70,    0,   71,  302,   67,
   68,    0,   69,   73,    0,    0,  270,    0,   70,    0,
   71,   73,   67,   68,    0,   69,   70,    0,  103,    0,
   67,   68,    0,   69,    0,    0,   72,    0,    0,   73,
    0,    0,    0,    0,   70,    0,  106,    0,   67,   68,
    0,   69,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   72,    0,   36,   36,    0,    0,   36,
   36,   36,   36,   36,   36,   36,    0,    0,    0,    0,
    0,  149,    0,    0,    0,    0,   36,   36,   36,   36,
   36,   36,    0,   72,    0,    0,    0,    0,    0,    0,
    0,   61,   62,    0,    0,    0,   72,   63,   64,    0,
    0,    0,    0,   65,   72,    0,    0,    0,    0,   61,
   62,   36,   36,    0,    0,   63,   64,   61,   62,    0,
   66,   65,   72,   63,   64,   61,   62,    0,    0,   65,
    0,   63,   64,    0,    0,    0,    0,   65,   66,    0,
    0,    0,   36,   36,    0,    0,   66,    0,    0,    0,
    0,    0,    0,    0,   66,    0,    0,    0,    0,   61,
   62,    0,    0,    0,    0,   63,   64,    0,    0,    0,
    0,   65,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   61,   62,   66,    0,
    0,    0,   63,   64,    0,    0,    0,    0,   65,  199,
  200,  201,  202,  203,    0,    0,    0,    0,  204,  205,
  206,  207,    0,  208,    0,   66,   61,   62,    0,    0,
    0,    0,   63,   64,    1,    2,    3,    4,   65,   61,
   62,    0,    0,    0,    0,   63,   64,   61,   62,    0,
    0,   65,    0,   63,   64,   66,    0,    0,    0,   65,
    0,    0,    0,    0,    0,   61,   62,    0,   66,    0,
    0,   63,   64,    0,    0,    0,   66,   65,   10,   11,
   12,   13,   14,   15,   16,   17,   18,   19,    0,    0,
    0,    0,    0,    0,   66,   36,   36,   36,   36,    0,
   36,   36,   36,   36,   36,   36,   36,   36,   36,   36,
   36,   36,   36,   36,    0,   36,  136,  136,    0,  136,
    0,  136,  136,  136,  136,  136,  136,    0,    0,    0,
    0,    0,    0,  185,    0,    0,    0,    0,  136,  136,
  136,  136,  136,   38,   38,    0,    0,   38,   38,   38,
   38,   38,   38,   38,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   38,   38,   38,   38,   38,   38,
  136,   37,   37,  136,    0,   37,   37,   37,   37,   37,
   37,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   37,   37,   37,   37,   37,   37,    0,   38,
   38,    0,    0,  136,    0,    0,    0,    0,    0,    0,
    0,   30,   30,    0,    0,   30,   30,   30,   30,   30,
    0,   30,    0,    0,    0,    0,    0,   37,   37,    0,
   38,   38,   30,   30,   30,   30,   30,   30,    0,    9,
    9,    0,    0,    9,    9,    9,    9,    9,    0,    9,
    0,    0,    0,    0,    0,    0,    0,    0,   37,   37,
    9,    9,    9,    0,    9,    9,    0,   30,   30,    1,
    2,    3,    4,    0,    0,    0,    0,    0,  127,  132,
    0,    0,    0,  125,  128,    0,  129,    0,  126,    0,
    0,    0,    0,    0,    0,    9,    9,    0,   30,   30,
    0,  131,    0,  130,  124,    0,    0,    0,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,   19,    0,    0,    0,    9,    9,    0,    0,
    0,    0,    0,    0,    0,  134,    0,    0,    0,    0,
    0,    0,    0,    0,  136,  136,  136,  136,  136,  136,
    0,  136,  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  133,  136,    0,    0,    0,
    0,    0,    0,   38,   38,   38,   38,    0,   38,   38,
   38,   38,   38,   38,   38,   38,   38,   38,   38,   38,
   38,   38,    0,   38,    0,    0,    0,    0,    0,    0,
    0,   37,   37,   37,   37,    0,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
  265,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   30,   30,   30,    0,   30,   30,   30,   30,
   30,   30,   30,   30,   30,   30,   30,   30,   30,   30,
    0,   30,    0,   75,    0,    0,    0,    0,    0,    0,
    9,    9,    9,    0,    9,    0,    0,    0,    0,    0,
    9,    9,    9,    9,    0,    0,    0,    0,    0,    0,
  241,    0,    0,    0,    0,    0,  247,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   75,    0,  116,
  117,  118,   75,  119,  257,   75,    0,    0,    0,  120,
  121,  122,  123,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  214,  215,  216,  217,  218,
  219,  220,  221,    0,  223,  224,  225,  226,  227,  228,
  229,  230,  231,  232,    0,    0,    1,    2,    3,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   75,    0,    0,    0,    0,    0,  277,    0,
    0,  279,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    5,    6,    7,    8,    9,
   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
    1,    2,    3,    4,    0,    0,  292,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  271,  298,  299,  300,    0,    0,    0,    0,    0,    0,
  305,    0,    0,    0,  308,    0,    0,    0,    0,    5,
    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   75,
};
short yycheck[] = {                                      33,
   45,    0,   46,   46,   38,   44,   40,   60,   42,   43,
   59,   45,   24,   25,   40,   40,   40,   41,   30,    0,
   44,  123,   40,   22,   42,   59,   42,   40,   41,  148,
   40,   44,   42,   41,   58,   59,   44,   61,   44,   84,
   58,   22,   40,  248,   87,   58,   59,   44,   61,   88,
   58,   59,  260,   44,   93,   33,   41,   96,   44,   44,
   38,   44,   40,  123,   42,   43,   91,   45,  113,  257,
  258,   71,   46,   58,   59,   41,   61,  260,   44,  284,
   92,   59,   40,   41,   42,   93,   44,   41,   62,  123,
   44,  125,  126,   91,   58,   94,   93,   61,   44,  123,
   58,   59,  260,  103,   58,   59,  106,   61,  259,  260,
  123,   33,   58,   94,  153,   44,   38,  125,   40,  125,
   42,   43,   71,   45,  124,   40,   41,   42,   35,   44,
   59,   40,   41,   42,  125,   44,  179,   59,  123,  125,
  140,  141,  125,   58,   59,  123,   44,  125,  126,   58,
   59,   41,   59,   44,   44,  123,  275,  106,  260,  123,
   44,   41,   58,  163,   44,   61,  115,   61,   59,  123,
   63,   64,   65,   41,   41,   59,   44,   44,   58,   59,
   41,   61,   41,   44,   41,   44,   79,   44,  187,   40,
  260,   41,  135,  136,   44,   40,   41,   42,   33,   44,
   41,  123,   62,   38,  126,   40,  187,   42,   43,   41,
   45,   41,   44,   58,   59,   41,   58,   42,   44,   58,
   40,   41,   42,  267,   44,  259,  260,  261,  262,  263,
  264,  265,  266,  272,  260,  288,  260,  271,   58,   59,
  265,  266,  260,  123,  244,  245,  246,  260,   40,  261,
  260,   40,  286,   40,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  302,  303,
  304,  305,  306,  307,  308,  309,  310,  311,  312,  313,
  314,  259,  260,  261,  262,  263,  264,  265,  266,   41,
   40,  126,   59,  271,  310,  311,  296,  297,  260,   59,
   59,   59,  260,   93,  260,   41,  293,   58,  286,  260,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,  302,  303,  304,  305,  306,  307,
  308,  309,  310,  311,  312,  313,  314,  259,  260,  261,
  262,  263,  264,  265,  266,  260,   59,   40,   59,  271,
   59,  260,   59,   41,  261,  262,  263,  264,   22,  106,
  115,   87,   54,   97,  286,   47,  288,  289,  290,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  301,
  302,  303,  304,  305,  306,  307,  308,  309,  310,  311,
  312,  313,  314,  300,  301,  302,  303,  304,  305,  306,
  307,  308,  309,  310,  311,  312,  313,  314,  259,  260,
  187,   50,  261,   -1,   -1,  260,  261,  262,  263,  264,
   -1,   -1,   -1,   -1,  259,  260,  261,  262,  263,  264,
  265,  266,   -1,   -1,   -1,   -1,  271,  288,   -1,   -1,
  260,  261,  262,  263,  264,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  288,   -1,  300,  301,  302,  303,  304,
  305,  306,  307,  308,  309,  310,  311,  312,  313,  314,
  305,  306,  307,  308,  309,  310,  311,  312,  313,  314,
  300,  301,  302,  303,  304,  305,  306,  307,  308,  309,
  310,  311,  312,  313,  314,   33,   -1,   -1,   -1,   -1,
   38,   -1,   40,   -1,   42,   43,   45,   45,  260,  261,
  262,  263,  264,   33,   -1,   89,   -1,   -1,   38,   -1,
   40,   33,   42,   43,   -1,   45,   38,   -1,   40,   33,
   42,   43,   71,   45,   38,   -1,   40,   41,   42,   43,
   -1,   45,   -1,   -1,   -1,   84,   -1,   -1,  300,  301,
  302,  303,  304,  305,  306,  307,  308,  309,  310,  311,
  312,  313,  314,   33,   -1,   -1,   -1,  106,   38,   -1,
   40,   -1,   42,   43,  148,   45,  115,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,  123,   -1,  125,  126,   59,
   33,   -1,   -1,   -1,   -1,   38,   -1,   40,   -1,   42,
   43,   -1,   45,  123,   -1,   -1,  126,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  126,   -1,   59,   61,   -1,   -1,
   33,   -1,  126,  197,   -1,   38,   -1,   40,   41,   42,
   43,   -1,   45,   33,   -1,   -1,  210,   -1,   38,   -1,
   40,   33,   42,   43,   -1,   45,   38,   -1,   40,   -1,
   42,   43,   -1,   45,   -1,   -1,  126,   -1,   -1,   33,
   -1,   -1,   -1,   -1,   38,   -1,   40,   -1,   42,   43,
   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  126,   -1,   37,   38,   -1,   -1,   41,
   42,   43,   44,   45,   46,   47,   -1,   -1,   -1,   -1,
   -1,  275,   -1,   -1,   -1,   -1,   58,   59,   60,   61,
   62,   63,   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  259,  260,   -1,   -1,   -1,  126,  265,  266,   -1,
   -1,   -1,   -1,  271,  126,   -1,   -1,   -1,   -1,  259,
  260,   93,   94,   -1,   -1,  265,  266,  259,  260,   -1,
  288,  271,  126,  265,  266,  259,  260,   -1,   -1,  271,
   -1,  265,  266,   -1,   -1,   -1,   -1,  271,  288,   -1,
   -1,   -1,  124,  125,   -1,   -1,  288,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  288,   -1,   -1,   -1,   -1,  259,
  260,   -1,   -1,   -1,   -1,  265,  266,   -1,   -1,   -1,
   -1,  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  259,  260,  288,   -1,
   -1,   -1,  265,  266,   -1,   -1,   -1,   -1,  271,  273,
  274,  275,  276,  277,   -1,   -1,   -1,   -1,  282,  283,
  284,  285,   -1,  287,   -1,  288,  259,  260,   -1,   -1,
   -1,   -1,  265,  266,  261,  262,  263,  264,  271,  259,
  260,   -1,   -1,   -1,   -1,  265,  266,  259,  260,   -1,
   -1,  271,   -1,  265,  266,  288,   -1,   -1,   -1,  271,
   -1,   -1,   -1,   -1,   -1,  259,  260,   -1,  288,   -1,
   -1,  265,  266,   -1,   -1,   -1,  288,  271,  305,  306,
  307,  308,  309,  310,  311,  312,  313,  314,   -1,   -1,
   -1,   -1,   -1,   -1,  288,  267,  268,  269,  270,   -1,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,   -1,  287,   37,   38,   -1,   40,
   -1,   42,   43,   44,   45,   46,   47,   -1,   -1,   -1,
   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   59,   60,
   61,   62,   63,   37,   38,   -1,   -1,   41,   42,   43,
   44,   45,   46,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   58,   59,   60,   61,   62,   63,
   91,   37,   38,   94,   -1,   41,   42,   43,   44,   45,
   46,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   58,   59,   60,   61,   62,   63,   -1,   93,
   94,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   93,   94,   -1,
  124,  125,   58,   59,   60,   61,   62,   63,   -1,   37,
   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,  125,
   58,   59,   60,   -1,   62,   63,   -1,   93,   94,  261,
  262,  263,  264,   -1,   -1,   -1,   -1,   -1,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   94,   -1,  124,  125,
   -1,   60,   -1,   62,   63,   -1,   -1,   -1,  300,  301,
  302,  303,  304,  305,  306,  307,  308,  309,  310,  311,
  312,  313,  314,   -1,   -1,   -1,  124,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  265,  266,  267,  268,  269,  270,
   -1,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  285,  124,  287,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  285,   -1,  287,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  267,  268,  269,  270,   -1,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  281,  282,  283,  284,  285,
  125,  287,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  268,  269,  270,   -1,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  281,  282,  283,  284,  285,
   -1,  287,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,
  268,  269,  270,   -1,  272,   -1,   -1,   -1,   -1,   -1,
  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,
  152,   -1,   -1,   -1,   -1,   -1,  158,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   88,   -1,  268,
  269,  270,   93,  272,  176,   96,   -1,   -1,   -1,  278,
  279,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  116,  117,  118,  119,  120,
  121,  122,  123,   -1,  125,  126,  127,  128,  129,  130,
  131,  132,  133,  134,   -1,   -1,  261,  262,  263,  264,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  153,   -1,   -1,   -1,   -1,   -1,  240,   -1,
   -1,  243,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  300,  301,  302,  303,  304,
  305,  306,  307,  308,  309,  310,  311,  312,  313,  314,
  261,  262,  263,  264,   -1,   -1,  278,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  211,  293,  294,  295,   -1,   -1,   -1,   -1,   -1,   -1,
  302,   -1,   -1,   -1,  306,   -1,   -1,   -1,   -1,  300,
  301,  302,  303,  304,  305,  306,  307,  308,  309,  310,
  311,  312,  313,  314,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,
};
#define YYFINAL 22
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 314
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,
0,0,0,0,0,0,0,0,0,"':'","';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INCLUDE",
"DEFINE","NUMBER","IDENTIFIER","INT","VOID","CHAR","FLOAT","PP","MM","POINTER",
"AND","OR","DIFF","SIZE","EQUAL","ADDE","MULE","DIVE","QUEE","SUBE","RREL",
"LREL","LSHF","RSHF","LEFTE","RIGHTE","XORE","ORE","ELSE","ANDE","LITERAL",
"CASE","DEFAULT","IF","SWITCH","WHILE","DO","FOR","GOTO","CONTINUE","BREAK",
"RETURN","TYPEDEF","EXTERN","STATIC","AUTO","REGISTER","SHORT","LONG","SIGNED",
"UNSIGNED","DOUBLE","CONST","VOLATILE","STRUCT","UNION","ENUM",
};
char *yyrule[] = {
"$accept : start_state",
"start_state : sub_start",
"start_state : start_state sub_start",
"expression : Value",
"expression : expression ',' Value",
"Value : cValue",
"Value : oValue assign_oper Value",
"cValue : mValue",
"cValue : mValue '?' expression ':' cValue",
"mValue : oValue",
"mValue : mValue '*' oValue",
"mValue : mValue '/' oValue",
"mValue : mValue '%' oValue",
"mValue : mValue '+' oValue",
"mValue : mValue '-' oValue",
"mValue : mValue '>' oValue",
"mValue : mValue '<' oValue",
"mValue : mValue LREL oValue",
"mValue : mValue RREL oValue",
"mValue : mValue RSHF oValue",
"mValue : mValue LSHF oValue",
"mValue : mValue '&' oValue",
"mValue : mValue AND oValue",
"mValue : mValue '|' oValue",
"mValue : mValue OR oValue",
"mValue : mValue EQUAL oValue",
"mValue : mValue '^' oValue",
"mValue : mValue DIFF oValue",
"oValue : uValue",
"oValue : '(' type_name ')' oValue",
"uValue : sValue",
"uValue : MM uValue",
"uValue : PP uValue",
"uValue : SIZE uValue",
"uValue : SIZE '(' type_name ')'",
"uValue : unray_oper uValue",
"sValue : tValue",
"sValue : sValue '.' tValue",
"sValue : sValue POINTER tValue",
"tValue : id",
"tValue : tValue '(' ')'",
"tValue : tValue '[' expression ']'",
"tValue : tValue '(' expression ')'",
"tValue : tValue PP",
"tValue : tValue MM",
"type_name : typeMix",
"type_name : typeMix pointer",
"typeMix : type_specifier",
"typeMix : type_qualifier typeMix",
"assign_oper : '='",
"assign_oper : ADDE",
"assign_oper : MULE",
"assign_oper : DIVE",
"assign_oper : QUEE",
"assign_oper : SUBE",
"assign_oper : LEFTE",
"assign_oper : RIGHTE",
"assign_oper : ORE",
"assign_oper : XORE",
"assign_oper : ANDE",
"unray_oper : '&'",
"unray_oper : '*'",
"unray_oper : '+'",
"unray_oper : '-'",
"unray_oper : '~'",
"unray_oper : '!'",
"type_specifier : CHAR",
"type_specifier : INT",
"type_specifier : FLOAT",
"type_specifier : VOID",
"type_specifier : DOUBLE",
"type_specifier : SHORT",
"type_specifier : LONG",
"type_specifier : SIGNED",
"type_specifier : UNSIGNED",
"type_specifier : struct_or_union_specifier",
"type_specifier : enum_specifier",
"enum_specifier : ENUM '{' enumerator_list '}'",
"enum_specifier : ENUM IDENTIFIER '{' enumerator_list '}'",
"enum_specifier : ENUM IDENTIFIER",
"enumerator_list : enumerator",
"enumerator_list : enumerator_list ',' enumerator",
"enumerator : IDENTIFIER",
"enumerator : IDENTIFIER '=' cValue",
"type_qualifier : CONST",
"type_qualifier : VOLATILE",
"type_qualifier_list : type_qualifier",
"type_qualifier_list : type_qualifier_list type_qualifier",
"declaration : declaration_specifiers",
"declaration : declaration_specifiers init_declarator_list",
"init_declarator_list : init_declarator",
"init_declarator_list : init_declarator_list ',' init_declarator",
"init_declarator : declarator",
"init_declarator : declarator '=' initializer",
"init_declarator : declarator ':' cValue",
"init_declarator : ':' cValue",
"declarator : direct_declarator",
"declarator : pointer direct_declarator",
"declarator : pointer",
"pointer : '*'",
"pointer : '*' type_qualifier_list",
"pointer : '*' pointer",
"pointer : '*' type_qualifier_list pointer",
"direct_declarator : IDENTIFIER",
"direct_declarator : '(' declarator ')'",
"direct_declarator : direct_declarator '(' ')'",
"direct_declarator : direct_declarator '[' ']'",
"direct_declarator : direct_declarator '[' cValue ']'",
"direct_declarator : direct_declarator '(' identifier_list ')'",
"direct_declarator : direct_declarator '(' parameter_list ')'",
"parameter_list : parameter_declaration",
"parameter_list : parameter_list ',' parameter_declaration",
"parameter_declaration : declaration_specifiers declarator",
"parameter_declaration : declaration_specifiers",
"identifier_list : IDENTIFIER",
"identifier_list : identifier_list ',' IDENTIFIER",
"initializer : Value",
"initializer : '{' initializer_list '}'",
"initializer : '{' initializer_list ',' '}'",
"initializer_list : initializer",
"initializer_list : initializer_list ',' initializer",
"declaration_specifiers : storage_class_specifier",
"declaration_specifiers : storage_class_specifier declaration_specifiers",
"declaration_specifiers : type_specifier",
"declaration_specifiers : type_specifier declaration_specifiers",
"declaration_specifiers : type_qualifier",
"declaration_specifiers : type_qualifier declaration_specifiers",
"struct_or_union : UNION",
"struct_or_union : STRUCT",
"struct_or_union_specifier : struct_or_union IDENTIFIER",
"struct_or_union_specifier : struct_or_union IDENTIFIER '{' '}'",
"struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_union_parameter_list '}'",
"struct_union_parameter_list : struct_union_parameter",
"struct_union_parameter_list : struct_union_parameter_list struct_union_parameter",
"struct_union_parameter : declaration ';'",
"struct_union_parameter : function",
"id : IDENTIFIER",
"id : NUMBER",
"id : '(' expression ')'",
"id : LITERAL",
"storage_class_specifier : TYPEDEF",
"storage_class_specifier : EXTERN",
"storage_class_specifier : STATIC",
"storage_class_specifier : AUTO",
"storage_class_specifier : REGISTER",
"statement : declaration ';'",
"statement : expression_statement",
"statement : function",
"statement : compound_statement",
"statement : selection_statement",
"statement : iteration_statement",
"statement : labeled_statement",
"statement : jump_statement",
"statement_list : statement",
"statement_list : statement_list statement",
"compound_statement : '{' statement_list '}'",
"compound_statement : '{' '}'",
"expression_statement : ';'",
"expression_statement : expression ';'",
"jump_statement : GOTO IDENTIFIER ';'",
"jump_statement : CONTINUE ';'",
"jump_statement : BREAK ';'",
"jump_statement : RETURN ';'",
"jump_statement : RETURN expression ';'",
"labeled_statement : IDENTIFIER ':' statement",
"labeled_statement : CASE cValue ':' statement",
"labeled_statement : DEFAULT ':' statement",
"selection_statement : IF '(' expression ')' statement",
"selection_statement : ELSE statement",
"selection_statement : SWITCH '(' expression ')' statement",
"iteration_statement : WHILE '(' expression ')' statement",
"iteration_statement : DO statement WHILE '(' expression ')' ';'",
"iteration_statement : FOR '(' expression_statement expression_statement ')' statement",
"iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement",
"function : declaration_specifiers declarator compound_statement",
"include : '#' INCLUDE '<' header '>'",
"include : '#' INCLUDE LITERAL",
"include : '#' INCLUDE '<' IDENTIFIER '>'",
"header : IDENTIFIER '.' IDENTIFIER",
"def : '#' DEFINE IDENTIFIER IDENTIFIER",
"def : '#' DEFINE IDENTIFIER NUMBER",
"sub_start : declaration ';'",
"sub_start : function",
"sub_start : ';'",
"sub_start : include",
"sub_start : def",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 378 "hw3.y"

void yyerror(const char *str)
{
	fprintf(stderr,"error : %s\n",str);
}
int main(void){
	
	printf("\n변수 선언은 함수의 선언부분의 매개변수도 포함합니다.\n\n");
	yyparse();
	printf("int 변수 선언 = %d\n",count[2]);
	printf("char 변수 선언 = %d\n",count[1]);
	printf("포인터 변수 선언 = %d\n",P);
	printf("배열 변수 선언 = %d\n",A);
	printf("함수 (호출,선언,정의) =  %d\n",funct);
	printf("수식 =  %d\n",op);
	printf("반복문 = %d\n",iteration);
	printf("선택문 = %d\n",selection);
	printf("return문 = %d\n",return_);

	return 0;
}
#line 831 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 6:
#line 63 "hw3.y"
{op++;}
break;
case 8:
#line 67 "hw3.y"
{/*op++;*/}
break;
case 10:
#line 71 "hw3.y"
{op++;}
break;
case 11:
#line 72 "hw3.y"
{op++;}
break;
case 12:
#line 73 "hw3.y"
{op++;}
break;
case 13:
#line 74 "hw3.y"
{op++;}
break;
case 14:
#line 75 "hw3.y"
{op++;}
break;
case 15:
#line 76 "hw3.y"
{op++;}
break;
case 16:
#line 77 "hw3.y"
{op++;}
break;
case 17:
#line 78 "hw3.y"
{op++;}
break;
case 18:
#line 79 "hw3.y"
{op++;}
break;
case 19:
#line 80 "hw3.y"
{op++;}
break;
case 20:
#line 81 "hw3.y"
{op++;}
break;
case 21:
#line 82 "hw3.y"
{op++;}
break;
case 22:
#line 83 "hw3.y"
{op++;}
break;
case 23:
#line 84 "hw3.y"
{op++;}
break;
case 24:
#line 85 "hw3.y"
{op++;}
break;
case 25:
#line 86 "hw3.y"
{op++;}
break;
case 26:
#line 87 "hw3.y"
{op++;}
break;
case 27:
#line 88 "hw3.y"
{op++;}
break;
case 31:
#line 96 "hw3.y"
{op++;}
break;
case 32:
#line 97 "hw3.y"
{op++;}
break;
case 38:
#line 105 "hw3.y"
{op++;}
break;
case 40:
#line 110 "hw3.y"
{funct++;}
break;
case 42:
#line 112 "hw3.y"
{ funct++;}
break;
case 43:
#line 113 "hw3.y"
{op++;}
break;
case 44:
#line 114 "hw3.y"
{op++;}
break;
case 66:
#line 145 "hw3.y"
{type = 1;}
break;
case 67:
#line 146 "hw3.y"
{type = 2;}
break;
case 89:
#line 187 "hw3.y"
{count[type] +=T; type = 0; T = 0;}
break;
case 93:
#line 197 "hw3.y"
{op++;}
break;
case 94:
#line 198 "hw3.y"
{op++;}
break;
case 95:
#line 199 "hw3.y"
{op++;}
break;
case 96:
#line 201 "hw3.y"
{if(!checkFunct){T++;} if(checkArr){A++; checkArr = 0;} checkFunct = 0; }
break;
case 97:
#line 202 "hw3.y"
{if(checkArr){A++; checkArr = 0;} if(!checkFunct) {P++;T++;} checkFunct = 0;}
break;
case 105:
#line 215 "hw3.y"
{funct++; checkFunct = 1;}
break;
case 106:
#line 216 "hw3.y"
{checkArr = 1;}
break;
case 107:
#line 217 "hw3.y"
{checkArr = 1;}
break;
case 108:
#line 218 "hw3.y"
{funct++; checkFunct = 1;}
break;
case 109:
#line 219 "hw3.y"
{funct++; checkFunct = 1;}
break;
case 112:
#line 228 "hw3.y"
{count[type] +=T; type = 0; T = 0;}
break;
case 149:
#line 299 "hw3.y"
{selection++;}
break;
case 150:
#line 300 "hw3.y"
{iteration++;}
break;
case 162:
#line 325 "hw3.y"
{return_++; }
break;
case 163:
#line 326 "hw3.y"
{return_++; }
break;
case 174:
#line 352 "hw3.y"
{type=0;T=0;checkFunct = 0;}
break;
#line 1196 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
