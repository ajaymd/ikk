#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int string_to_int(string s) {
	stringstream ss(s);
	int t;
	ss >> t;
	return t;
}

void foo(string str, int si, int pval, char pop, int poperand, string resstr, vector<string>& res, int K) {
	if (si == str.size()) {
		if (pval == K) res.push_back(resstr + "=" + to_string(K));
		return ;
	}

	string cstr("");
	for (int i = si; i < str.length(); ++i) {
		cstr.push_back(str[i]);
		int coperand = string_to_int(cstr);

		// This is the first operand we will be using
		if (si == 0) {
			foo(str, i + 1, coperand, ' ', coperand, cstr, res, K);
			continue;
		}
		// For addition
		foo(str, i + 1, pval + coperand, '+', coperand, resstr + "+" + cstr, res, K);

		// For multiplication
		if (pop == '+') {
			int oldval = pval - poperand;
			int val = oldval + (poperand * coperand);
			foo(str, i + 1, val, '+', poperand * coperand, resstr + "*" + cstr, res, K);
		} else
			foo(str, i + 1, pval * coperand, '*', coperand, resstr + "*" + cstr, res, K);
	}

}

int main(int argc, char const *argv[])
{
	string s("222");
	vector<string> res;
	char pop(' ');

	foo(s, 0, 0, pop, 0, "", res, 8);
	for (auto r : res) cout << r << endl;
	return 0;
}