#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, MIN_NO = -2000000000, MAX_NO = 2000000000;  

// -------------------------- START --------------------------

vector<int> max_in_sliding_window(vector<int> arr, int w)
{
	int n = arr.size();
	/*
	Input:
	arr = [1 3 -1 -3 5 3 6 7] (n = 8)
	w = 3

	Output:
	ans = [3, 3, 5, 5, 6, 7] (size = 6)
	
	Size of the ans = n - w + 1 = 8 - 3 + 1 = 6.
	*/
	vector<int> ans(n - w + 1);
	// Note that we are storing indices not values, in deque.
	deque<int> indices;
	/*
	Input:
	arr = [1 3 -1 -3 5 3 6 7] (n = 8)
	w = 3

	For each step we can uniquely define the window by its right most element index. 

	All possible windows:
	[1 3 -1] -3 5 3 6 7 -> 2 (and this index is w - 1)
	1 [3 -1 -3] 5 3 6 7 -> 3
	1 3 [-1 -3 5] 3 6 7 -> 4
	1 3 -1 [-3 5 3] 6 7 -> 5
	1 3 -1 -3 [5 3 6] 7 -> 6
	1 3 -1 -3 5 [3 6 7] -> 7 (and this index is n - 1)

	So for i = 0 to w - 2, we will just setup the deque and for i = w - 1 to n - 1, we will add 
	the answer. 
	*/
	for (int i = 0; i < n; i++)
	{
		/*
		Suppose arr[j] <= arr[i] where j < i, then arr[j] is not needed, it can be removed. 
		ith number is on the right side of jth number and jth number is <= ith number, so jth 
		number can never be the answer for further calculations! 
		Try some examples to understand this clearly!
		*/
		while (!indices.empty() && arr[indices.back()] <= arr[i])
		{
			indices.pop_back();
		}
		// Add current index.
		indices.push_back(i);
		// If i >= w - 1 then add the answer for window arr[i - w + 1, i].
		if (i >= w - 1)
		{
			/*
			Current window should only see elements in arr[i - w + 1, i], so remove previous 
			elements if any.
			When i >= w then only this while loop can be executed, so we have placed this inside 
			if statement.
			*/
			while (indices.front() <= i - w)
			{
				indices.pop_front();
			}
			/*
			Observe that deque contains numbers in decreasing order, so first number is the 
			maximum number! 
			*/
			ans[i - w + 1] = arr[indices.front()];
		}
	}
	return ans;
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
	while (test_cases--)
	{
		int n;
		cin >> n;
		assert(1 <= n);
		assert(n <= MAX_N);
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			assert(MIN_NO <= arr[i]);
			assert(arr[i] <= MAX_NO);
		}
		int w;
		cin >> w;
		assert(1 <= w);
		assert(w <= n);

		vector<int> ans = max_in_sliding_window(arr, w);
		
		int len = ans.size();
		assert(len == n - w + 1);
		// cout << len << endl;
		for (int i = 0; i < len; i++)
		{
			//set<int> vals(arr.begin() + i, arr.begin() + i + w);
			//assert(ans[i] == *vals.rbegin());
			cout << ans[i] << endl;
		}
		cout << endl;
	}

	return 0;
}