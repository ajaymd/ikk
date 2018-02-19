#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

// ------------------------ START ------------------------

int directions[4][2] = 
{
	// {row, col}
	{0, 1}, 	// go right 
	{1, 0}, 	// go down
	{0, -1}, 	// go left 
	{-1, 0} 	// go up.
};

bool should_turn(int cur_row, int cur_col, int rows, int cols)
{
	/*
	Consider these grids to understand what the below code does. 

	O O O O O O #
	# O O O O # O
	O # O O # O O
	O # O O O # O
	# O O O O O #

	=

	O O O	 O O O #
	# O O	 O O # O
	O # O	 O # O O

	O # O	 O O # O
	# O O	 O O O #


	< (rows + 1) / 2 will give priority to top part when current position is horizontally 
	centered. 
	< cols / 2 will give priority to right part when current position is vertically centered.
	
	*/

	// Check if position is in top-left part.
	if ((cur_row < (rows + 1) / 2) && (cur_col < cols / 2))
	{
		// Condition to turn when current position is in top-left part.
		return cur_row == cur_col + 1;
	}
	// Condition to turn when current position in other parts.
	return min(cur_row, rows - 1 - cur_row) == min(cur_col, cols - 1 - cur_col);
}

string printSpirally(vector<vector<char>> matrix)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	int total = rows * cols;
	string ans(total, ' ');
	// Initial position is at top left corner with direction towards right. 
	int direction = 0;
	int cur_row = 0, cur_col = 0;
	for (int i = 0; i < total; i++)
	{
		ans[i] = matrix[cur_row][cur_col];
		// Check if we should turn our direction or not.
		if (should_turn(cur_row, cur_col, rows, cols))
		{
			direction = (direction + 1) % 4;
		}
		// Update the position.
		cur_row += directions[direction][0];
		cur_col += directions[direction][1];
	}
	return ans;
}

// ------------------------ STOP -------------------------

int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_small_test_cases_expected_output.txt", "w", stdout);
	freopen("..//test_cases//generated_big_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//generated_big_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		int rows, cols;
		cin >> rows >> cols;
		assert(1 <= rows);
		assert(rows <= MAX_N);
		assert(1 <= cols);
		assert(cols <= MAX_N);
		assert(rows * cols <= MAX_N);
		vector<vector<char>> matrix(rows, vector<char>(cols));
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cin >> matrix[i][j];
				assert(('a' <= matrix[i][j] && matrix[i][j] <= 'z') || 
					('A' <= matrix[i][j] && matrix[i][j] <= 'Z'));
			}
		}
		string ret = printSpirally(matrix);
		assert(ret.length() == rows * cols);
		cout << ret << endl;
	}

	return 0;
}