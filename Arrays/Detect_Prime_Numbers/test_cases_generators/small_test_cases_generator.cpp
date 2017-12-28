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

const int MAX_N = 1000, MAX_A = 4000000;

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//small_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);
	
	int test_cases = 100;
	cout << test_cases << endl << endl;
	for (int i = 0; i < test_cases; i++)
	{
		int N = random_number(MAX_N) + 1;
		cout << N << endl;
		assert(1 <= N);
		assert(N <= MAX_N);
		for (int j = 0; j < N; j++)
		{
			int no = random_number(MAX_A) + 1;
			assert(1 <= no);
			assert(no <= MAX_A);
			cout << no << endl;
		}
		cout << endl;
	}

	return 0;
}