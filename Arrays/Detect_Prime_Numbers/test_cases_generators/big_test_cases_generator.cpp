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

const int MAX_N = 300000, MAX_A = 4000000;

void _3()
{
	cout << MAX_N << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		//cout << 2999999 << endl;
		cout << 3999971 << endl;
	}	
	cout << endl;
}

void _2()
{
	cout << MAX_N << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << random_number(MAX_A) + 1 << endl;
	}	
	cout << endl;
}

void _1()
{
	cout << MAX_N << endl;
	int no = MAX_A;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << no-- << endl;
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 3;
	cout << test_cases << endl << endl;
	_1();
	_2();
	_3();

	return 0;
}