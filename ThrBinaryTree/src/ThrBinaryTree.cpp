#include "ThrBinaryTree.h"

static ThrBiNode* GetNewNode(ThrElemType data) {
	ThrBiNode* NewNode = (ThrBiNode*)malloc(sizeof(ThrBiNode));
	if (NewNode == NULL) {
		fprintf(stderr, "Memory allocation error");
		exit(EXIT_FAILURE);
	}
	NewNode->data = data;
	NewNode->lchild = NewNode->rchild = NULL;
	NewNode->l_tag = NewNode->r_tag = 0;
	return NewNode;
}


void PreCreateThrBiTree(ThrBiTree* Thr, const char* str,  int* index) {
	if (str[*index] == '#' || *index >= strlen(str)) {
		(*index)++;
		*Thr = NULL;
		return;
	}
	else {
		*Thr = GetNewNode(str[(*index)++]);
		PreCreateThrBiTree(&(*Thr)->lchild, str, index);
		PreCreateThrBiTree(&(*Thr)->rchild, str, index);
	}
}

void PreOrderThrBiTree(const ThrBiTree Thr) {
	if (Thr == NULL) {
		return;
	}
	else {
		printf("%c ", Thr->data);
		PreOrderThrBiTree(Thr->lchild);
		PreOrderThrBiTree(Thr->rchild);
	}
}