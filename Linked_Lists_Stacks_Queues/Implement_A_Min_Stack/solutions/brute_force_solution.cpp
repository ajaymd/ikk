#include<bits/stdc++.h>

using namespace std;

// -------------------------- START --------------------------

const int MAX_N = 100000, MIN_VAL = -1, MAX_VAL = 2000000000;

vector<int> min_stack(vector<int> operations)
{
	int n = operations.size();
	vector<int> ans;
	stack<int> original, helper;
	for (int i = 0; i < n; i++)
	{
		if (operations[i] >= 1)
		{
			original.push(operations[i]);
		}
		else if (operations[i] == -1)
		{
			if (original.empty() == false)
			{
				original.pop();
			}
		}
		else
		{
			if (original.empty())
			{
				// If stack is empty, consider -1 as the minimum element.
				ans.push_back(-1);
			}
			else
			{
				/*
				Transfer all elements to other stack updating the minimum
				value.
				*/
				int min_val = MAX_VAL;
				while (original.empty() == false)
				{
					min_val = min(min_val, original.top());
					helper.push(original.top());
					original.pop();
				}
				// Add the minimum value.
				ans.push_back(min_val);
				// Restore the stack.
				while(helper.empty() == false)
				{
					original.push(helper.top());
					helper.pop();
				}
			}
		}
	}
	return ans;
}

// -------------------------- STOP ---------------------------

int main()
{
	// freopen(
	// 	"..//test_cases//sample_test_cases_input.txt", 
	// 	"r", stdin
	// );
	// freopen(
	// 	"..//test_cases//sample_test_cases_expected_output.txt",
	// 	"w", stdout
	// );
	// freopen(
	// 	"..//test_cases//handmade_test_cases_input.txt",
	// 	"r", stdin
	// );
	// freopen(
	// 	"..//test_cases//handmade_test_cases_expected_output.txt",
	// 	"w", stdout
	// );
	// freopen(
	// 	"..//test_cases//generated_small_test_cases_input.txt",
	// 	"r", stdin
	// );
	// freopen(
	// 	"..//test_cases//generated_small_test_cases_expected_output.txt",
	// 	"w", stdout
	// );
	// freopen(
	// 	"..//test_cases//generated_big_test_cases_input.txt",
	// 	"r", stdin
	// );
	// freopen(
	// 	"..//test_cases//generated_big_test_cases_expected_output.txt",
	// 	"w", stdout
	// );
	// freopen(
	// 	"..//test_cases//ignore.txt",
	// 	"w", stdout
	// );

	int test_cases;
	cin >> test_cases;
	assert(test_cases >= 0);
	while (test_cases--)
	{
		int n;
		cin >> n;
		assert(1 <= n);
		assert(n <= MAX_N);
		vector<int> operations(n);
		int queries = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> operations[i];
			assert(MIN_VAL <= operations[i]);
			assert(operations[i] <= MAX_VAL);
			queries += (operations[i] == 0);
		}
		vector<int> ans = min_stack(operations);
		int len = ans.size();
		assert(len == queries);
		for (int i = 0; i < queries; i++)
		{
			cout << ans[i] << endl;
		}
		cout << endl;
	}

	return 0;
}