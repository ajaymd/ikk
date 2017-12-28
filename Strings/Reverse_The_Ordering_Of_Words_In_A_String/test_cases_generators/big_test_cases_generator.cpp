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

string all_chars = "";

void _3(int no_of_spaces_at_the_beginning, int no_of_spaces_at_the_end)
{
	for (int i = 0; i < no_of_spaces_at_the_beginning; i++)
	{
		cout << all_chars[0];
	}
	for (int i = 0; i < MAX_N - (no_of_spaces_at_the_beginning + no_of_spaces_at_the_end); i++)
	{
		cout << all_chars[random_number(all_chars.length())];
	}
	for (int i = 0; i < no_of_spaces_at_the_end; i++)
	{
		cout << all_chars[0];
	}
	cout << endl;
}

void _2() 
{
	for (int i = 0; i < MAX_N; i++)
	{
		cout << all_chars[0];
	}
	cout << endl;
}

void _1() 
{
	for (int i = 0; i < MAX_N; i++)
	{
		cout << all_chars[1];
	}
	cout << endl;
}

void setup()
{
	all_chars = " .,?!':;-";
	for (int i = 0; i < 26; i++)
	{
		all_chars += (char)('a' + i);
		all_chars += (char)('A' + i);
	}
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	setup();

	int test_cases = 5;
	cout << test_cases << endl << endl;
	_1();
	_2();
	_3(5, 10);
	_3(2, 11);
	_3(8, 4);

	return 0;
}