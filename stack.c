/*stack.c*/
#include"stack.h"
#define STACKMAX 1000

typedef struct Stack
{
    char *name;
    int addr;
    int flag;
    struct Stack *next;
} STACK;
static STACK *first=NULL;
static int stacksize=0;

void stack_insert(char *name, int type,int addr)
{
    //static int addr=0;
    //static int procaddr = 0;
    static int i = 0;

    STACK *st;//インクリメント用
    STACK *new;//追加するレコード
    st=first;
    new=(STACK*)malloc(sizeof(STACK));//メモリ確保
    if(new==NULL){
        fprintf(stderr,"stack.c: memerror");
        return;
    }
    /*レコードが存在しない場合はインクリメントしない*/
    if(st!=NULL){
        while(st->next!=NULL){
            st=st->next;
        }//末尾まで移動
        st->next=new;//リストの連結
    }else{st=new;first=new;}

    new->name=(char*)malloc(strlen(name)*sizeof(char));//必要な分だけnameを確保

    if(type==2)//TYPE==PROC
    {
        strcpy(new->name,name);
        new->addr = addr;
        new->flag = type;
        //procaddr++;
        i++;
        stacksize++;
        printf("%s\tis inserted to stack: addr = %d type = %d\n", name,new->addr, type);
        return;
    }

    /*TYPE==VAR*/
    new->addr=addr;
    strcpy(new->name,name);
    new->flag=type;
    //addr++;
    i++;
    stacksize++;
    printf("%s\tis inserted to stack: addr = %d type = %d\n", name,new->addr, type);
    //DEBAG
    //printf("%d %s\n", stack[i - 1].flag, stack[i - 1].name);
    //ENDDEBAG
}

int stack_lookup(char *name)
{
    int i=0;
    STACK *st;//インクリメント用
    st=first;
    while(strcmp(st->name,name)!=0 ){
        st=st->next;
        if(st==NULL){
            fprintf(stderr,"stack.c: No such Value \"%s\"!!\n",name);
            return;
        } 
    }
    
    printf("%s\tis looked up: addr = %d, type = %d\n", name,st->addr,st->flag);
    return st->addr;
}

int type_lookup(char *name){
    int i = 0;
    STACK *st; //インクリメント用
    st = first;
    while (strcmp(st->name, name) != 0)
    {
        st = st->next;
        if (st == NULL)
        {
            fprintf(stderr, "stack.c: No such Value \"%s\"!!\n", name);
            return;
        }
    }

    //printf("%s\tis looked up: addr = %d, type = %d\n", name, st->addr, st->flag);
    return st->flag;
}

void stack_delete()
{
    STACK *prev;
    STACK *del;
    del=first;
    for(;del!=NULL;){
        if(del->flag==1){
            printf("%s\tis deleted: addr = %d, type = %d\n",del->name,del->addr,del->flag);
            prev->next=del->next;//張り替え
            free(del->name);//レコードの削除
            free(del);
            del=prev->next;//次のアドレスを復元
            stacksize--;
        }
        else
        {
            prev=del;
            del=del->next;//次のレコードへインクリメント
        }
    }
}

void alldelete(){
    STACK *prev;
    STACK *del;
    del=first;
    for(;del!=NULL;){
        printf("%s\tis deleted: addr = %d, type = %d\n",del->name,del->addr,del->flag);
        prev=del->next;//張り替え
        free(del->name);//レコードの削除
        free(del);
        del=prev;//次のアドレスを復元
        stacksize--;
        
    }

}