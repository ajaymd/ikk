#include<bits/stdc++.h>

using namespace std;

//--------------------------------START------------------------------------

const int MAX_N = 100000;

vector<vector<int>> kary(MAX_N + 1);

int find_max_height(int root)
{
	// Handle base case when root is a leaf node.
	if (kary[root].size() == 0)									
	{
		return 0;
	}
	int h = 0;
	for (int i = 0; i < kary[root].size(); i++)
	{
		// Find height of each children and store the maximum height of children. 
		h = max(h, find_max_height(kary[root][i]));				
	}
	return h + 1;			
}

int find_height(int k, vector<int> from, vector<int> to)
{
	int edges = from.size();
	for (int i = 1; i <= edges + 1; i++)
	{
		// Just clear the global variable. 
		kary[i].clear();										
	}
	/*
	It is not a good idea to iterate over from array for each node, hence we iterate over from 
	array once and store children of each node separately in kary[node].  
	*/
	for (int i = 0; i < edges; i++)								
	{
		// Array kary[node] will store all the children of node. 
		kary[from[i]].push_back(to[i]);							
		// Ignore this. This is just for validation of input.
		assert(kary[from[i]].size() <= k);						
	}
	/*
	Till now we have separated and stored children of each node in kary[node] array. Now we can 
	do dfs and find the height of the tree. 
	*/
	return find_max_height(1);									
}

//--------------------------------STOP------------------------------------

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
		int k;
		cin >> k;

		int edges;
		cin >> edges;
		
		int N = edges + 1;
		assert(1 <= N);
		assert(N <= MAX_N);
		assert(0 <= k);
		assert(k <= N - 1);
		
		vector<int> from(edges, 0);
		for (int i = 0; i < edges; i++)
		{
			cin >> from[i];
			assert(1 <= from[i]);
			assert(from[i] <= N);
		}
		
		cin >> edges;
		assert(edges == N - 1);
		
		vector<int> to(edges, 0);
		for (int i = 0; i < edges; i++)
		{
			cin >> to[i];
			assert(1 <= to[i]);
			assert(to[i] <= N);
		}

		unordered_map<int, int> no_of_in_edges;
		for (int i = 0; i < edges; i++)
		{
			no_of_in_edges[to[i]]++;
		} 
		assert(no_of_in_edges.size() == N - 1);

		for (auto it = no_of_in_edges.begin(); it != no_of_in_edges.end(); it++)
		{
			assert(it->second == 1);
		}

		int h = find_height(k, from, to);
		assert(0 <= h);
		assert(h <= N - 1);
		cout << h << endl;
	}

	return 0;
}