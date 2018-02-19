#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

// ------------------------ START ---------------------

/*
Function to recursively check, if string s in range start to end (both inclusive), is a valid 
palindrome or not.
*/
bool recursive_palindrome_check(string &s, int start, int end)
{
	/* 
	1) start == end. 
	String containing only one character is always a palindrome.
	2) start > end.
	Empty string is always a palindrome. 
	*/
	if (start >= end)
	{
		return true;
	}
	// If s[start] is not an alphabetical character then ignore it.
	if (isalpha(s[start]) == false)
	{
		return recursive_palindrome_check(s, start + 1, end);
	}
	// If s[end] is not an alphabetical character then ignore it. 
	if (isalpha(s[end]) == false)
	{
		return recursive_palindrome_check(s, start, end - 1);
	}
	/*
	If s[start] and s[end] both are alphabetical characters then compare them ignoring their cases
	and if they found to be same then continue check after ignoring both alphabetical characters.
	*/
	if (tolower(s[start]) == tolower(s[end]))
	{
		return recursive_palindrome_check(s, start + 1, end - 1);
	}
	/*
	If s[start] and s[end] both are different alphabetical characters (after ignoring their cases)
	then s is not a palindrome.  
	*/
	return false;
}

bool is_palindrome(string s)
{
	// Check if string s is palindrome or not using recursion.
	return recursive_palindrome_check(s, 0, s.length() - 1);
}

// ------------------------ STOP ----------------------

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_small_test_cases_expected_output.txt", "w", stdout);
	freopen("..//test_cases//generated_big_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//generated_big_test_cases_expected_output.txt", "w", stdout);
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
		for (int i = 0; i < n; i++)
		{
			assert
			(
				isalpha(s[i]) || 
				s[i] == ' ' || 
				s[i] == '.' || 
				s[i] == ',' || 
				s[i] == '!' || 
				s[i] == '-' || 
				s[i] == ';' || 
				s[i] == ':' || 
				s[i] == '\'' || 
				s[i] == '"'
			);
		}
		cout << is_palindrome(s) << endl;
	}	

	return 0;
}