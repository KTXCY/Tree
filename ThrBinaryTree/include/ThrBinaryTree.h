#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdBool.h>

typedef char ThrElemType;

typedef struct ThrBiNode {
	ThrElemType data;
	struct ThrBiNode* lchild, * rchild;
	unsigned short l_tag, r_tag;
}ThrBiNode, * ThrBiTree;

void PreCreateThrBiTree(ThrBiTree*, const char*,  int*);

void PreOrderThrBiTree(const ThrBiTree);
