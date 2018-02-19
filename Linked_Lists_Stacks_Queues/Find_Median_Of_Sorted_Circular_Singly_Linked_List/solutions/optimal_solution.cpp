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

/*
	----START----
*/

LinkedListNode* find_first_big(LinkedListNode* ptr)
{
    if (ptr->val < ptr->next->val)
    {
        return ptr->next;
    }
    LinkedListNode* cur = ptr->next;
    while (cur != ptr)
    {
        if (cur->val < cur->next->val)
        {
            return cur->next;
        }
        cur = cur->next;
    }
    assert(false);
    return NULL;
}

bool is_non_decreasing(LinkedListNode* head)
{
    LinkedListNode* cur = head;
    while (cur->next != head)
    {
        if (cur->val > cur->next->val)
        {
            return false;
        }
        cur = cur->next;
    }
    return true;
}

LinkedListNode* find_first_small(LinkedListNode* ptr)
{
    if (ptr->val > ptr->next->val)
    {
        return ptr->next;
    }
    LinkedListNode* cur = ptr->next;
    while (cur != ptr)
    {
        if (cur->val > cur->next->val)
        {
            return cur->next;
        }
        cur = cur->next;
    }
    return NULL;
}

// Finds size of the linked list
int find_size(LinkedListNode* ptr)                                                  
{
    int N = 1;
    LinkedListNode *cur = ptr->next;
    while (cur != ptr)
    {
        N++;
        cur = cur->next;
    }
    return N;
}

int find_median(LinkedListNode* ptr) 
{
    /*
        Linked list will be one of these 3 types
        1) (2 -> 2 -> 2 -> 2 -> 2 -> 2)
        2) (2 -> 2 -> 4 -> 6 -> 8 -> 8)
        3) (8 -> 8 -> 4 -> 6 -> 2 -> 2)

        Now first case is trivial.

        In 2nd case if we can find first smallest element (call it head) then finding median will 
        be trivial. Just find middle element/elements.
        // (2 -> 2 -> 4 -> 6 -> 8 -> 8) then head will be ([2]head -> 2 -> 4 -> 6 -> 8 -> 8)
    
        In 3rd case if we can find first largest element (call it head) then finding median will 
        be trivial. Just find middle element/elements.
        // (8 -> 8 -> 4 -> 6 -> 2 -> 2) then head will be ([8]head -> 8 -> 4 -> 6 -> 2 -> 2)

    */

	int N = find_size(ptr);
    /*
    We do not know if given linked list is non-increasing or non-decreasing. If it is 
    non_decreasing (2->4->6->8) then there will be <= 1 pair big->small (8->2). If it is 
    non_increasing (8->6->4->2) then there will be many pair big->small (8->6, 6->4, 4->2). When 
    both non-increasing and non-decreasing (2->2->2) then there will be no small->big. This 
    function returns pointer to small. For non-decreasing case it will be unique. For 
    (2 -> 2 -> 2) it will be NULL. For non-increasing it will be any one of the valid pairs. 
    */
    LinkedListNode *first_small = find_first_small(ptr);                        

    // When all elements are same (2->2->2) then return any element.
    if (first_small == NULL)                                                    
    {
        return ptr->val;
    }

    LinkedListNode *head = NULL;
    /*
    Take pointer to small that we got previously, as head and check if linked list is 
    non-decreasing or not.
    */
    if (is_non_decreasing(first_small))                                         
    {
        // If it is non-decreasing then we have found our head
        head = first_small;                                                     
    }
    else
    {
        // Non-increasing                                                                           
        head = find_first_big(ptr);
    }

    // Till now we have found our head.     

    // Exact middle element in case of odd N and middle left element in case of even N.
	for (int i = 0; i < (N - 1) / 2; i++)							           
	{
		head = head->next;
	}
	if (N % 2)
	{
		return head->val;
	}
    /*
    Look at the constraints, do not forget to use long long int otherwise wrong answer due to 
    overflow. Test cases are carefully chosen to overflow this. 
    */
	return ((long long int)head->val + (long long int)head->next->val) / 2LL;	
}

/*
	----STOP----
*/

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

	    vector<int> nos(ptr_size);

	    for(int i = 0; i < ptr_size; i++) {
	        int ptr_item;
	        cin >> ptr_item;

	        nos[i] = ptr_item;

	        assert(-MAX_VAL <= ptr_item);
	        assert(ptr_item <= MAX_VAL);
	        assert(ptr_item % 2 == 0);
	        
	        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        ptr_tail = _insert_node_into_singlylinkedlist(ptr, ptr_tail, ptr_item);

	        if(i == 0) {
	            ptr = ptr_tail;
	        }
	    }

        // This section makes sure that input is either in non-increasing or non-decreasing order
	    vector<int> sorted_nos = nos;                                               
	    sort(sorted_nos.begin(), sorted_nos.end());
	    if (nos[0] == sorted_nos[0])
	    {
	        for (int i = 0; i < ptr_size; i++)
	        {
	            assert(nos[i] == sorted_nos[i]);
	        }
	    }
	    else
	    {
	        for (int i = 0; i < ptr_size; i++)
	        {
	            assert(nos[ptr_size - 1 - i] == sorted_nos[i]);
	        }
	    }

	    //----added manually----
        // Till now it was linear, now join tail to head and make it circular. 
	   	ptr_tail->next = ptr;															
	    /*
        Now we have got circular linked list but ptr will be the first element, but we need to 
        give arbitrary node. 
        */
	    // Value of arbitrary_shift will be [0, ptr_size). 
	   	int arbitrary_shift;                 											 
	    cin >> arbitrary_shift;
	   	while (arbitrary_shift--)
	   	{
	   		ptr = ptr->next;
	   	}
	   	//--------

	    res = find_median(ptr);
	    
	    assert(-MAX_VAL <= res);
	    assert(res <= MAX_VAL);
	    
	    cout << res << endl;
	}
    return 0;
}