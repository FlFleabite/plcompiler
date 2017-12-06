#include <stdio.h>
#include <stdlib.h>
#include "code.h"
#include "optype.h"

main(int argc, char *argv[]) {
    FILE *fp;
    int tok;
    OPCODE code;
    
    char arith_op[][4] = {
      "neg",
      "+",
      "-",
      "*",
      "div",
      "==",
      "!=",
      "<",
      "<=",
      ">",
      ">="
    };

    char code_str[][4] = {
      "lit",
      "lod",
      "sto",
      "mvx",
      "opr",
      "int",
      "cal",
      "rtn",
      "jmp",
      "jpc",
      "get",
      "put"
    };

    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "cannot open file: %s\n", argv[1]);
        exit(1);
    }

    while( fread( &code, sizeof(OPCODE), 1, fp ) ){
      switch( code.opcode ){
      case OPR:
	printf("%s %3d %3d %3s\n",
	       code_str[code.opcode], code.basereg, code.indexreg, 
	       arith_op[code.address] );
	break;
      default:
	printf("%s %3d %3d %3d\n", 
	       code_str[code.opcode], code.basereg, code.indexreg, 
	       code.address );
	break;
      }
    }
    
}
