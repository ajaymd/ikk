#include<bits/stdc++.h>

using namespace std;

// -------------------------- START --------------------------

// Function to convert string to long long int.
long long int string_to_lli(string &no_str)
{
	long long int no = 0;
	int len = no_str.length();
	for (int i = 0; i < len; i++)
	{
		no = 10LL * no + (no_str[i] - '0');
	}
	return no;
}

/*	
	This function copies digit at position i to position len - 1 - i for i in range 0 to l. If 
	876555123 and l = 2, r = 6 then this function will return 876555678.   
*/
long long int copy_left_to_right(int len, string &n_str, int l, int r)
{
	while (l >= 0)
	{
		n_str[r] = n_str[l];
		l--;
		r++;
	}
	return string_to_lli(n_str);
}

/*
	This function adds 1 to lth position and propagates carry if needed. It also copies lth 
	position to rth position i.e if 190 then this function will return 202. 
*/
long long int add_to_mid_and_copy_left_to_right(int len, string &n_str, int l, int r)
{
	n_str[l]++;
	while (l >= 0)
	{
		if (n_str[l] >= char (10 + '0'))
		{
			n_str[l - 1]++;
			n_str[l] = (n_str[l] - '0') % 10 + '0';
		}
		n_str[r] = n_str[l];
		l--;
		r++;
	}
	return string_to_lli(n_str);
}

// Function to find next smallest palindrome of n_str.
long long int solve(int len, string &n_str, int l, int r)
{
	int l_copy = l, r_copy = r;
	/*
	Start from middle and try to find first mismatch. 
	n_str = "87655078", l = 3, r = 4.
	First compare n_str[3] and n_str[4], then n_str[2] and n_str[5], then n_str[1] and n_str[6]...
	We will stop when we will find the mismatch i.e. n_str[l] != n_str[r].
	*/
	while (l >= 0 && n_str[l] == n_str[r])
	{
		l--;
		r++;
	}
	// Given no is already palindrome i.e. 12321.
	if (l < 0)											
	{
		return add_to_mid_and_copy_left_to_right(len, n_str, l_copy, r_copy);
	}
	// No is of type 8(7)6(5)4 here 8 > 5 hence next smallest palindrome will be 87678.
	if (n_str[l] > n_str[r])									
	{
		return copy_left_to_right(len, n_str, l_copy, r_copy);
	}
	// No is of type 8(7)6(8)9 here 7 < 8 hence next smallest palindrome will be 87778. 
	else												
	{
		return add_to_mid_and_copy_left_to_right(len, n_str, l_copy, r_copy);	
	}
}

// Function to check if all digits are 9 or not.
bool all_nine(string &n_str)
{
	int len = n_str.length();
	for (int i = 0; i < len; i++)
	{
		if (n_str[i] != '9')
		{
			return false;
		}
	}
	return true;
}

// Function to convert int to string.
string int_to_string(int no)
{
	if (no == 0)
	{
		return "0";
	}
	string no_str = "";
	while (no)
	{
		no_str = (char) (no % 10 + '0') + no_str;
		no /= 10;
	}
	return no_str;
}

// Function to find next smallest palindrome of n.
long long int next_palindrome(int n) 
{
	string n_str = int_to_string(n);
	int len = n_str.length();
	// Only possible case when no of digits will be increased. 
	if (all_nine(n_str))									
	{
		long long int ret = 1LL;
		for (int i = 0; i < len; i++)
		{
			ret *= 10LL;
		}
		ret++;
		return ret;
	}
	// 1-indexed. When n = 1234321 then l = 4, r = 4 and when n = 12344321 then l = 4, r = 5.
	int l, r;											
	if (len % 2)									
	{
		l = (len + 1) / 2;
		r = (len + 1) / 2;
	}
	else										
	{
		l = len / 2;							
		r = len / 2 + 1;
	}
	// It will be easy if l and r are 0 indexed instead of 1 indexed. 
	return solve(len, n_str, l - 1, r - 1);					
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