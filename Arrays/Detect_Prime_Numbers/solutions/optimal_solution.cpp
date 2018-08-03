#include<bits/stdc++.h>

using namespace std;

// ----------------------------- START -------------------------------

const int MAX_N = 300000, MAX_A = 4000000;

bool is_prime[MAX_A + 1];

void pre_process(int N, int max_value)
{
	fill_n(&is_prime[0], max_value + 1, true);
	// IMP. 1 is not a prime no. 
	is_prime[1] = false;														
	// i <= max_value is also correct but this more efficient. 
	for (int i = 2; i * i <= max_value; i++)									
	{
		/*
		Using int will overflow. Consider max_value = 10^6 now start = (10^6 *
		10^6) > INT_MAX! 
		*/
		long long int start = (long long int)i * (long long int)i;				
		if (start <= max_value)
		{
			/*
			In most of the implementations people start from j = i + i, but
			this will be just  waste of time. Think when i = 5 now we can visit
			like 10, 15, 20, 25, 30, 35... but here note that 10 = 2 * 5 so
			when i = 2 we have already marked it, same for 15 = 3 * 5 so when
			i = 3 we have already marked it! So it is same as starting from
			i * i. But directly starting from i * i will save time! 
			*/
			for (int j = start; j <= max_value; j += i)							
			{
				is_prime[j] = false;
			}
		}
	}
}

string detect_primes(vector<int> a)
{
	int N = a.size();

	pre_process(N, *max_element(a.begin(), a.end()));
	
	string ans(N, '0');
	for (int i = 0; i < N; i++)
	{
		if (is_prime[a[i]])
		{
			ans[i] = '1';
		}
		else
		{
			ans[i] = '0';
		}
	}
	return ans;
}

// ------------------------------ END --------------------------------

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//handmade_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//small_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//big_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	assert(1 <= test_cases);
	while (test_cases--)
	{
		int N;
		cin >> N;
		assert(1 <= N);
		assert(N <= MAX_N);
		vector<int> a(N);
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
			assert(1 <= a[i]);
			assert(a[i] <= MAX_A);
		}
		string ans = detect_primes(a);
		assert(ans.length() == N);
		for (int i = 0; i < N; i++)
		{
			assert(ans[i] == '0' || ans[i] == '1');
		}
		cout << ans << endl;
	}

	return 0;
}