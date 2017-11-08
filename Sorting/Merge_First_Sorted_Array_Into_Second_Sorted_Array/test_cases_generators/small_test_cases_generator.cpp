#include<bits/stdc++.h>

using namespace std;

// ----------------------------------------------------------------------

long long int MAX_MOD = 1000000000000000000LL;

// Random number in range [0, mod). Mod should be <= 10^18.

long long int random_number(long long int mod)	
{
	assert(1 <= mod);
	assert(mod <= MAX_MOD);
	if (RAND_MAX == 32767)
	{
		long long int no = rand();	
		no |= ((long long int)rand() << 15LL);
		no |= ((long long int)rand() << 30LL);
		no |= ((long long int)rand() << 45LL);
		no |= ((long long int)rand() << 47LL);
		return no % mod;
	}
	else if (RAND_MAX == 2147483647)
	{
		long long int no = rand();
		no |= ((long long int)rand() << 31LL);
		return no % mod;  
	}
	assert(false);
	return -1;
}

// --------------------------------------------------------------------------

const int MAX_N = 1000, MAX_VAL = 200;

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_small_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 100;
	cout << test_cases << endl;
	while (test_cases--)
	{
		cout << endl;
		int n = random_number(MAX_N);
		cout << n << endl;
		vector<int> arr1(n);
		for (int i = 0; i < n; i++)
		{
			arr1[i] = random_number(MAX_VAL) + 1;
		}
		sort(arr1.begin(), arr1.end());
		for (int i = 0; i < n; i++)
		{
			cout << arr1[i] << endl;
		}

		cout << n + n << endl;
		vector<int> arr2(n);
		for (int i = 0; i < n; i++)
		{
			arr2[i] = random_number(MAX_VAL) + 1;
		}
		sort(arr2.begin(), arr2.end());
		for (int i = 0; i < n; i++)
		{
			cout << arr2[i] << endl;
		}
		for (int i = 0; i < n; i++)
		{
			cout << 0 << endl;
		}
	}

	return 0;
}