#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 20;

// ------------------------ START -------------------------

// Find is_palindrome[i][j] for all possible substrings in O(n^2) time complexity.
void find_is_palindrome_for_all_substrings(vector<vector<bool>> &is_palindrome, int n, string &s)
{
	for (int len = 1; len <= n; len++)
	{
		for (int start = 0; start < n; start++)
		{
			int stop = start + len - 1;
			// We want to find if s[start, stop] is a palindrome or not.
			if (stop >= n)
			{
				break;
			}
			is_palindrome[start][stop] = false;
			if (len <= 2)
			{
				is_palindrome[start][stop] = (s[start] == s[stop]);
			}
			else if (s[start] == s[stop])
			{
				/*
				When first and last characters are same then whether string is a palindrome or 
				not, depends on the inner string.
				For example:
				1) In "abcba", 'a' = 'a' so string is a palindrome or not will depend on "bcb".
				1) In "abcca", 'a' = 'a' so string is a palindrome or not will depend on "bcc".
				*/
				is_palindrome[start][stop] = is_palindrome[start + 1][stop - 1];
			}
		}
	}
}

vector<string> generate_palindromic_decompositions(string s)
{
	int n = s.length();
	/*
	For all substrings of s, we will pre-calculate if it is a palindrome or not.
	is_palindrome[i][j] (where i <= j and 0 <= i, j < n) will contain whether s[i, j] is a 
	palindrome or not.
	*/
	vector<vector<bool>> is_palindrome (n, vector<bool> (n, false));
	find_is_palindrome_for_all_substrings(is_palindrome, n, s);
	/* 
	decompositions_container[i] will contain all possible palindromic decompositions of s[0, i]. 
	So our answer will be decompositions_container[0, n - 1].
	We will build our solution like: 
	decompositions_container[0, 0] -> decompositions_container[0, 1] ->  ... -> 
	decompositions_container[0, n - 1].
	Why we are storing these values? -> To avoid recalculation. 
	*/
	vector<vector<string>> decompositions_container(n, vector<string>(0));
	/*
	Loop to find decompositions_container[i] (i.e. all possible palindromic decompositions of 
	s[0, i].)
	*/
	for (int i = 0; i < n; i++)
	{
		// If s[0, i] is a palindrome then add it.
		if (is_palindrome[0][i])
		{
			decompositions_container[i].push_back(s.substr(0, i + 1));
		}
		/*
		Loop to find other palindromic decompositions of s[0, i] using already calculated 
		palindromic decompositions of s[0, 0], ..., s[0, n - 1]. 
		*/
		for (int j = 0; j < i; j++)
		{
			if (is_palindrome[j + 1][i])
			{
				/*
				If s[j + 1][i] is a palindromic substring, then we can join palindromic 
				decompositions (that we have already found) of s[0, j] with it to form the 
				palindromic decomposition of s[0, i].
				*/
				string cur_sub_str = '|' + s.substr(j + 1, i - j);
				int len = decompositions_container[j].size();
				for (int k = 0; k < len; k++)
				{
					/*
					Here we are directly using previously calculated values, but in recursion we 
					recalculate them. So that is why this solution is faster than recursive 
					solution. 
					*/
					decompositions_container[i].push_back(decompositions_container[j][k] + 
						cur_sub_str);
				}
			}
		}
	}
	return decompositions_container[n - 1];
}	

// ------------------------ STOP --------------------------


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
		assert(1 <= n);
		assert(n <= MAX_N);
		for (int i = 0; i < n; i++)
		{
			assert('a' <= s[i]);
			assert(s[i] <= 'z');
		}
		vector<string> ans = generate_palindromic_decompositions(s);
		int len = ans.size();
		cout << len << " different palindromic decompositions possible." << endl;
		for (int i = 0; i < len; i++)
		{
			cout << ans[i] << endl;
		}
		cout << endl;
	}

	return 0;
}