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

const char queen = 'q';
const char no_queen = '-';

/*
Function to check if we can place a queen at position chess_board[row][col].
As we are placing queens row wise, we only have to check possible clash with queens placed above the current
row. (No need to worry about the chessboard below current row, as we have not placed any queens below current
row yet!)
*/ 
bool is_safe(vector<string> &chess_board, int row, int col, int n)
{
    // Check top-left to bottom-right diagonal.
    int cur_row = row, cur_col = col;
    while (cur_row >= 0 && cur_col >= 0)
    {
        if (chess_board[cur_row--][cur_col--] == queen)
        {
            return false;
        }
    }
    // Check column.
    cur_row = row;
    while (cur_row >= 0)
    {
        if (chess_board[cur_row--][col] == queen)
        {
            return false;
        }
    }
    // Check top-right to bottom-left diagonal.
    cur_row = row, cur_col = col;
    while (cur_row >= 0 && cur_col < n)
    {
        if (chess_board[cur_row--][cur_col++] == queen)
        {
            return false;
        }
    }
    return true;
}

void find_all_arrangements_util(vector<vector<string>> &ret, vector<string> &chess_board, int n, int row)
{
    // If all queens are placed.
    if (row == n)
    {
        // Add the current arrangement.
        ret.push_back(chess_board);
        return;
    }
    // For current row, try to place queen at chess_board[row][0 <= col < n].
    for (int col = 0; col < n; col++)
    {
        // We can place a queen only if it does not clash with already placed queens.
        if (is_safe(chess_board, row, col, n))
        {
            // Place queen.
            chess_board[row][col] = queen;
            /*
            We have placed queens in rows from 0 to row, without any clash. Now try to place queen in next
            row.
            */
            find_all_arrangements_util(ret, chess_board, n, row + 1);
            // We have considered the current possibility, now backtrack.
            chess_board[row][col] = no_queen;
        }
    }
}

vector<vector<string>> find_all_arrangements(int n)
{
    // We will store all the possible arrangements in this array.
    vector<vector<string>> ret;
    // Chessboard row containing no queen.
    string chess_board_empty_row(n, no_queen);
    // Chessboard containing no queen.
    vector<string> chess_board(n, chess_board_empty_row);
    find_all_arrangements_util(ret, chess_board, n, 0);
    return ret;
}


#include<unordered_set>
unordered_set<string> our_arrangements;

void run_custom_checker(
    stringstream &input_file, stringstream &expected_output_file, stringstream &output_file, 
    ResultStruct &r_obj
) {
    //Don't print anything to STDOUT in this function
    //Enter your custom checker scoring logic here

    r_obj.result = true;
    r_obj.score = 1.0f;
    r_obj.message = "Success";

    
    int n;
    input_file >> n;
    vector<vector<string>> all_arrangements = find_all_arrangements(n);
    int our_len = all_arrangements.size();
    for (int i = 0; i < our_len; i++)
    {
        string arrangement = "";
        for (int j = 0; j < n; j++)
        {
            arrangement += all_arrangements[i][j] + " ";
        }
        our_arrangements.insert(arrangement);
    }
    
    
    string temp;
    while(getline(output_file, temp))
    {
        auto it = our_arrangements.find(temp);
        if (it == our_arrangements.end())
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
        our_arrangements.erase(it);
    }
    // If there are some arrangements that user did not generate then return wrong answer. 
    if (our_arrangements.size())
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
