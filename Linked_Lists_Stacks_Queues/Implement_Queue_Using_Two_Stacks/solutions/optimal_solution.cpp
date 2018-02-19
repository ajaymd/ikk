#include <bits/stdc++.h>

using namespace std;

class LinkedListNode {
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) 
    {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, 
	int val) 
{
    if(head == NULL) 
    {
        head = new LinkedListNode(val);
        tail = head;
    }
    else 
    {
        LinkedListNode *node = new LinkedListNode(val);
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

const int MAX_N = 100000, MAX_VAL = 2000000000;

/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/

void print_linked_list(LinkedListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "NULL" << endl;
}

//----------------------------------START------------------------------------

int dequeue(stack<int> &s1, stack<int> &s2)					
{
	// When both stacks are empty then return -1
	if (s1.empty() && s2.empty())							
	{
		return -1;
	}
	// When second stack is non empty then pop and return from it
	if (s2.empty() == false)								
	{
		int val = s2.top();
		s2.pop();
		return val;
	}
	// When second stack is empty then transfer all elements from first stack to second stack 
	while (s1.empty() == false)								
	{
		s2.push(s1.top());
		s1.pop();
	}
	// int val = s2.top(); s2.pop(); return val; will be the same. 
	return dequeue(s1, s2);									
}

// Always push in first stack
void enqueue(stack<int> &s, int val)						
{
	s.push(val);
}

LinkedListNode* implement_queue(LinkedListNode* operations) 
{
	stack<int> s1, s2;
	LinkedListNode *head = NULL;
	LinkedListNode *tail = NULL;
	while (operations != NULL)
	{
		if (operations->val >= 0)
		{
			enqueue(s1, operations->val);
		}
		else
		{
			tail = _insert_node_into_singlylinkedlist(head, tail, dequeue(s1, s2));
			if (head == NULL)
			{
				head = tail;
			}
		}
		operations = operations->next;
	}
	return head;
}

//----------------------------------STOP------------------------------------

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//small_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//big_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//big_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{

    LinkedListNode* res;
    int operations_size = 0;

    LinkedListNode* operations = NULL;
    LinkedListNode* operations_tail = NULL;

    cin >> operations_size;

    assert(1 <= operations_size);
    assert(operations_size <= MAX_N);

    int actual_dequeue = 0;

    for(int i = 0; i < operations_size; i++) {
        int operations_item;
        cin >> operations_item;

        assert(-1 <= operations_item);
        assert(operations_item <= MAX_VAL);

        if (operations_item == -1)
        {
        	actual_dequeue++;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        operations_tail = _insert_node_into_singlylinkedlist(operations, operations_tail, 
        	operations_item);

        if(i == 0) {
            operations = operations_tail;
        }
    }

    assert(1 <= actual_dequeue);

    //print_linked_list(operations);

    res = implement_queue(operations);

    //print_linked_list(res);

    int cur_dequeue = 0;

    while (res != NULL) {

    	assert(-1 <= res->val);
    	assert(res->val <= MAX_VAL);

    	cur_dequeue++;

        cout << res->val << endl;

        res = res->next;
    }
    cout << endl;

    assert(actual_dequeue == cur_dequeue);
	}

    return 0;
}