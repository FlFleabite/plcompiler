#include	<stdio.h>
#include	"code.h"
#include	"optype.h"

void main(argc,argv)
int	argc;
char	*argv[];
{
    OPCODE	r;
    char	code[4],br[3],ir[3],ad[10];
    FILE	*infile;
    int		count;

    if(argc == 1)	infile = stdin;
    else if(argc == 2) {
	if((infile=fopen(argv[1],"r"))==NULL) {
	    fprintf(stderr,"Object file %s cannot open\n",argv[1]);
	    exit(1);
	}
    } else fprintf(stderr,"Too many options\n");

    count = 0;
    while(fread(&r,sizeof(r),1,infile)) {
	switch(r.opcode) {
	    case LIT:
		sprintf(code,"lit");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"'%d'",r.address);
		break;
	    case LOD:
		sprintf(code,"lod");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    case STO:
		sprintf(code,"sto");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    case MVX:
		sprintf(code,"mvx");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    case OPR:
		sprintf(code,"opr");
		(*br)=(*ir)='\0';
		switch(r.address) {
		    case 0:
			sprintf(ad,"minus");
			break;
		    case 1:
			sprintf(ad,"+");
			break;
		    case 2:
			sprintf(ad,"-");
			break;
		    case 3:
			sprintf(ad,"*");
			break;
		    case 4:
			sprintf(ad,"div");
			break;
		    case 5:
			sprintf(ad,"=");
			break;
		    case 6:
			sprintf(ad,"<>");
			break;
		    case 7:
			sprintf(ad,"<");
			break;
		    case 8:
			sprintf(ad,"<=");
			break;
		    case 9:
			sprintf(ad,">");
			break;
		    case 10:
			sprintf(ad,">=");
			break;
		    default:
			sprintf(ad,"???");
		}
		break;
	    case INT:
		sprintf(code,"int");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    case CAL:
		sprintf(code,"cal");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    case RTN:
		sprintf(code,"rtn");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    case JMP:
		sprintf(code,"jmp");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    case JPC:
		sprintf(code,"jpc");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    case GET:
		sprintf(code,"get");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    case PUT:
		sprintf(code,"put");
		sprintf(br,"R%1d",r.basereg);
		sprintf(ir,"R%1d",r.indexreg);
		sprintf(ad,"%d",r.address);
		break;
	    default:
		sprintf(code,"???");
		(*br)=(*ir)=(*ad)='\0';
	}
	printf("%05d :\t%s\t%s\t%s\t%s\n",count++,code,br,ir,ad);
    } /* While */
    fclose(infile);
}
