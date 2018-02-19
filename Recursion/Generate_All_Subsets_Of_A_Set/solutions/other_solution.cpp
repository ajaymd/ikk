#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 20;

// -------------------- START --------------------

void generate_all_subsets_util(vector<string> &all_subsets, string &s, int pos, string cur_subset)
{
	/*
	If we have reached the end then add generated subset. 
	In C++ string.length() is O(1), but make sure about your language. If it is O(n) then better 
	to calculate it only once, store it (store it in global variable or pass as an argument to the
	function) and reuse it. 
	*/
	if (pos == s.length())
	{
		all_subsets.push_back(cur_subset);
		return;
	}
	// Do not include s[pos].
	generate_all_subsets_util(all_subsets, s, pos + 1, cur_subset);
	// Include s[pos].
	generate_all_subsets_util(all_subsets, s, pos + 1, cur_subset + s[pos]);
}

vector<string> generate_all_subsets(string s)
{
	vector<string> all_subsets;
	generate_all_subsets_util(all_subsets, s, 0, "");
	return all_subsets;
}

// -------------------- STOP ---------------------

int main()
{
	freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
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