#include "BiTreeSqQueue.h"

void InitQueue(SqQueue* qu) {
	qu->front = qu->rear = 0;
}

bool QueueEmpty(SqQueue qu) {
	if (qu.front == qu.rear) {
		return  true;
	}
	else {
		return false;
	}
}

bool enQueue(SqQueue* qu, BiTree node) {
	if ((qu->rear + 1) % MAXSIZE == qu->front) {
		return false;
	}
	qu->data[qu->rear] = node;
	qu->rear = (qu->rear + 1) % MAXSIZE;
	return true;
}

bool deQueue(SqQueue* qu, BiTree*node) {
	if (qu->front == qu->rear) {
		return false;
	}
	*node = qu->data[qu->front];
	qu->front = (qu->front + 1) % MAXSIZE;
	return true;
}