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

const int MAX_ROWS = 100, MAX_COLS = 100, MAX_KEYS = 10;

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 100;
	cout << test_cases << endl;
	while(test_cases--)
	{
		cout << endl;
		int r = random_number(MAX_ROWS) + 1;
		int c = random_number(MAX_COLS) + 1;
		cout << r << endl;
		vector<vector<char>> grid(r, vector<char>(c));
		vector<pair<int, int>> land;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int temp = random_number(100);
				if (temp < 20)
				{
					grid[i][j] = '.';
					land.push_back({i, j});
				}
				else if (temp < 40)
				{
					grid[i][j] = '#';
				}
				else if (temp < 80)
				{
					grid[i][j] = (char)(random_number(MAX_KEYS) + 'a');
					land.push_back({i, j});
				}
				else
				{
					grid[i][j] = (char)(random_number(MAX_KEYS) + 'A');	
					land.push_back({i, j});
				}
			}
		}

		int temp1 = random_number(land.size());
		int temp2 = random_number(land.size());
		while (temp1 == temp2)
		{
			temp2 = random_number(land.size());
		}

		grid[land[temp1].first][land[temp1].second] = '@';
		grid[land[temp2].first][land[temp2].second] = '+';

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << grid[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}