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

void run_custom_checker(stringstream &input_file, stringstream &expected_output_file, stringstream &output_file, 
	ResultStruct &r_obj) {

	//Don't print anything to STDOUT in this function
	//Enter your custom checker scoring logic here

	r_obj.result = true;
    r_obj.score = 1.0f;
    r_obj.message = "Success";


    vector<vector<int>> ans;
    int counter = 0;
    int temp;
    char comma;
    while (output_file >> temp)
    {
    	counter++;
    	if (counter % 3 == 1)
    	{
    		ans.push_back(vector<int>(0));
    	}
    	if (counter % 3 != 0)
    	{
    		output_file >> comma;
    	}
    	ans[ans.size() - 1].push_back(temp);
    }
    if (counter % 3 != 0)
    {
    	r_obj.result = false;
        r_obj.score = 0.0f;
        r_obj.message = "Wrong answer!";
        return;
    }


    vector<vector<int>> expected_ans;
    counter = 0;
    while (expected_output_file >> temp)
    {
    	counter++;
    	if (counter % 3 == 1)
    	{
    		expected_ans.push_back(vector<int>(0));
    	}
    	if (counter % 3 != 0)
    	{
    		expected_output_file >> comma;
    	}
    	expected_ans[expected_ans.size() - 1].push_back(temp);
    }


    if (ans.size() != expected_ans.size())
    {
    	r_obj.result = false;
        r_obj.score = 0.0f;
        r_obj.message = "Wrong answer!";
        return;
    }


    int ans_size = ans.size();
    for (int i = 0; i < ans_size; i++)
    {
    	sort(ans[i].begin(), ans[i].end());
    	sort(expected_ans[i].begin(), expected_ans[i].end());
    }
    sort(ans.begin(), ans.end());
    sort(expected_ans.begin(), expected_ans.end());


    for (int i = 0; i < ans_size; i++)
    {
    	for (int j = 0; j < 3; j++)
    	{
    		if (ans[i][j] != expected_ans[i][j])
    		{
    			r_obj.result = false;
		        r_obj.score = 0.0f;
		        r_obj.message = "Wrong answer!";
		        return;
    		}
    	}
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
