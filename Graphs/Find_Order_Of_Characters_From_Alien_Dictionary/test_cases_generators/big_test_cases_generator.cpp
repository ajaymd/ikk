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

int MAX_CHARS = 100000;

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//generated_big_test_cases_input.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 15;
	cout << test_cases << endl;
	while (test_cases--)
	{
		cout << endl;
		int n;
		vector<string> words;
		int char_count = 0;
		while (char_count < MAX_CHARS)
		{
			int len = min(MAX_CHARS - char_count, (int)random_number(1500) + 1);
			char_count += len;
			string s = "";
			for (int i = 0; i < len; i++)
			{
				s += (char)(random_number(26) + 'a');
			}
			words.push_back(s);
		}
		string order = "";
		for (int i = 'a'; i <= 'z'; i++)
		{
			order = order + (char) i;
		}
		for (int i = 0; i < 26; i++)
		{
			int pos = random_number(26);
			swap(order[i], order[pos]);
		}
		n = words.size();
		sort(words.begin(), words.end());
		cout << n << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < words[i].length(); j++)
			{
				cout << order[words[i][j] - 'a'];
			}
			cout << endl;
		}
	}

	return 0;
}