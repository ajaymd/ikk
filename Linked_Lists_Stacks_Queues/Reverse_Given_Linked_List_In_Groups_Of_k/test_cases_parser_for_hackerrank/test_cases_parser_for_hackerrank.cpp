#include<bits/stdc++.h>

using namespace std;

// When counter is 5 then return "005" when counter is 48 then return "048" when counter is 123 then return "123"

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

// If we have added output for 5 testcases (output000.txt to output004.txt) then this will return output005.txt

string file_name_for_next_output()
{
	static int output_counter = 0;			// for outputxxx.txt
	string no = integer_to_string(output_counter);
	output_counter++;
	return "..//parsed_test_cases_for_hackerrank//output" + no + ".txt";
}

// If we have added input for 5 testcases (input000.txt to input004.txt) then this will return input005.txt

string file_name_for_next_input()
{
	static int input_counter = 0;			// for inputxxx.txt
	string no = integer_to_string(input_counter);
	input_counter++;
	return "..//parsed_test_cases_for_hackerrank//input" + no + ".txt";
}

// According to problem statement output format complete this method. 
/*
	If output is a string then:



	string file_name = file_name_for_next_output();
	ofstream fout(file_name.c_str());
	string s;
	fin >> s;
	fout << s << endl;

	fout.close();



	Here we are writing to some outputxxx.txt file. 

	Make sure that we are using appropriate format (like endl, spaces, tabs etc).
*/

void copy_output(ifstream &fin)
{
	string file_name = file_name_for_next_output();
	ofstream fout(file_name.c_str());
	// start from here

	string no_str;
	while (1)
	{
		getline(fin, no_str);
		if (no_str == "")
		{
			break;
		}
		fout << no_str << endl;
	}

	fout.close();
	// To resolve "\r\n" vs "\n" issue. 
	string command_to_run = "dos2unix ..//parsed_test_cases_for_hackerrank//" + file_name;
	system(command_to_run.c_str());
}

// According to problem statement input format complete this method. 
/*
	If input is an array then:



	string file_name = file_name_for_next_output();
	ofstream fout(file_name.c_str());
	int N;
	fin >> N;
	fout << N << endl;
	for (int i = 0; i < N; i++)
	{
		int no;
		fin >> no;
		fout << no << " ";
	}
	fout << endl;

	fout.close();
	


	Here we are writing to some inputxxx.txt file. 

	Make sure that we are using appropriate format (like endl, spaces, tabs etc).
*/

void copy_input(ifstream &fin)
{
	string file_name = file_name_for_next_input();
	ofstream fout(file_name.c_str());
	// start from here	

	int n;
	fin >> n;
	fout << n << endl;
	while (n--)
	{
		int temp;
		fin >> temp;
		fout << temp << endl;
	}
	int k;
	fin >> k;
	fout << k << endl;

	fout.close();
	// To resolve "\r\n" vs "\n" issue. 
	string command_to_run = "dos2unix ..//parsed_test_cases_for_hackerrank//" + file_name;
	system(command_to_run.c_str());
}

// This fucntion copies no_of_test_cases testcases from given files. copy_input_from file will contain inputs and copy_output_from will contain expected outpus. 

void parse_test_cases(string copy_input_from, string copy_output_from, int no_of_test_cases)
{
	if (no_of_test_cases <= 0)
	{
		return;
	}
	ifstream fin(copy_input_from.c_str());
	int test_cases;
	fin >> test_cases;
	assert(no_of_test_cases <= test_cases);
	for (int i = 0; i < no_of_test_cases; i++)
	{
		copy_input(fin);
	}
	fin.close();
	fin.open(copy_output_from.c_str());
	for (int i = 0; i < no_of_test_cases; i++)
	{
		copy_output(fin);
	}
}

int main()
{
	parse_test_cases("..//test_cases//sample_test_cases_input.txt", "..//test_cases//sample_test_cases_expected_output.txt", 2);
	parse_test_cases("..//test_cases//handmade_test_cases_input.txt", "..//test_cases//handmade_test_cases_expected_output.txt", 10);
	parse_test_cases("..//test_cases//generated_small_test_cases_input.txt", "..//test_cases//generated_small_test_cases_expected_output.txt", 14);
	parse_test_cases("..//test_cases//generated_big_test_cases_input.txt", "..//test_cases//generated_big_test_cases_expected_output.txt", 4);

	return 0;
}