#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 20;

// ------------------------ START -------------------------

int n;

//Check if s[l, r] is a palindrome or not.
bool is_palindrome(string &s, int l, int r)
{
	while (l < r)
	{
		if (s[l++] != s[r--])
		{
			return false;
		}
	}
	return true;
}

void generate_palindromic_decompositions_util(vector<string> &decompositions_container, string &s,
	int pos, string cur_decomposition)
{
	// If we have reached the end, add the string. 
	if (pos == n)
	{
		decompositions_container.push_back(cur_decomposition);
		return;
	}	
	// Try to add s[pos, i] if it a palindrome.
	for (int i = pos; i < n; i++)
	{
		if (is_palindrome(s, pos, i))
		{
			if (pos == 0)
			{
				// We are adding s[0, i] so do not put '|' before it.
				generate_palindromic_decompositions_util(decompositions_container, s, i + 1, 
					s.substr(pos, i - pos + 1));
			}
			else
			{
				generate_palindromic_decompositions_util(decompositions_container, s, i + 1, 
					cur_decomposition + '|' + s.substr(pos, i - pos + 1));
			}
		}
	}
}

vector<string> generate_palindromic_decompositions(string s)
{
	/*
	Store length of given string in global variable because we will be accessing it lots of time.
	*/
	n = s.length();
	vector<string> decompositions_container;
	generate_palindromic_decompositions_util(decompositions_container, s, 0, "");
	return decompositions_container;
}

// ------------------------ STOP --------------------------


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
		cout << len << endl;
		for (int i = 0; i < len; i++)
		{
			//cout << ans[i] << endl;
		}
		//cout << endl;
	}

	return 0;
}