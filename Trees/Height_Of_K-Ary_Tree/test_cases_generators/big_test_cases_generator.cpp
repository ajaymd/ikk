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

_2()
{
	cout << endl;
	int N = MAX_N;
		
	int k = 0;
	vector<int> from;
	vector<int> to;
	vector<int> edges[MAX_N];

	for (int i = 2; i <= N; i++)
	{
		int no = random_number(i - 1) + 1;				// (1 to i - 1)
		from.push_back(no);
		to.push_back(i);
		edges[no].push_back(i);
		k = max(k, (int)edges[no].size());
	}
	cout << k << endl;
	cout << from.size() << endl;
	for (int i = 0; i < from.size(); i++)
	{
		cout << from[i] << endl;
	}
	cout << to.size() << endl;
	for (int i = 0; i < to.size(); i++)
	{
		cout << to[i] << endl;
	}	
}

_1()
{
	cout << endl;
	cout << 1 << endl;
	int N = MAX_N;
	cout << N - 1 << endl;
	for (int i = 1; i < N; i++)
	{
		cout << i << endl;
	}
	cout << N - 1 << endl;
	for (int i = 2; i <= N; i++)
	{
		cout << i << endl;
	}
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);
	cout << 3 << endl;
	_1();
	_2();
	_2();

	return 0;
}