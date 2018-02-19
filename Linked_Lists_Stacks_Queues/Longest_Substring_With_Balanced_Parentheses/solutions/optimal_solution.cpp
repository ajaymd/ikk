#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

// -------------------------- START --------------------------

int find_max_length_of_matching_parentheses(string brackets)
{
	int n = brackets.length();
	/*
	One observation to make is that, if a matching '(' isn’t found for any ')', then string 
	till ')' can no longer be part of the substring we are looking for. i.e. "(()))()()" now at 
	4th position no maching '(' is found for ')', hence part "(()))" is not needed in further 
	calculations!
	valid_from variable keeps track of that. 
	*/
	int max_len = 0, valid_from = 0;
	// Stores the indices of the opening brackets.
	stack<int> opening_brackets;
	for (int i = 0; i < n; i++)
	{
		if (brackets[i] == '(')
		{
			// Store the index of opening bracket.
			opening_brackets.push(i);
		}
		else
		{
			// For ')' no matching '(' is found hence update the valid_from variable.
			if (opening_brackets.empty())
			{
				valid_from = i + 1;
			}
			else
			{
				// Remove the matched '('.
				opening_brackets.pop();
				// Try "(())))(())()" and "((((())(((()" to understand the following steps.
				if (opening_brackets.empty())
				{
					/*
					In "(())))(())()" when we are at last ')', stack will become empty and 
					valid_from will be at 6th position, so answer that needs to be checked is 
					11 - 6 + 1 = 6 corresponding to "(())()".   
					*/
					max_len = max(max_len, i - valid_from + 1);
				}
				else
				{
					/*
					In "((((())(((()" when we are at last ')', stack will contain 
					[0, 1, 21 7, 8, 9], so answer that needs to be checked is 11 - 9 = 2 
					corresponding to "()". 
					*/
					max_len = max(max_len, i - opening_brackets.top());
				}
			}
		}
	}
	return max_len;
}

// -------------------------- STOP ---------------------------

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
	assert(test_cases >= 0);
	while (test_cases--)
	{
		string brackets;
		cin >> brackets;
		int n = brackets.length();
		assert(1 <= n);
		assert(n <= MAX_N);
		for (int i = 0; i < n; i++)
		{
			assert(brackets[i] == '(' || brackets[i] == ')');
		}
		int ans = find_max_length_of_matching_parentheses(brackets);
		assert(0 <= ans);
		assert(ans <= n);
		assert(ans % 2 == 0);
		cout << ans << endl;
	}

	return 0;
}