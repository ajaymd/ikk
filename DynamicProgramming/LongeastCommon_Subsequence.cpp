#include <iostream>
#include <string>
#include <vector>

using namespace std;

int rec(0);
int mem(0);

string LCS_rec(string s1, string s2, int i1, int i2) {
	if (i1 == s1.size() || i2 == s2.size() ) return "";
	rec++;
	if (s1[i1] == s2[i2]) {
		return s1[i1] + LCS_rec(s1, s2 , i1 + 1, i2 + 1);
	} else {
		string res1 = LCS_rec(s1, s2, i1, i2 + 1);
		string res2 = LCS_rec(s1, s2, i1 + 1, i2);
		return res1.size() > res2.size() ? res1 : res2;
	}
}

string LCS_memo(string s1, string s2, int i1, int i2, vector<vector<string>>& memo) {

	if (i1 == s1.size() || i2 == s2.size() ) return "";
	if (memo[i1][i2] != "") return memo[i1][i2];
	mem++;
	if (s1[i1] == s2[i2]) {
		memo[i1][i2] =  s1[i1] + LCS_memo(s1, s2 , i1 + 1, i2 + 1, memo);
	} else {
		string res1 = LCS_memo(s1, s2, i1, i2 + 1, memo);
		string res2 = LCS_memo(s1, s2, i1 + 1, i2, memo);
		memo[i1][i2] = res1.size() > res2.size() ? res1 : res2;
	}
	return memo[i1][i2];
}

string LCS_dp(string s1, string s2) {
	vector<vector<string>> memo(s1.length() + 1, vector<string>(s2.length() + 1, ""));

	for (int i1 = 1 ; i1 <= s1.length(); i1++) {
		for (int i2 = 1; i2 <= s2.length(); i2++) {
			if (s1[i1 - 1] == s2[i2 - 1]) {
				memo[i1][i2] = memo[i1 - 1][i2 - 1] + s1[i1 - 1];
			} else {
				memo[i1][i2] = memo[i1 - 1][i2].length() > memo[i1][i2 - 1].length() ? memo[i1 - 1][i2] : memo[i1][i2 - 1];
			}
		}
	}
	return memo[s1.size()][s2.size()];
}


int main(int argc, char const *argv[])
{
	string res("");

	cout << LCS_rec("AGGTAB", "GXTXAYB", 0, 0) << endl;
	vector<vector<string>> memo(7, vector<string>(8, ""));
	cout << LCS_memo("AGGTAB", "GXTXAYB", 0, 0, memo) << endl;
	//cout << LCS_rec("AGGTAB", "GXTXAYB") << endl;
	cout << LCS_dp("AGGTAB", "GXTXAYB") << endl;

	cout << "rec " << rec << endl;
	cout << "mem " << mem << endl;
	return 0;
}
