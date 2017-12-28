/*
 * isIdentical.c
 *
 *      Author: Gayatri
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"

bool isIdentical(node_t *root1, node_t *root2) {
	if(!root1 && !root2)
		return true;

	if(root1 && root2 && root1->val == root2->val) {
		return (isIdentical(root1->left, root2->left) &&
				isIdentical(root1->right, root2->right));
	}

	return false;
}
