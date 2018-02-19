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

// Reverse singly linked list in O(len) time and O(1) space. 
void reverse_linked_list(LinkedListNode *cur)
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
}

LinkedListNode *reverse_linked_list_in_groups_of_k(LinkedListNode *head, int k)
{
	/*
	Input:
	list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
	k: 3
	Output:
	3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 8 -> 7-> NULL
	Groups to be reversed are (1 -> 2 -> 3), (4 -> 5 -> 6) and (7 -> 8).

	We will call reverse_linked_list function when (start = 1 and stop = 2),
	(start = 4 and stop = 6) and (start = 7 and stop = 8). 
	*/
	// Points to previous node of start. When start = head, prev_of_start = NULL.
	LinkedListNode *prev_of_start = NULL;
	LinkedListNode *start = head;
	LinkedListNode *stop = head;
	int count = 0;
	// Traverse whole linked list.
	while (stop)
	{
		count++;
		/*
		If we have covered k nodes in between start and stop (inclusive) or we are at the last 
		node.
		*/
		if (count == k || stop->next == NULL)
		{
			// Points to next node of start. 
			LinkedListNode *next_of_stop = stop->next;
			/*
			We want to reverse start to stop nodes, set stop->next = NULL so we know where to 
			stop.
			*/
			stop->next = NULL;
			// Reverse start to stop nodes. 
			reverse_linked_list(start);
			if (prev_of_start == NULL)
			{
				// Head will change when we are reversing the linked list first time. 
				head = stop;
			}
			else
			{
				/*
				We have reversed start to stop nodes, hence now stop will be next node of 
				prev_of_start. 
				*/
				prev_of_start->next = stop;
			}
			/*
			We have reversed start to stop nodes, hence next_of_stop will be next node of start. 
			*/
			start->next = next_of_stop;
			/*
			In the above example, after we have reversed first k nodes list will be:
			3 -> 2 -> 1 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL,
			start will point to 1, next_of_stop will point to 4.
			
			Now we will set start and stop to point at 4.
			And prev_of_start should be previous of 4 that is 1.
			*/
			prev_of_start = start;
			start = next_of_stop;
			stop = next_of_stop;
			// Reset counter. 
			count = 0;
		}
		else
		{
			// Go to next node. 
			stop = stop->next;
		}
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
		int k;
		cin >> k;
		assert(1 <= k);
		assert(k <= n);

		LinkedListNode *ans = reverse_linked_list_in_groups_of_k(head, k);
		while (ans != NULL)
		{
			cout << ans->val << endl;
			ans = ans->next;
		}
		cout << endl;
	}

	return 0;
}
