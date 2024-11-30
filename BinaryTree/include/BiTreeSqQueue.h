#pragma once
#include "BiTreeSqStack.h"

typedef struct SqQueue {
	BiNode* data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue* );

bool QueueEmpty(SqQueue );

bool enQueue(SqQueue*, BiTree);

bool deQueue(SqQueue* , BiTree*);
