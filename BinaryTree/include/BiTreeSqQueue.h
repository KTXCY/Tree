#pragma once

#include "BiTreeSqStack.h"

typedef struct SqQueue {
    BiNode* data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

void InitQueue(SqQueue* qu);

bool QueueEmpty(SqQueue qu);

bool enQueue(SqQueue* qu, BiTree node);

bool deQueue(SqQueue* qu, BiTree* node);
