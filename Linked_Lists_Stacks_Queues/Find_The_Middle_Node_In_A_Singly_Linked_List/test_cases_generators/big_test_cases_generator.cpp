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

const int MAX_N = 100000, MAX_NO = 2000000000;

void generate_test_case(int &test_cases, int n)
{
	test_cases--;
	cout << endl;
	cout << n << endl;
	while (n--)
	{
		cout << random_number(2LL * MAX_NO + 1LL) - MAX_NO << endl;
	}
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 28;
	cout << test_cases << endl;
	for (int i = 0; i <= 21; i++)
	{
		// Already in sample test cases.
		if (i != 4 && i != 5)
		{
			generate_test_case(test_cases, i);
		}
	}
	generate_test_case(test_cases, 577);
	generate_test_case(test_cases, 609);
	generate_test_case(test_cases, 723);

	generate_test_case(test_cases, MAX_N - 4);
	generate_test_case(test_cases, MAX_N - 3);
	generate_test_case(test_cases, MAX_N - 2);
	generate_test_case(test_cases, MAX_N - 1);
	generate_test_case(test_cases, MAX_N);

	assert(test_cases == 0);

	return 0;
}