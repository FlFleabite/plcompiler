/*stack.h*/
#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void stack_insert(char *name, int type,int addr);
int stack_lookup(char *name);
int type_lookup(char *name);
void stack_delete();

#endif