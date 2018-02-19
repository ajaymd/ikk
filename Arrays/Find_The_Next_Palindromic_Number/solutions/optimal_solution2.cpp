#include<bits/stdc++.h>

using namespace std;

// -------------------------- START --------------------------

// Function to convert long long int to string.
string lli_to_string(long long int no)
{
	if (no == 0LL)
	{
		return "0";
	}
	string no_str = "";
	while (no)
	{
		no_str = (char) (no % 10LL + '0') + no_str;
		no /= 10LL;
	}
	return no_str;
}

// Function to convert string to long long int.
long long int string_to_lli(string no_str)
{
	long long int no = 0LL;
	int len = no_str.length();
	for (int i = 0; i < len; i++)
	{
		no = 10LL * no + (no_str[i] - '0');
	}
	return no;
}

long long int next_palindrome(int n)
{
	string n_str = lli_to_string(n);
	int len = n_str.length();
	/*
	Will be used to divide string into left half and right half.
	n = 123456 -> left half= "123" -> right half = "456",
	n = 1234567 -> left half = "1234" -> right half = "567".
	*/
	int offset = len % 2;
	/*
	n = 999 -> all_nine_case = 1001,
	n = 125 -> all_nine_case = 1001.

	Suppose n = 2147447411 -> all_nine_case = 10000000001, which can not be stored in int, so use 
	long long int to avoid overflow. 
	*/
	long long int all_nine_case = pow(10, len) + 1LL;
	/*
	n = 123456 -> left_half_str = "123",
	n = 1234567 -> left_half_str = "1234".
	*/
	string left_half_str = n_str.substr(0, len / 2 + offset);
	/*
	n = 123456 -> left_half_str = "123" -> left_half_plus_one_str = "124",
	n = 1234567 -> left_half_str = "1234" -> left_half_plus_one_str = "1235".
	*/ 
	string left_half_plus_one_str = lli_to_string(string_to_lli(left_half_str) + 1LL);
	/*
	n = 123456 -> left_half_str = "123" -> mirror_without_addition_case = 123321,
	n = 1234567 -> left_half_str = "1234" -> mirror_without_addition_case = 1234321.
	*/
	long long int mirror_without_addition_case = string_to_lli(
		left_half_str + 
		string(
			left_half_str.rbegin() + 
			offset, left_half_str.rend()
		)
	);
	/*
	n = 123456 -> left_half_str = "123" -> left_half_plus_one_str = "124" -> 
	mirror_with_addition_case = 124421,
	n = 1234567 -> left_half_str = "1234" -> left_half_plus_one_str = "1235" -> 
	mirror_with_addition_case = 1235321.

	Suppose n = 2147447411 -> mirror_with_addition_case = 2147557412, which can not be stored in 
	int, so use long long int to avoid overflow. 
	*/ 
	long long int mirror_with_addition_case = string_to_lli(
		left_half_plus_one_str + 
		string(
			left_half_plus_one_str.rbegin() + 
			offset, 
			left_half_plus_one_str.rend()
		)
	);
	/*
	In these cases mirror_without_addition_case will be smaller than n, so it can not be the 
	answer.

	n = 123456 -> left_half_str = "123" -> mirror_without_addition_case = 123321,
	n = 1234567 -> left_half_str = "1234" -> mirror_without_addition_case = 1234321.

	In these cases mirror_without_addition_case will be greate than n, so it is the answer.

	n = 123156 -> left_half_str = "123" -> mirror_without_addition_case = 123321,
	n = 1234167 -> left_half_str = "1234" -> mirror_without_addition_case = 1234321.	
	*/
	if (mirror_without_addition_case - n > 0LL)
	{
		return mirror_without_addition_case;
	}
	// When mirror_without_addition_case - n <= 0.
	return min(all_nine_case, mirror_with_addition_case);
}

// -------------------------- STOP ---------------------------

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
	while (test_cases--)
	{
		long long int n;
		cin >> n;
		assert(0 <= n);
		assert(n <= INT_MAX);
		long long int ans = next_palindrome(n);
		cout << ans << endl;
	}

	return 0;
}