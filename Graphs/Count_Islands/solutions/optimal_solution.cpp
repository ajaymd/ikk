#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 450;

// ---- START ----

// All 8 directions. Consider as pair: {add_r[i], add_r[i]}.
const int add_r[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int add_c[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void bfs(int r, int c, vector<vector<int>> &matrix)
{
	queue<pair<int, int>> q;
	q.push({r, c});
	matrix[r][c] = 0;
	while (q.empty() == false)
	{
		pair<int, int> head = q.front();
		q.pop();
		int r = head.first;
		int c = head.second;
	
		for (int i = 0; i < 8; i++)
		{
			// Try to visit all 8 neighbours.
			int new_r = r + add_r[i];
			int new_c = c + add_c[i];

			// Out of the matrix. 
			if (new_r < 0 || new_r >= matrix.size() || new_c < 0 || new_c >= matrix[0].size())
			{
				continue;
			}

			if (matrix[new_r][new_c])
			{
				/*
				We could have marked as 0 when we pop-up the element from the queue and not here. 
				This will also give correct answer, but that is not the correct way! If we do 
				that, same element will be pushed multiple times in the queue (that will increase 
				running time and queue size unnecessarily)! Take some examples and try to figure 
				it out. 
				*/
				matrix[new_r][new_c] = 0;
				q.push({new_r, new_c});
			}
		}
	}
}

int count_islands(vector<vector<int>> matrix)
{
	int islands = 0;
	int n = matrix.size();
	int m = matrix[0].size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// When we find unvisited node, visit it and visit all the reachable nodes. 
			if (matrix[i][j])
			{
				islands++;
				bfs(i, j, matrix);
			}
		}
	}
	return islands;
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
		int n, m;
		cin >> n >> m;
		assert(1 <= n);
		assert(n <= MAX_N);
		assert(1 <= m);
		assert(m <= MAX_N);

		vector<vector<int>> matrix(n, vector<int>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> matrix[i][j];
				assert(0 <= matrix[i][j]);
				assert(matrix[i][j] <= 1);
			}
		}

		int islands = count_islands(matrix);
		assert(0 <= islands);
		assert(islands <= n * m);

		cout << islands << endl;
	}

	return 0;
}