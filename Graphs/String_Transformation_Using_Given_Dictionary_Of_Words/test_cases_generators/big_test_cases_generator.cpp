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

const int MIN_NO_OF_CHARS = 2, MAX_NO_OF_CHARS = 100000;

void generate_test_case1(int &test_cases, int no_of_words, int len, int char_set)
{
	test_cases--;
	cout << endl;

	cout << no_of_words << endl;
	string s = "";
	for (int j = 0; j < len; j++)
	{
		s += (char) (random_number(char_set) + 'a');
	}
	for (int i = 0; i < no_of_words; i++)
	{
		int pos = random_number(len);
		char original = s[pos];
		s[pos] = (char) (random_number(char_set) + 'a');
		cout << s << endl;
		s[pos] = original;
	}
	cout << s << endl;
	for (int j = 0; j < len; j++)
	{
		cout << (char) (random_number(char_set) + 'a');
	}
	cout << endl;
}


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
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 12;
	cout << test_cases << endl;

	generate_test_case(test_cases, MAX_NO_OF_CHARS / 1 - 2, 1, 26);
	generate_test_case(test_cases, MAX_NO_OF_CHARS / 2 - 2, 2, 26);
	generate_test_case(test_cases, MAX_NO_OF_CHARS / 3 - 2, 3, 18);
	generate_test_case(test_cases, MAX_NO_OF_CHARS / 4 - 2, 4, 11);
	generate_test_case(test_cases, MAX_NO_OF_CHARS / 7 - 2, 7, 5);
	generate_test_case(test_cases, MAX_NO_OF_CHARS / 10 - 2, 10, 3);
	generate_test_case(test_cases, MAX_NO_OF_CHARS / 16 - 2, 16, 3);

	generate_test_case1(test_cases, 1, MAX_NO_OF_CHARS / (1 + 2), 26);
	generate_test_case1(test_cases, 2, MAX_NO_OF_CHARS / (2 + 2), 26);
	generate_test_case1(test_cases, 3, MAX_NO_OF_CHARS / (3 + 2), 5);
	generate_test_case1(test_cases, 4, MAX_NO_OF_CHARS / (4 + 2), 3);
	generate_test_case1(test_cases, 5, MAX_NO_OF_CHARS / (5 + 2), 2);

	assert(test_cases == 0);

	return 0;
}