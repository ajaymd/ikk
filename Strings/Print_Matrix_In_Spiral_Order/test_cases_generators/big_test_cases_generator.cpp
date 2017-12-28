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

const int MAX_ROWS_AND_COLS = 316;

void _1(int rows, int cols)
{
	cout << rows << endl;
	cout << cols << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (random_number(2))
			{
				cout << (char) (random_number(26) + 'a') << " ";
			}
			else
			{
				cout << (char) (random_number(26) + 'A') << " ";
			}
		}
		cout << endl;
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
	_1(316, 316); 
	_1(311, 317);
	_1(308, 318);
	_1(317, 315);
	_1(316, 313);

	return 0;
}