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

const int MAX_N = 100000, MAX_VALUE = 1000000000;

void _2()
{
	int N1 = MAX_N / 2;
	cout << N1 << endl;
	for (int i = 0; i < N1; i++)
	{
		cout << random_number(MAX_VALUE + 1) << endl;
	}
	int N2 = MAX_N / 2;
	cout << N2 << endl;
	for (int i = 0; i < N2; i++)
	{
		cout << random_number(MAX_VALUE + 1) << endl;
	}
	cout << N1 << endl << endl;
}

void _1()
{
	int N1 = MAX_N / 2;
	cout << N1 << endl; 
	for (int i = 0; i < N1; i++)
	{
		cout << random_number(MAX_VALUE + 1) << endl;
	}
	int N2 = MAX_N / 2;
	cout << N2 << endl;
	for (int i = 0; i < N2; i++)
	{
		cout << random_number(MAX_VALUE + 1) << endl;
	}
	cout << N1 - 1 << endl << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);
	int test_cases = 2;
	cout << test_cases << endl << endl;
	_1();
	_2();

	return 0;
}