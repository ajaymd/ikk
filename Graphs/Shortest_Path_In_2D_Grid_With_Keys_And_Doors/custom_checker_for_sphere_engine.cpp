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

const int MAX_ROWS = 100, MAX_COLS = 100, MAX_KEYS = 10, MAX_MASK = (1 << MAX_KEYS), INF = MAX_ROWS * MAX_COLS * (MAX_KEYS + 1);

bool is_start(char ch)
{
    return ch == '@';
}

bool is_stop(char ch)
{
    return ch == '+';
}

bool is_water(char ch)
{
    return ch == '#';
}

bool is_land(char ch)
{
    return ch == '.';
}

bool is_key(char ch)
{
    return ('a' <= ch && ch < ('a' + MAX_KEYS));
}

bool is_door(char ch)
{
    return ('A' <= ch && ch < ('A' + MAX_KEYS));
}

bool can_open_door(char door, int ring_of_keys)
{
    return (ring_of_keys >> (door - 'A')) & 1;
}

void run_custom_checker(stringstream &input_file, stringstream &expected_output_file, stringstream &output_file, 
	ResultStruct &r_obj) {
    //Don't print anything to STDOUT in this function
    //Enter your custom checker scoring logic here

    r_obj.result = true;
    r_obj.score = 1.0f;
    r_obj.message = "Success";
    
    
    int grid_rows = 0;
    int grid_cols = 0;
    input_file >> grid_rows;
    vector< string > grid(grid_rows);
    for(int grid_i = 0; grid_i < grid_rows; grid_i++) {
        input_file >> grid[grid_i];
    }
    grid_cols = grid[0].length();
    

    vector < vector<int> > res;
    int counter = 0, temp;
    while (output_file >> temp)
    {
        counter++;
        //cerr << "counter = " << counter << " temp = " << temp << endl;
        if (counter % 2)
        {
            res.push_back(vector<int>(0));
        }
        res[res.size() - 1].push_back(temp);
        if (counter > 2 * grid_rows * grid_cols || temp < 0 || ((counter % 2 == 1) && temp >= grid_rows) || ((counter % 2 == 0) && temp >= grid_cols))
        {
            //cerr << "returned wrong" << endl;
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
    }
        
   	if (counter % 2)
    {
        r_obj.result = false;
        r_obj.score = 0.0f;
        r_obj.message = "Wrong answer!";
        return;
    }

    int expected_length;
    expected_output_file >> expected_length;
    //cerr<< "expected length = " << expected_length << endl;
    

    if (res.size() != expected_length || is_start(grid[res[0][0]][res[0][1]]) == false || is_stop(grid[res[res.size() - 1][0]][res[res.size() - 1][1]]) == false)
    {
        r_obj.result = false;
        r_obj.score = 0.0f;
        r_obj.message = "Wrong answer!";
        return;
    }
    //cerr<< "going to check" << endl;
    int ring_of_keys = 0;
    for (int i = 0; i < res.size(); i++)
    {
        char cur = grid[res[i][0]][res[i][1]]; 
        //cerr << "cur = " << cur << endl;
        if (is_water(cur))
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
        if (is_door(cur) && can_open_door(cur, ring_of_keys) == false)
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
        if (is_key(cur))
        {
            ring_of_keys |= (1 << (cur - 'a'));
        }
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
