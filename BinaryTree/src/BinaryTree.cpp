#include "BinaryTree.h"
#include "BiTreeSqStack.h"
#include "BiTreeSqQueue.h"
static BiNode* GetNewNode(TElemType data) {
	BiNode* NewNode = (BiNode*)malloc(sizeof(BiNode));
	if (NewNode == NULL) {
		fprintf(stderr, "Memory allocation error");
		exit(EXIT_FAILURE);
	}
	NewNode->data = data;
	NewNode->lchild = NewNode->rchild = NULL;
	return NewNode;
}

// 先序构造二叉树
void PreCreateBiTree(BiTree* T, const char* str, int* index) {
	if (str[*index] == '#' || *index >= strlen(str)) {
		(*index)++;
		*T = NULL;
		return;
	}
	else {
		(*T) = GetNewNode(str[(*index)++]);
		PreCreateBiTree(&(*T)->lchild, str, index);
		PreCreateBiTree(&(*T)->rchild, str, index);
	}
}

// 先序遍历
void PreOrderTraversal(BiTree T) {
	if (T == NULL) {
		return;
	}
	else {
		printf("%c ", T->data);
		PreOrderTraversal(T->lchild);
		PreOrderTraversal(T->rchild);
	}
}

// 中序遍历
void InOrderTraversal(BiTree T) {
	if (T == NULL) {
		return;
	}
	else {
		InOrderTraversal(T->lchild);
		printf("%c ", T->data);
		InOrderTraversal(T->rchild);
	}
}

// 后序遍历
void PostOrderTraversal(BiTree T) {
	if (T == NULL) {
		return;
	}
	else {
		PostOrderTraversal(T->lchild);
		PostOrderTraversal(T->rchild);
		printf("%c ", T->data);
	}
}

// 拷贝二叉树
void CopyTree(BiTree T, BiTree* NewT) {
	if (T == NULL) {
		*NewT = NULL;
		return;
	}
	else {
		(*NewT) = GetNewNode(T->data);
		CopyTree(T->lchild, &(*NewT)->lchild);
		CopyTree(T->rchild, &(*NewT)->rchild);
	}
}

// 计算二叉树的深度
int Depth(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	else {
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m > n) {
			return (m + 1);
		}
		else {
			return (n + 1);
		}
	}
}

// 计算结点数
int NodeCount(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	else {
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

// 计算叶子数
int LeafCount(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	if (T->lchild == NULL && T->rchild == NULL) {
		return 1;
	}
	else {
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

// 释放结点
void FreeBiNode(BiTree* T) {
	if (*T == NULL) {
		return;
	}
	else {
		FreeBiNode(&(*T)->lchild);
		FreeBiNode(&(*T)->rchild);
		free(*T);
		(*T) = NULL;
	}
}

// 非递归中序遍历
void InOrderTraverse(BiTree T) {
	SqStack S;
	InitStack(&S);
	BiNode* p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(&S, p);
			p = p->lchild;
			BiNode* q;
			Pop(&S, &q);
			printf("%c ", q->data);
			p = q->rchild;
		}
	}
	FreeStack(&S);
}

// 层序遍历 
void LevelOrder(BiTree T) {
	SqQueue qu;
	InitQueue(&qu);
	if (T == NULL) {
		return;
	}
	enQueue(&qu, T);
	while (!QueueEmpty(qu)) {
		BiNode* p;
		deQueue(&qu, &p);
		printf("%c ", p->data);
		if (p->lchild != NULL) {
			enQueue(&qu, p->lchild);
		}
		if (p->rchild != NULL) {
			enQueue(&qu, p->rchild);
		}
	}
}