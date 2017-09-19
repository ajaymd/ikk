#include <bits/stdc++.h>

using namespace std;
class LinkedListNode {
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
    if(head == NULL) {
        head = new LinkedListNode(val);
        tail = head;
    }
    else {
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

void print_linked_list(LinkedListNode* ptr)
{
	while (ptr != NULL)
	{
		cout << ptr->val << " -> ";
		ptr = ptr->next;
	}
	cout << "NULL" << endl;
}

//---------------------------------------START----------------------------------------

LinkedListNode* find_head_and_size(LinkedListNode* ptr, int *N)		// N is pointer 
{
	LinkedListNode *head = ptr;										// We are given sorted linked list, hence head will be first occurence of the smallest value 
	LinkedListNode *cur = ptr;
	cur = cur->next;
	while (cur != ptr)												// Start from given ptr and find the first occurence of the smallest element 
	{
		*N = *N + 1;												// Also find the size of the linked list
		if (cur->val < head->val)
		{
			head = cur;
		}
		cur = cur->next;
	}
	return head;
}

int find_median(LinkedListNode* ptr) 
{
	int N = 1;
	LinkedListNode *head = find_head_and_size(ptr, &N);
	for (int i = 0; i < (N - 1) / 2; i++)							// Exact middle element in case of odd N and middle left element in case of even N.
	{
		head = head->next;
	}
	if (N % 2)
	{
		return head->val;
	}
	return ((long long int)head->val + (long long int)head->next->val) / 2LL;		// Look at the constraints, do not forget to use long long int otherwise wrong answer due to overflow. Test cases are carefully chosen to overflow this. 
}

//---------------------------------------STOP--------------------------------------

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

    //ofstream fout(getenv("OUTPUT_PATH"));

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{

    int res;
    int ptr_size = 0;

    LinkedListNode* ptr = NULL;
    LinkedListNode* ptr_tail = NULL;

    cin >> ptr_size;

    assert(1 <= ptr_size);
    assert(ptr_size <= MAX_N);

    int last_ptr_item = -MAX_VAL;

    for(int i = 0; i < ptr_size; i++) {
        int ptr_item;
        cin >> ptr_item;
        
        assert(last_ptr_item <= ptr_item);
        last_ptr_item = ptr_item;

        assert(-MAX_VAL <= ptr_item);
        assert(ptr_item <= MAX_VAL);
        assert(ptr_item % 2 == 0);
        
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ptr_tail = _insert_node_into_singlylinkedlist(ptr, ptr_tail, ptr_item);

        if(i == 0) {
            ptr = ptr_tail;
        }
    }

    //print_linked_list(ptr);

   	ptr_tail->next = ptr;															// Till now it was linear, now join tail to head and make it circular.
   	srand(time(NULL));
   	int arbitary_shift = rand() % ptr_size;											// We need to give arbitrary node. 
   	while (arbitary_shift--)
   	{
   		ptr = ptr->next;
   	}


    //cout << ptr->val << endl;
    res = find_median(ptr);
    
    assert(-MAX_VAL <= res);
    assert(res <= MAX_VAL);
    
    cout << res << endl;


    //fout << res << endl;

    //fout.close();

	}
    return 0;
}