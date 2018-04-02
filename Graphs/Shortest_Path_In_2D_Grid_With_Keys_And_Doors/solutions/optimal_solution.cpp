#include<bits/stdc++.h>

using namespace std;

// ---- START ----

const int MAX_ROWS = 100, MAX_COLS = 100, MAX_KEYS = 10, MAX_MASK = (1 << MAX_KEYS), 
	INF = MAX_ROWS * MAX_COLS * (MAX_KEYS + 1);
const int add_r[4] = {-1, 0, 1, 0};
const int add_c[4] = {0, -1, 0, 1};

vector<vector<int>> build_path(vector<vector<vector<int>>> &dp, 
	vector<vector<vector<pair<pair<int, int>, int>>>> &parent, int ring_of_keys, 
	pair<int, int> &start, pair<int, int> &stop)
{
	vector<vector<int>> ans;
	ans.push_back(vector<int>(0));
	ans[0].push_back(stop.first);
	ans[0].push_back(stop.second);

	/*
	stop only when ring_of_keys is 0. Both conditions are necessary. Consider input 1 5 "#a@A+#", 
	here @ -> a -> @ -> A -> + , so when reconstructing + -> A -> @ and still we need to continue! 
	*/
	while (stop != start || ring_of_keys != 0)
	{
		pair<pair<int, int>, int> par = parent[stop.first][stop.second][ring_of_keys];
		stop = par.first;
		ring_of_keys = par.second;
		ans.push_back(vector<int>(0));
		ans[ans.size() - 1].push_back(stop.first);
		ans[ans.size() - 1].push_back(stop.second);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

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

void add_neighbour_to_queue(int to_r, int to_c, int to_ring_of_keys, 
	pair<pair<int, int>, int> from, vector<vector<vector<pair<pair<int, int>, int>>>> &parent, 
	vector<vector<vector<int>>> &dp, vector<vector<vector<bool>>> &visited, 
	queue<pair<pair<int, int>, int>> &q)
{
	parent[to_r][to_c][to_ring_of_keys] = from;
	dp[to_r][to_c][to_ring_of_keys] = dp[from.first.first][from.first.second][from.second] + 1;
	visited[to_r][to_c][to_ring_of_keys] = true;
	q.push({{to_r, to_c}, to_ring_of_keys});
}

// better to pass vectors by reference
void bfs(vector<string> &grid, pair<int, int> &start, vector<vector<vector<int>>> &dp, 
	vector<vector<vector<pair<pair<int, int>, int>>>> &parent, 
	vector<vector<vector<bool>>> &visited)		
{
	int rows = grid.size();
	int cols = grid[0].length();

	queue<pair<pair<int, int>, int>> q;
	// Starting point with no keys has 0 distance (itself). 
	q.push({start, 0});
	dp[start.first][start.second][0] = 0;
	visited[start.first][start.second][0] = true;

	while(q.empty() == false)
	{
		pair<pair<int, int>, int> from = q.front();
		q.pop();
		if (is_stop(grid[from.first.first][from.first.second]))
		{
			continue;
		}
		// Visit all four neighbours and update.
		for (int i = 0; i < 4; i++)
		{
			int to_r = from.first.first + add_r[i];
			int to_c = from.first.second + add_c[i];
			if (to_r < 0 || to_r >= rows || to_c < 0 || to_c >= cols)
			{
				continue;
			}
			if (is_water(grid[to_r][to_c]))
			{
				continue;
			}
			else if (is_land(grid[to_r][to_c]) || is_start(grid[to_r][to_c]) || 
				is_stop(grid[to_r][to_c]))
			{
				if (visited[to_r][to_c][from.second] == false)
				{
					add_neighbour_to_queue(to_r, to_c, from.second, from, parent, dp, visited, q);
				}
			}
			else if (is_key(grid[to_r][to_c]))
			{
				int new_ring_of_keys = from.second  | (1 << (grid[to_r][to_c] - 'a'));
				if (visited[to_r][to_c][new_ring_of_keys] == false)
				{
					add_neighbour_to_queue(to_r, to_c, new_ring_of_keys, from, parent, dp, 
						visited, q);
				}
			}
			else if (is_door(grid[to_r][to_c]))
			{
				// Can enter only if we have key for that door. 
				if (can_open_door(grid[to_r][to_c], from.second))
				{
					if (visited[to_r][to_c][from.second] == false)
					{
						add_neighbour_to_queue(to_r, to_c, from.second, from, parent, dp, 
							visited, q);
					}
				}
			}
		}
	}
}

// node that start and stop are passed by reference hence change will be reflected. 
void get_start_and_stop_positions(vector<string> &grid, pair<int, int> &start, 
	pair<int, int> &stop)	
{
	int rows = grid.size();
	int cols = grid[0].length();
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (is_start(grid[r][c]))
			{
				start = {r, c};
			}
			else if(is_stop(grid[r][c]))
			{
				stop = {r, c};
			}
		}
	}
}

vector<vector<int>> find_shortest_path(vector<string> grid)
{
	int rows = grid.size();
	int cols = grid[0].length();
	pair<int, int> start, stop;
	// Get the starting and ending point.
	get_start_and_stop_positions(grid, start, stop);
	/*
	dp[r][c][ring] denotes length of shortest path from starting point to (r, c) and we have 
	already got keys in the ring. 
	*/
	vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(MAX_MASK, INF)));
	/*
	parent[r][c][ring] denotes the last node through which dp[r][c][ring] is updated. This will 
	help to reconstruct the path.
	*/
	vector<vector<vector<pair<pair<int, int>, int>>>> parent(rows, 
		vector<vector<pair<pair<int, int>, int>>>(cols, vector<pair<pair<int, int>, int>>
			(MAX_MASK, {{-1, -1}, -1})));
	/*
	visited[r][c][ring] keeps track of dp[r][c][ring] is visited or not. Though parent is enough 
	to track this, but for readability purpose I have added this also. 
	*/
	vector<vector<vector<bool>>> visited(rows, 
		vector<vector<bool>>(cols, vector<bool>(MAX_MASK, false)));
	// Do bfs.
	bfs(grid, start, dp, parent, visited);
	/*
	As dp[r][c][ring] denotes shortest path from start point and we have already got keys in the 
	ring, we just need to find for which key path is shorter. 
	*/
	int length = INF;
	int ring_of_keys;
	for (int i = 0; i < MAX_MASK; i++)
	{
		if (length > dp[stop.first][stop.second][i])
		{
			length = dp[stop.first][stop.second][i];
			ring_of_keys = i;
		}
	}
	// cout << length << endl;

	// Build the path from using parent. 
	return build_path(dp, parent, ring_of_keys, start, stop);
}

// ---- STOP ----


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
		int rows, cols;
		// cin >> rows >> cols;
		cin >> rows;
		/* assert(1 <= rows);
		assert(rows <= MAX_ROWS);
		assert(1 <= cols);
		assert(cols <= MAX_COLS);*/

		vector<string> grid (rows);
		int start = 0, stop = 0;
		for (int r = 0; r < rows; r++)
		{
			cin >> grid[r];
			cols = grid[r].length();
			for (int c = 0; c < cols; c++)
			{
				assert(
					is_start(grid[r][c]) ||
					is_stop(grid[r][c])  ||
					is_water(grid[r][c]) ||
					is_land(grid[r][c])  ||
					is_key(grid[r][c])   ||
					is_door(grid[r][c])
				);
				if (is_start(grid[r][c]))
				{
					start++;
				}
				else if (is_stop(grid[r][c]))
				{
					stop++;
				}
			}
		}
		assert(start == 1);
		assert(stop == 1);

		vector<vector<int>> ans = find_shortest_path(grid);

		cout << ans.size() << " cells will be visited in shortest path." << endl;
		cout << "Actual path is:" << endl;
		assert(ans.size() != 0);
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i][0] << " " << ans[i][1] << endl;
		}
		cout << endl;
	}

	return 0;
}