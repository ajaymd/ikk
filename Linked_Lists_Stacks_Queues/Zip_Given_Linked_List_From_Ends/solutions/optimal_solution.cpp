#include<bits/stdc++.h>

using namespace std;

const int MIN_N = 0, MAX_N = 100000, MIN_VAL = -2000000000, MAX_VAL = 2000000000;

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

// Reverse singly linked list in O(len) time and O(1) space. 
LinkedListNode *reverse_linked_list(LinkedListNode *cur)
{
	LinkedListNode *prev = NULL;
	LinkedListNode *next;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

LinkedListNode *zip_given_linked_list(LinkedListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	/*
	Using slow-fast technique find the middle element.
	If head: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL,
	then slow should stop at 3.
	*/ 
	LinkedListNode *slow = head;
	LinkedListNode *fast = head->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	/*
	Separate linked lists from middle. 
	list1: 1 -> 2 -> 3 -> NULL
	list2: 4 -> 5 -> 6 -> NULL
	*/
	LinkedListNode *list1 = head;
	LinkedListNode *list2 = slow->next;
	/*
	Till now:
	1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
	With list1 pointing to 1, list2 pointing to 4 and slow pointing to 3.

	Now break main linked list into two parts.
	So do 3->next = NULL.
	*/
	slow->next = NULL;
	/*
	From
	list2: 4 -> 5 -> 6 -> NULL
	to 
	list2: 6 -> 5 -> 4 -> NULL
	*/
	list2 = reverse_linked_list(list2);
	/*
	Instead of defining two new pointers next1 and next2, we can use previously defined slow and 
	fast to save memory, but for readability purpose we have used two new pointers.
	*/
	LinkedListNode *next1;
	LinkedListNode *next2;
	/*
	Merge list1 and list2.
	list1: 1 -> 2 -> 3 -> NULL
	list2: 6 -> 5 -> 4 -> NULL
	merged: 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> NULL
	*/
	while (list2)
	{
		next1 = list1->next;
		next2 = list2->next;
		list1->next = list2;
		list2->next=next1;
		list1 = next1;
		list2 = next2;
	}
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

		LinkedListNode *ans = zip_given_linked_list(head);
		while (ans != NULL)
		{
			cout << ans->val << endl;
			ans = ans->next;
		}
		cout << endl;
	}

	return 0;
}
