#include<bits/stdc++.h>

using namespace std;

const int MAX_CAPACITY = 100000, MAX_N = 100000, MAX_KEY = 100000, MAX_VAL = 100000;

// -------------------------- START --------------------------

class LRU_cache
{
	// Maximum size of the cache.
	int capacity = 0;
	int time_stamp = 0;
	// Heap storing {time_stamp, key} pairs.
	vector<pair<int, int>> lru_heap;
	// Hash map storing {key, {time_stamp, value}} pairs.
	unordered_map<int, pair<int, int>> cache;

public:
	
	// Constructor.
	LRU_cache(int _capacity) 
	{
		capacity = _capacity;
	}

	// Return value of the key, if key is present, else return -1.
	int get(int key) 
	{
		// If the key is already present.
		if(cache.find(key) != cache.end()) 
		{
			// Update the timestamp in the hash map to current timestamp.
			cache[key].first = time_stamp--;
			return cache[key].second;
		} 
		else 
		{
			return -1;
		}
	}

	// If key is present in cache then updates its values, else add {key, value} pair in cache.
	void set(int key, int value) 
	{
		// Take care of the case where key is already in the cache.
		if(cache.find(key)!=cache.end()) 
		{
	  		cache[key]={time_stamp--, value};
	  		return;
		}
		// Remove least recently used element if cache is full.
		if(lru_heap.size() == capacity)
		{
			// Loop till we have removed one element from cache.
		  	while(true) 
		  	{
			    // Remove from heap. Removed element will be at the back of vector.
			    pop_heap(lru_heap.begin(), lru_heap.end());
			    // Get the removed element from back.
			    auto& top = lru_heap.back();
			    // Check timestamp in hash map.
			    if(cache[top.second].first == top.first) 
			    {
			    	/*
				    Element has same time stamp in heap and hash map hence we have found the 
				    element to be removed.
				    */
				    // Remove it from hash map.
				    cache.erase(top.second);
				    // Remove from heap.
				    lru_heap.pop_back();
				    break;
			    }
			    else 
			    {
			    	// This key was updated, hence push it back in heap with updated time stamp.
			    	top.first = cache[top.second].first;
			    	push_heap(lru_heap.begin(), lru_heap.end());
			    }
		  	}
		}
		// Add the new key into hash map and heap with the appropriate timestamp.
		cache[key] = {time_stamp, value};
		lru_heap.push_back({time_stamp, key});
		push_heap(lru_heap.begin(), lru_heap.end());
		time_stamp--;
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