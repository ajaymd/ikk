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

int MAX_N = 100000;

void generate_test_case(int &test_cases, int n, int missing_no)
{
	test_cases--;
	vector<int> nos;
	for (int i = 1; i <= n; i++)
	{
		if (missing_no != i)
		{
			nos.push_back(i);
		}
	}
	random_shuffle(nos.begin(), nos.end());
	cout << n - 1 << endl;
	for (int i = 0; i < n - 1; i++)
	{
		cout << nos[i] << endl;
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
	generate_test_case(test_cases, MAX_N, 1);
	generate_test_case(test_cases, MAX_N, MAX_N);
	generate_test_case(test_cases, MAX_N, MAX_N / 2);
	/*
	65536 is a special number. 
	Try to find sum from 1 to 65536. 
	It is the first number for which sum of 1 to n will overflow int.
	Now in previous test cases (n * (n + 1)) / 2 as well as the sum of array (sum of 1 to n, except the missing number), both will overflow, hence solution using int with summation will get accepted! 
	Now in these test cases (n * (n + 1)) / 2 will overflow, but sum of array (sum of 1 to n, except the missing number) will not overflow! hence solution using int with summation will get wrong answer! 
	*/ 
	generate_test_case(test_cases, 65536, 33769);
	generate_test_case(test_cases, 65536, 43210);
	assert(test_cases == 0);

	return 0;
}