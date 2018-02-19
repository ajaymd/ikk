#include<bits/stdc++.h>
using namespace std;

const int MIN_N = 2, MAX_N = 111;

// -------------------- START --------------------------

// Function to find maximum product by cutting rope of length n into pieces.
long long int max_product_from_cut_pieces(int n)
{
	// Need to use long long int otherwise it will overflow for the given constraints.
	vector<long long int> max_product(n + 1, 0);
	// Base case.
	max_product[1] = 1;
	// Use dp bottom-up approach.
	for (int cur_rope_length = 2; cur_rope_length <= n; cur_rope_length++)
	{
		/*
		Think practically, when ever we are making last cur it will be between 1 and 
		cur_rope_length - 1. 
		Also due to bottom-up approach we already have found the maximum product for smaller 
		lengths. 
		So now we iterate over all the possibilities of last cut (from 1 to cur_rope_length - 1) 
		and find the maximum product for the cur_rope_length.
		*/
		for (int cut_length = 1; cut_length < cur_rope_length; cut_length++)
		{
			max_product[cur_rope_length] = max(
				max_product[cur_rope_length], 
				(long long int) cut_length * max_product[cur_rope_length - cut_length]
			);
		}
		/*
		In the above loop we have found the answer when we have to make at least one cut.
		For cur_rope_length=n we have to make at least one cut and when we iterate over 1 to 
		cur_rope_length - 1 we are already making one cut, hence max_product[cur_rope_length - 
		cut_length] "need not" to have at least one cut.
		So for lengths other than n update answer when no cut. 
		*/
		if (cur_rope_length != n)
		{
			max_product[cur_rope_length] = max(
				max_product[cur_rope_length], 
				(long long int)cur_rope_length
			);
		}
	}
	return max_product[n];
}

// -------------------- STOP ---------------------------

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
	assert(test_cases >= 0);
	while (test_cases--)
	{
		int n;
		cin >> n;
		assert(MIN_N <= n);
		assert(n <= MAX_N);
		long long int ans = max_product_from_cut_pieces(n);
		assert(1 <= ans);
		cout << ans << endl;
	}

	return 0;
}