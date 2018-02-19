#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, MAX_VAL = 2000000000;

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

//-----------------------------------START----------------------------------------

/*
 * Complete the function below.
 */

/*
    For your reference. 

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
*/

// build tree using values (a[l], a[l+1], ..., a[r]).
TreeNode * build_balanced_bst_helper(int l, int r, vector<int> &a)					
{
	if (l > r)	
	{
		return NULL;
	}
	int m = l + (r - l) / 2;
	// to build balanced tree we need to choose the middle element as the root 
	TreeNode *temp = new TreeNode(a[m]);											
	// recursively create subtree and add it as left child
	temp->left_ptr = build_balanced_bst_helper(l, m - 1, a);						
	// recursively create subtree and add it as right child 
	temp->right_ptr = build_balanced_bst_helper(m + 1, r, a);						
	return temp;
}

TreeNode * build_balanced_bst(vector<int> a)
{
	int N = a.size();
	// build balanced BST
	return build_balanced_bst_helper(0, N - 1, a);									
}

//-----------------------------------STOP----------------------------------------

bool check_balanced_bst(TreeNode *root, int l, int r, vector<int>& a)
{
	// If no value in [l, r] and tree is also empty.
    if (l > r && root == NULL)                              
    {
        return true;
    }
    // If no value in [l, r] but tree contains something. 
    else if (l > r && root != NULL)                         
    {
        return false;
    }
    // If some values in [l, r] but tree is empty.
    if (root == NULL)                                       
    {
        return false;
    }
    
    int mid1 = l + (r - l) / 2;
    int mid2 = l + (r - l + 1) / 2;
    
    bool valid1 = (root->val == a[mid1] && check_balanced_bst(root->left_ptr, l, mid1 - 1, a) && 
    	check_balanced_bst(root->right_ptr, mid1 + 1, r, a));
    // actually we are doing valid1 || valid2 but when valid1 is true then no need to find valid2
    if (valid1)                                             
    {
        return true;        
    }
    /*
    when odd no of elements in [l, r] then mid1 = mid2 so valid1 = valid2 and no need to find 
    valid2. 
    */ 
    if (mid1 == mid2)                                       
    {
        return false;        
    }
    return (root->val == a[mid2] && check_balanced_bst(root->left_ptr, l, mid2 - 1, a) && 
    	check_balanced_bst(root->right_ptr, mid2 + 1, r, a));  
}

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

		TreeNode* root = build_balanced_bst(a);
    
	    if (check_balanced_bst(root, 0, a_size - 1, a))
	    {
	        cout << "Valid Balanced BST" << endl;
	    }
	    else
	    {
	        cout << "Invalid Balanced BST" << endl;
	    }
	}

	return 0;
}