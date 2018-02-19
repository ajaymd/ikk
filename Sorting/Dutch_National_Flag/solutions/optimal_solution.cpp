#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;

// ---- START ----

// First read the editorial.txt file and then it will be easy to understand the code. 
string dutch_flag_sort(string balls)
{
	int n = balls.length();

	// When we will encounter any red ball, we will swap it with character present at this index.
	int swap_red_here = 0;

	// Position we are processing currently.
	int current_idx = 0;

	// When we will encounter any blue ball, we will swap it with character present at this index.
	int swap_blue_here = n - 1;

	// Continue till we have sorted all the balls. 
	while (current_idx <= swap_blue_here)
	{
		if (balls[current_idx] == 'R')
		{
			/*
				Two cases here:

				1) We have encountered at least one 'G'. For that we know the solution, just swap 
				'R' with left most 'G'.
				2) We have not encountered any 'G'. Consider string 'RRRRR' and current_idx = 0. 
				In this case 'swap_red_here' we will be the same index as 'current_idx' that is 0.
				Here we just swap 'R' with it self! (Basically we are doing no change!) 

				So either we are swapping with left most 'G' if available or we are swapping with 
				itself. So both of them will maintain the structure!

				Also note that we are incrementing both the indices, current_idx and 
				swap_red_here.

				To understand that also, consider both the cases:

				1) We have encountered at least one 'G'. Consider "RRGGRB", current_idx = 4 and 
				swap_red_here will be 2, so after swap it will look like "RRRGGB", now index of 
				left most 'G' should be incremented and also at the current index we have 'G' so 
				we can skip it.
				2) We have not encountered any 'G'. Consider string 'RRRRR' and current_idx = 0. 
				In this case 'swap_red_here' we will be the same index as 'current_idx' that is 0.
				So, after the swap we can increment both of them. (This might be tricky to 
				understand without taking examples, better try to take some examples.)
			*/
			swap(balls[current_idx++], balls[swap_red_here++]);
		}
		else if (balls[current_idx] == 'G')
		{
			// Just skip the current character.
			current_idx++;
		}
		else
		{
			/*
				Two cases here:

				1) 'R' or 'G' is the last character. Then after swapping we can not increment 
				current_idx. Consider "RRGGBGRBB", current_idx = 4 and swap_blue_here = 6. After 
				the swap it will become "RRGGRGBBB". At current_idx 'R' will be there so we can 
				not skip it! In the next iteration we need to consider the same index.  
				2) 'B' is the last character. Then we will swap current 'B' with that 'B' that 
				will just decrement the swap_blue_here. (This might be tricky to understand 
				without taking examples, better try to take some examples.)
			*/
			swap(balls[current_idx], balls[swap_blue_here--]);
		}
	}
	return balls;
}

// ---- STOP ----

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
		string balls;
		cin >> balls;
		int n = balls.length();
		assert(1 <= n);
		assert(n <= MAX_N);

		int r = 0, g = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			assert(balls[i] == 'R' || balls[i] == 'G' || balls[i] == 'B');
			if (balls[i] == 'R')
			{
				r++;
			}
			else if (balls[i] == 'G')
			{
				g++;
			}
			else
			{
				b++;
			}
		}

		string ans = dutch_flag_sort(balls);

		assert(ans.length() == n);
		int idx = 0;
		while (r--)
		{
			assert(ans[idx++] == 'R');
		}
		while (g--)
		{
			assert(ans[idx++] == 'G');
		}
		while (b--)
		{
			assert(ans[idx++] == 'B');
		}

		cout << ans << endl << endl;
	}

	return 0;
}