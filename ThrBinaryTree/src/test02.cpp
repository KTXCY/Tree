#include "ThrBinaryTree.h"

int main() {
	ThrBiNode* Thr;
	const char* str = "ABD##EH##IJ##K##CF##G##";
	int index = 0;
	PreCreateThrBiTree(&Thr, str, &index);
	PreOrderThrBiTree(Thr);
	return 0;
}