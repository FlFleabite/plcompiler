parser: y.tab.o lex.yy.o stack.o
	gcc y.tab.o lex.yy.o stack.o -ll -o parser -g 

scanner.o: lex.yy.c
	gcc lex.yy.c -c -ll

stack.o:stack.c stack.h
	gcc stack.c -c -g 

y.tab.o: y.tab.c
	gcc y.tab.c -c -g

y.tab.c: parser.y stack.o
	yacc -d parser.y 

y.tab.h: parser.y
	yacc -d parser.y 

lex.yy.c: scanner.l y.tab.h
	lex scanner.l

clean:
	rm y.tab.c lex.yy.c -f
	rm *.o
