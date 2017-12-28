/*
 * printNodesAtLevelK.c
 *
 *      Author: Gayatri
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"

void printLevel(node_t *root, int k) {
	if(!root || k < 1)
		return;

	if(k == 1) {
		printf("%d ", root->val);
		return;
	}

	printLevel(root->left, k-1);
	printLevel(root->right, k-1);
}
