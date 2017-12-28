#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 4000;

long long int random_number(long long int mod)
{
	long long int number = rand();
	number |= ((long long int)rand() << 31LL);
	return number % mod;  
}

void _6()												// bzbaaaaaa...aaa
{
	cout << "bzb";
	for (int i = 0; i < MAX_N - 3; i++)
	{
		cout << "a";
	}
	cout << endl;
}

void _5()												// First generate any random palindrome and then rotate it. 
{
	string s = "";
	for (int i = 0; i < MAX_N / 2; i++)
	{
		int temp = random_number(26);
		s = (char)('a' + temp) + s + (char)('a' + temp);
	}
	s = s + s;
	s = s.substr(MAX_N / 2, MAX_N);
	cout << s << endl;
}

void _4()												// MAX_N = 4000 so 4000 / 26 = 153 now we can make 152 cycles of abc...xyz. 152 = 76 + 76 cycles. Here first 76 will be abc...xyzabc...xyz and then other 76 cycles will be reverse of(abc...xyzabc...xyz). Then rotate it. 
{
	string s = "";
	int cycles = 76;
	for (int i = 0; i < cycles * 26; i++)
	{
		s = s + char ('a' + i % 26);
	}
	string s_rev = s;
	reverse(s_rev.begin(), s_rev.end()); 
	s = s + s_rev;
	s = s + s;
	s = s.substr((152 * 26) / 2, 152 * 26);
	cout << s << endl;
}

void _3()												// Random string 
{
	for (int i = 0; i < MAX_N; i++)
	{
		cout << char ('a' + random_number(26));
	}
	cout << endl;
}

void _2()												// Random string 
{
	_3();
}

void _1()												// bzzbaaaaaa...aaa
{
	cout << "bzzb";
	for (int i = 0; i < MAX_N - 4; i++)
	{
		cout << "a";
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	freopen("..//test_cases//big_test_cases_input.txt", "w", stdout);

	int test_cases = 6;
	cout << test_cases << endl;
	_1();
	_2();
	_3();
	_4();
	_5();
	_6();

	return 0;
}