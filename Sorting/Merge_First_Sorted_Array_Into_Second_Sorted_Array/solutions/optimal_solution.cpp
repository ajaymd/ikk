#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, MAX_VAL = 2000000000;

// ---- START ----

vector<int> merger_first_into_second(vector<int> arr1, vector<int> arr2)
{
	int n = arr1.size();
	// Start merging from the end. 
	int last1 = n - 1;
	int last2 = n - 1;
	int last = n + n - 1;
	// At least one element reamining. 
	while (last >= 0)
	{
		// If no elements remaining in arr1.
		if (last1 < 0)
		{
			arr2[last--] = arr2[last2--];
		}
		// If no elements remaining in arr2.
		else if (last2 < 0)
		{
			arr2[last--] = arr1[last1--];
		}
		// Priority to larger element, as we are merging from the end. 
		else if (arr1[last1] <= arr2[last2])
		{
			arr2[last--] = arr2[last2--];
		}
		else
		{
			arr2[last--] = arr1[last1--];
		}
	}
	return arr2;
}

// ---- STOP ----

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
		int n;
		cin >> n;
		assert(1 <= n);
		assert(n <= MAX_N);

		vector<int> arr(n + n);

		vector<int> arr1(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr1[i];
			assert(1 <= arr1[i]);
			assert(arr1[i] <= MAX_VAL);
			arr[i] = arr1[i];
			if (i != 0)
			{
				assert(arr1[i - 1] <= arr1[i]);
			}
		}

		int nn;
		cin >> nn;
		assert(n + n == nn);

		vector<int> arr2(n + n);
		for (int i = 0; i < n + n; i++)
		{
			cin >> arr2[i];
			if (i < n)
			{
				assert(1 <= arr2[i]);
				assert(arr2[i] <= MAX_VAL);
				arr[i + n] = arr2[i];
				if (i != 0)
				{
					assert(arr2[i - 1] <= arr2[i]);
				}
			}
			else
			{
				assert(arr2[i] == 0);
			}
		}

		vector<int> ans = merger_first_into_second(arr1, arr2);

		assert(ans.size() == n + n);

		sort(arr.begin(), arr.end());

		cout << n + n << endl;
		for (int i = 0; i < n + n; i++)
		{
			assert(ans[i] == arr[i]);
			cout << ans[i] << endl;
		}
		cout << endl;
	}

	return 0;
}