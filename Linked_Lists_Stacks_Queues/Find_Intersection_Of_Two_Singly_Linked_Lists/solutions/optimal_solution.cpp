#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct LinkedListNode LinkedListNode;

const int MAX_N = 100000, MAX_VALUE = 1000000000;

struct LinkedListNode 
{
    int val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, 
	int val) 
{
    if(head == NULL) 
    {
        head = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else 
    {
        LinkedListNode *node = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

/*
	----START----
*/

int get_size(LinkedListNode *head)
{
	int N = 0;
	while (head != NULL)
	{
		N++;
		head = head->next;
	}
	return N;
}

int find_intersection(LinkedListNode *l1, LinkedListNode *l2)
{
	// Size of first linked list.
	int N1 = get_size(l1);										
	// Size of second linked list.
	int N2 = get_size(l2);										
	while (N1 > N2)										
	{
		l1 = l1->next;
		N1--;
	}
	while (N2 > N1)										
	{
		l2 = l2->next;
		N2--;
	}
	// Comparing address.
	while (l1 != NULL && l1 != l2)								
	{
		l1 = l1->next;
		l2 = l2->next;
	}
	// If we have reached end.
	if (l1 == NULL)												
	{
		return -1;
	}
	// Intersection at node pointed by current value of l1.
	return l1->val;												
}

/*
	----STOP----
*/

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//handmade_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//small_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//big_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//igvaluere.txt", "w", stdout);

	int test_cases;
	scanf("%d", &test_cases);

	assert(0 <= test_cases);
	assert(test_cases <= 1000);

	while (test_cases--)
	{
	    int res;
	    int l1_size = 0;

	    LinkedListNode* l1 = NULL;
	    LinkedListNode* l1_tail = NULL;

	    scanf("%d\n", &l1_size);

	    assert(0 <= l1_size);
	    assert(l1_size <= MAX_N);

	    for(int i = 0; i < l1_size; i++) {
	        int l1_item;
	        scanf("%d", &l1_item);

	        assert(0 <= l1_item);
	        assert(l1_item <= MAX_VALUE);

	        l1_tail = _insert_node_into_singlylinkedlist(l1, l1_tail, l1_item);

	        if(i == 0) {
	            l1 = l1_tail;
	        }
	    }

	    int l2_size = 0;

	    LinkedListNode* l2 = NULL;
	    LinkedListNode* l2_tail = NULL;

	    scanf("%d\n", &l2_size);

	    assert(0 <= l2_size);
	    assert(l2_size <= MAX_N);

	    for(int i = 0; i < l2_size; i++) {
	        int l2_item;
	        scanf("%d", &l2_item);

	        assert(0 <= l2_item);
	        assert(l2_item <= MAX_VALUE);

	        l2_tail = _insert_node_into_singlylinkedlist(l2, l2_tail, l2_item);

	        if(i == 0) {
	            l2 = l2_tail;
	        }
	    }

	    //----added manually----

	    int merge_at;
	    scanf("%d\n", &merge_at);

	    assert(0 <= merge_at);
		assert(merge_at <= l1_size);
		assert(l1_size - merge_at + l2_size <= MAX_N);

	    LinkedListNode* l1_temp = l1;
	    for (int i = 0; i < merge_at; i++)
	    {
	        l1_temp = l1_temp->next;        
	    }
	    if (l2_tail == NULL)
	    {
	        l2 = l1_temp;
	    }
	    else
	    {
	        l2_tail->next = l1_temp;     
	    }

	    //--------

	    res = find_intersection(l1, l2);

	    printf("%d\n", res);
	}

    return 0;
}
