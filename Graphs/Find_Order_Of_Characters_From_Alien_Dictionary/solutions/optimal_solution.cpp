#include<bits/stdc++.h>

using namespace std;

int MAX_CHARS = 100000;

// ---- START ----
/*
Note that we are passing adj_list, topological_order and visited by reference. Either use pass by 
reference or use global variables. 
*/
void dfs(char from, unordered_map<char, vector<char>> &adj_list, 
	string &topological_order, unordered_set<char> &visited)
{	
	visited.insert(from);
	for (auto it = adj_list[from].begin(); it != adj_list[from].end(); it++)
	{
		if (visited.find(*it) == visited.end())
		{
			dfs(*it, adj_list, topological_order, visited);
		}
	}
	topological_order = from + topological_order;
}

// Topological sort. 
string topological_sort(unordered_map<char, vector<char>> &adj_list)
{
	string topological_order = "";
	unordered_set<char> visited;
	for (auto it = adj_list.begin(); it != adj_list.end(); it++)
	{
		// If current node is not visited then visit it and visit nodes reachable from that node. 
		if (visited.find(it->first) == visited.end())
		{
			dfs(it->first, adj_list, topological_order, visited);
		}
	}
	return topological_order;
}

string find_order(vector<string> words)
{
	int n = words.size();
	// Contains adjacent nodes. 
	unordered_map<char, vector<char>> adj_list;
	
	/*
	Initialize nodes with no edges. This is imp. Otherwise testcases having only one type of 
	character will fail.
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < words[i].length(); j++)
		{
			adj_list[words[i][j]] = vector<char>(0);
		}
	}

	// Find mismatch and add edges. 
	for (int i = 0; i < n - 1; i++)
	{
		int min_len = min(words[i].length(), words[i + 1].length());
		for (int j = 0; j < min_len; j++)
		{
			if (words[i][j] != words[i + 1][j])
			{
				adj_list[words[i][j]].push_back(words[i + 1][j]);
				break;
			}
		}
	}

	return topological_sort(adj_list);
}

// ---- STOP ----

void make_sure_unique_ordering_possible_dfs(
	char from, 
	unordered_map<char, vector<char>> &adj_list, 
	string &topological_order, 
	unordered_set<char> &visited, 
	unordered_set<char> &active
)
{
	visited.insert(from);
	active.insert(from);
	for (auto it = adj_list[from].begin(); it != adj_list[from].end(); it++)
	{
		// If active then it contains a cycle. 
		assert(active.find(*it) == active.end());
		if (visited.find(*it) == visited.end())
		{
			make_sure_unique_ordering_possible_dfs(*it, adj_list, topological_order, visited, 
				active);
		}
	}
	active.erase(from);
	topological_order = from + topological_order;
}

void make_sure_unique_ordering_possible_topological_sort(unordered_map<char, 
	vector<char>> &adj_list, unordered_set<char> &diff_chars)
{
	string topological_order = "";
	unordered_set<char> visited;
	unordered_set<char> active;
	for (auto it = adj_list.begin(); it != adj_list.end(); it++)
	{
		if (visited.find(it->first) == visited.end())
		{
			make_sure_unique_ordering_possible_dfs(it->first, adj_list, topological_order, 
				visited, active);
		}
	}

	/*
	If we want to get order uniquely then from starting node, each node will be at unique distance
	(0, 1, ..., n - 1). It is not possible that two nodes are at same distance, because if it is 
	the case then we can change their order in output (not unique)! 
	*/
	unordered_map<char, int> dist;

	dist[topological_order[0]] = 0;
	for (int i = 0; i < topological_order.length(); i++)
	{
		for (auto it = adj_list[topological_order[i]].begin(); 
			it != adj_list[topological_order[i]].end(); it++)
		{
			dist[*it] = dist[topological_order[i]] + 1;
		}
	}

	unordered_set<int> diff_dists;
	for (auto it = dist.begin(); it != dist.end(); it++)
	{
		diff_dists.insert(it->second);
	}
	assert(diff_dists.size() == diff_chars.size());
}

void make_sure_unique_ordering_possible(vector <string> &words, unordered_set<char> &diff_chars)
{
	int n = words.size(); 
	unordered_set<char> has_in_edge;
	unordered_set<char> has_out_edge;
	unordered_map<char, vector<char>> adj_list;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < words[i].length(); j++)
		{
			adj_list[words[i][j]] = vector<char>(0);
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		int min_len = min(words[i].length(), words[i + 1].length());
		for (int j = 0; j < min_len; j++)
		{
			if (words[i][j] != words[i + 1][j])
			{
				has_out_edge.insert(words[i][j]);
				has_in_edge.insert(words[i + 1][j]);
				adj_list[words[i][j]].push_back(words[i + 1][j]);
				break;
			}
		}
	}

	// There should be exactly one node with no input edges.
	assert(has_out_edge.size() == diff_chars.size() - 1);
	// There should be exactly one node with no output edges.
	assert(has_in_edge.size() == diff_chars.size() - 1);

	make_sure_unique_ordering_possible_topological_sort(adj_list, diff_chars);
}

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_small_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_big_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		int n;
		cin >> n;
		assert(1 <= n);

		vector <string> words(n);
		int char_count = 0;
		unordered_set<char> diff_chars;

		for (int i = 0; i < n; i++)
		{
			cin >> words[i];
			char_count += words[i].length();
			assert(words[i].length() != 0);
			assert(char_count <= MAX_CHARS);
			for (int j = 0; j < words[i].length(); j++)
			{
				diff_chars.insert(words[i][j]);
				assert('a' <= words[i][j]);
				assert(words[i][j] <= 'z');
			}
		}

		make_sure_unique_ordering_possible(words, diff_chars);

		string ans = find_order(words);

		assert(ans.length() == diff_chars.size());
		cout << ans << endl;
	}

	return 0;
}
