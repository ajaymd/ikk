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

const int MIN_N = 0, MAX_N = 100000, MIN_VAL = -2000000000, MAX_VAL = 2000000000;

void generate_test_case(int &test_cases)
{
	test_cases--;
	cout << endl;

	int n = MAX_N - test_cases;
	cout << n << endl;
	while (n--)
	{
		cout << random_number(2LL * MAX_VAL + 1LL) - MAX_VAL << endl;
	}
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 4;
	cout << test_cases << endl;
	while(test_cases)
	{
		generate_test_case(test_cases);
	}
	assert(test_cases == 0);

	return 0;
}