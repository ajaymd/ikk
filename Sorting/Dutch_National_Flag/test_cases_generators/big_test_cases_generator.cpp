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

const int MAX_N = 200000;

void gen_test_case()
{
	cout << endl;
	int n = MAX_N;
	string balls = "";
	while (n--)
	{
		int rn = random_number(3);
		if (rn == 0)
		{
			balls += 'B';
		}
		else if (rn == 1)
		{
			balls += 'R';
		}
		else
		{
			balls += 'G';
		}
	}
	cout << balls << endl;
}

void _2(int &test_cases, string order)
{
	test_cases--;
	cout << endl;
	int n = MAX_N;
	int nby3 = n / 3;
	for (int i = 0; i < nby3; i++)
	{
		cout << order[0];
	}
	for (int i = 0; i < nby3; i++)
	{
		cout << order[1];
	}
	for (int i = 0; i < n - 2 * nby3; i++)
	{
		cout << order[2];
	}
	cout << endl;
}

void _1(int &test_cases)
{
	test_cases--;
	cout << endl;
	int n = MAX_N;
	for (int i = 0; i < n; i++)
	{
		cout << 'B';
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 20;
	cout << test_cases << endl;
	_1(test_cases);
	string order = "BGR";

	do
	{
		_2(test_cases, order);
	
	}while (next_permutation(order.begin(), order.end()));

	while (test_cases--)
	{
		gen_test_case();
	}

	return 0;
}