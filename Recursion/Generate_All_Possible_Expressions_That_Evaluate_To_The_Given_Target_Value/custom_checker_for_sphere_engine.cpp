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

int n;

// Function to convert string to long long int. "123" -> 123.
long long int str_to_ll(string &str)
{
    long long int val = 0;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        val = val * 10LL + (str[i] - '0');
    }
    return val;
}

/*
Function to generate all valid expressions that evaluates to the given target value.
all_expressions_container -> will contain answer.
cur_expr -> will contain the expression build till now. 
Suppose one of our final expression will look like "n1+n2*n3*n4+n5+n6*n7+n8", then we will build "cur_expr" like: 
    -> n1 (First time we will not add any operator with the number.)
    -> n1+n2 (Afterwards we will add one operator ('+' or '*') with number.)
    -> n1+n2*n3
    -> n1+n2*n3*n4
    -> n1+n2*n3*n4+n5
    -> n1+n2*n3*n4+n5+n6
    -> n1+n2*n3*n4+n5+n6*n7
    -> n1+n2*n3*n4+n5+n6*n7+n8
s -> given string.
target -> given target value.
pos -> in cur_expr we have already included digits from s[0, pos - 1] and s[pos, n - 1] is remaining to process.
cur_expr_val -> value of cur_expr. 
cur_expr_val_after_rightmost_addition_sign -> value of cur_expr after the rightmost addition sign '+'. 
Suppose cur_expr = 52 then cur_expr_val_after_rightmost_addition_sign = 52.
Suppose cur_expr = 52 + 47 then cur_expr_val_after_rightmost_addition_sign = 47.
Suppose cur_expr = 52 + 3 * 4 then cur_expr_val_after_rightmost_addition_sign = 12.
Suppose cur_expr = 52 + 3 * 4 * 2 then cur_expr_val_after_rightmost_addition_sign = 24.
Suppose cur_expr = 52 + 3 * 4 * 2 + 78 then cur_expr_val_after_rightmost_addition_sign = 78.
(Will be explained in detail, why it is needed, when it will be used in code, now don't worry about it.)
*/
void generate_all_expressions_util(vector<string> &all_expressions_container, string cur_expr, string s, long long int target, int pos, long long int cur_expr_val, long long int cur_expr_val_after_rightmost_addition_sign)
{
    // If processed the whole string.
    if (pos == n)
    {
        // Check if generated expression evaluates to the target value or not. 
        if (cur_expr_val == target)
        {
            // If generated expression evaluates to the target value then store it.
            all_expressions_container.push_back(cur_expr);
        }
        return;
    }
    /*
    As mentioned earliers we will build "cur_expr" in stages like:
        -> n1 (First time we will not add any operator with the number.)
        -> n1+n2 (Afterwards we will add one operator ('+' or '*') with number.)
        -> n1+n2*n3
        -> .....
    Now this loop will consider all possible s[pos, i] as a number and will add this number in cur_expr. 
    Note that when we consider s[pos, i] as a number, it means we are using join operation!
    (Basically we are trying all possibilities!) 
    */
    for (int i = pos; i < n; i++)
    {
        // Get the string s[pos, i] (both inclusive).
        string no_to_add_as_str = s.substr(pos, i - pos + 1);
        // Convert it to number.
        long long int no_to_add = str_to_ll(no_to_add_as_str);
        // If we have just started then first we will add number without operator. 
        if (pos == 0)
        {
            generate_all_expressions_util(all_expressions_container, no_to_add_as_str, s, target, i + 1, no_to_add, no_to_add);
        } 
        else
        {
            /*
            Add number with '+' operator before it. 
            For the next call variables will be:
            - cur_expr = cur_expr + '+' + no_to_add_as_str (As we are adding number with '+' operator befor it.)
            - pos = i + 1 (As we have included s[pos, i] also, now remaining string to add is s[i + 1, n - 1].)
            - cur_expr_val = cur_expr_val + no_to_add (As we have added number in the cur_expr with '+' operator, value of the cur_expr will be increased by number we are going to add.)
            - cur_expr_val_after_rightmost_addition_sign = no_to_add (As we have added number in the cur_expr with '+' operator, value of the expression after rightmost addition sign is the number itself.)
            */
            generate_all_expressions_util(all_expressions_container, cur_expr + '+' + no_to_add_as_str, s, target, i + 1, cur_expr_val + no_to_add, no_to_add);
            /*
            Add number with '*' operator before it. 
            For the next call variables will be:
            - cur_expr = cur_expr + '*' + no_to_add_as_str (As we are adding number with '*' operator befor it.)
            - pos = i + 1 (As we have included s[pos, i] also, now remaining string to add is s[i + 1, n - 1].)
            Now let's take one example before we mention other variables.
            Suppose we already have build cur_expr = "1 + 3" then cur_expr_val will be 4 and cur_expr_val_after_rightmost_addition_sign will be 3.
            Now if we want to add 4 with '*' operator then cur_expr will look like "1 + 3 * 4". 
            Now how can we find the value of "1 + 3 * 4" using the values for "1 + 3"?
            Observe that due to higher precedence of '*' over '+', 3 that we have added preciously as addition should be removed and it should be added as multiplication!
            So to find value of "1 + 3 * 4" from "1 + 3", first subtract the value of expression after the right most '+' sign and then add it with multiplication with new number we are going to add. So we have to do 4 - 3 + (3 * 4) = 13 and that will give the value of the expression.  
            Also expression value after right most '+' sign will be (3 * 4).
            - cur_expr_val = cur_expr_val - cur_expr_val_after_rightmost_addition_sign + (cur_expr_val_after_rightmost_addition_sign * no_to_add)
            - cur_expr_val_after_rightmost_addition_sign = cur_expr_val_after_rightmost_addition_sign * no_to_add
            */
            generate_all_expressions_util(all_expressions_container, cur_expr + '*' + no_to_add_as_str, s, target, i + 1, cur_expr_val - cur_expr_val_after_rightmost_addition_sign + (cur_expr_val_after_rightmost_addition_sign * no_to_add), cur_expr_val_after_rightmost_addition_sign * no_to_add);
        }
    }
}

vector<string> generate_all_expressions(string s, long long int target)
{
    // Store length of given string in global variable because we will be accessing it lots of time. 
    n = s.length();
    // This vector will store the answer.
    vector<string> all_expressions_container;
    generate_all_expressions_util(all_expressions_container, "", s, target, 0, 0LL, 0LL);
    return all_expressions_container;
}

unordered_set<string> our_expressions;

void run_custom_checker(stringstream &input_file, stringstream &expected_output_file, stringstream &output_file, 
	ResultStruct &r_obj) {
    //Don't print anything to STDOUT in this function
    //Enter your custom checker scoring logic here
    
    r_obj.result = true;
    r_obj.score = 1.0f;
    r_obj.message = "Success";

    
    string s;
    input_file >> s;
    long long int target;
    input_file >> target;
    

    vector<string> all_expressions = generate_all_expressions(s, target);
    int our_len = all_expressions.size();
    for (int i = 0; i < our_len; i++)
    {
        our_expressions.insert(all_expressions[i]);
    } 

    
    string expr;
    while(output_file >> expr)
    {
        auto it = our_expressions.find(expr);
        if (it == our_expressions.end())
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
        our_expressions.erase(it);
    }
    // If there are some expressions that user did not generate then return wrong answer. 
    if (our_expressions.size())
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
