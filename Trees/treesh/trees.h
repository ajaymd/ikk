/*
 * trees.h
 *
 *      Author: Gayatri
 */

#ifndef TREES_H_
#define TREES_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
	int val;
	struct node_s *left;
	struct node_s *right;
} node_t;

int min(int a, int b);
node_t *createNewNode(int val);
bool isIdentical(node_t *root1, node_t *root2);
void dfsRec(node_t *root);
void dfsIter(node_t *root);
void bfsIter(node_t *root);
void printLevel(node_t *root, int k);
node_t *bstInsert(node_t *root, int val);
int minInBst(node_t *root);
int findNextInBST(node_t *root, int k);

#endif /* TREES_H_ */
