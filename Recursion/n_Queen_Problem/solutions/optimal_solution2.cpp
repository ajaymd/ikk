#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 13;

// -------------------------- START --------------------------

const char queen = 'q';
const char no_queen = '-';

// Function to check if we can place a queen at position chess_board[row][col].
bool is_safe(vector<bool> &slash_diagonal_occupied, vector<bool> &col_occupied, 
	vector<bool> &back_slash_diagonal_occupied, int row, int col, int n)
{
	// Check top-left to bottom-right diagonal.
	if (slash_diagonal_occupied[row + col])
	{
		return false;
	}
	// Check column.
	if (col_occupied[col])
	{
		return false;
	}
	// Check top-right to bottom-left diagonal.
	if (back_slash_diagonal_occupied[row - col + n - 1])
	{
		return false;
	}
	return true;
}

void find_all_arrangements_util(vector<vector<int>> &arrangements, vector<int> &cur_arrangement, 
	vector<bool> &slash_diagonal_occupied, vector<bool> &col_occupied, 
	vector<bool> &back_slash_diagonal_occupied, int n, int row)
{
	// If all queens are placed.
	if (row == n)
	{
		// Add the current arrangement.
		arrangements.push_back(cur_arrangement);
		return;
	}
	// For current row, try to place queen at chess_board[row][0 <= col < n].
	for (int col = 0; col < n; col++)
	{
		// We can place a queen only if it does not clash with already placed queens.
		if (is_safe(slash_diagonal_occupied, col_occupied, back_slash_diagonal_occupied, row, 
			col, n))
		{
			// Place queen. In current row we are placing queen at column col. 
			cur_arrangement[row] = col;
			// Mark appropriate diagonals and column as occupied.
			slash_diagonal_occupied[row + col] = true;
			col_occupied[col] = true;
			back_slash_diagonal_occupied[row - col + n - 1] = true;
			/*
			We have placed queens in rows from 0 to row, without any clash. Now try to place 
			queen in next row.
			*/
			find_all_arrangements_util(arrangements, cur_arrangement, slash_diagonal_occupied, 
				col_occupied, back_slash_diagonal_occupied, n, row + 1);
			// Mark appropriate diagonals and column as unoccupied.
			slash_diagonal_occupied[row + col] = false;
			col_occupied[col] = false;
			back_slash_diagonal_occupied[row - col + n - 1] = false;
		}
	}
}

vector<vector<string>> find_all_arrangements(int n)
{
	/*
	We know that in one row we will have only one queen (and total n queens), so instead of 2-D 
	grid we can store the information of queens' position in 1D array.

	Grid: 

	--q-
	q---
	---q
	-q--

	has queens at positions, 
	row -> col 

	0 -> 2, 
	1 -> 0,
	2 -> 3,
	3 -> 1

	In a 1D array it can be represented as:

	arrangement[0] = 2,
	arrangement[1] = 0,
	arrangement[2] = 3,
	arrangement[3] = 1

	So we have the same information now stored in 1D array (space O(n)) instead of 2D array 
	(space O(n^2)).  
	*/
	// arrangements[i] will be of size n, denoting one 1D arrangement as explained above. 
	vector<vector<int>> arrangements;
	// One arrangement in 1D.
	vector<int> cur_arrangement(n);
	/*
	If slash_diagonal_occupied[i] = true then slash diagonal number i is occupied by one of the 
	already placed queens.
	*/
	vector<bool> slash_diagonal_occupied (n + n - 1, false);
	/*
	If col_occupied[i] = true then column number i is occupied by one of the already placed 
	queens. 
	*/
	vector<bool> col_occupied (n, false);
	/*
	If back_slash_diagonal_occupied[i] = true then back slash diagonal number i is occupied by 
	one of the already placed queens.
	*/
	vector<bool> back_slash_diagonal_occupied (n + n - 1, false);
	find_all_arrangements_util(arrangements, cur_arrangement, slash_diagonal_occupied, 
		col_occupied, back_slash_diagonal_occupied, n, 0);
	// We will store all the possible arrangements in this array. (Actual 2-D arrangement.)
	vector<vector<string>> ret;
	// Chessboard row containing no queen.
	string chess_board_empty_row(n, no_queen);
	// Chessboard containing no queen.
	vector<string> chess_board(n, chess_board_empty_row);
	/*
	Now onwards code to convert arrangements from 1D to 2D, because we are asked to return the 
	actual grid in 2D.
	*/
	int len = arrangements.size();
	// Iterate over all 1D arrangements.
	for (int i = 0; i < len; i++)
	{
		// Add chessboard without any queen.
		ret.push_back(chess_board);
		// Iterate over the positions of the queens and place queens in 2D arrangement.
		for (int row = 0; row < n; row++)
		{
			/*
			arrangements[i] -> describes ith arrangement in 1D.
			arrangements[i][j] -> describes column number in which, a queen is placed, in jth row,
			in ith arrangement in 1D.

			ret[i] -> describes ith arrangement in 2D.
			ret[i][j] -> describes jth row, in ith arrangement in 2D.
			ret[i][j][k] -> describes ith column, in jth row, in ith arrangement in 2D.

			This might be confusing without trying few examples.  
			*/
			ret[i][row][arrangements[i][row]] = queen;
		}
	}
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
		cout << res.size() << " different arrangements possible." << endl << endl;
		for(int res_i = 0; res_i < res.size(); res_i++) 
		{
        	for(int res_j = 0; res_j < res[res_i].size(); res_j++) 
        	{
            	cout << res[res_i][res_j] << endl;
        	}
        	cout << endl;
    	}
    	cout << endl;
	}

	return 0;
}