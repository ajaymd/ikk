#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, MAX_NO = 2000000000;

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

LinkedListNode * insert_node_into_singly_linked_list(LinkedListNode * tail, int val)
{
	LinkedListNode *temp = new LinkedListNode(val);
	if (tail != NULL)
	{
		tail->next = temp;
	}
	return temp;
}

// -------------------------- START --------------------------

LinkedListNode* find_middle_node(LinkedListNode* head)
{
	LinkedListNode *slow_ptr = head;
	LinkedListNode *fast_ptr = head;
	while (fast_ptr && fast_ptr->next)
	{
		// Forward two steps.
		fast_ptr = fast_ptr->next->next;
		// Forward one step.
		slow_ptr = slow_ptr->next;
	}
	return slow_ptr;
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
	assert(test_cases > 0);
	while (test_cases--)
	{
		int n;
		cin >> n;
		assert(0 <= n);
		assert(n <= MAX_N);
		LinkedListNode *head = NULL;
		LinkedListNode *tail = NULL;
		for (int i = 0; i < n; i++)
		{
			int val;
			cin >> val;
			assert(-MAX_NO <= val);
			assert(val <= MAX_NO);
			tail = insert_node_into_singly_linked_list(tail, val);
			if (head == NULL)
			{
				head = tail;
			}
		}
		LinkedListNode *middle_node = find_middle_node(head);
		while (middle_node)
		{
			cout << middle_node->val << endl;
			middle_node = middle_node->next;
		}
		cout << endl;
	}

	return 0;
}