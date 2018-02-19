#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 35;

// ------------------- START -------------------

long long int how_many_BSTs(int n)
{
	// BSTs[i] stores the number of BSTS possible with i nodes.
	vector<long long int> BSTs(n + 1, 0LL);
	// Base case.
	BSTs[0] = 1LL;
	/*
	In recursion there will be lots of recalculations (unnecessary recalculations), so to avoid 
	that we can store the values once calculated. 
	Here in each loop iteration we will find the value of BSTs[cur_BST_size]. As we are 
	calculating from 1 to n, when we are finding value for BSTs[cur_BST_size], we will have 
	values for BSTs[ < cur_BST_size] already calculated and they can be used directly.
	*/
	for (int cur_BST_size = 1; cur_BST_size <= n; cur_BST_size++)
	{
		// Calculate BSTs[cur_BST_size].
		for (int number_of_nodes_in_left_subBST = 0; 
			number_of_nodes_in_left_subBST < cur_BST_size; 
			number_of_nodes_in_left_subBST++)
		{
			int number_of_nodes_in_right_subBST = 
				cur_BST_size - 1 - number_of_nodes_in_left_subBST;
			BSTs[cur_BST_size] += BSTs[number_of_nodes_in_left_subBST] * 
				BSTs[number_of_nodes_in_right_subBST];
		}
	}
	return BSTs[n];
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