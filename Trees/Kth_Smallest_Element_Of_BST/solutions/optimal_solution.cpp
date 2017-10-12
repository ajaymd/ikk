#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 6000, MAX_VAL = 2000000000;

struct TreeNode
{
	int val;
	TreeNode* left_ptr;
	TreeNode* right_ptr;

	TreeNode(int _val = 0)
	{
		val = _val;
		left_ptr = NULL;
		right_ptr = NULL;
	}
};

TreeNode* bst_insert(TreeNode* root, int val)
{
	if (root == NULL)												// destination.
	{
		return new TreeNode(val);
	}
	if (val <= root->val)											// element is <= hence insert it in left subtree.
	{
		root->left_ptr = bst_insert(root->left_ptr, val);			// if root->left_ptr is null then new TreeNode will be created and root->left_ptr is assigned its address else it will be assigned to the same value as previouly stored.
	}
	else  															// element is > hence insert it in right subtree.
	{
		root->right_ptr = bst_insert(root->right_ptr, val);			// if root->right_ptr is null then new TreeNode will be created and root->right_ptr is assigned its address else it will be assigned to the same value as previouly stored.
	}
	return root;
}

//-------------------------------START-----------------------------------

int kth_element;													// kth smallest element is stored in this variable. 
//int counter = 0;													// when running more than one testcases then dont use static in counter = 0 use this and initialize counter = 0 at the beginning of each testcase. 

void get_k_th_element(TreeNode* root, int k)
{
	/*
		this function uses the idea of inorder_traversal. 
	*/
	static int counter = 0;
	if (root == NULL || counter >= k)								// either root is null or we have already found the answer. 			
	{
		return;
	}
	get_k_th_element(root->left_ptr, k);							// first try to find from left subtree, because elements in left suubtree will be smaller than the root.
	if (counter < k)												// if we have not found the answer till now. 		
	{
		counter++;
		if (counter == k)											// if current node is the kth node.
		{
			kth_element = root->val;
			return;
		}
		get_k_th_element(root->right_ptr, k);						// we have explored left subtree and the root now explore right subtree. 
	}
}

int kth_smallest_element(TreeNode *root, int k)
{
	get_k_th_element(root, k);										// find kth smallest element
	return kth_element;
}

//-------------------------------------STOP---------------------------------

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

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		//counter = 0;
		int N;
		cin >> N;
		assert(1 <= N);
		assert(N <= MAX_N);

		TreeNode* root = NULL;

		for (int i = 0; i < N; i++)
		{
			int data;
			cin >> data;

			assert(-MAX_VAL <= data);
			assert(data <= MAX_VAL);

			root = bst_insert(root, data);
		}

		int k;
		cin >> k;
		assert(1 <= k);
		assert(k <= k);

		int ans = kth_smallest_element(root, k);
		cout << ans << endl;
	}

	return 0;
}