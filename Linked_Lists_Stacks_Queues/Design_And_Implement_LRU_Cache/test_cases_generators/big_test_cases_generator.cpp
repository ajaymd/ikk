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

const int MAX_CAPACITY = 100000, MAX_N = 100000, MAX_KEY = 10000, MAX_VAL = 10000;

void special_test_case(int &test_cases, int n, int max_capacity, int max_key, int max_val)
{
	test_cases--;
	cout << endl;
	int capacity = max_capacity;
	cout << capacity << endl;

	cout << 99999 << endl;
	for (int j = 0; j < 49999; j++)
	{
		cout << 1 << endl;
	}
	for (int j = 0; j < 49999; j++)
	{
		cout << 0 << endl;
	}
	cout << 1 << endl;

	cout << 99999 << endl;
	for (int j = 0; j <	49999; j++)
	{
		cout << j + 1 << endl;
	}
	for (int j = 0; j < 49999; j++)
	{
		cout << j + 1 << endl;
	}
	cout << 50000 << endl;

	cout << 99999 << endl;
	for (int i = 0; i < 99999; i++)
	{
		cout << random_number(max_val) + 1 << endl;
	}
}

void generate_test_case(int &test_cases, int n = MAX_N, int max_capacity = MAX_CAPACITY, int max_key = MAX_KEY, int max_val = MAX_VAL)
{
	test_cases--;
	cout << endl;

	int capacity = random_number(max_capacity) + 1;
	cout << capacity << endl;
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << random_number(2) << endl;
	}
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << random_number(max_key) + 1 << endl;
	}
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << random_number(max_val) + 1 << endl;
	}
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 27;
	cout << test_cases << endl;
	generate_test_case(test_cases, 15, 3, 5, 5);
	generate_test_case(test_cases, 18, 3, 5, 5);
	for (int i = 0; i < 22; i++)
	{
		generate_test_case(test_cases, 500 + i, 50 + i, 50 + i, 50 + i);
	}
	generate_test_case(test_cases);
	generate_test_case(test_cases, MAX_N, 100, MAX_KEY, MAX_VAL);
	special_test_case(test_cases, MAX_N, 49999, 100000, 10000);

	assert(test_cases == 0);

	return 0;
}