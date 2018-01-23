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

	int test_cases = 3;
	cout << test_cases << endl;
	while (test_cases--)
	{
		cout << endl;
		int N = MAX_N;
		cout << N << endl;
		for (int i = 0; i < N / 2; i++)
		{
			cout << random_number(MAX_VAL + 1) << endl;
		}
		for (int i = 0; i < N / 2; i++)
		{
			if (i % 2)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << random_number(MAX_VAL + 1) << endl;
			}
		}
	}

	return 0;
}