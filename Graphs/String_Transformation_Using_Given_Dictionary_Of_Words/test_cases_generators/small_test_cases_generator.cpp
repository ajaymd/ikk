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

const int MIN_NO_OF_CHARS = 2, MAX_NO_OF_CHARS = 100000, MAX_NO_OF_WORDS = 500, MAX_LEN = 5;

void generate_test_case(int &test_cases, int no_of_words, int len, int char_set)
{
	test_cases--;
	cout << endl;

	cout << no_of_words << endl;
	for (int i = 0; i < no_of_words; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << (char) (random_number(char_set) + 'a');
		}
		cout << endl;
	}
	for (int j = 0; j < len; j++)
	{
		cout << (char) (random_number(char_set) + 'a');
	}
	cout << endl;
	for (int j = 0; j < len; j++)
	{
		cout << (char) (random_number(char_set) + 'a');
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_small_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 9;
	cout << test_cases << endl;
	while(test_cases)
	{
		int no_of_words = random_number(MAX_NO_OF_WORDS) + 400;
		int len = random_number(MAX_LEN) + 2;
		generate_test_case(test_cases, no_of_words, len, 5);
	}
	assert(test_cases == 0);

	return 0;
}