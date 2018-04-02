#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 15;

// ----------------------- START -----------------------

void find_brackets(int opening, int closing, int n, string s, vector<string> &brackets)
{
	if (closing == n)
	{
		brackets.push_back(s);
		return;
	}
	if (opening < n)
	{
		find_brackets(opening + 1, closing, n, s + '(', brackets);		
	}
	if (opening > closing)
	{
		find_brackets(opening, closing + 1, n, s + ')', brackets);		
	}
}

vector<string> find_all_well_formed_brackets(int n)
{
	vector<string> brackets;
	find_brackets(0, 0, n, "", brackets);
	return brackets;
}

// ----------------------- STOP ------------------------

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	// freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	// freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_small_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_big_test_cases_expected_output.txt", "w", stdout);
	freopen("..//test_cases//ignore_input.txt", "r", stdin);
	freopen("..//test_cases//ignore_output.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		int n;
		cin >> n;
		assert(0 <= n);
		assert(n <= MAX_N);
		vector<string> brackets = find_all_well_formed_brackets(n);
		int len = brackets.size();
		for (int i = 0; i < len; i++)
		{
			assert(brackets[i].length() == n + n);
			cout << brackets[i] << endl;
		}
		cout << endl;
	}

	return 0;
}