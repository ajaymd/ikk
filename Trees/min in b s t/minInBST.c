/*
 * minInBst.c
 *
 *      Author: Gayatri
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"

int minInBst(node_t *root) {
	if(!root)
		return INT_MAX;

	return min(root->val, minInBst(root->left));
}
