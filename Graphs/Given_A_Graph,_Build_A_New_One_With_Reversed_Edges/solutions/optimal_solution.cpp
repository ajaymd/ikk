#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 315;

struct Node
{
	int val;
	vector<Node *> neighbours;
	Node(int _val = 0)
	{
		val = _val;
		neighbours.clear();
	}
};

// ---- START ----

void dfs(Node *node, unordered_map<int, Node *> &reversed)
{	
	/*
	Note that we are passing reversed by reference, either use passing by reference or use global 
	variable. 
	*/
	// First create new node.
	reversed[node->val] = new Node(node->val);
	int n = node->neighbours.size();
	// Visit all the neighbours.
	for (int i = 0; i < n; i++)
	{
		// If node is not visited then first visit it.
		if (reversed.find(node->neighbours[i]->val) == reversed.end())
		{
			dfs(node->neighbours[i], reversed);
		}
		// Add the reverse edge. 
		reversed[node->neighbours[i]->val]->neighbours.push_back(reversed[node->val]);
	}
}

Node *build_other_graph(Node *node)
{
	/*
	In constraints we are given that each node contains distinct values, so we can keep track of 
	node address using that value. {value : node}.
	*/
	unordered_map<int, Node *> reversed;
	// Build the graph.
	dfs(node, reversed);
	// Return any node of the new graph. 
	return reversed.begin()->second;
}

// ---- STOP ----

void helper_dfs(Node *reversed_node, unordered_map<int, Node *> &reversed)
{
	reversed[reversed_node->val] = reversed_node;
	int n = reversed_node->neighbours.size();
	for (int i = 0; i < n; i++)
	{
		if (reversed.find(reversed_node->neighbours[i]->val) == reversed.end())
		{
			helper_dfs(reversed_node->neighbours[i], reversed);
		}
	}
}

unordered_map<int, Node *> helper_get_all_addresses_in_reversed_graph(Node * reversed_node)
{
	unordered_map<int, Node *> reversed;
	helper_dfs(reversed_node, reversed);
	return reversed;
}

string helper(int graph_nodes, vector<int> graph_from, vector<int> graph_to)
{
	unordered_map<int, Node *> original;
	for (int i = 1; i <= graph_nodes; i++)
	{
		original[i] = new Node(i);
	}
	set<pair<int, int>> edges;
	int graph_edges = graph_from.size();
	for (int i = 0; i < graph_edges; i++)
	{
		original[graph_from[i]]->neighbours.push_back(original[graph_to[i]]);

		edges.insert({graph_from[i], graph_to[i]});
	}	 

	// Student will return only one node. Do a dfs and get all the nodes.
	unordered_map<int, Node *> reversed = 
	helper_get_all_addresses_in_reversed_graph(build_other_graph(original[1]));

	if (reversed.size() != graph_nodes)
	{
		return "Wrong Answer!";
	}

	for (auto it = reversed.begin(); it != reversed.end(); it++)
	{
		if (1 > it->first || it->first > graph_nodes)
		{
			return "Wrong Answer!";
		}
		// New graph should not contain node from original graph. 
		if (original[it->first] == reversed[it->first])
		{
			return "Wrong Answer!";
		}
		int n = it->second->neighbours.size();
		for (int i = 0; i < n; i++)
		{
			int val = it->second->neighbours[i]->val;
			auto itttt = edges.find({val, it->first}); 
			if (itttt == edges.end())
			{
				return "Wrong Answer!";
			}
			edges.erase(itttt);
		}
	}
	// All the edges should be present in the new graph. 
	if (edges.size() > 0)
	{
		return "Wrong Answer!";
	}
	return "Correct Answer!";
}

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
	while (test_cases--)
	{
		int graph_nodes, graph_edges;
		cin >> graph_nodes >> graph_edges;
		assert(1 <= graph_nodes);
		assert(graph_nodes <= MAX_NODES);
		assert(graph_nodes == 1 || graph_nodes <= graph_edges);
		assert(graph_edges <= graph_nodes * (graph_nodes - 1));

		vector<int> graph_from(graph_edges);
		vector<int> graph_to(graph_edges);

		set<pair<int, int>> already_present_edges; 

		for (int i = 0; i < graph_edges; i++)
		{
			cin >> graph_from[i] >> graph_to[i];
			assert(1 <= graph_from[i]);
			assert(graph_from[i] <= graph_nodes);
			assert(1 <= graph_to[i]);
			assert(graph_to[i] <= graph_nodes);
			assert(graph_from[i] != graph_to[i]);
			assert(already_present_edges.find({graph_from[i], graph_to[i]}) == 
				already_present_edges.end());
			already_present_edges.insert({graph_from[i], graph_to[i]});
		}

		cout << helper(graph_nodes, graph_from, graph_to) << endl;
	}

	return 0;
}