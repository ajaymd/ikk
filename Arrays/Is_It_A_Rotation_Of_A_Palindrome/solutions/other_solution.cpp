#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 4000;

// Author: Dipen Dadhaniya
/*
From GeeksforGeeks http://www.cdn.geeksforgeeks.org/check-given-string-rotation-palindrome/ to 
verify the solution_optimal.cpp 
*/


// A utility function to check if a string str is palindrome
bool isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = str.length() - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
        if (str[l++] != str[h--])
            return false;
 
    // If we reach here, then all characters were matching
    return true;
}
 
// Function to check if a given string is a rotation of a
// palindrome.
bool check_if_rotated(string str)
{
   // If string iteself is palindrome
   if (isPalindrome(str))
         return true;
 
   // Now try all rotations one by one
   int n = str.length();
   for (int i = 0; i < n-1; i++)
   {
       string str1 = str.substr(i+1, n-i-1);
       string str2 = str.substr(0, i+1);
 
       // Check if this rotation is palindrome
       if (isPalindrome(str1.append(str2)))
          return true;
   }
   return false;
}

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//small_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//big_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//big_test_cases_output.txt", "w", stdout);
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
		
		int ans = check_if_rotated(s);
		
		assert(0 <= ans);
		assert(ans <= 1);
		
		cout << ans << endl;
	}

	return 0;
}