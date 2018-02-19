// Author: Dipen Dadhaniya 
// Optimal Solution 

#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 4000;





// ---------------------------------- START ------------------------------------

/*
Problem is very easy. Here is the link for one solution. 
http://www.geeksforgeeks.org/check-given-string-rotation-palindrome/ 
Still I will like to present other solution with same time complexity O(N^2) but more efficient. 
In the above solution substring and string concatination is used, but we can build our solution 
using just two pointers!  
First we will see when N is odd. Consider s = cdcbaab. Here observe that if we consider d as 
middle element then new string will look like abcdcba. So we only need to check if for atleast one
position after considering it as middle element we can get palindromic string or not. 
When N is even we do the same thing but now there will be two middle elements. Consider s = 
cddcbaab then we need to consider each two adj chars and check for palindromic string. If we 
consider dd as middle elements then new string will look like abcddcba. 
We are not using substring and concatination hence it will be more effective than the previous 
solition.  
*/

/*
Consider N = 7. When idx = 5 then after decrement idx = 4, when idx = 0 then after decrement 
idx = 6.  
*/
int decrement_index(int idx, int N)
{
	return (idx - 1 + N) % N;
}

/*
Consider N = 7. When idx = 5 then after increment idx = 6, when idx = 6 then after increment 
idx = 0. 
*/
int increment_index(int idx, int N)
{
	return (idx + 1) % N;
}

int check_if_rotated(string s)			
{
	int N = s.length();
	/* 
	When we start from the middle element/elements checking for palindrome, how many pairs we need
	to check. Take example of both odd and even and will get it. 
	*/
	int steps = (N + 1) / 2;							

	for (int i = 0; i < N; i++)
	{
		int l = i;
		int r = i;
		if (N % 2 == 0)
		{
			// N is even then two elements! 
			r = increment_index(r, N);					
		}
		bool valid = true;

		for (int j = 0; j < steps && valid; j++)
		{
			if (s[l] != s[r])
			{
				valid = false;
			}
			else
			{
				l = decrement_index(l, N);
				r = increment_index(r, N);	
			}
		}
		if (valid == true)
		{
			return 1;
		}
	}
	return 0;
}

// ---------------------------------- END ------------------------------------

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
		string s;
		cin >> s;
		int N = s.length();

		assert(1 <= N);
		assert(N <= MAX_N);
		
		for (int i = 0; i < N; i++)
		{
			assert('a' <= s[i]);
			assert(s[i] <= 'z');
		}

		int ans = check_if_rotated(s);
		
		assert(0 <= ans);
		assert(ans <= 1);
		
		cout << ans << endl;
	}

	return 0;
}