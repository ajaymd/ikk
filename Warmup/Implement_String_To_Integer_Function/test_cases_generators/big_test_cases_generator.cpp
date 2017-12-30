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

const int MAX_N = 100000;

void _3(int & test_cases, string l, string m, string r)
{
	test_cases--;
	int n = MAX_N - 30;
	string s = "";
	for (int i = 0; i < n; i++)
	{
		int type = random_number(100) + 1;
		if (type <= 10)
		{
			s += ".";
		}
		else if (type <= 20)
		{
			s += "+";
		}
		else if (type <= 30)
		{
			s += "-";
		}
		else if (type <= 65)
		{
			s += (char) (random_number(26) + 'a');
		}
		else
		{
			s += (char) (random_number(26) + 'A');
		}
	}
	s = l + s.substr(0, n / 2) + m + s.substr(n / 2, n - (n / 2)) + r;
	cout << s << endl;
}

void _2(int & test_cases)
{
	test_cases--;
	cout << "-";
	for (int i = 0; i < MAX_N - 2; i++)
	{
		cout << "a";	
	}
	cout << "-";
	cout << endl;
}

void _1(int & test_cases)
{
	test_cases--;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << "0";	
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 5;
	cout << test_cases << endl << endl;
	_1(test_cases);
	_2(test_cases);
	_3(test_cases, "-98765432", "+234567", "57843");
	_3(test_cases, "", "578462.5876", "875+63");
	_3(test_cases, "+", "", "-2.");
	assert(test_cases == 0);

	return 0;
}