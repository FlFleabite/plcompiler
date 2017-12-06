%{
/* 
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16
#include"stack.h"
#include"optype.h"
#include"code.h"
extern int yylineno;
extern char *yytext;
enum FLAG {GLOBAL,LOCAL,PROC};
enum FLAG flag=GLOBAL; 
FILE *fp;
static int currentstack=0;
static int startstack=0;
static int opnumber=0;
%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS
%left MULT DIV

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER
%token <ident> IDENT

%type <num> label

%%

program
    : {fp=fopen("result.code","wb");}PROGRAM IDENT SEMICOLON outblock PERIOD{fclose(fp);alldelete();}
	;

outblock
    : var_decl_part {generate(JMP,0,0,0);/*backpatch*/}label subprog_decl_part {backpatch($3-1,opnumber);}statement
    ;

var_decl_part
    : /* empty */
    | var_decl_list SEMICOLON
    ;

var_decl_list
    : var_decl_list SEMICOLON var_decl
    | var_decl
    ;

var_decl
    : VAR id_list
    ;

subprog_decl_part
	: {currentstack=0;}subprog_decl_list SEMICOLON
    | /* empty */
    ;

subprog_decl_list
	: subprog_decl_list SEMICOLON subprog_decl
	| subprog_decl
	;

subprog_decl
	: proc_decl
	;

proc_decl
	: PROCEDURE proc_name SEMICOLON {flag=LOCAL;} inblock {flag=GLOBAL;
	stack_delete();generate(RTN,0,0,0);}
	;

proc_name
	: IDENT {stack_insert($1,PROC,opnumber);} /*add stack*/
	;

inblock
	: var_decl_part statement
	;

statement_list
	: statement_list SEMICOLON statement
	| statement
	;

statement
	: assignment_statement
	| if_statement
	| while_statement
	| for_statement
	| proc_call_statement
	| null_statement
	| block_statement
	| read_statement
	| write_statement
	;

assignment_statement
	: IDENT ASSIGN expression {generate(STO,type_lookup($1),0,stack_lookup($1));}
	;

if_statement
	: IF condition {generate(JPC,0,0,0);/*backpatch*/} label THEN statement {generate(JMP,0,0,0);/*backpatch*/} label {backpatch($4-1,opnumber);} else_statement {backpatch($8-1,opnumber);}
	;

else_statement
	: /* empty */
	| ELSE statement
	;

while_statement
	: WHILE label condition {generate(JPC,0,0,0);/*backpatch*/} label DO statement {generate(JMP,0,0,$2);backpatch($5-1,opnumber);}
	;

for_statement
	: FOR IDENT ASSIGN expression 
	{generate(STO,type_lookup($2),0,stack_lookup($2));}/*インクリメント用変数の初期値の設定*/ 
	TO label expression 
	{generate(LOD,type_lookup($2),0,stack_lookup($2));generate(OPR,0,0,10); generate(JPC,0,0,0);/*backpatch*/} /*終了判定*/
	label DO statement 
	{/*インクリメント*/generate(LIT,0,0,1);generate(LOD,type_lookup($2),0,stack_lookup($2));generate(OPR,0,0,1);generate(STO,type_lookup($2),0,stack_lookup($2)); generate(JMP,0,0,$7); backpatch($10-1,opnumber);}/*変数のインクリメント*/
	;

proc_call_statement
	: proc_call_name

proc_call_name
	: IDENT {generate(CAL,0,0,stack_lookup($1));}/*stacklookup*/
	;

block_statement
	: SBEGIN statement_list SEND
	;

read_statement
	: READ LPAREN IDENT RPAREN {generate(GET,0,0,0);generate(STO,type_lookup($3),0,stack_lookup($3));}
	;

write_statement
	: WRITE LPAREN expression RPAREN {generate(PUT,0,0,0);}
	;

null_statement
	: /* empty */ 
	;

condition
	: expression EQ expression{generate(OPR,0,0,5);}
	| expression NEQ expression{generate(OPR,0,0,6);}
	| expression LT expression{generate(OPR,0,0,7);}
	| expression LE expression{generate(OPR,0,0,8);}
	| expression GT expression{generate(OPR,0,0,9);}
	| expression GE expression{generate(OPR,0,0,10);}
	;

expression
	: term
	| PLUS term
	| MINUS term{generate(OPR,0,0,0);}
	| expression PLUS term{generate(OPR,0,0,1);}
	| expression MINUS term{generate(OPR,0,0,2);}
	;

term
	: factor
	| term MULT factor{generate(OPR,0,0,3);}
	| term DIV factor{generate(OPR,0,0,4);}
	;

factor
	: var_name
	| NUMBER{generate(LIT,0,0,$1);}
	| LPAREN expression RPAREN
	;

var_name 
	: IDENT {generate(LOD,type_lookup($1),0,stack_lookup($1));}
	;

arg_list
	: expression
	| arg_list COMMA expression
	;

id_list
	: IDENT {stack_insert($1,flag,currentstack);currentstack++; generate(LIT,0,0,0);}
	| id_list COMMA IDENT {stack_insert($3,flag,currentstack);currentstack++; generate(LIT,0,0,0);}
	;

label
	: {$$ = opnumber;};/*backpatch用,label位置の命令数を保持*/

%% 
yyerror(char *s)
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
	printf("code: %d %d %d %d\n",item.opcode,item.basereg,item.indexreg,item.address);
	//ENDDEBAG

	fwrite(&item,sizeof(OPCODE),1,fp);

	opnumber++;
	/*
	switch(opcode){
		case 0:
		case 1:
		case 10:
			currentstack++;
			break;
		case 2:
		case 3:
		case 4:
		case 9:
		case 11:
			currentstack--;
			break;
		case 6:
			startstack=currentstack+5;
			currentstack+=4;
			break;
		case 7:
			currentstack=startstack-5;
	}*/
}

void backpatch(int a,REG b){

	fseek(fp,(long)(a*sizeof(OPCODE)),0);
	fseek(fp,(long)(sizeof(int)+sizeof(REG)*2),1);
	fwrite(&b,sizeof(REG),1,fp);
	fseek(fp,(long)0,2);

	printf("backpatch: op = %d, REG = %d\n",a,b);
}