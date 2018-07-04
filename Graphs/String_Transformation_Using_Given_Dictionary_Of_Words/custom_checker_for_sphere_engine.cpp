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

#include<unordered_set>
unordered_set<string> words_hash;

// Check if str1 and str2 differs ar exactly one positon.
bool only_one_char_difference(int len, string &str1, string &str2)
{
    int difference = 0;
    for (int i = 0; i < len; i++)
    {
        if (str1[i] != str2[i])
        {
            // If there is already one miss match, and now we have found another. 
            if (difference == 1)
            {
                return false;
            }
            difference++;
        }
    }
    // If difference == 0, it means strings are same. So, difference == 1 is needed. 
    return difference == 1;
}

void run_custom_checker(stringstream &input_file, stringstream &expected_output_file, stringstream &output_file, 
    ResultStruct &r_obj) {
    //Don't print anything to STDOUT in this function
    //Enter your custom checker scoring logic here

    r_obj.result = true;
    r_obj.score = 1.0f;
    r_obj.message = "Success";
    
    // cerr << "Input:" << endl;
    int N;
    input_file >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        input_file >> s;
        // cerr << "s= " << s << endl;
        words_hash.insert(s);
    }
    string start, stop;
    input_file >> start >> stop;
    // cerr << "start, stop = " << start << ", " << stop << endl;
    

    // cerr << "Output:" << endl;
    string temp;
    vector<string> ans;
    while(output_file >> temp)
    {
        // cerr << "temp = " << temp << endl;
        ans.push_back(temp);
    }
    int ans_size = ans.size();
    

    // cerr << "Expected Output:" << endl;
    vector<string> expected_ans;
    while(expected_output_file >> temp)
    {
        // cerr << "temp = " << temp << endl;
        expected_ans.push_back(temp);
    }
    int expected_ans_size = expected_ans.size();
    
    
    if (expected_ans_size == 1 && ans_size == 1)
    {
        // Must be "-1".
        if (ans[0] != expected_ans[0])
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
        }
        return;
    }
    if (ans_size != expected_ans_size)
    {
        r_obj.result = false;
        r_obj.score = 0.0f;
        r_obj.message = "Wrong answer!";
        return;
    }
    

    for (int i = 1; i < ans_size - 1; i++)
    {
        if (words_hash.find(ans[i]) == words_hash.end())
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
    }
    if (ans[0] != start || ans[ans_size - 1] != stop)
    {
        r_obj.result = false;
        r_obj.score = 0.0f;
        r_obj.message = "Wrong answer!";
        return;
    }
    int len = expected_ans[0].length();
    for (int i = 0; i < ans_size; i++)
    {
        if (ans[i].length() != len)
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
    }
    for (int i = 1; i < ans_size; i++)
    {
        if (only_one_char_difference(len, ans[i - 1], ans[i]) == false)
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
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
