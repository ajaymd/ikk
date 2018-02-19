#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

// ----------------------- START -----------------------

string move_letters_to_left_side_with_minimizing_memory_writes(string s)
{
	int len = s.length();
	// Position where we should put next encountered letter.
	int write_here = 0;
	for (int i = 0; i < len; i++)
	{
		// Check if letter.
		if (!isdigit(s[i]))
		{
			/* 
			We want to minimize write operations, so writes like s[same position]=s[same position]
			having no effect can be avoided.

			Consider s = "ABCD234efg" -> "ABCDefgefg". When i = 0, write_here will also be 0, so 
			it will try to do s[0] = s[0] but this has no effect and can be avoided to reduce the 
			memory writes. 
			*/
			if (i != write_here)
			{
				s[write_here] = s[i];
			}
			/* 
			At write_here position we have put a letter (if if block is executed) or letter is 
			already present at that position (if if block is not executed), so store next letter 
			at write_here++ position. 
			*/
			write_here++;
		}
	}
	return s;
}

// ----------------------- STOP ------------------------


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
	while (test_cases--)
	{
		string s;
		cin >> s;
		assert(1 <= s.length());
		assert(s.length() <= MAX_N);
		string ret = move_letters_to_left_side(s);
		assert(ret.length() == s.length());
		cout << ret << endl;
	}

	return 0;
}