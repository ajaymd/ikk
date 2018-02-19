#include<bits/stdc++.h>

using namespace std;

const int MIN_N = 1, MAX_N = 100000, MIN_VAL = -2000000000, MAX_VAL = 2000000000;

class LinkedListNode
{
public:
	int val;
	LinkedListNode *next;

	LinkedListNode(int _val)
	{
		val = _val;
		next = NULL;
	}
};

LinkedListNode *insert_node_into_singly_linked_list(LinkedListNode *tail, int val)
{
	LinkedListNode *temp = new LinkedListNode(val);
	if (tail != NULL)
	{
		tail->next = temp;
	}
	return temp;
}

// -------------------------- START --------------------------

LinkedListNode *swap_nodes(LinkedListNode *head, int k)
{
	/*
	ptr1 will point to kth node from beginning and prev1 will point to its previous node.
	If ptr1 is head then prev1 will be NULL.
	*/
	LinkedListNode *prev1 = NULL;
	LinkedListNode *ptr1 = head;
	while(--k)
	{
		prev1 = ptr1;
		ptr1 = ptr1->next;
	}
	/*
	ptr2 will point to kth node from end and prev2 will point to its previous node.
	If ptr2 is head then prev2 will be NULL.

	If we set temp at kth node from beginning and ptr2 at head, 
	and we keep on increasing both till temp reaches last node,
	then ptr2 will be at the kth node from end.

	Let's understand why? - 
	When we started distance between ptr2 and temp is k - 1 links.
	We have incremented both temp and ptr2 same no of times, hence at the end also distance 
	between ptr2 and 
	temp will be k - 1 links. 
	Now temp is at last node hence ptr2 will be at kth node from end! 

	Try few examples to understand it clearly.  
	*/
	LinkedListNode *temp = ptr1;
	LinkedListNode *prev2 = NULL;
	LinkedListNode *ptr2 = head;
	while (temp->next)
	{
		temp = temp->next;
		prev2 = ptr2;
		ptr2 = ptr2->next;
	}
	if (prev1 != NULL)
	{
		// Link previous node of ptr1 to ptr2.
		prev1->next = ptr2;
	}
	else
	{
		// prev1 == NULL means ptr1 is head hence after swap, ptr2 will become head. 
		head = ptr2;
	}
	if (prev2 != NULL)
	{
		// Link previous node of ptr2 to ptr1.
		prev2->next = ptr1;
	}
	else
	{
		// prev2 == NULL means ptr2 is head hence after swap, ptr1 will become head.
		head = ptr1;
	}
	// Swap next pointers of ptr1 and ptr2.
	temp = ptr1->next;
	ptr1->next = ptr2->next;
	ptr2->next = temp;
	return head;
}

// -------------------------- STOP ---------------------------

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_small_test_cases_expected_output.txt", "w", stdout);
	freopen("..//test_cases//generated_big_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//generated_big_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	assert(test_cases >= 0);
	while (test_cases--)
	{
		int n;
		cin >> n;
		assert(MIN_N <= n);
		assert(n <= MAX_N);

		LinkedListNode *head = NULL, *tail = NULL;

		for (int i = 0; i < n; i++)
		{
			int val;
			cin >> val;
			assert(MIN_VAL <= val);
			assert(val <= MAX_VAL);

			tail = insert_node_into_singly_linked_list(tail, val);
			if (head == NULL)
			{
				head = tail;
			}
		}
		int k;
		cin >> k;
		assert(1 <= k);
		assert(k <= n);

		LinkedListNode *ans = swap_nodes(head, k);
		while (ans != NULL)
		{
			cout << ans->val << endl;
			ans = ans->next;
		}
		cout << endl;
	}

	return 0;
}
