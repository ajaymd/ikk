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

void generate_all_subsets_util(vector<string> &all_subsets, string &s, int pos, string cur_subset)
{
    /*
    If we have reached the end then add generated subset. 
    In C++ string.length() is O(1), but make sure about your language. If it is O(n) then better to calculate it only once, store it (store it in global variable or pass as an argument to the function) and reuse it. 
    */
    if (pos == s.length())
    {
        all_subsets.push_back(cur_subset);
        return;
    }
    // Do not include s[pos].
    generate_all_subsets_util(all_subsets, s, pos + 1, cur_subset);
    // Include s[pos].
    generate_all_subsets_util(all_subsets, s, pos + 1, cur_subset + s[pos]);
}

vector<string> generate_all_subsets(string s)
{
    vector<string> all_subsets;
    generate_all_subsets_util(all_subsets, s, 0, "");
    return all_subsets;
}

#include<unordered_set>
unordered_set<string> our_subsets;

void run_custom_checker(stringstream &input_file, stringstream &expected_output_file, stringstream &output_file, 
	ResultStruct &r_obj) {
    //Don't print anything to STDOUT in this function
    //Enter your custom checker scoring logic here
    
    r_obj.result = true;
    r_obj.score = 1.0f;
    r_obj.message = "Success";
   	
    // Getline is needed as input can be empty string.
    string s;
    getline(input_file, s);
    vector<string> all_subsets = generate_all_subsets(s);
    int our_len = all_subsets.size();
    for (int i = 0; i < our_len; i++)
    {
        our_subsets.insert(all_subsets[i]);
    } 
    
    
    string temp;
    // Need to use getline as file can contain empty string.
    while(getline(output_file, temp))
    {
        auto it = our_subsets.find(temp);
        if (it == our_subsets.end())
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
        our_subsets.erase(it);
    }
    // If there are some expressions that user did not generate then return wrong answer. 
    if (our_subsets.size())
    {
        r_obj.result = false;
        r_obj.score = 0.0f;
        r_obj.message = "Wrong answer!";
    }
}
// End of BODY

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
