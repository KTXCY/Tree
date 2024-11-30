#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdBool.h>


typedef char TElemType;

typedef struct BiNode {
	TElemType data;
	struct BiNode* lchild, * rchild;
}BiNode, * BiTree;

// 先序构造二叉树
void PreCreateBiTree(BiTree*, const char*, int*);

// 先序遍历
void PreOrderTraversal(BiTree);

// 中序遍历
void InOrderTraversal(BiTree);

// 后序遍历
void PostOrderTraversal(BiTree);

// 拷贝二叉树
void CopyTree(BiTree, BiTree*);

// 计算二叉树的深度
int Depth(BiTree);

// 计算结点数
int NodeCount(BiTree);

// 计算叶子数
int LeafCount(BiTree);

// 释放结点
void FreeBiNode(BiTree*);

void InOrderTraverse(BiTree );