hw4 : y.tab.c lex.yy.c 
	cc y.tab.c lex.yy.c -o hw4 
y.tab.c : hw4.y 
	yacc -d hw4.y 
lex.yy.c : hw4.l 
	lex hw4.l 
