/*
 * dfsRecursive.c
 *
 *      Author: Gayatri
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"

void dfsRec(node_t *root) {
	if(!root)
		return;

	printf("%d ", root->val);
	dfsRec(root->left);
	dfsRec(root->right);
}
