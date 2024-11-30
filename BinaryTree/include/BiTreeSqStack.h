#pragma once
#include "BinaryTree.h"
#define MAXSIZE 100

typedef struct BiTreeSqStack {
	BiTree* base;
	BiTree* top;
	int StackSize;
}SqStack;

void InitStack(SqStack* );

bool StackEmpty(const SqStack);

bool Pop(SqStack*, BiTree*);

bool Push(SqStack*, BiTree);

void FreeStack(SqStack*);