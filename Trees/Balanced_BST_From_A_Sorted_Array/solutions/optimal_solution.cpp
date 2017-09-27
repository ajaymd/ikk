#include<bits/stdc++.h>

using namespace std;

//-----------------------------------START----------------------------------------

const int MAX_N = 100000, MAX_VAL = 2000000000;

struct node
{
	int val;
	node *l;
	node *r;
	node()
	{
		val = MAX_VAL + 1;
		l = NULL;
		r = NULL;
	}
};

//int index = 0;													// when running more than 1 testcase use this (each time set index = 0) else use static given in function  

void dfs(node *root, vector<vector<int>> &ans)	
{
	static int index = 0;										// at which index of ans we should store 
	if (root == NULL)
	{
		return;
	}
	ans[index][0] = root->val;									// set the root
	if (root->l == NULL)										// if root has left child then store it else store itself, as suggested in output format
	{	
		ans[index][1] = root->val;
	}
	else											
	{
		ans[index][1] = root->l->val;
	}
	if (root->r == NULL)										// if root has right child then store it else store itself, as suggested in output format
	{
		ans[index][2] = root->val;
	}
	else
	{
		ans[index][2] = root->r->val;
	}
	index++;
	dfs(root->l, ans);											// recursively add from left and right child 
	dfs(root->r, ans);
}

node * add_node(int l, int r, vector<int> &a)					// build tree using values (a[l], a[l+1], ..., a[r]).
{
	if (l > r)	
	{
		return NULL;
	}
	int m = l + (r - l) / 2;
	node *temp = new node();
	temp->val = a[m];											// to build balanced tree we need to choose the middle element as the root 
	temp->l = add_node(l, m - 1, a);							// recursively create subtree and add it as left child
	temp->r = add_node(m + 1, r, a);							// recursively create subtree and add it as right child 
	return temp;
}

vector<vector<int>> build_balanced_bst(vector<int> a)
{
	int N = a.size();
	vector<vector<int>> ans(N, vector<int>(3, MAX_VAL + 1));
	node *root = add_node(0, N - 1, a);							// build balanced BST
	dfs(root, ans);												// fill ans from tree
	return ans;
}

//-----------------------------------STOP----------------------------------------

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
		//index = 0;

		int N;
		cin >> N;
		assert(1 <= N);
		assert(N <= MAX_N);
		vector<int> a(N, 0);
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
			assert(-MAX_VAL <= a[i]);
			assert(a[i] <= MAX_VAL);
		}
		
		set<int> s(a.begin(), a.end());
		assert(s.size() == N);
		int idx = 0;
		for (auto it = s.begin(); it != s.end(); it++)
		{
			assert(a[idx++] == *it);
		}

		vector<vector<int>> ans = build_balanced_bst(a);
		assert(ans.size() == N);
		assert(ans[0].size() == 3);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				assert(-MAX_VAL <= ans[i][j]);
				assert(ans[i][j] <= MAX_VAL);

				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}