/*
 * findNext.c
 *
 *      Author: Gayatri
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"

//This is the O(n) method using in-order traversal
/*
int findNextInBST(node_t *root, int k) {
	int res = 0;

	if(!root)
		return INT_MIN;

	res = findNextInBST(root->left, k);
	if(res > k)
		return res;
	if(root->val > k)
		return root->val;
	res = findNextInBST(root->right, k);
	return res;
}
*/

//This is the O(log n) (average case) method using binary search
int curNext = INT_MAX;  // Current best candidate for next higher element to k
int findNextInBST(node_t *root, int k) {
	if(!root)
		return INT_MAX;

	if(root->val > k && root->val < curNext) {
		curNext = root->val;
	}

	if(k < root->val) {
		curNext = min(findNextInBST(root->left, k), curNext);
	} else {
		curNext = min(findNextInBST(root->right, k), curNext);
	}

	return curNext;
}
