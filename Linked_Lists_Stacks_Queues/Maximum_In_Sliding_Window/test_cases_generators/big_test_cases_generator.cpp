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

const int MAX_N = 100000, MIN_NO = -2000000000, MAX_NO = 2000000000;

void _2(int n, int w, int &test_cases)
{
	cout << endl;
	test_cases--;
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << random_number(2LL * (long long int) MAX_NO + 1LL) - MAX_NO << endl;
	}
	cout << w << endl;
}

void _1(int no, int w, int &test_cases)
{
	cout << endl;
	test_cases--;
	int n = MAX_N;
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << no << endl;
	}
	cout << w << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 6;
	cout << test_cases << endl;

	_1(MAX_NO, MAX_N, test_cases);
	_1(MIN_NO, 1, test_cases);
	
	_2(MAX_N, MAX_N, test_cases);
	_2(MAX_N, 1, test_cases);
	_2(MAX_N - 1, 59, test_cases);
	_2(MAX_N - 2, 307,test_cases);

	assert(test_cases == 0);

	return 0;
}