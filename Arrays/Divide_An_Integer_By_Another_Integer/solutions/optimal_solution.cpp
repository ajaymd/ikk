#include<bits/stdc++.h>

using namespace std;

const long long int MAX_AB = 1000000000000000000LL;


//-------------------------START------------------------------

long long int divide(long long int a, long long int b)
{
	if (a == 0)											// 0 / non_zero = 0
	{
		return 0;
	}
	if ((a < 0 && b > 0) || (a > 0 && b < 0))			// neg / pos or pos / neg
	{
		return -divide(abs(a), abs(b));
	}
	if (a < 0 && b < 0)									// neg / neg
	{
		return divide(-a, -b);
	}
	if (a < b)											// like 2 / 5
	{
		return 0;
	}
	long long int q = 1;								// long long int is imp
	long long int b_copy = b;							// long long int is imp
	while ((b_copy << 1) <= a)							// 37 / 3 can be written as 8 * (37 / (3 * 8)) + (37 - (3 * 8)) / 3
	{
		b_copy <<= 1;
		q <<= 1;
	}
	return q + divide(a - b_copy, b);
}

//-------------------------STOP------------------------------


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
	while (test_cases--)
	{
		long long int a, b;
		cin >> a >> b;
		assert(-MAX_AB <= a);
		assert(a <= MAX_AB);
		assert(-MAX_AB <= b);
		assert(b <= MAX_AB);
		assert(b != 0);
		long long int ans = divide(a, b);
		assert(ans == a / b);
		cout << ans << endl;
	}

	return 0;
}