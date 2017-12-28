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

const int MAX_N = 6000, MAX_VAL = 2000000000;

int _5()
{
	cout << endl;
	int N = MAX_N;
	cout << N << endl;
	for (int i = 0; i < N; i++)
	{
		cout << random_number(2LL * MAX_VAL + 1LL) - MAX_VAL << endl;
	}
	cout << random_number(N) + 1 << endl;
}

int _4()
{
	cout << endl;
	cout << MAX_N << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << MAX_N - i << endl;
	}
	cout << 1 << endl;
}

int _3()
{
	cout << endl;
	cout << MAX_N << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << MAX_N - i << endl;
	}
	cout << MAX_N << endl;
}

int _2()
{
	cout << endl;
	cout << MAX_N << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << i + 1 << endl;
	}
	cout << 1 << endl;
}

int _1()
{
	cout << endl;
	cout << MAX_N << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << i + 1 << endl;
	}
	cout << MAX_N << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);
	int test_cases = 6;
	cout << test_cases << endl;
	_1();
	_2();
	_3();
	_4();
	_5();
	_5();

	return 0;
}