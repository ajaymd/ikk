#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

struct TreeNode
{
	/*
	To find height of tree, value stored in nodes does not matter. So in input also we are not 
	given this field. 
	*/
	//int val;															
	// Address of children nodes. 
	vector<TreeNode*> children;											
	TreeNode()
	{
		children.clear();
	}
};

//--------------------------------START------------------------------------

/*
 * Complete the function below.
 */

/*
    For your reference:
    
    struct TreeNode
    {
    	// Address of children nodes. 
        vector<TreeNode*> children;										
        TreeNode()
        {
            children.clear();
        }
    };
*/

int find_height(TreeNode* root)
{
	// Handle base case when root is a leaf node.
	if (root->children.size() == 0)										
	{
		return 0;
	}
	int h = 0;
	for (int i = 0; i < root->children.size(); i++)
	{
		// Find height of each children and store the maximum height of children. 
		h = max(h, find_height(root->children[i]));					
	}
	return h + 1;			
}

//--------------------------------STOP------------------------------------

// To build k-ary tree use this to speed up the insertion process. 
unordered_map<int, TreeNode*> address; 									

TreeNode* build_tree(vector<int> from, vector<int> to)
{
	int N = from.size() + 1;
	// Clear the global variable. 
	address.clear();													
	for (int i = 1; i <= N; i++)
	{
		// Create N nodes. 
		address[i] = new TreeNode();									
	}
	for (int i = 0; i < N - 1; i++)								  
	{
		// Link the nodes. (Build the k-ary tree.)
		address[from[i]]->children.push_back(address[to[i]]);			
	}
	return address[1];									
}

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

		TreeNode* root = build_tree(from, to);

		int h = find_height(root);
		assert(0 <= h);
		assert(h <= N - 1);
		cout << h << endl;
	}

	return 0;
}