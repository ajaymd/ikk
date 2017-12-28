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

const int MAX_N = 18;
const long long int MAX_VAL = 4;

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_small_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 20;
	cout << test_cases << endl;
	while (test_cases--)
	{
		cout << endl;
		int n = MAX_N;
		cout << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << random_number(2 * MAX_VAL + 1) - MAX_VAL << endl;
		}
		cout << (random_number(2) == 0 ? 1 : -1) * random_number(MAX_N * MAX_VAL / 2) << endl;
	}

	return 0;
}