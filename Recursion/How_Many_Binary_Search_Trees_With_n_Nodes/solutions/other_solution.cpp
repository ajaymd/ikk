#include<bits/stdc++.h>

using namespace std;

// ------------------- START -------------------

const int MAX_N = 35;

/*
Global variable used to store the results.
memorized_BSTs[i] == -1, indicates that number of binary search trees possible with i nodes is 
remaining to calculate.
memorized_BSTs[i] != -1, indicates that number of binary search trees possible with i nodes i 
calculated once and now onwards we can reuse it, no need to recalculate.  
*/
vector<long long int> memorized_BSTs(MAX_N + 1, -1);

long long int how_many_BSTs(int n)
{
	// If base case.
	if (n == 0)
	{
		return 1LL;
	}
	// If we have already calculated the value then return it, do not recalculate.
	if (memorized_BSTs[n] != -1LL)
	{
		return memorized_BSTs[n];
	}
	/*
	Any BST with n nodes can be divided in 3 parts, 
	1) root.
	2) left sub-BST. 
	3) right sub-BST.
	
	There will be always one root hence structure of BST will only depend on the left sub-BST and 
	the right sub-BST. 

	We have 1 root fixed hence we have n - 1 nodes in left sub-BST + right sub-BST.
	So that is,
	n - 1 = nodes in left sub-BST + nodes in right sub-BST. 
	To get all the possibilities we can fix nodes in left sub-BST and get nodes in right sub-BST!
	So from the above formula,

	nodes in left sub-BST -> nodes in right sub-BST
	
	0 -> n - 1
	1 -> n - 2
	2 -> n - 3
	...
	n - 3 -> 2 
	n - 2 -> 1
	n - 1 -> 0

	Now suppose we take one fixed possibility 2 (nodes in left sub-BST) -> n - 3 
	(nodes in right sub-BST), then if we can get total number of BSTs possible with 2 nodes 
	(let's say it is x) and total number of BSTs possible with n - 3 nodes (let's say it is y), 
	then we can get the total number of BSTs possible with n nodes for the current possibility 
	(WHEN IN LEFT SUB-BST WE HAVE 2 NODES AND IN RIGHT SUB-BST WE HAVE n - 3 NODES) by x * y. Now 
	question is why x * y? For BST with n nodes we will fix one root, on the left subBST we fix 1 
	tree out of x possible BSTs, then to create BST with n nodes, we can use any of the y possible
	BSTs on the right sub-BST. So for one fixed sub-BST on left side we have generated y BSTs with
	n nodes. Now doing this for all x sub-BSTs possible on left side, total number of generated 
	BSTs = y + y + ... y (total x times) and that is x * y. (This will be difficult to understand 
	unless you try some examples yourself.)

	Now as we have done for 2 -> n - 3, we can try all possibilities and get the final answer 
	denoting total number of BSTS possible with n nodes!

	Let's take a small example n = 3 and see how every possible BST is covered in one of the 
	parition.
	All possible BSTs with 3 nodes are,
	1) root, root->left, root->left->left
	2) root, root->left, root->left->right
	3) root, root->right, root->right->right
	4) root, root->right, root->right->left
	5) root, root->left, root->right

	Now if we try:
	0 -> 2
	1 -> 1
	2 -> 0

	then we can divide the above 5 possibilities as:
	0 -> 2 : 	3) root, root->right, root->right->right
				4) root, root->right, root->right->left
	1 -> 1 : 	5) root, root->left, root->right
	2 -> 0 : 	1) root, root->left, root->left->left
				2) root, root->left, root->left->right
	*/
	long long int BSTs = 0LL;
	// Try all possibilities by taking number of nodes in left subBST from 0 to n - 1.
	for (int number_of_nodes_in_left_subBST = 0; number_of_nodes_in_left_subBST < n; 
		number_of_nodes_in_left_subBST++)
	{
		int number_of_nodes_in_right_subBST = n - 1 - number_of_nodes_in_left_subBST;
		BSTs += how_many_BSTs(number_of_nodes_in_left_subBST) * 
			how_many_BSTs(number_of_nodes_in_right_subBST);
	}
	// Store the calculated result, nowonwards do not recalculate it for n nodes. 
	memorized_BSTs[n] = BSTs;
	return BSTs;
}

// ------------------- STOP -------------------

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
		assert(n <= MAX_N);
		cout << how_many_BSTs(n) << endl;
	}

	return 0;
}