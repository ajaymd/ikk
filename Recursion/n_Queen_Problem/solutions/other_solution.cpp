#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 13;

// -------------------------- START --------------------------

const char queen = 'q';
const char no_queen = '-';

/*
Function to check if we can place a queen at position chess_board[row][col].
As we are placing queens row wise, we only have to check possible clash with queens placed above 
the current row. (No need to worry about the chessboard below current row, as we have not placed 
any queens below current row yet!)
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

void find_all_arrangements_util(vector<vector<string>> &ret, vector<string> &chess_board, int n, 
	int row)
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
			We have placed queens in rows from 0 to row, without any clash. Now try to place 
			queen in next row.
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

// -------------------------- STOP ---------------------------

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_small_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_big_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		int n;
		cin >> n;
		assert(1 <= n);
		assert(n <= MAX_N);
		vector<vector<string>> res = find_all_arrangements(n);
		cout << res.size() << endl;
		for(int res_i = 0; res_i < res.size(); res_i++) 
		{
        	for(int res_j = 0; res_j < res[res_i].size(); res_j++) 
        	{
            	//cout << res[res_i][res_j] << endl;
        	}
        	//cout << endl;
    	}
    	//cout << endl;
	}

	return 0;
}