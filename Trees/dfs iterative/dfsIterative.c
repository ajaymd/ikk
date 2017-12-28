/*
 * dfsIterative.c
 *
 *      Author: Gayatri
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"
#include "stack.h"

void dfsIter(node_t *root) {
	stck_t *s = createNewStack();
	node_t *next = NULL;

	s->top = push(s->top, (void *)root);

	while((next = (node_t *)pop(&(s->top))) != NULL) {
		printf("%d ", next->val);
		if(next->right) {
			s->top = push(s->top, next->right);
		}
		if(next->left) {
			s->top = push(s->top, next->left);
		}
	}
}
