#include<bits/stdc++.h>

using namespace std;

const long long int MAX_AB = 1000000000000000000LL;


//-------------------------START------------------------------

long long int divide(long long int a, long long int b)
{
	// 0 / non_zero = 0
	if (a == 0)											
	{
		return 0;
	}
	// neg / pos or pos / neg
	if ((a < 0 && b > 0) || (a > 0 && b < 0))			
	{
		return -divide(abs(a), abs(b));
	}
	// neg / neg
	if (a < 0 && b < 0)									
	{
		return divide(-a, -b);
	}
	// like 2 / 5
	if (a < b)											
	{
		return 0;
	}
	// 37 / 3 can be written as 8 * (37 / (3 * 8)) + (37 - (3 * 8)) / 3
	int no_of_shifts = 0;
	while ((b << (no_of_shifts + 1)) <= a)
	{
		no_of_shifts++;
	}
	return (1LL << no_of_shifts) + divide(a - (b << no_of_shifts), b);
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