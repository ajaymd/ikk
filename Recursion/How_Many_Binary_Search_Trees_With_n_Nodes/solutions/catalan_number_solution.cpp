#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 35;

// ------------------- START -------------------


/* -------- 
THIS SOLUTION WILL FAIL SOME OF THE TEST CASES DUE TO OVERFLOW (of long long int) ISSUE IN 
n_choose_r FUNCTION. 

Also if you will simply provide solution using Catalan numbers in interview, without explaining 
the intuition,
then it will not be accepted.

Solution using recursion with memorization, is preferable than this solution. 
-------- */

long long int n_choose_r(long long int n, long long int r)
{
	// n choose r = n choose (n - r) property. Like 5 Choose 2 = 10 = 5 Choose 3. 
	if (r > n - r)
	{
		r = n - r;
	}
	// n choose r = [n * (n - 1) * --- * (n - r + 1)] / [r * (r - 1) * --- * 1].
	long long int nCr = 1;
	for (long long int i = 0; i < r; i++)
	{
		nCr *= (n - i);
		nCr /= (i + 1LL);
	}
	return nCr;
}

// Return nth Catalan number.
long long int how_many_BSTs(int n)
{
	/*
	Value of nth Catalan number = (2n Choose n) / (n + 1)
	*/
	long long int two_n_choose_n = n_choose_r(n + n, n);
	return two_n_choose_n / ((long long int) n + 1LL);
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