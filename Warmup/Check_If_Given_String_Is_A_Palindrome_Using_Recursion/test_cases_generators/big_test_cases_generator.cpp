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

string punctuation = ".,!-;:'\"";

void _4(int &test_cases)
{
	test_cases--;
	int n = MAX_N;
	for (int i = 0; i < n; i++)
	{
		int type = random_number(100) + 1;
		if (type <= 50)
		{
			cout << punctuation[random_number(punctuation.length())]; 
		}
		else if (type <= 75)
		{
			char ch = random_number(26) + 'a'; 
			cout << ch;
		}
		else
		{
			char ch = random_number(26) + 'A'; 
			cout << ch;	
		}
	}
	cout << endl;
}
 

void _3(int &test_cases, string mid)
{
	test_cases--;
	int n = MAX_N - 1;
	string l = "";
	string r = "";
	for (int i = 0; i < n / 2; i++)
	{
		int type = random_number(100) + 1;
		if (type <= 50)
		{
			char ch = punctuation[random_number(punctuation.length())]; 
			l = l + ch;
			r = ch + r;
		}
		else if (type <= 75)
		{
			char ch = random_number(26) + 'a'; 
			l = l + ch;
			r = ch + r;
		}
		else
		{
			char ch = random_number(26) + 'A'; 
			l = l + ch;
			r = ch + r;	
		}
	}
	assert(mid.length() <= 1);
	cout << l << mid << r;
	cout << endl;
}

void _2(int &test_cases)
{
	test_cases--;
	int n = MAX_N;
	for (int i = 0; i < n; i++)
	{
		if (random_number(2))
		{
			cout << 'K';
		}
		else
		{
			cout << '!';	
		}
	}
	cout << endl;
}

void _1(int &test_cases, char ch)
{
	test_cases--;
	int n = MAX_N;
	for (int i = 0; i < n; i++)
	{
		cout << ch;
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 7;
	cout << test_cases << endl << endl;
	_1(test_cases, '.');
	_1(test_cases, 'e');
	_2(test_cases);
	_3(test_cases, "");
	_3(test_cases, "G");
	_3(test_cases, "-");
	_4(test_cases);
	assert(test_cases == 0);

	return 0;
}