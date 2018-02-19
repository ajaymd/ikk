#include<bits/stdc++.h>

using namespace std;

const int MAX_CAPACITY = 100000, MAX_N = 100000, MAX_KEY = 100000, MAX_VAL = 100000;

// -------------------------- START --------------------------

class LRU_cache
{
	// Maximum size of the cache.
	int capacity;
	class ListNode
	{
	public:
		int key;
		int value;
		ListNode *prev;
		ListNode *next;

		ListNode(int _key = 0, int _value = 0)
		{
			key = _key;
			value = _value;
			prev = NULL;
			next = NULL;
		}
	};
	// Linked list whose nodes store {key, value}.
	ListNode *head = NULL, *tail = NULL;
	// key -> pointer to where it is stored in linked list.
	unordered_map<int, ListNode *> key_to_actual_storage_mapping;

public:

	// Constructor.
	LRU_cache(int _capacity)
	{
		capacity = _capacity;
	}

	/*
	Add {key, value} at the front of linked list. 
	Also add the mapping (key -> pointer to where it is stored in linked list).
	That is (key -> head of the linked list).
	*/
	void add_to_front(int key, int value)
	{
		ListNode *temp = new ListNode(key, value);
		// If linked list is empty, set head and tail.
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		key_to_actual_storage_mapping[key] = head;
	}

	/*
	Remove one {key, value} from the end of linked list.
	Also remove the mapping (key -> pointer to where it is stored in linked list).
	*/
	void remove_least_recently_used()
	{
		int key = tail->key;
		key_to_actual_storage_mapping.erase(key);
		// If only one node, set head and tail. 
		if (head == tail)
		{
			delete tail;
			head = tail = NULL;
			return;
		}
		// Set tail.
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
	}

	// Remove node from linked list.
	void erase_node(ListNode *cur_node)
	{
		ListNode *prev_node = cur_node->prev;
		ListNode *next_node = cur_node->next;
		// Connect previous node with next node.
		if (prev_node != NULL)
		{
			prev_node->next = next_node;
		}
		if (next_node != NULL)
		{
			next_node->prev = prev_node;
		}
		// If node to be removed is the only node in linked list, set head and tail.
		if (head == tail)
		{
			head = tail = NULL;
		}
		// If node to be removed is head, set head.
		else if (head == cur_node)
		{
			head = next_node;
		}
		// If node to be removed is tail, set tail.
		else if (tail == cur_node)
		{
			tail = prev_node;
		}
		delete cur_node;
	}

	// Return value of the key, if key is present, else return -1.
	int get(int key)
	{
		unordered_map<int, ListNode *>::iterator it = key_to_actual_storage_mapping.find(key);
		// If key is not present in mapping then return -1.
		if (it == key_to_actual_storage_mapping.end())
		{
			return -1;
		}
		// it->second points to node in the linked list.
		int value = it->second->value;
		// Remove from the original position.
		erase_node(it->second);
		// Add to the front.
		add_to_front(key, value);
		return value;
	}

	// If key is present in cache then updates its values, else add {key, value} pair in cache.
	void set(int key, int value)
	{
		unordered_map<int, ListNode*>::iterator it = key_to_actual_storage_mapping.find(key);
		// If key is not present in mapping then add {key, value} and setup the mapping.
		if (it == key_to_actual_storage_mapping.end())
		{
			// If cache is full then remove the least recently used {key, value}.
			if (key_to_actual_storage_mapping.size() == capacity)
			{
				remove_least_recently_used();
			}
			// Add to the front.
			add_to_front(key, value);
			return;
		}
		// Remove from the original position.
		erase_node(it->second);
		// Add to the front.
		add_to_front(key, value);
	}
};

vector<int> implement_LRU_cache(int capacity, vector<int> query_type, vector<int> key, 
	vector<int> value)
{
	int n = query_type.size();
	// Setup cache. 
	LRU_cache* cache = new LRU_cache(capacity);
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		if (query_type[i] == 0)
		{
			ans.push_back(cache->get(key[i]));
		}
		else
		{
			cache->set(key[i], value[i]);
		}
	}
	return ans;
}

// -------------------------- STOP ---------------------------

int main()
{
	clock_t start, end;
	start = clock();

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
		int capacity;
		cin >> capacity;
		assert(1 <= capacity);
		assert(capacity <= MAX_CAPACITY);

		int n;
		cin >> n;
		assert(1 <= n);
		assert(n <= MAX_N);
		vector<int> query_type(n);
		int no_of_get_queries = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> query_type[i];
			no_of_get_queries += (query_type[i] == 0);
			assert(query_type[i] == 0 || query_type[i] == 1);
		}

		int temp_n;
		cin >> temp_n;
		assert(n == temp_n);
		vector<int> key(n);
		for (int i = 0; i < n; i++)
		{
			cin >> key[i];
			assert(1 <= key[i]);
			assert(key[i] <= MAX_KEY);
		}

		cin >> temp_n;
		assert(n == temp_n);
		vector<int> value(n);
		for (int i = 0; i < n; i++)
		{
			cin >> value[i];
			assert(1 <= value[i]);
			assert(value[i] <= MAX_VAL);
		}

		vector<int> ans = implement_LRU_cache(capacity, query_type, key, value);
		int len = ans.size();
		assert(len == no_of_get_queries);
		for (int i = 0; i < len; i++)
		{
			cout << ans[i] << endl;
		}
		cout << endl;
	}

	end = clock();
    cout << ((double) (end - start)) / CLOCKS_PER_SEC << endl;

	return 0;
}