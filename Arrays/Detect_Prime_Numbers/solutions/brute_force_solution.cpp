#include<bits/stdc++.h>

using namespace std;

// ----------------------------- START -------------------------------

const int MAX_N = 300000, MAX_A = 4000000;

int check_if_prime(int no)
{
	if (no == 1)
	{
		return 0;
	}
	for (int i = 2; i < no; i++)						
	{
		if (no % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

string detect_primes(vector<int> a)
{
	int N = a.size();
	string ans(N, '0');
	for (int i = 0; i < N; i++)
	{
		if (check_if_prime(a[i]))
		{
			ans[i] = '1';
		}
		else
		{
			ans[i] = '0';
		}
	}
	return ans;
}

// ------------------------------ END --------------------------------

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//small_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//big_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	assert(1 <= test_cases);
	while (test_cases--)
	{
		int N;
		cin >> N;
		assert(1 <= N);
		assert(N <= MAX_N);
		vector<int> a(N);
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
			assert(1 <= a[i]);
			assert(a[i] <= MAX_A);
		}
		string ans = detect_primes(a);
		assert(ans.length() == N);
		for (int i = 0; i < N; i++)
		{
			assert(ans[i] == '0' || ans[i] == '1');
		}
		cout << ans << endl;
	}

	return 0;
}