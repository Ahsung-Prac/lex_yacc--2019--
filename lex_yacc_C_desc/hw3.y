%{
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
%}

%token INCLUDE
%token DEFINE
%token NUMBER IDENTIFIER
%token INT VOID
%token CHAR
%token FLOAT
%token PP  /* "++" */
%token MM  /* "--" */
%token POINTER /* "->" */
%token AND
%token OR
%token DIFF    /* "!=" */
%token SIZE    /* "sizeof" */
%token EQUAL   /* "==" */	
%token ADDE 	/* 연산 배정문 ex "+=" */
%token MULE
%token DIVE
%token QUEE     /* "%=" */
%token SUBE
%token RREL
%token LREL
%token LSHF
%token RSHF
%token LEFTE
%token RIGHTE
%token XORE      /* "^=" */
%token ORE
%token ELSE
%token ANDE
%token LITERAL   /* 문자열 상수  */
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token SHORT LONG SIGNED UNSIGNED DOUBLE CONST VOLATILE
%token STRUCT UNION ENUM
%start start_state
%%

start_state :sub_start  /*실제 시작은 sub_start를 좌결합으로 반복*/
 	| start_state sub_start  ; 

expression : Value 	/* 변수나, 숫자, 함수등을  호출, 사용 하는 모든 수식 표현들 */
	| expression ',' Value 
	;

Value : cValue /* 배정문 표현  */
	| oValue assign_oper Value {op++;} 
	;

cValue : mValue /*? : 논리비교 연산자 */
	| mValue '?' expression ':' cValue {/*op++;*/}
	;

mValue : oValue /* 피연산자 2개 연산 표현 */
	| mValue '*' oValue    {op++;}
	| mValue '/' oValue    {op++;}
	| mValue '%' oValue    {op++;}
	| mValue '+' oValue    {op++;}
	| mValue '-' oValue    {op++;}
	| mValue '>' oValue    {op++;}
	| mValue '<' oValue    {op++;}
	| mValue  LREL  oValue {op++;}
	| mValue  RREL  oValue {op++;}
	| mValue RSHF oValue {op++;}
	| mValue LSHF oValue {op++;}
	| mValue '&' oValue    {op++;}
	| mValue  AND oValue   {op++;}
	| mValue '|' oValue    {op++;}
	| mValue OR oValue     {op++;}
	| mValue EQUAL oValue  {op++;}
	| mValue '^' oValue    {op++;}
	| mValue  DIFF  oValue {op++;}


oValue : uValue  /*type 캐스팅!*/
	| '(' type_name ')' oValue
	;
		
uValue : sValue /*전위 연산자 우결합*/
	| MM uValue {op++;} 
	| PP uValue {op++;}
	| SIZE uValue
	| SIZE '(' type_name ')' 
	| unray_oper uValue
	; 

sValue : tValue
	| sValue '.' tValue  /*멤버접근자로 함수나 배열의 인자도 부를 수 있다.*/
	| sValue POINTER tValue  {op++;}
	;


tValue : id   /*후위 연산자 좌결합*/
	| tValue '('')' {funct++;}  
	| tValue '['expression']'
	| tValue '(' expression ')'{ funct++;}
	| tValue PP  {op++;}
	| tValue MM {op++;}  
	;

type_name: typeMix   /* c언어에서 tpye의 종류  */
	|  typeMix pointer
	;
typeMix: type_specifier
	| type_qualifier typeMix
	;

assign_oper: '='/*모든 배정문*/
	| ADDE
	| MULE
	| DIVE
	| QUEE
	| SUBE
	| LEFTE
	| RIGHTE
	| ORE
	| XORE
	| ANDE
	;

unray_oper: '&' /*단일 피연산자 연산자 */
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

type_specifier: CHAR 	{type = 1;} /*char형은 인덱스 '1' */
	| INT		{type = 2;} /*int형은 인덱스 '2'*/	
	| FLOAT
	| VOID		/*기본 타입들*/
	| DOUBLE  
	| SHORT
	| LONG
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier /* struct형 선언, 정의 */
	| enum_specifier   /*enum 선언 정의 */
	;


enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;


enumerator
	: IDENTIFIER
	| IDENTIFIER '=' cValue
	;


type_qualifier  /*const 와 valatile */
	: CONST
	| VOLATILE
	;
type_qualifier_list
	: type_qualifier
	|type_qualifier_list type_qualifier
	;

declaration : declaration_specifiers  /*타입과 변수들 선언*/
	| declaration_specifiers init_declarator_list 	{count[type] +=T; type = 0; T = 0;}
	; 

init_declarator_list /*변수 선언시 타입을 제외한 나머지 부분*/
	: init_declarator 			
	| init_declarator_list ',' init_declarator  
	;

init_declarator
	: declarator 
	| declarator '=' initializer {op++;}
	| declarator ':' cValue {op++;}    /*구조체 정의부에서 필요한 선언 법*/
	| ':' cValue {op++;}
	;
declarator: direct_declarator    {if(!checkFunct){T++;} if(checkArr){A++; checkArr = 0;} checkFunct = 0; }
	| pointer direct_declarator 	{if(checkArr){A++; checkArr = 0;} if(!checkFunct) {P++;T++;} checkFunct = 0;}	
	| pointer    	/*함수 선언시 매개변수로 (int *,char*) */
	;

pointer: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;


direct_declarator: IDENTIFIER 	/*변수의 기본형들 (일반 식별자,함수,배열) */
	| '(' declarator ')'	/*함수인지 check한다 */
	| direct_declarator '('')' {funct++; checkFunct = 1;}
        | direct_declarator'['']'  	{checkArr = 1;}/*배열인지 체크 다차원 배열 중복방지*/
	| direct_declarator'[' cValue ']'    	{checkArr = 1;}/*cValue는 상수연산을 포함하고있음*/ 
	| direct_declarator'('identifier_list')' {funct++; checkFunct = 1;}
	| direct_declarator'(' parameter_list')' {funct++; checkFunct = 1;}
	;
	
parameter_list /* 함수 정의시 필요한 인자형태 */
	: parameter_declaration 
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator {count[type] +=T; type = 0; T = 0;}
	| declaration_specifiers /*함수 선언시 매개변수 타입만 선언*/
	;


identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;
					


initializer /*배열  값 넣을때*/
	:  Value 
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;
initializer_list
	: initializer
	| initializer_list ',' initializer
	;




declaration_specifiers  /* 선언시 타입의 종류들..구조체선언,정의도  포함*/
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;



struct_or_union :	UNION    /*구조체, union */
	|	STRUCT
	;

struct_or_union_specifier: struct_or_union IDENTIFIER  /*구조체 정의*/
	| struct_or_union IDENTIFIER '{''}'
	| struct_or_union IDENTIFIER '{'struct_union_parameter_list '}'
	;

struct_union_parameter_list : struct_union_parameter /* 구조체의 내용물 */
	| struct_union_parameter_list  struct_union_parameter
	;
struct_union_parameter: declaration ';' | function
	;
	


id : IDENTIFIER  /* expression의 가장 기본 */
	| NUMBER
	| '(' expression ')'
	| LITERAL
	;


storage_class_specifier : TYPEDEF 
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

statement : declaration ';' 	/*변수,함수 선언 */
	| expression_statement  /*연산,수식 기본 표현들*/
	| function		/*함수 선언과 정의*/
	| compound_statement    /*실제 프로그램이 연산되는 실행문 */
	| selection_statement   {selection++;} /*선택문 */
	| iteration_statement	{iteration++;}/*반복문 */
	| labeled_statement	/*레이블 */
	| jump_statement	/*분기문 */
	;

statement_list: statement   	/* statement들의 모임 좌결합*/
	| statement_list statement
	;

compound_statement            /*"{}" 중괄호 안에 실행되는 명령어들을 담는다 */
	:'{' statement_list '}'
	|'{' '}'
	;



expression_statement 
	: ';'
	| expression ';'
	;
 
jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';' {return_++; } /*return 문은 함수안에서만 실행되며 함수 종료와 반환값을 주는 역할*/
	| RETURN expression ';'{return_++; }
	;


labeled_statement
	: IDENTIFIER ':' statement
	| CASE cValue ':' statement
	| DEFAULT ':' statement
	;


selection_statement
	: IF '(' expression ')' statement
	| ELSE statement /*else문도 읽을 수 있지만 if문 없이 단독 사용이 가능해서 불완전함 */
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement




function : declaration_specifiers declarator compound_statement {type=0;T=0;checkFunct = 0;}
	;

include : '#' INCLUDE '<' header '>'  /*include 헤더의 일반적인 형태만 넣음*/
	| '#' INCLUDE LITERAL
	| '#' INCLUDE '<' IDENTIFIER'>'
	;
header: IDENTIFIER '.' IDENTIFIER
	;



def	: '#' DEFINE IDENTIFIER IDENTIFIER
	| '#' DEFINE IDENTIFIER NUMBER /* 전처리기는 정의 부분에 제한이 없고
					  구분이 줄바꿈이어서 reduce가 쉽지않아
					  자주사용하는 한정된 구문만 정의했습니다. */
	;

sub_start:  declaration ';' /*처음 전역 부분에서는 선언과 정의만 가능하다.*/
	| function          /*실행문들은 함수의 정의부분 안에서 가능*/
	|';' 
	| include	
	| def
	;

%%

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
