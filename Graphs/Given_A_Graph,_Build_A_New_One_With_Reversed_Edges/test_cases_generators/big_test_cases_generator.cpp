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

const int MAX_NODES = 315;

void _4()
{
	cout << endl;
	int edges = MAX_NODES * (MAX_NODES - 1) / 2;
	cout << MAX_NODES << " " << edges << endl;
	set<pair<int, int>> e;
	while (e.size() < edges)
	{
		int from = random_number(MAX_NODES) + 1;
		int to = random_number(MAX_NODES) + 1;
		while (from == to)
		{
			to = random_number(MAX_NODES) + 1;
		}
		e.insert({from, to});
	}
	for (auto it = e.begin(); it != e.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}

void _3()
{
	cout << endl;
	int edges = MAX_NODES * (MAX_NODES - 1) / 3;
	cout << MAX_NODES << " " << edges << endl;
	set<pair<int, int>> e;
	while (e.size() < edges)
	{
		int from = random_number(MAX_NODES) + 1;
		int to = random_number(MAX_NODES) + 1;
		while (from == to)
		{
			to = random_number(MAX_NODES) + 1;
		}
		e.insert({from, to});
	}
	for (auto it = e.begin(); it != e.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}

void _2()
{
	cout << endl;
	cout << MAX_NODES << " " << MAX_NODES * (MAX_NODES - 1) << endl;
	for (int i = 1; i <= MAX_NODES; i++)
	{
		for (int j = 1; j <= MAX_NODES; j++)
		{
			if (i != j)
			{
				cout << i << " " << j << endl;
			}
		}
	}
}

void _1()
{
	cout << endl;
	cout << MAX_NODES << " " << MAX_NODES << endl;
	for (int i = 1; i < MAX_NODES; i++)
	{
		cout << i << " " << i + 1 << endl;
	}
	cout << MAX_NODES << " " << 1 << endl;
}


int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 4;
	cout << test_cases << endl;

	_1();
	_2();
	_3();
	_4();

	return 0;
}