#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

// ----------------------- START -------------------------

/*
Suppose s = "abcdefgh" and we call reverse_string(s[2], 4) then this function will reverse "cdef" 
part of "abcdefgh".  
*/
void reverse_string(char *str, int len)
{
    for(int i = 0; i < len / 2; i++)
    {
        swap(str[i], str[len - 1 - i]);
    }
}

string reverse_ordering_of_words(string s)
{
    int len = s.length();
    // Reverse whole string.
    reverse_string(&s[0], len);
    int word_beginning = 0;
    // Find word boundaries and reverse word by word.
    for(int word_end = 0; word_end < len; word_end++)
    {
        if(s[word_end] == ' ')	
        {
            reverse_string(&s[word_beginning] , word_end - word_beginning);
            word_beginning = word_end + 1;
        }
    }
    /* 
	If there is no space at the end then last word will not be reversed in the above for loop. 
	So need to reverse it. 
	Think about s = "hi". 
	Reverse the last word.
    */
    reverse_string(&s[word_beginning], len - word_beginning);
    return s;
}

// ----------------------- STOP -------------------------

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
	// This is necessary! 
	getline(cin, scan_new_line);
	getline(cin, scan_new_line);
	while (test_cases--)
	{
		string s;
		getline(cin, s);
		assert(1 <= s.length());
		assert(s.length() <= MAX_N);
		cout << reverse_ordering_of_words(s) << endl;
	}

	return 0;
}