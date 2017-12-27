#include<bits/stdc++.h>

using namespace std;

const int MIN_N = 2, MAX_N = 111;

// -------------------- START ---------------------------

// Function to find a^b in O(log(b)).
// Use long long int otherwise it will overflow, for the given constraints.
long long int power(int a, int b)
{
	// a^0 = 1.
	if (b == 0)
	{
		return 1LL;
	}
	/*
	Suppose we want to find a^13. 
	a^13 = a^6 * a^6 * a^1. 
	Now instead of finding a^6 two times we can calculate it once (to speedup) and then use it. 
	Then multiply with remaining a. 
	*/
	long long int ret = power(a, b / 2);
	ret = ret * ret;
	if (b % 2)
	{
		ret = ret * (long long int)a;
	}
	return ret;
}

// Function to find maximum product by cutting rope of length n into pieces.
// Also need to use long long int otherwise it will overflow for the given constraints.
long long int max_product_from_cut_pieces(int n)
{
	// Base cases.
	if (n <= 3)
	{
		return (long long int)n - 1;
	}
	// Try some examples and will notice that there is fixed pattern.
	// Cut the rope such that all pieces have length 3.
	if (n % 3 == 0)
	{
		return power(3, n / 3);
	}
	// Cut the rope such that one piece has length 4 and rest pieces have length 3.
	if (n % 3 == 1)
	{
		return power(3, (n - 4) / 3) * 4LL;
	}
	// Cut the rope such that one piece has length 2 and rest pieces have length 3.
	return power(3, (n - 2) / 3) * 2LL; 
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