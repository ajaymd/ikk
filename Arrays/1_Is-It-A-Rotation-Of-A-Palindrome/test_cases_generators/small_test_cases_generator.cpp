#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

long long int random_number(long long int mod)
{
	long long int number = rand();
	number |= ((long long int)rand() << 31LL);
	return number % mod;  
}

void random_string()
{
	int N = random_number(MAX_N) + 5;
	for (int i = 0; i < N; i++)
	{
		cout << (char)('a' + random_number(26));
	}
	cout << endl;
}

void random_palindrome()								
{
	string s = "";
	int N = random_number(MAX_N) + 5;
	if (N % 2)
	{
		s += (char) ('a' + random_number(26));
	}
	for (int i = 0; i < N / 2; i++)
	{
		int temp = random_number(26);
		s = (char)('a' + temp) + s + (char)('a' + temp);
	}
	s = s + s;
	s = s.substr(N / 2, N);										
	cout << s << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//small_test_cases_input.txt", "w", stdout);

	int test_cases = 100;
	cout << test_cases << endl;
	for (int i = 0; i < test_cases; i++)
	{
		int type = random_number(2);
		if (type)
		{
			random_palindrome();
		}
		else
		{
			random_string();
		}
	}

	return 0;
}