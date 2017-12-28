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

const int MAX_NODES = 100, MAX_WEIGHT = 2000000000;

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_small_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 100;
	cout << test_cases << endl;
	while(test_cases--)
	{
		cout << endl;
		int dag_nodes = random_number(MAX_NODES) + 1;
		int dag_edges = (dag_nodes * (dag_nodes - 1)) / 2;
		cout << dag_nodes << " " << dag_edges << endl;

		for (int i = 1; i <= dag_nodes; i++)
		{
			for (int j = i + 1; j <= dag_nodes; j++)
			{
				cout << i << " " << j << " " << random_number(MAX_WEIGHT) + 1 << endl;
			}
		}

		int from_node = random_number(dag_nodes) + 1;
		int to_node = random_number(dag_nodes) + 1;
		if (from_node > to_node)
		{
			swap(from_node, to_node);
		}

		cout << from_node << endl << to_node << endl;
	}

	return 0;
}