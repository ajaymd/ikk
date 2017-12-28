#include<bits/stdc++.h>

using namespace std;



int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//small_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//big_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		int N;
		cin >> N;
		queue<int> q;
		while (N--)
		{
			int no;
			cin >> no;
			if (no >= 0)
			{
				q.push(no);
			}
			else
			{
				if (q.empty())
				{
					cout << -1 << endl;
				}
				else
				{
					cout << q.front() << endl;
					q.pop();
				}
			}
		}
		cout << endl;
	}

	return 0;
}