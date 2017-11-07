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

const int MAX_NODES = 51;

void gen_test_case()
{
	cout << endl;
	int nodes = random_number(MAX_NODES) + 50;
	int edges = nodes * (nodes - 1) / 5;

	cout << nodes << " " << edges << endl;
	set<pair<int, int>> e;
	while (e.size() < edges)
	{
		int from = random_number(nodes) + 1;
		int to = random_number(nodes) + 1;
		while (from == to)
		{
			to = random_number(nodes) + 1;
		}
		e.insert({from, to});
	}
	for (auto it = e.begin(); it != e.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_small_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 100;
	cout << test_cases << endl;
	while (test_cases--)
	{
		gen_test_case();
	}

	return 0;
}