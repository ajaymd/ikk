/*
 * bfsIterative.c
 *
 *      Author: Gayatri
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"
#include "queue.h"

void bfsIter(node_t *root) {
	queue_t *q = createNewQueue();
	node_t *next = NULL;

	enqueue(&(q->front), &(q->back), (void *)root);

	while((next = (node_t *)dequeue(&(q->front), &(q->back))) != NULL) {
		printf("%d ", next->val);
		if(next->left) {
			enqueue(&(q->front), &(q->back), (void *)next->left);
		}
		if(next->right) {
			enqueue(&(q->front), &(q->back), (void *)next->right);
		}
	}
}
