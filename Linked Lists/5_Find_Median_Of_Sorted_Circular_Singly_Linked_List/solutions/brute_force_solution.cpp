#include<bits/stdc++.h>

using namespace std;



int main()
{
	//freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//sample_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//small_test_cases_output.txt", "w", stdout);
	//freopen("..//test_cases//big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//big_test_cases_output.txt", "w", stdout);
	freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		int N;
		cin >> N;
		vector<long long int> nos(N);
		for (int i = 0; i < N; i++)
		{
			cin >> nos[i];
		}
		int shifts;
		cin >> shifts;
		sort(nos.begin(), nos.end());
		if (N % 2)
		{
			cout << nos[N / 2] << endl;
		}
		else
		{
			cout << (nos[(N - 1) / 2] + nos[(N - 1) / 2 + 1]) / 2 << endl;
		}
	}

	return 0;
}