//#include<stdio.h>
//#include<stdlib.h>

#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, MAX_VALUE = 1000000000;

struct node
{
	int value;
	struct node *next;
};

struct node * merge(struct node *L1, int merge_at_position)			// consider L1 in range [0, N1] where L1[N1] will be NULL. Now to create test case we merge L2's tail to L1's merge_at_position (0-indexed), so when merge_at_position = N1 then they are not intersecting (L1[N1] = NULL).
{
	int cur_pos = 0;
	while (cur_pos < merge_at_position)
	{
		L1 = L1->next;
		cur_pos++;
	}
	return L1;
}

struct node * insert(struct node * tail, int value)						// Insert new node at the end with given value. 
{
	if (tail == NULL)										// When linked list is empty 
	{
		tail = (struct node *) malloc(sizeof(struct node));
	}
	else
	{
		tail->next = (struct node *) malloc(sizeof(struct node));
		tail = tail->next;	
	}
	tail->value = value;
	tail->next = NULL;
	return tail;
}

void print_linked_list(struct node *head)
{
	while (head != NULL)
	{
		cout << head->value << " -> ";
		head = head->next;
	}
	cout << "NULL" << endl;
}

int get_size(struct node *head)
{
	int N = 0;
	while (head != NULL)
	{
		N++;
		head = head->next;
	}
	return N;
}

int find_intersection(struct node *L1, struct node *L2)
{
	int N1 = get_size(L1);									// Size of first linked list
	int N2 = get_size(L2);									// Size of second linked list
	if (N1 < N2)											// For simplicty
	{
		struct node *temp = L1;
		L1 = L2;
		L2 = temp;
	}
	if (N1 < N2)
	{
		int temp = N1;
		N1 = N2;
		N2 = temp;
	}		
	while (N1 > N2)										
	{
		L1 = L1->next;
		N1--;
	}
	while (L1 != NULL && L1 != L2)								// Comparing address 
	{
		L1 = L1->next;
		L2 = L2->next;
	}
	if (L1 == NULL)												// If we have reached end 
	{
		return -1;
	}
	return L1->value;											// Intersection at node pointed by current value of L1 
}

int main()
{
	freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//sample_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//small_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//big_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//igvaluere.txt", "w", stdout);

	int test_cases;
	scanf("%d", &test_cases);
	while (test_cases--)
	{
		int N1;
		scanf("%d", &N1);
		assert(0 <= N1);
		assert(N1 <= MAX_N);

		struct node *L1 = NULL;
		struct node *tail_1 = NULL;
		
		int i;
		for (i = 0; i < N1; i++)
		{
			int value;
			scanf("%d", &value);
			assert(0 <= value);
			assert(value <= MAX_VALUE);

			tail_1 = insert(tail_1, value);								
			if (L1 == NULL)											// First insert
			{
				L1 = tail_1;
			}
		}

		int N2;
		scanf("%d", &N2);
		assert(0 <= N2);
		assert(N2 <= MAX_N);
		
		struct node *L2 = NULL;
		struct node *tail_2 = NULL;
		
		for (i = 0; i < N2; i++)
		{
			int value;
			scanf("%d", &value);
			assert(0 <= value);
			assert(value <= MAX_VALUE);
			tail_2 = insert(tail_2, value);
			if (L2 == NULL)											// First insert
			{
				L2 = tail_2;
			}
		}

		int merge_at_position;										// 0 - indexed
		scanf("%d", &merge_at_position);
		assert(0 <= merge_at_position);
		assert(merge_at_position <= N1);
		assert(N1 - merge_at_position + N2 <= MAX_N);				// After merge second linked list should not be of size > MAX_N
		if (L2 == NULL)												// When second linked list is empty
		{
			L2 = merge(L1, merge_at_position); 
		}
		else
		{
			tail_2->next = merge(L1, merge_at_position);
		}

		//print_linked_list(L1);
		//print_linked_list(L2);

		int ans = find_intersection(L1, L2);

		assert(-1 <= ans);
		assert(ans <= MAX_VALUE);
		printf("%d\n", ans);
	}
	return 0;
}