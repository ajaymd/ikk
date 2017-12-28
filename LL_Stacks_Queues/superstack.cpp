#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;

vector<string> tokenize(string str) {
	vector<string> res;
	string tmp;
	stringstream ss(str);
	while (getline(ss, tmp, ' ')) {
		if (!tmp.empty()) res.push_back(tmp);
	}
	return res;
}


void superStack(vector <string> operations) {
	unordered_map<int, long int> hm;
	stack<long int> s;

	for (auto oper : operations) {
		vector<string> toks = tokenize(oper);
		if (toks[0] == "push") {
			//cout << "push: " << stoi(toks[1]) << " ( " << s.size() << " ) " << endl;
			cout <<  stoi(toks[1]) <<  endl;
			s.push(stoi(toks[1]));
		} else if (toks[0] == "inc") {
			int idx = stoi(toks[1]);
			long int val = stoi(toks[2]);
			if (hm.find(idx) == hm.end()) hm[idx] = val;
			else hm[idx] += val;
			long int incr = (hm.find(s.size()) == hm.end()) ? 0 : hm[s.size()];
			cout << s.top() + incr << endl;
		} else {
			int cincr(0);
			int sz = s.size();
			if (hm.find(sz) != hm.end()) { cincr = hm[sz]; hm[sz - 1] += hm[sz]; hm.erase(sz) ;}
			s.pop();
			if (s.empty()) { cout << "EMPTY" << endl; continue;}
			cout <<  s.top() + hm[sz - 1] << endl;
		}
	}
}


int main()
{
	int operations_size = 0;
	cin >> operations_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<string> operations;
	for (int i = 0; i < operations_size; i++) {
		string operations_item;
		getline(cin, operations_item);
		operations.push_back(operations_item);
	}

	superStack(operations);

	return 0;
}
