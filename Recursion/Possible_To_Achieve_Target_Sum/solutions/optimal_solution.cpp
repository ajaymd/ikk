#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 18;
const long long int MAX_VAL = 100000000000000000LL;

// ---- START ----

/*

	----
	In hackerrank use long int, instead of long long int.
	----


	bool check(int start, int n, vector<long int> &arr, long int remaining, bool 
		at_lest_one_included)
	{	
		// Note that we are passing arr by reference. Either pass by reference or use global 
		variable. Passing by value will slow down the solution. 
		if (start >= n)
		{
			// remaining sum should be 0 and we should have included at least one number!
			return remaining == 0 && at_lest_one_included;
		}
	    
		// We are not including current element. So at_lest_one_included will be dependent on 
		previous elements. 
		if (check(start + 1, n, arr, remaining, at_lest_one_included))
		{
			return true;
		}
		// Include the current element. Now we have included at least one element so 
		at_lest_one_included should be true. 
		return check(start + 1, n, arr, remaining - arr[start], true);
	}

	bool check_if_sum_possible(vector<long int> arr, long int k)
	{
		return check(0, arr.size(), arr, k, false);
	}

*/

/*
Note that we are passing arr by reference. Either pass by reference or use global variable. 
Passing by value will slow down the solution. 
*/
bool check(int start, int n, vector<long long int> &arr, long long int remaining, 
	bool at_lest_one_included)
{	

	if (start >= n)
	{
		// remaining sum should be 0 and we should have included at least one number!
		return remaining == 0 && at_lest_one_included;
	}
	/*
	We are not including current element. So at_lest_one_included will be dependent on previous 
	elements. 
	*/
	if (check(start + 1, n, arr, remaining, at_lest_one_included))
	{
		return true;
	}
	/*
	Include the current element. Now we have included at least one element so 
	at_lest_one_included should be true. 
	*/
	return check(start + 1, n, arr, remaining - arr[start], true);
}

bool check_if_sum_possible(vector<long long int> arr, long long int k)
{
	return check(0, arr.size(), arr, k, false);
}


// ---- STOP ----

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

		vector<long long int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			assert(-MAX_VAL <= arr[i]);
			assert(arr[i] <= MAX_VAL);
		}

		long long int k;
		cin >> k;
		assert(-MAX_VAL <= k);
		assert(k <= MAX_VAL);

		cout << check_if_sum_possible(arr, k) << endl;
	}

	return 0;
}