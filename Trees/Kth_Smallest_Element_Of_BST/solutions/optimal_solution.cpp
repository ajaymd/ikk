#include<bits/stdc++.h>

using namespace std;

//-------------------------------START-----------------------------------

const int MAX_N = 6000, MAX_VAL = 2000000000;

struct node
{
	int val;
	node* l;
	node* r;
	node(int _val = MAX_VAL + 1) : val(_val) 
	{
		l = NULL;
		r = NULL;
	}
};

int kth_element = MAX_VAL + 1;							// kth smallest element is stored in this variable. 
//int counter = 0;										// when running more than one testcases then dont use static in counter = 0 use this and initialize counter = 0 at the beginning of each testcase. 

void get_k_th_element(node* root, int k)
{
	/*
		this function uses the idea of inorder_traversal. 
	*/
	static int counter = 0;
	if (root == NULL || counter >= k)					// either root is null or we have already found the answer. 			
	{
		return;
	}
	get_k_th_element(root->l, k);						// first try to find from left subtree, because elements in left suubtree will be smaller than the root.
	if (counter < k)									// if we have not found the answer till now. 		
	{
		counter++;
		if (counter == k)								// if current node is the kth node.
		{
			kth_element = root->val;
			return;
		}
		get_k_th_element(root->r, k);					// we have explored left subtree and the root now explore right subtree. 
	}
}

node* bst_insert(node* root, int val)
{
	if (root == NULL)									// destination.
	{
		return new node(val);
	}
	if (val <= root->val)								// element is <= hence insert it in left subtree.
	{
		root->l = bst_insert(root->l, val);				// if root->l is null then new node will be created and root->l is assigned its address else it will be assigned to the same value as previouly stored.
	}
	else  												// element is > hence insert it in right subtree.
	{
		root->r = bst_insert(root->r, val);				// if root->r is null then new node will be created and root->l is assigned its address else it will be assigned to the same value as previouly stored.
	}
	return root;
}

int kth_smallest_element(vector<int> data, int k)
{
	int N = data.size();
	node* root = NULL;
	for (int i = 0; i < N; i++)							// build bst from data
	{
		root = bst_insert(root, data[i]);
	}
	get_k_th_element(root, k);							// find kth smallest element
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
		vector<int> data(N, 0);
		for (int i = 0; i < N; i++)
		{
			cin >> data[i];
			assert(-MAX_VAL <= data[i]);
			assert(data[i] <= MAX_VAL);
		}
		int k;
		cin >> k;
		assert(1 <= k);
		assert(k <= k);
		int ans = kth_smallest_element(data, k);
		sort(data.begin(), data.end());
		assert(ans == data[k - 1]);
		cout << ans << endl;
	}

	return 0;
}