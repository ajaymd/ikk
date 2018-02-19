#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 20;

// -------------------- START --------------------

vector<string> generate_all_subsets(string s)
{
	int n = s.length();
	vector<string> all_subsets;
	// Base case when n = 0 i.e. s = "".
	all_subsets.push_back("");
	/*
	Suppose s = "xyz".
	Now try to find pattern in following steps (think how any step is related to previous step!):
	- [""]
	- ["", "x"]
	- ["", "x", "y", "xy"]
	- ["", "x", "y", "xy", "z", "xz", "yz", "xyz"]
	Let me explain what we have done in last step.
	First take array from previous step, that is ["", "x", "y", "xy"], append 'z' to each string, 
	that is ["z", "xz", "yz", "xyz"], now merge it with array in previous step! 
	*/
	for (int i = 1; i <= n; i++)
	{
		int old_len = all_subsets.size();
		for (int j = 0; j < old_len; j++)
		{
			/*
			Note that we are doing push_back that is adding value at the end of array, so we 
			already have the old values stored in it.
			*/
			all_subsets.push_back(all_subsets[j] + s[i - 1]);
		}
	}
	return all_subsets;
}

// -------------------- STOP ---------------------

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
	string scan_new_line;
	getline(cin, scan_new_line);
	getline(cin, scan_new_line);
	while (test_cases--)
	{
		string s;
		getline(cin, s);
		int n = s.length();
		assert(0 <= n);
		assert(n <= MAX_N);
		vector<bool> visited(26, false);
		for (int i = 0; i < n; i++)
		{
			assert('a' <= s[i]);
			assert(s[i] <= 'z');
			assert(visited[s[i] - 'a'] == false);
			visited[s[i] - 'a'] = true;
		}
		vector<string> all_subsets = generate_all_subsets(s);
		int len = all_subsets.size();
		assert(len == (1 << n));
		cout << len << endl;
		for (int i = 0; i < len; i++)
		{
			cout << all_subsets[i] << endl;
		}
		cout << endl;
	}

	return 0;
}