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

const int MAX_N = 500;

string all_chars = "";

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
	freopen("..//test_cases//generated_small_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	setup();

	int test_cases = 100;
	cout << test_cases << endl << endl;
	for (int i = 0; i < test_cases; i++)
	{
		int n = random_number(MAX_N) + 1;
		for (int i = 0; i < n; i++)
		{
			cout << all_chars[random_number(all_chars.length())];
		}
		cout << endl;
	}

	return 0;
}