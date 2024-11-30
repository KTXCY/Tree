#include "BiTreeSqStack.h"

void InitStack(SqStack* S) {
	S->base = (BiTree*)malloc(sizeof(BiTree) * MAXSIZE);
	if (S->base == NULL) {
		fprintf(stderr, "Memory allocation error");
		exit(EXIT_FAILURE);
	}
	S->top = S->base;
	S->StackSize = MAXSIZE;
}

bool StackEmpty(const SqStack S) {
	if (S.top == S.base) {
		return true;
	}
	else {
		return false;
	}
}

bool Pop(SqStack* S, BiTree* T) {
	if (S->top == S->base) {
		fprintf(stderr, "Memory allocation error");
		return false;
	}
	else {
		(*T) = *(--S->top);
		return true;
	}
}

bool Push(SqStack* S, BiTree T) {
	if (S->top - S->top >= S->StackSize) {
		printf("Stack is full!\n");
		return false;
	}
	*(S->top++) = T;
	return true;
}

void FreeStack(SqStack* S) {
	if (S->base == NULL) {
		printf("memory allocation failure\n");
		exit(EXIT_SUCCESS);
	}
	free(S->base);
}