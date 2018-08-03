#include<bits/stdc++.h>

using namespace std;

int input_counter = 0;					// for inputxxx.txt
int output_counter = 0;					// for outputxxx.txt

/*
When counter is 5 then return "005" when counter is 48 then return "048" when
counter is 123 then return "123"
*/
string integer_to_string(int counter)
{
	string ret = "";
	while (counter)
	{
		ret = (char)('0' + counter % 10) + ret;
		counter /= 10;
	}
	while (ret.length() < 3)
	{
		ret = '0' + ret;
	}
	return ret;					
}

/*
If we have added output for 5 testcases (output000.txt to output004.txt) then
this will return output005.txt
*/
string file_name_for_next_output()
{
	string no = integer_to_string(output_counter);
	output_counter++;
	return "..//parsed_test_cases_for_hackerrank//output" + no + ".txt";
}

/*
If we have added input for 5 testcases (input000.txt to input004.txt) then this
will return input005.txt
*/
string file_name_for_next_input()
{
	string no = integer_to_string(input_counter);
	input_counter++;
	return "..//parsed_test_cases_for_hackerrank//input" + no + ".txt";
}

// According to problem statement output format complete this method. 
/*
If output is a string then:

string file_name = file_name_for_next_output();
freopen(file_name.c_str(), "w", stdout);
string s;
cin >> s;
cout << s << endl;

Here we are writing to some outputxxx.txt file. 

Make sure that we are using appropriate format (like endl, spaces, tabs etc).
*/
void copy_output()
{
	string file_name = file_name_for_next_output();
	freopen(file_name.c_str(), "w", stdout);
	// start from here
	string s;
	cin >> s;
	cout << s << endl;
}

// According to problem statement input format complete this method. 
/*
If input is an array then:

string file_name = file_name_for_next_output();
freopen(file_name.c_str(), "w", stdout);
int N;
cin >> N;
cout << N << endl;
for (int i = 0; i < N; i++)
{
	int no;
	cin >> no;
	cout << no << " ";
}
cout << endl;

Here we are writing to some inputxxx.txt file. 

Make sure that we are using appropriate format (like endl, spaces, tabs etc).
*/
void copy_input()
{
	string file_name = file_name_for_next_input();
	freopen(file_name.c_str(), "w", stdout);
	// start from here	
	int N;
	cin >> N;
	cout << N << endl;
	for (int i = 0; i < N; i++)
	{
		int no;
		cin >> no;
		cout << no << endl;
	}
}

/*
This fucntion copies no_of_test_cases testcases from given files.
copy_input_from file will contain inputs and copy_output_from will contain
expected outpus. 
*/
void parse_test_cases(
	string copy_input_from, string copy_output_from, int no_of_test_cases
)
{
	freopen(copy_input_from.c_str(), "r", stdin);
	int test_cases;
	cin >> test_cases;
	assert(no_of_test_cases <= test_cases);
	for (int i = 0; i < no_of_test_cases; i++)
	{
		copy_input();
	}
	freopen(copy_output_from.c_str(), "r", stdin);
	for (int i = 0; i < no_of_test_cases; i++)
	{
		copy_output();
	}
}

int main()
{
	parse_test_cases(
		"..//test_cases//sample_test_cases_input.txt",
		"..//test_cases//sample_test_cases_output.txt",
		3
	);
	parse_test_cases(
		"..//test_cases//handmade_test_cases_input.txt",
		"..//test_cases//handmade_test_cases_output.txt",
		8
	);
	parse_test_cases(
		"..//test_cases//small_test_cases_input.txt",
		"..//test_cases//small_test_cases_output.txt",
		17
	);
	parse_test_cases(
		"..//test_cases//big_test_cases_input.txt",
		"..//test_cases//big_test_cases_output.txt",
		3
	);

	return 0;
}