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

const int MAX_N = 100000, MAX_K = 100000, MAX_FILE = 100000, MAX_SUM_N = 100000;



int main()
{
	srand(time(NULL));
	freopen("..//test_cases//big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);
	string file = "";
	int file_length = 100000;
	for (int i = 0; i < file_length; i++)
	{
		file += (char)(random_number(26) + 'a');
	}
	cout << file << endl;
	int K = 13;
	cout << K << endl;
	int queries = 100;
	cout << queries << endl;
	for (int i = 0; i < queries; i++)
	{
		cout << random_number(1001) << endl;
	}

	return 0;
}