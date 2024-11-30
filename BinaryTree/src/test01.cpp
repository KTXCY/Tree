#include "BinaryTree.h"
#include "BiTreeSqStack.h"

int main() {
	BiNode* T;
	BiNode* S;

	const char* str = "ABC##DE#G##F###";
	int index = 0;
	PreCreateBiTree(&T, str, &index);

	printf("先序遍历二叉树：");
	PreOrderTraversal(T);
	printf("\n");

	printf("中序遍历二叉树：");
	InOrderTraversal(T);
	printf("\n");

	printf("后序遍历二叉树：");
	PostOrderTraversal(T);
	printf("\n");


	printf("Copy Binary Tree: ");
	CopyTree(T, &S);
	PreOrderTraversal(S);
	printf("\n");

	int D = Depth(T);
	printf("Tree Depth: %d\n", D);

	int N = NodeCount(T);
	printf("Tree NodeCount: %d\n", N);

	N = LeafCount(T);
	printf("Tree LeafCount: %d\n", N);

	printf("中序遍历二叉树：");
	InOrderTraversal(T);
	printf("\n");

	printf("中序遍历非递归：");
	InOrderTraverse(T);
	printf("\n");

	printf("层序遍历：");
	LevelOrder(T);
	printf("\n");

	FreeBiNode(&T);
	FreeBiNode(&S);

	

	return 0;
}