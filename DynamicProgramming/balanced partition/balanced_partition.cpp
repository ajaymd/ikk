#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

// Balanced partition
// If all the elemnets are +ve
bool ssum_rec(vector<int> ip, int target, int ei) {
	if(target == 0) 
		return true;
	else if (ei < 0) 
		return false;
	else 
		return ssum_rec(ip, target, ei-1) || ssum_rec(ip, target-ip[ei],ei-1);
}


bool ssum_dp(vector<int> a) {
	if(a.empty()) return false;
	int target = accumulate(a.begin(), a.end(),0);
	if(target%2) return false;
	target /= 2;
	unordered_map<int ,vector<int>> um;

	um[0] = vector<int>(); // by considering no elements we can get '0'
	
	for(int i = 0; i < a.size(); i++) {
		if(um.count(a[i])==0) um[a[i]].push_back(a[i]);
		for(auto p:um) {
			if(um.count(a[i]+p.first) == 0) {
				um[a[i]+p.first] = um[p.first];
				um[a[i]+p.first].push_back(a[i]);
			}
		}
	}

	if(um.count(target) == 0) return false;
	
	cout << "Printing result" << endl;
	for(auto v: um[target]) {
		cout << v << " ";
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{
	vector<int> t = { 4, 1, -5, 6, -11, 3};
	int target = -1;
	cout << ssum_rec(t,target,t.size()-1) << endl;

	ssum_dp(t);

	cout << endl;
	return 0;
}
