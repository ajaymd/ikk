#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

// --------------------- START -----------------------

/* 
sum of numbers in given array + missing number = (1 + 2 + ... + (n - 1) + n) = (n * (n + 1)) / 2.
hence,
missing number = (n * (n + 1)) / 2 - sum of numbers in given array.
*/
int find_the_missing_number(vector<int> nos)
{
	/* 
	As per the given constraints n can be upto 10^5.
	So for larger value of n, sum of numbers in given array can easily exceed limit of unsigned 
	integer (2147483647) causing overflow and hence wrong answer.
	So need to use long long int to avoid overflow.
	*/
	long long int nos_sum = 0LL;
	int n_minus_1 = nos.size();
	for (int i = 0; i < n_minus_1; i++)
	{
		nos_sum += nos[i];
	}
	/*
	As per the given constraints n can be upto 10^5.
	So for larger value of n, sum of number from 1 to n can easily exceed limit of unsigned 
	integer (2147483647) causing overflow and hence wrong answer.
	So need to use long long int to avoid overflow.
	*/
	long long int n = n_minus_1 + 1LL;
	return ((n * (n + 1LL)) / 2LL) - nos_sum;
}

// --------------------- STOP ------------------------

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_small_test_cases_expected_output.txt", "w", stdout);
	freopen("..//test_cases//generated_big_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//generated_big_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		int n_minus_1;
		cin >> n_minus_1;
		int n = n_minus_1 + 1;
		assert(1 <= n);
		assert(n <= MAX_N);
		vector<int> nos(n_minus_1);
		set<int> nos_set;
		for (int i = 0; i < n_minus_1; i++)
		{
			cin >> nos[i];
			if (nos_set.find(nos[i]) == nos_set.end())
			{
				nos_set.insert(nos[i]);
			}
			else
			{
				// nos must contain distinct numbers.
				assert(false);
			}
		}
		if (n != 1)
		{
			// nos must contain number in range [1 to n] inclusive.
			assert(1 <= *nos_set.begin());
			assert(*nos_set.rbegin() <= n);
		}
		int missing_no = find_the_missing_number(nos);
		assert(1 <= missing_no);
		assert(missing_no <= n);
		cout << missing_no << endl;
	}


	return 0;
}