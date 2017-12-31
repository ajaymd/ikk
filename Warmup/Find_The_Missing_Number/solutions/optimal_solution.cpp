#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

// --------------------- START -----------------------

/*
xor of numbers given in array ^ missing number = (1 ^ 2 ^ ... ^ (n - 1) ^ n). 
hence 
missing number = (1 ^ 2 ^ ... ^ (n - 1) ^ n) ^ xor of numbers given in array.
Now there is a shortcut to find (1 ^ 2 ^ ... ^ (n - 1) ^ n).
xor of all numbers from 1 to n = 
	- n%4 == 0 ---> n
	- n%4 == 1 ---> 1
	- n%4 == 2 ---> n + 1
	- n%4 == 3 ---> 0
(Try some examples and will get the pattern!)
*/

int find_the_missing_number(vector<int> nos)
{
	int nos_xor = 0;
	int n_minus_1 = nos.size();
	for (int i = 0; i < n_minus_1; i++)
	{
		nos_xor ^= nos[i];
	}
	int n = n_minus_1 + 1;
	int all_xor = (n % 4 == 0) ? n : (n % 4 == 1) ? 1 : (n % 4 == 2) ? n + 1 : 0;
	return all_xor ^ nos_xor;
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
				assert(false);
			}
		}
		if (n != 1)
		{
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