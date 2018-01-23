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

const int MAX_N = 100000, MAX_VAL = 2000000000;



int main()
{
	srand(time(NULL));
	freopen("..//test_cases//big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 2;
	cout << test_cases << endl;
	while (test_cases--)
	{
		cout << endl;
		int N = random_number(MAX_N) + 1;
		cout << N << endl;
		multiset<int> ms;
		for (int i = 0; i < N; i++)
		{
			ms.insert(2LL * ((random_number(2LL * MAX_VAL + 1LL) - MAX_VAL) / 2LL));
		}
		assert(ms.size() == N);
		if (random_number(2))
		{
			for (auto it = ms.begin(); it != ms.end(); it++)
			{
				cout << *it << endl;
			}	
		}
		else
		{
			for (auto it = ms.rbegin(); it != ms.rend(); it++)
			{
				cout << *it << endl;
			}	
		}
		cout << random_number(N) << endl;
	}

	return 0;
}