#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, MIN_VAL = -1, MAX_VAL = 2000000000;

// -------------------------- START --------------------------

vector<int> min_stack(vector<int> operations)
{
	int n = operations.size();
	vector<int> ans;
	// At any point of time min_till_now.top() will contain minimum of all elements present in stack.
	stack<int> min_till_now;
	for (int i = 0; i < n; i++)
	{
		if (operations[i] >= 1)
		{
			/*
			If stack is empty then after adding operations[i], minimum of entire stack will become
			operations[i]. 
			If stack is not empty then after adding operations[i], minimum of entire stack will 
			become min(operations[i], minimum of already present elements in stack).
			*/
			int minimum_value = operations[i];
			if (min_till_now.empty() == false)
			{
				minimum_value = min(minimum_value, min_till_now.top());
			}
			min_till_now.push(minimum_value);
		}
		else if (operations[i] == -1)
		{
			if (min_till_now.empty() == false)
			{
				min_till_now.pop();
			}
		}
		else
		{
			if (min_till_now.empty())
			{
				// If stack is empty, consider -1 as the minimum element.
				ans.push_back(-1);
			}
			else
			{
				/*
				min_till_now.top() contains the minimum of all elements present in stack 
				simple_stack. 
				*/
				ans.push_back(min_till_now.top());
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