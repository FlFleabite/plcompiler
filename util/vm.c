/*
 *
 *
        学生実験(コンパイラ) 仮想マシン実現系
	
	An Implementation for Gakusei jikken Compiler Virtual machine

	$Id: vm.c,v 2.3 1995/06/29 05:00:25 yuen Exp $

	$Log: vm.c,v $
 * Revision 2.3  1995/06/29  05:00:25  yuen
 * strings.h -> string.h
 *
 * Revision 2.2  1995/06/29  04:57:37  yuen
 * RTN simulation is not quite right
 *
 * Revision 2.1  1993/06/08  08:17:36  yuen
 * H5 version vm.c
 *
 * Revision 1.4  1993/06/08  08:15:47  yuen
 * Procedure call and return renewed
 *
 * Revision 1.3  1992/10/21  04:03:35  yuen
 * disassembler modified
 *
 * Revision 1.2  1992/10/21  02:46:16  yuen
 * debug mode is added.
 *
 * Revision 1.1  1992/10/20  09:38:16  yuen
 * Initial revision
 *
*/

/*
	Including files
*/

#include <stdio.h>
#include <ctype.h>
#ifdef SYSV
#include <string.h>
#else
#include <strings.h>
#endif
#include "code.h"

/*
	Some neccessary types

	レジスタの構造は整数型と同じである。
*/

typedef int REG;	/* A REGister is an integer */

/*
        インストラクションを示すワードは４つの部分からなる
	構造体を用いる。

	opcode   : オペレーションコード (1から13)
	basereg  : ベースレジスタ番号
	indexreg : インデックスレジスタ番号
	address  : アドレス/即値フィールド
 */
typedef struct {	/* A Word type for OPeration CODE */
	int	opcode;		/* Operation number */
	REG basereg;	/* Base register */
	REG indexreg;	/* Index register */
	REG address;	/* Address */
} OPCODE;

/*
	Global variables
	大域変数
*/

/*
        仮想マシンは5個のレジスタを持つ
 */

REG reg[5];			/* The Vertual Machine has 5 registers */

/*
        レジスタ 0 はプログラムカウンタとして用いる
 */	

#define PC	reg[0]	/* Register 0 is the program counter */

/*
        レジスタ 2 はスタックポインタとして用いる
 */

#define R2	reg[2]	/* Register 2 is the stack pointer */

/*
        実行するコードをファイルからロードしてくる領域を
	配列として確保する。領域の大きさはMAXLOADで決める。
 */

#define MAXLOAD	10240	/* The size for instructions */

OPCODE	load_area[MAXLOAD]; /* The memory allocation for instructions */

/*
        インストラクションレジスタは現在実行中のコード配列
	へのポインタとする。
 */

OPCODE	*ir;		/* Instruction register is a pointer to a opcode */

/*
        実行時に用いるスタック領域。
	最大の大きさはMAXSTACKで決める。
 */

#define	MAXSTACK 2000	/* The size for the stack */

REG	stack_area[MAXSTACK];	/* The memory allocation for the stack */

/*
  	フラグ
 */
int	dflag,vflag;

/*

 */

void exec_code();
void getinstruction();
void usage();

/*
        メインルーチン
 */

void
main(int argc,char **argv)		/* The main routine */
{
	FILE	*infile;
	int		i;
	int		objsize;

       /*
	* First check the -v and -d flag and the number of arguments
	* フラグのチェック
	* vflag =1 : 最後にスタックトップを出力
	* dflag =1 : デバッグモード (入力命令とスタックの状態を
	*            一命令ごとに表示する)
	*/

	vflag = 0; dflag = 0; infile = NULL;
	for(i = 1;i < argc;i++) {
		if(*argv[i]=='-') { /* The first character of the argument
				       is '-', i.e. a flag.
				       引数の一文字めが '-' ならば、フラグ */
			if(!strcmp(argv[i]+1,"v")) { /* vflag */
				vflag = 1; }
			else if(!strcmp(argv[i]+1,"d")) { /* dflag */
				dflag = 1; }
			else { /* Illegal flag */
				(void)usage(argv);}
		}
		else {	/* Should be filename
			   入力ファイル名 */
			if(infile != NULL) {	/* File already open
						   ファイル名は一つ */
				fprintf(stderr,"Too many object files");
				exit(1);
			}
			if((infile=fopen(argv[i],"r"))==NULL) {
				fprintf(stderr,"File %s couldn't open\n",argv[i]);
				exit(1);
			}
		}
	}
	if(infile==NULL) { /* No input file specified, then read from stdin.
			      ファイル名が指定されなかったときは
			      標準入力から読む */
		infile = stdin; }
       /*
	*	Load the object code
	*	オブジェクトコードのロード
	*/
	for(i=0;fread(&load_area[i],sizeof(OPCODE),1,infile);i++) {
		if (i>=MAXLOAD-1) {
			fprintf(stderr,"Too Big Object\n");
			exit(3);
		}
	}
	objsize = i;

       /*
	*	Execute the code sequentially
	*       命令コードの実行
	*/
	R2 = -1;		/* The stack be empty */

	while(PC < objsize) {
		ir=&load_area[PC];	/* Next instruction is pointed by PC */
		PC++;
		exec_code();		/* Call the command interpreter */
	}

	fprintf(stderr,"\nCode Executed normally.\n");
	if (vflag)
		printf("Stack top value = %d\n",stack_area[R2]);
}

/*
 * コマンドインタプリタ
 */

void
exec_code()		/* The command interpreter */
{
	if(dflag) {showstatus(0);}

	switch(ir->opcode) {
		case LIT:	R2=R2+1;	/* Load lITeral */
			stack_area[R2]=ir->address;
			break;
		case LOD:	R2=R2+1;	/* LOaD */
			stack_area[R2]=
				stack_area[(((ir->basereg)==0)?0:reg[ir->basereg])
				+(((ir->indexreg)==0)?0:reg[ir->indexreg])
				+(ir->address)];
			break;
		case STO:			/* STOre */
			stack_area[(((ir->basereg)==0)?0:reg[ir->basereg])
				+(((ir->indexreg)==0)?0:reg[ir->indexreg])
				+(ir->address)]=stack_area[R2];
			R2--;
			break;
		case MVX:			/* MoVe indeX register */
			reg[ir->indexreg]=stack_area[R2];
			R2--;
			break;
		case OPR:			/* arithmetic OPeRation */
			switch(ir->address) {
				case 0:		/* Inversion */
					stack_area[R2]=-stack_area[R2]; break;
				case 1: R2=R2-1;	/* Summation */
					stack_area[R2]=stack_area[R2]+stack_area[R2+1];
					break;
				case 2: R2--;	/* Subtraction */
					stack_area[R2]=stack_area[R2]-stack_area[R2+1];
					break;
				case 3: R2--;	/* Multiplication */
					stack_area[R2]=stack_area[R2]*stack_area[R2+1];
					break;
				case 4: R2--;	/* Division */
					stack_area[R2]=stack_area[R2]/stack_area[R2+1];
					break;
				case 5: R2--;	/* Equality */
					if(stack_area[R2] == stack_area[R2+1])
						stack_area[R2]=1;
					else stack_area[R2]=0;
					break;
				case 6: R2--;	/* Disequality */
					if(stack_area[R2] != stack_area[R2+1])
						stack_area[R2]=1;
					else stack_area[R2]=0;
					break;
				case 7: R2--;	/* Less Than */
					if(stack_area[R2] < stack_area[R2+1])
						stack_area[R2]=1;
					else stack_area[R2]=0;
					break;
				case 8: R2--;	/* Less or Equal */
					if(stack_area[R2] <= stack_area[R2+1])
						stack_area[R2]=1;
					else stack_area[R2]=0;
					break;
				case 9: R2--;	/* Greater Than */
					if(stack_area[R2] > stack_area[R2+1])
						stack_area[R2]=1;
					else stack_area[R2]=0;
					break;
				case 10: R2--;	/* Greater or Equal */
					if(stack_area[R2] >= stack_area[R2+1])
						stack_area[R2]=1;
					else stack_area[R2]=0;
					break;
				default:
					fprintf(stderr,"Illegal arithmetic operation\n");
					exit(4);
				}
				break;
		case INT:	/* INcrement the stack Top */
			R2 = R2 + (ir -> address);
			break;
		case CAL:	/* A procedure CALl */
			stack_area[R2+1]=reg[1];
			stack_area[R2+2]=PC;
			stack_area[R2+3]=reg[3];
			stack_area[R2+4]=reg[4];
			reg[1]=R2+5;
			R2=R2+4;
			PC=ir->address;
			break;
		case RTN:	/* ReTurN */
			R2 = reg[1]-5;
			PC = stack_area[reg[1]-3];
			reg[3]=stack_area[reg[1]-2];
			reg[4]=stack_area[reg[1]-1];
			reg[1]=stack_area[reg[1]-4];
			break;
		case JMP:	/* JuMP */
			PC = ir -> address;
			break;
		case JPC:	/* JumP on Condition */
			if(stack_area[R2]==0) {
				PC = ir-> address;
			}
			R2--;
			break;
		case GET:	/* GET data */
			R2++;
			printf("> ");
			scanf("%d",&stack_area[R2]);
			break;
		case PUT:	/* PUT data */
			printf("%d\n",stack_area[R2]);
			R2--;
			break;
		default:	/* Illegal instruction */
			fprintf(stderr,"Illegal instruction: %d\n",ir->opcode);
			exit(1);
	}
	if(dflag) {showstatus(1);}	/* Debug mode */
}

/*
 * VM の状態を表示する
 */
showstatus(int n)	/* Show the current status of the VM */
{
	int i;
	char instruction[80];

if(n==0) {
	printf("$ %05d\n",PC-1);
	instruction[0]='*';	/* Show instruction */
	instruction[1]=' ';
	instruction[2]='\0';
	(void)getinstruction(instruction);
	printf("%s\n",instruction); }
else {
	printf("* PC:%05d ",PC); /* Show registers */
	printf("R1:%05d ",reg[1]);
	printf("R2:%05d ",R2);
	printf("R3:%05d ",reg[3]);
	printf("R4:%05d\n",reg[4]);

	printf("* Stack:["); /* Show stack */
	for(i=0;i<=R2;i++) printf("%d ",stack_area[i]);
	printf("]\n\n");}
}

void
getinstruction(char *s)
{
	char buffer[80];
	
	switch(ir->opcode) {
	      case LIT: strcat(s,"LIT  "); break;
	      case LOD: strcat(s,"LOD  "); break;
	      case STO: strcat(s,"STO  "); break;
	      case MVX: strcat(s,"MVX  "); break;
	      case OPR: strcat(s,"OPR  "); break;
	      case INT: strcat(s,"INT  "); break;
	      case CAL: strcat(s,"CAL  "); break;
	      case RTN: strcat(s,"RTN  "); break;
	      case JMP: strcat(s,"JMP  "); break;
	      case JPC: strcat(s,"JPC  "); break;
	      case GET: strcat(s,"GET  "); break;
	      case PUT: strcat(s,"PUT  "); break;
	      case GETC: strcat(s,"GETC "); break;
	      case PUTC: strcat(s,"PUTC "); break;
	      default: strcat(s,"???? ");	/* This can't happen */
	}
	switch(ir->basereg) {
	      case 0: strcat(s,"   "); break;
	      case 1: strcat(s,"R1 "); break;
	      case 2: strcat(s,"R2 "); break;
	      case 3: strcat(s,"R3 "); break;
	      case 4: strcat(s,"R4 "); break;
	      default: strcat(s,"?? "); /* This can't happen */
	}
	switch(ir->indexreg) {
	      case 0: strcat(s,"   "); break;
	      case 1: strcat(s,"R1 "); break;
	      case 2: strcat(s,"R2 "); break;
	      case 3: strcat(s,"R3 "); break;
	      case 4: strcat(s,"R4 "); break;
	      default: strcat(s,"?? "); /* This can't happen */
	}
	sprintf(buffer,"%d",ir->address);
	strcat(s,buffer);
}

void
usage(char **argv)
{
	fprintf(stderr,"Usage: %s [-d] [-v] [objectfile]\n",argv[0]);
	fprintf(stderr,"\t-d\tDebug mode\n\t-v\tVerbose mode\n");
	exit(1);
}
