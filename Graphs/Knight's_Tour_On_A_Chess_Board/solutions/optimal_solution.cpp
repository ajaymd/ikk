#include<bits/stdc++.h>

using namespace std;

const int MIN_SIZE = 1, MAX_SIZE = 100000;

// -------------------------- START --------------------------

const int no_of_possible_moves = 8;
// 8 possible moves of knight.
const int add_row[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int add_col[] = {-1, 1, 2, 2, 1, -1, -2, -2};

/*
Check if position described by new_row th row and new_col th col, is inside the chess board or 
not.
*/
bool is_valid_position(int rows, int cols, int new_row, int new_col)
{
	return ((0 <= new_row) && (new_row < rows) && (0 <= new_col) && (new_col < cols));
} 

int find_minimum_number_of_moves(int rows, int cols, int start_row, 
	int start_col, int end_row, int end_col) 
{
	// If starting and ending positions are same.
	if (start_row == end_row && start_col == end_col)
	{
		return 0;
	}
	/*
	If dist[i][j] = -1, cell described by ith row and jth col is not visited till now.
	If dist[i][j] != -1, cell described by ith row and jth col can be reached from 
	starting position in minimum dist[row][col] moves.
	*/
	vector<vector<int>> dist(rows, vector<int>(cols, -1));
	// Starting position can be reached from starting position in 0 moves.
	dist[start_row][start_col] = 0;
	queue<pair<int, int>> bfs_q;
	// Add starting position. 
	bfs_q.push({start_row, start_col});
	while(bfs_q.empty() == false)
	{
		// Remove first element from queue. 
		int cur_row = bfs_q.front().first;
		int cur_col = bfs_q.front().second;
		bfs_q.pop();
		// Update neighbours that are not visited till now. 
		for (int i = 0; i < no_of_possible_moves; i++)
		{
			// Neighbour's position. 
			int new_row = cur_row + add_row[i];
			int new_col = cur_col + add_col[i];
			if (is_valid_position(rows, cols, new_row, new_col))
			{
				// If neihbour is not visited till now.
				if (dist[new_row][new_col] == -1)
				{
					/*
					From starting position we can reach current position in dist[cur_row][cur_col]
					moves.
					From current position we reach the neighbour in 1 move. 
					So, from starting position, the neighbour can be reached in 
					dist[cur_row][cur_col] + 1 moves.
					*/
					dist[new_row][new_col] = dist[cur_row][cur_col] + 1;
					// If we have found the ending position. 
					if (new_row == end_row && new_col == end_col)
					{
						return dist[end_row][end_col];
					}
					// Add the neighbour in queue. 
					bfs_q.push({new_row, new_col});
				}
			}
		}
	}
	// If ending position can not be reached from starting position.
	return -1;
}

// -------------------------- STOP ---------------------------

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
	assert(test_cases >= 0);
	while (test_cases--)
	{
		int rows, cols, start_row, start_col, end_row, end_col;
		cin >> rows >> cols >> start_row >> start_col >> end_row >> end_col;
		assert(MIN_SIZE <= rows * cols);
		assert(rows * cols <= MAX_SIZE);
		assert(0 <= start_row);
		assert(start_row < rows);
		assert(0 <= start_col);
		assert(start_col < cols);
		assert(0 <= end_row);
		assert(end_row < rows);
		assert(0 <= end_col);
		assert(end_col < cols);
		int moves = find_minimum_number_of_moves(rows, cols, start_row, 
			start_col, end_row, end_col);
		assert(-1 <= moves);
		cout << moves << endl;
	}

	return 0;
}