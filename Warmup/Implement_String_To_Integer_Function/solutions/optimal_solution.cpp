#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

// ---------------------- START ------------------------

int string_to_integer(string s)
{
	int n = s.length();
	int i = 0;
	// Find position of first digit. If no digit then i will be incremented to n.
	while (i < n && isdigit(s[i]) == false)
	{
		i++;
	}
	// Set the sign. 
	int sign = 1;
	if (i != 0 && s[i - 1] == '-')
	{
		sign = -1;
	}
	// Extract the integer without considering sign. We will add sign later.
	int ans = 0;
	while (i < n && isdigit(s[i]))
	{
		/*
		Suppose we have number 123 and we want to append 4 at the end to make it 1234, then it 
		can be done using, (123 * 10) + 4 = 1234.
		If we have string "1234", then to convert it to number by visiting left to right, we can 
		do 0 -> 1 -> 12 -> 123 -> 1234. 
		*/ 
		ans = (ans * 10) + (s[i] - '0');
		i++;
	}
	// Add the sign. 
	return sign * ans;
}

// ---------------------- STOP -------------------------


int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_small_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_big_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	string scan_new_line;
	getline(cin, scan_new_line);
	getline(cin, scan_new_line);
	while (test_cases--)
	{
		string s;
		getline(cin, s);
		int n = s.length();
		assert(1 <= n);
		assert(n <= MAX_N);
		bool at_lest_one_digit = false;
		for (int i = 0; i < n; i++)
		{
			if (isdigit(s[i]))
			{
				at_lest_one_digit = true;
				break;
			}
		}
		int ans = string_to_integer(s);
		cout << ans << endl;
	}


	return 0;
}