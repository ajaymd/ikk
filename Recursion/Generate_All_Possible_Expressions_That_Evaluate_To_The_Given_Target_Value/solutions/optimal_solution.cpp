#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 13;
const long long int MAX_TARGET = 10000000000000LL;

// ---------------------- START ----------------------

int n;

// Function to convert string to long long int. "123" -> 123.
long long int str_to_ll(string &str)
{
	long long int val = 0;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		val = val * 10LL + (str[i] - '0');
	}
	return val;
}

/*
Function to generate all valid expressions that evaluates to the given target value.
all_expressions_container -> will contain answer.
cur_expr -> will contain the expression build till now. 
Suppose one of our final expression will look like "n1+n2*n3*n4+n5+n6*n7+n8", then we will build
"cur_expr" like: 
	-> n1 (First time we will not add any operator with the number.)
	-> n1+n2 (Afterwards we will add one operator ('+' or '*') with number.)
	-> n1+n2*n3
	-> n1+n2*n3*n4
	-> n1+n2*n3*n4+n5
	-> n1+n2*n3*n4+n5+n6
	-> n1+n2*n3*n4+n5+n6*n7
	-> n1+n2*n3*n4+n5+n6*n7+n8
s -> given string.
target -> given target value.
pos -> in cur_expr we have already included digits from s[0, pos - 1] and s[pos, n - 1] is 
remaining to process.
cur_expr_val -> value of cur_expr. 
cur_expr_val_after_rightmost_addition_sign -> value of cur_expr after the rightmost addition sign
'+'. 
Suppose cur_expr = 52 then cur_expr_val_after_rightmost_addition_sign = 52.
Suppose cur_expr = 52 + 47 then cur_expr_val_after_rightmost_addition_sign = 47.
Suppose cur_expr = 52 + 3 * 4 then cur_expr_val_after_rightmost_addition_sign = 12.
Suppose cur_expr = 52 + 3 * 4 * 2 then cur_expr_val_after_rightmost_addition_sign = 24.
Suppose cur_expr = 52 + 3 * 4 * 2 + 78 then cur_expr_val_after_rightmost_addition_sign = 78.
(Will be explained in detail, why it is needed, when it will be used in code, now don't worry 
about it.)
*/
void generate_all_expressions_util(vector<string> &all_expressions_container, string cur_expr, 
	string &s, long long int target, int pos, long long int cur_expr_val, 
	long long int cur_expr_val_after_rightmost_addition_sign)
{
	// If processed the whole string.
	if (pos == n)
	{
		// Check if generated expression evaluates to the target value or not. 
		if (cur_expr_val == target)
		{
			// If generated expression evaluates to the target value then store it.
			all_expressions_container.push_back(cur_expr);
		}
		return;
	}
	/*
	As mentioned earliers we will build "cur_expr" in stages like:
		-> n1 (First time we will not add any operator with the number.)
		-> n1+n2 (Afterwards we will add one operator ('+' or '*') with number.)
		-> n1+n2*n3
		-> .....
	Now this loop will consider all possible s[pos, i] as a number and will add this number in 
	cur_expr. 
	Note that when we consider s[pos, i] as a number, it means we are using join operation!
	(Basically we are trying all possibilities!) 
	*/
	for (int i = pos; i < n; i++)
	{
		// Get the string s[pos, i] (both inclusive).
		string no_to_add_as_str = s.substr(pos, i - pos + 1);
		// Convert it to number.
		long long int no_to_add = str_to_ll(no_to_add_as_str);
		// If we have just started then first we will add number without operator. 
		if (pos == 0)
		{
			generate_all_expressions_util(all_expressions_container, no_to_add_as_str, s, target,
				i + 1, no_to_add, no_to_add);
		} 
		else
		{
			/*
			Add number with '+' operator before it. 
			For the next call variables will be:
			- cur_expr = cur_expr + '+' + no_to_add_as_str (As we are adding number with '+' 
			operator befor it.)
			- pos = i + 1 (As we have included s[pos, i] also, now remaining string to add is 
			s[i + 1, n - 1].)
			- cur_expr_val = cur_expr_val + no_to_add (As we have added number in the cur_expr 
			with '+' operator, value of the cur_expr will be increased by number we are going to 
			add.)
			- cur_expr_val_after_rightmost_addition_sign = no_to_add (As we have added number in 
			the cur_expr with '+' operator, value of the expression after rightmost addition sign
			is the number itself.)
			*/
			generate_all_expressions_util(all_expressions_container, cur_expr + '+' + 
				no_to_add_as_str, s, target, i + 1, cur_expr_val + no_to_add, no_to_add);
			/*
			Add number with '*' operator before it. 
			For the next call variables will be:
			- cur_expr = cur_expr + '*' + no_to_add_as_str (As we are adding number with '*' 
			operator befor it.)
			- pos = i + 1 (As we have included s[pos, i] also, now remaining string to add is 
			s[i + 1, n - 1].)
			Now let's take one example before we mention other variables.
			Suppose we already have build cur_expr = "1 + 3" then cur_expr_val will be 4 and cur_expr_val_after_rightmost_addition_sign will be 3.
			Now if we want to add 4 with '*' operator then cur_expr will look like "1 + 3 * 4". 
			Now how can we find the value of "1 + 3 * 4" using the values for "1 + 3"?
			Observe that due to higher precedence of '*' over '+', 3 that we have added 
			preciously as addition should be removed and it should be added as multiplication!
			So to find value of "1 + 3 * 4" from "1 + 3", first subtract the value of expression 
			after the right most '+' sign and then add it with multiplication with new number we 
			are going to add. So we have to do 4 - 3 + (3 * 4) = 13 and that will give the value 
			of the expression.  
			Also expression value after right most '+' sign will be (3 * 4).
			- cur_expr_val = cur_expr_val - cur_expr_val_after_rightmost_addition_sign + (cur_expr_val_after_rightmost_addition_sign * no_to_add)
			- cur_expr_val_after_rightmost_addition_sign = 
			cur_expr_val_after_rightmost_addition_sign * no_to_add
			*/
			generate_all_expressions_util(
				all_expressions_container, 
				cur_expr + '*' + no_to_add_as_str, s, target, i + 1, 
				cur_expr_val - cur_expr_val_after_rightmost_addition_sign + 
				(cur_expr_val_after_rightmost_addition_sign * no_to_add), 
				cur_expr_val_after_rightmost_addition_sign * no_to_add
			);
		}
	}
}

vector<string> generate_all_expressions(string s, long long int target)
{
	/*
	Store length of given string in global variable because we will be accessing it lots of 
	time. 
	*/
	n = s.length();
	// This vector will store the answer.
	vector<string> all_expressions_container;
	generate_all_expressions_util(all_expressions_container, "", s, target, 0, 0LL, 0LL);
	return all_expressions_container;
}

// ---------------------- STOP -----------------------

int main()
{
	freopen("..//test_cases//sample_test_cases_input.txt", "r", stdin);
	freopen("..//test_cases//sample_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//handmade_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//handmade_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_small_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_small_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//generated_big_test_cases_input.txt", "r", stdin);
	//freopen("..//test_cases//generated_big_test_cases_expected_output.txt", "w", stdout);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases;
	cin >> test_cases;
	while (test_cases--)
	{
		string s;
		cin >> s;
		int n = s.length();
		assert(1 <= n);
		assert(n <= MAX_N);
		for (int i = 0; i < n; i++)
		{
			assert('0' <= s[i]);
			assert(s[i] <= '9');
		}

		long long int target;
		cin >> target;
		assert(0 <= target);
		assert(target < MAX_TARGET);

		vector<string> all_expressions = generate_all_expressions(s, target);

		int len = all_expressions.size();
		cout << len << endl;
		for (int i = 0; i < len; i++)
		{
			cout << all_expressions[i] << endl;
		} 
		cout << endl;
	}

	return 0;
}