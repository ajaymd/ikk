#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, MAX_K = 100000, MAX_FILE = 100000, MAX_SUM_N = 100000;

//--------------------------------------START-----------------------------------------

// You need to declare this. Global scope so that read_K function can use it.
string file;													
// You need to declare this. Global scope so that read_K function can use it.
int K;															

// You need to implement this in language you are using in exactly the same manner given here. 
string read_K()													
{
	// Used static because we want to read from where we left in previous read
	static int ptr = 0;											
	// Handle the case when remaining bytes < requested bytes
	int len = min(K, (int)file.length() - ptr);					
	// It is always better if we don't use concatinatin each time. like ans = ans + (some char)
	string ans (len, '0');										
	for (int i = 0; i < len; i++)
	{
		ans[i] = file[ptr++];
	}
	return ans;
}

// You need to implement and complete this. 
string read(int N)												
{
	/*
	Use static because out read should be consistent, it might be possible that read_K returns 
	more bytes than we needed.
	*/
	static string buffer = "";									
	// Some bytes might be remaining in buffer, so keep track of them. 
	static int buffer_ptr = 0;					
	/*
	Here also we could have first find the length of the answer so that we do not need to use 
	concatination each time, but for better readibility of code we preferred to do this way. 
	*/				
	string ans = "";											
	while (ans.length() < N)
	{
		if (buffer_ptr < buffer.length())
		{
			ans = ans + buffer[buffer_ptr++];				
		}
		else													
		{	
			// Nothing in buffer is left, read something new 
			buffer = read_K();
			buffer_ptr = 0;
			// If we have read the whole file. 
			if (buffer == "")									
			{
				return ans;
			}
		}
	}
	return ans;
}

vector<string> read_function_caller(string file, int K, vector<int> value_of_n)
{
	// Initialize the global variables.
	::file = file;												
	::K = K;													

	int queries = value_of_n.size();
	vector<string> ans;
	for (int i = 0; i < queries; i++)
	{
		ans.push_back(read(value_of_n[i]));
	}
	return ans;
}

//-------------------------------------END---------------------------------------

int main()
{
	freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//sample_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//small_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//big_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	string file;
	getline(cin, file);
	//cout << file << endl;
	assert(file.length() <= MAX_FILE);
	int K;
	cin >> K;
	assert(1 <= K);
	assert(K <= MAX_K);
	int queries;
	cin >> queries;
	vector<int> value_of_n(queries);
	int sum_N = 0;
	for (int i = 0; i < queries; i++)
	{
		int N;
		cin >> N;
		assert(0 <= N);
		assert(N <= MAX_N);
		sum_N += N;
		assert(sum_N <= MAX_SUM_N);
		value_of_n[i] = N;
	}
	vector<string> ans = read_function_caller(file, K, value_of_n);
	for (int i = 0; i < queries; i++)
	{
		assert(ans[i].length() <= value_of_n[i]);
		cout << ans[i] << endl;
	}

	return 0;
}
