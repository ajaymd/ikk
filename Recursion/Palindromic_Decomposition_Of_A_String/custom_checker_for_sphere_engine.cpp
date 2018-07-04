// Using C++14 (gcc-5 5.1.1) 

#include "spoj.h"
#include <bits/stdc++.h>

using namespace std;

class ResultStruct {
public:
    bool   result;
    float  score;
    string message;
};

string read_whole_file_into_string(FILE * f) {

	char * buffer = '\0';
	int length;
	
	if (f) {
		fseek (f, 0, SEEK_END);
		length = (int) ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = (char *) malloc (length + 1);
		if (buffer) {
			fread (buffer, 1, length, f);
			buffer[length] = '\0';
		}
	}
	if (buffer) {
		return string(buffer);
	}
	return "";
}

// ------------------------- START -------------------------

int n;

//Check if s[l, r] is a palindrome or not.
bool is_palindrome(string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void generate_palindromic_decompositions_util(vector<string> &decompositions_container, string &s, int pos, string cur_decomposition)
{
    // If we have reached the end, add the string. 
    if (pos == n)
    {
        decompositions_container.push_back(cur_decomposition);
        return;
    }   
    // Try to add s[pos, i] if it a palindrome.
    for (int i = pos; i < n; i++)
    {
        if (is_palindrome(s, pos, i))
        {
            if (pos == 0)
            {
                // We are adding s[0, i] so do not put '|' before it.
                generate_palindromic_decompositions_util(decompositions_container, s, i + 1, s.substr(pos, i - pos + 1));
            }
            else
            {
                generate_palindromic_decompositions_util(decompositions_container, s, i + 1, cur_decomposition + '|' + s.substr(pos, i - pos + 1));
            }
        }
    }
}

vector<string> generate_palindromic_decompositions(string s)
{
    // Store length of given string in global variable because we will be accessing it lots of time. 
    n = s.length();
    vector<string> decompositions_container;
    generate_palindromic_decompositions_util(decompositions_container, s, 0, "");
    return decompositions_container;
}

#include<unordered_set>
unordered_set<string> our_decompositions;

void run_custom_checker(stringstream &input_file, stringstream &expected_output_file, stringstream &output_file, 
	ResultStruct &r_obj) {
    //Don't print anything to STDOUT in this function
    //Enter your custom checker scoring logic here
    
    r_obj.result = true;
    r_obj.score = 1.0f;
    r_obj.message = "Success";
   	
    
    string s;
    input_file >> s;
    vector<string> all_decompositions = generate_palindromic_decompositions(s);
    int our_len = all_decompositions.size();
    for (int i = 0; i < our_len; i++)
    {
        our_decompositions.insert(all_decompositions[i]);
    } 
    
    
    string temp;
    while(output_file >> temp)
    {
        auto it = our_decompositions.find(temp);
        if (it == our_decompositions.end())
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
        our_decompositions.erase(it);
    }
    // If there are some expressions that user did not generate then return wrong answer. 
    if (our_decompositions.size())
    {
        r_obj.result = false;
        r_obj.score = 0.0f;
        r_obj.message = "Wrong answer!";
    }
}

// ------------------------- STOP -------------------------

int main(void) {
	spoj_init();

	string whole_input = read_whole_file_into_string(spoj_p_in);
	string whole_expected_output = read_whole_file_into_string(spoj_p_out);
	string whole_output = read_whole_file_into_string(spoj_t_out);

	cerr << "Input length: " << whole_input.length() << endl;
	// cerr << "Input:" << endl;
	// cerr << whole_input << endl;

	cerr << "Expected output length: " << whole_expected_output.length() << endl;
	// cerr << "Expected output:" << endl;
	// cerr << whole_expected_output << endl;

	cerr << "Output length: " << whole_output.length() << endl;
	// cerr << "Output:" << endl;
	// cerr << whole_output << endl;
	
    ResultStruct r_obj;
    r_obj.result = false;
    r_obj.score = 0.0f;
    r_obj.message = "Uninitialized";

    stringstream input_file(whole_input);
    stringstream expected_output_file(whole_expected_output);
    stringstream output_file(whole_output);


    run_custom_checker(input_file, expected_output_file, output_file, r_obj);
    if (r_obj.result) {
    	return SPOJ_RV_POSITIVE;
    }

	return SPOJ_RV_NEGATIVE;
}
