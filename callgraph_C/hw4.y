%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

typedef struct line { /*호출된 라인을 링크드 리스트로 저장한다 용량의 한계떄문에 링크드리스트 활용*/
	int line_num;
	struct line *next_Line;
}line;

 /*정의된 함수 구조체 */
typedef struct inner{ 
	struct inner *in[4000];/*정의부에서 콜한 함수 최대 4000개 호출로 제한*/
	int in_count[4000];	/*같은 함수가 콜된 횟수 저장*/
	line *in_line[2000];    /*각 함수가 몇번째 줄에서 호출됬는지 링크드 리스트의 첫 포인터*/
	line *in_last_line[4000];/* 각 함수가 호출된 라인을 저장한 링크드 리스트의 마지막 포인터*/
	int num; 		/*내장함수가 아닌 콜한 함수의 개수*/
	char func_name[21];	/*현재 함수의 이름, 이름은 20자가 최대*/
	int bnum;		/*콜한 빌트인함수 개수*/
	char bult_in[4000][21];	/*정의부에서 콜한 빌트인함수 최대 4천개 호출로 제한*/
	int bult_count[4000];	/*같은 내장함수가 호출된 횟수 저장*/
	line *bult_line[4000];	/*호출된 라인의 링크드리스트 첫 포인터*/
	line *bult_last_line[4000]; /*호출된 라인의 링크드리스트 마지막 포인터*/
	int checkCall;
	struct inner *callee;
	struct inner *pathCallee;
}inner;
/*함수는 최대 5천개까지 생성 가능*/
inner FUNC[5000];

int findex(const char *name,int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (strcmp(FUNC[i].func_name, name) == 0) { 
			return i; //인덱스 리턴
		}
	}
	return -1;
}
int Line=1;
 /*함수 정의부에서 콜된 함수를 내부에 저장하는 함수 */
 /*전에 이미 저장된 함수는 또 저장하지 않는다 */
/*word: 호출된 함수명*/
/*FUNC: 현재까지 정의된 함수를 저장하고 있는 배열 */
/*len : 현재 검사중인 함수의 인덱스 */
/*bult: 내장함수인지 아닌지 판단, 아니라면 word명인 FUNC의 인덱스를 가지고 있음*/
void overLab(char * word,inner *FUNC,int len,int bult) { 
	int i;				
	if (bult == -1) {
		for (i = 0; i < FUNC[len].bnum; i++) {
			if (strcmp(word, FUNC[len].bult_in[i]) == 0) {
				FUNC[len].bult_count[i]++;
				/*몇줄에서 호출되는지 링크드 리스트로 저장한다. */
				FUNC[len].bult_last_line[i] -> next_Line = (line *)malloc(sizeof(line));
				FUNC[len].bult_last_line[i] = FUNC[len].bult_last_line[i]->next_Line;
				FUNC[len].bult_last_line[i]->line_num = Line;	
				return;
			};
		}
		strcpy(FUNC[len].bult_in[FUNC[len].bnum],word);
		FUNC[len].bnum += 1; FUNC[len].bult_count[FUNC[len].bnum-1]=1;
		
		FUNC[len].bult_line[FUNC[len].bnum - 1] = (line *)malloc(sizeof(line));
		FUNC[len].bult_line[FUNC[len].bnum - 1]->line_num = Line;
		FUNC[len].bult_last_line[FUNC[len].bnum - 1] = FUNC[len].bult_line[FUNC[len].bnum - 1];
		return;
	}
	else {
		for (i = 0; i < FUNC[len].num; i++) {
			if (strcmp(word, FUNC[len].in[i]->func_name) == 0) {
				FUNC[len].in_count[i]++;
				
				FUNC[len].in_last_line[i] -> next_Line = (line *)malloc(sizeof(line));
				FUNC[len].in_last_line[i] = FUNC[len].in_last_line[i]->next_Line;
				FUNC[len].in_last_line[i]->line_num = Line;
				return;
			};

		}
		FUNC[len].in[FUNC[len].num] = &FUNC[bult];
		FUNC[len].num += 1; FUNC[len].in_count[FUNC[len].num-1]=1;
		
		FUNC[len].in_line[FUNC[len].num - 1] = (line *)malloc(sizeof(line));
		FUNC[len].in_line[FUNC[len].num - 1]->line_num = Line;
		FUNC[len].in_last_line[FUNC[len].num - 1] = FUNC[len].in_line[FUNC[len].num - 1];
		return;
	}
}
int funcindex = 0;
int main_index = -1; 
char funcCall[21];  /*name 임시저장,name이 매개변수의 이름이 되기 전에 빼놓기 위해*/
char name[21];
int len =0; /*지금까지 정의된 함수의  총개수*/
int checkf = 0;  /*함수 호출인지 체크*/
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
	| '(' type_mix ')' oValue
	;
		
uValue : sValue /*전위 연산자 우결합*/
	| MM uValue {op++;} 
	| PP uValue {op++;}
	| SIZE uValue
	| SIZE '(' type_name ')' 
	| SIZE '(' type_mix ')'
	| unray_oper uValue
	; 

sValue : tValue
	| sValue '.' tValue  /*멤버접근자로 함수나 배열의 인자도 부를 수 있다.*/
	| sValue POINTER tValue  {op++;}
	;


tValue : id   /*후위 연산자 좌결합*/
	| fValue ')'
	{
 	if(checkf == 1)
                 {
                         int temp = findex(funcCall, len);
                         overLab(funcCall,FUNC,funcindex,temp);
                 }
                 checkf=0;
	}   
	| tValue '['expression']'
	| fValue  expression ')' 
	{
 	if(checkf == 1)
                 {     
                        int temp = findex(funcCall, len); /*// -1이면 bult-in함수*/
  			overLab(funcCall,FUNC,funcindex,temp);
                 }
                 checkf=0;
	}	
	| tValue PP  {op++;}
	| tValue MM {op++;}  
	;
fValue : id '(' {strcpy(funcCall, name); checkf = 1; funct++; } /*함수 매개변수가 이름으로 읽히는 것 방지*/
	;

type_name: declaration_specifiers /*c언어 안의 타입의 종류*/
         ;
 type_mix: type_name pointer
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
	| FLOAT		{type = 0;}
	| VOID		{type = 0;} /*기본 타입들*/
	| DOUBLE  	{type = 0;}
	| SHORT		{type = 0;}
	| LONG		{type = 0;}
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier	{type = 0;} /* struct형 선언, 정의 */
	| enum_specifier   {type = 0;}	/*enum 선언 정의 */
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
	| '['']'
	;

pointer: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;


direct_declarator: IDENTIFIER 	/*변수의 기본형들 (일반 식별자,함수,배열) */
	| '(' declarator ')'	/*함수인지 check한다 */
	| direct_declarator funCheck ')' 
	{  	
		
		int index = findex(funcCall,len); 	/*예전에 선언됬던 함수인지 아닌지 체크*/
		if( index == -1){      			/*처음 선언or정의되는 함수 */
			
			strcpy(FUNC[len].func_name,funcCall);
			FUNC[len].num = 0;
			FUNC[len].bnum = 0;
			funcindex = len; 	/*새롭게 추가된함수의 인덱스는 len, 선언만 하고 끝난다면 의미없다.*/
			len++;	     		/*총길이 증가*/			
			funct++; checkFunct = 1;
		}
		else{    /*예전에 선언했던 함수를 정의*/
			funcindex = index; /*함수의 인덱스는 findex로 찾은 인덱스*/
			/*총길이의 증가는 없음*/ 			
		}
		if(main_index == -1){ /*찾은 후에도 strcmp연산은 비용이 많이들기에 추가한 사항*/
			if(strcmp("main",funcCall)==0){
				main_index = len-1;
			}		
		}
	}


        | direct_declarator'['']'  	{checkArr = 1;}/*배열인지 체크 다차원 배열 중복방지*/
	| direct_declarator'[' cValue ']'    	{checkArr = 1;}/*cValue는 상수연산을 포함하고있음*/ 
	| direct_declarator funCheck identifier_list')' 
	{	
		int index = findex(funcCall,len);
		
		if( index == -1){

                         strcpy(FUNC[len].func_name,funcCall);
                         FUNC[len].num = 0;
                         FUNC[len].bnum = 0;
                         funcindex = len; /* 새롭게 추가된함수의 인덱스는 len, 선언만 하고 끝난다면 의미없다.*/
                         len++;       /*총길이 증가*/
                         funct++; checkFunct = 1;
                 }
		else{
                         funcindex = index; /*예전에 선언했던 함수를 정의하려고 부름*/
                         /*총길이의 증가는 없음*/
		}	
		
		if(main_index == -1){ 
                         if(strcmp("main",funcCall)==0){
                                 main_index = len-1;
                         }
                 }	
	}

	| direct_declarator funCheck parameter_list')' 
	{
		int index = findex(funcCall,len);
	
		if( index == -1){

                         strcpy(FUNC[len].func_name,funcCall);
                         FUNC[len].num = 0;
                         FUNC[len].bnum = 0;
                         funcindex = len; /* 새롭게 추가된함수의 인덱스는 len, 선언만 하고 끝난다면 의미없다.*/
                         len++;       /*총길이 증가*/
                         funct++; checkFunct = 1;
                 }
		else{
                         funcindex = index; /*예전에 선언했던 함수를 정의하려고 부름*/
                         /*총길이의 증가는 없음*/
		}
		if(main_index == -1){ 
                         if(strcmp("main",funcCall)==0){
                                 main_index = len-1;
                         }
                 }
	}
	;

funCheck: '(' {strcpy(funcCall,name);}  /*함수일때 다음 파라미터의 name으로 섞이기 전 함수명 저장*/
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




function : declaration_specifiers functionO
	;

functionO :declarator compound_statement {type = 0; T = 0; checkFunct=0;}
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
	{
		//int j=0;
	}
	|';' 
	| include	
	| def
	| functionO
	;

%%

void yyerror(const char *str)
{
	fprintf(stderr,"error : %s\n",str);
}
int main(void){
	int i;
	FILE * f;
	f = fopen("B511209.txt","wt");
	if(f == NULL){
		puts("파일열기 오류, 같은 폴더에 B511209.txt 파일이 있는지 확인해주세요.\n");
		return 0;
	}
	fprintf(f,"1.리눅스 서버에 맞춰 최대한 메모리를 할당했기에 다른 컴퓨터에서 돌릴 경우 메모리부족으로 컴파일이 안될 수 있습니다.\n\n%");
	fprintf(f,"2.리눅스에서 생성한 텍스트파일을 다른 운영체제에서 열면 출력 형태가 다를 수 있습니다.\n\n\n\n");
	fprintf(f,"프로그래밍언어 HW4 B511209 최아성_콜그래프\n\n");
	fprintf(f,"출력 방식\n-----------\n\n");
	fprintf(f,"함수1 -> 호출한 함수 나열...(호출된 횟수와 호출된 라인 출력)\n\n");
	fprintf(f,"===== 함수1 start ====(함수 1에서 내장함수를 제외한 호출한 함수들의 그래프를 이어서 출력)\n\n");
	fprintf(f,"\ttab띄고 (callee:함수1) 피호출함수 ->  함수1에서부터 이어서 호출하는 그래프 반복 출력 \n\n\n");
	fprintf(f,"/* 이미 한번 콜그래프가 그려진 함수는 더 그리지 않고 이미 그려진  그래프의 경로만 알려줍니다 */.\n\n");
	fprintf(f,"========================================================================================\n\n\n\n\n\n");
	
	printf("\n 콜그래프 시작----------------------------------------------------------------------------------------\n\n\n");
	
	void Print(inner *Temp,int depth) {
		if (!Temp) return;
		int i;
		int j;
		line *temp;
		/*현재 호출된 함수 이름 출력*/
		printf(" %s -> {", Temp->func_name);
		fprintf(f," %s -> {", Temp->func_name);
		/*check된 함수(이 전에 그래프가 이미 그려진 함수) 콜백함수,재귀함수는 무한루프에 빠질 수 있으므로 처리*/
		/*check된 함수는 자신 안에 포함된 함수를 더이상 그래프 그리지 않고 이전에 그렸던 그래프의 경로를 알려줌.*/
		if (Temp -> checkCall) {
			if (Temp == Temp->callee) {
				printf(" 재귀함수 ");
				fprintf(f," 재귀함수 ");
			}
			else {
				inner *calltemp = Temp;
				printf(" 경로:");
				fprintf(f," 경로:");
				/*피호출 함수가 역순으로 경로를 배치*/
				Temp->pathCallee = NULL;
				while (calltemp->callee) {
					calltemp->callee->pathCallee = calltemp;
					calltemp = calltemp->callee;
				}
				/*경로를 순서대로 출력*/
				while (calltemp) {
					printf(" %s ", calltemp->func_name);
					fprintf(f," %s ", calltemp->func_name);
					calltemp = calltemp->pathCallee;
					if(calltemp) {printf("->"); fprintf(f,"->"); }
				}
				printf("에서 먼저 그래프 그려짐. ");
				fprintf(f,"에서 먼저 그래프 그려짐. ");
			}
			printf("}\n\n\n");
			fprintf(f,"}\n\n\n");
			return;
		}
		/*처음 호출된 함수 처리*/
		Temp -> checkCall = 1; 
	
		/*함수 내부에서 호출된 함수들의 이름과 선언된 위치와 횟수를 출력*/
		for (i = 0; i < Temp->num; i++) {
				printf(" %s:%d.times(",Temp->in[i]->func_name,Temp->in_count[i]);
				fprintf(f," %s:%d.times(",Temp->in[i]->func_name,Temp->in_count[i]);
				temp = Temp->in_line[i];
				while (temp) {
					printf("%d", temp->line_num);
					fprintf(f,"%d", temp->line_num);
					temp = temp->next_Line;
					if(temp){ printf(","); fprintf(f,","); }
				}
				printf(")");  fprintf(f,")");
				if(i<Temp->num-1 ){ printf(",  "); fprintf(f,",  "); } 
		}
		if(Temp->bnum > 0) { printf(" |내장함수|:"); fprintf(f," |내장함수|:"); }
		for (i = 0; i < Temp->bnum; i++) {
			printf(" %s:%d.times(", Temp->bult_in[i],Temp->bult_count[i]);
			fprintf(f," %s:%d.times(", Temp->bult_in[i],Temp->bult_count[i]);
			temp = Temp->bult_line[i];
			while (temp) {
				printf("%d", temp->line_num);
				fprintf(f,"%d", temp->line_num);
				temp = temp->next_Line;
				if(temp) {printf(","); fprintf(f,","); }
			}
			printf(")"); fprintf(f,")");
			if(i<Temp->bnum-1){ printf(",  "); fprintf(f,",  "); }
		}
		
		printf(" }\n\n"); fprintf(f," }\n\n");

		/*내장함수가 아닌, 정의된 함수중에서 그래프가 이어서 그려질 함수가 존재한다면 재귀적으로 Print함수를 이용해 더 그린다*/
		if(Temp->num > 0){
                         for (j = 0; j < depth-1; j++) { printf("\t\t|"); fprintf(f,"\t\t|"); }
                         printf("=============================== %s  Start ===============================\n\n\n",Temp->func_name);
                         fprintf(f,"=============================== %s  Start ===============================\n\n\n",Temp->func_name);
                }
		else{printf("\n"); fprintf(f,"\n");}
		for (i = 0; i < Temp->num; i++) {
			for (j = 0; j < depth; j++) { printf("\t\t|"); fprintf(f,"\t\t|"); }
 
			/*처음 함수가 호출되었을때 자신을 호출한 함수를 저장한다.*/
			if(Temp->in[i]->checkCall !=1 ) {Temp -> in[i] -> callee = Temp;}

		 	printf(" (callee:%s)",Temp->func_name); 
			fprintf(f," (callee:%s)",Temp->func_name);
			if(Temp == Temp->in[i]){
				printf(" %s -> { 재귀함수 }\n\n\n",Temp->in[i]->func_name);
				fprintf(f," %s -> { 재귀함수 }\n\n\n",Temp->in[i]->func_name);
			}
			else{
				Print(Temp->in[i],depth+1);
			}
		}
		if(Temp->num > 0){
			for (j = 0; j < depth-1; j++) { printf("\t\t|"); fprintf(f,"\t\t|"); }
			printf("=============================== %s  End ===============================\n\n\n\n\n",Temp->func_name);
			fprintf(f,"=============================== %s  End ===============================\n\n\n\n\n",Temp->func_name);
		}
	}
	
	yyparse();

	inner * Temp = &FUNC[main_index];
	printf("\n");
	fprintf(f,"\n");
	Print(Temp,1);
	
	printf("\n\n\n    선언된 함수의 종류\n------------------------------\n");
	fprintf(f,"\n\n\n    선언된 함수의 종류\n------------------------------\n");
	for(i = 0; i < len ; i++){
		printf(" %s \n",FUNC[i].func_name);
		fprintf(f," %s \n",FUNC[i].func_name);
	}
	printf("\n");
	
	fclose(f);
	return 0;
}
