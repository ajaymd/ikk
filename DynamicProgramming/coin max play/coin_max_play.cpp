#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <numeric>

using namespace std;

int coin_max_profit_rec(vector<int>& v, int i , int j) {
	if(j == i) return v[i];
	if(j -i == 1) return max(v[i], v[j]);
	if(i > j) return INT_MAX;

	int p1 = v[i] + min(coin_max_profit_rec(v,i+2,j), coin_max_profit_rec(v,i+1,j-1));
	int p2 = v[j] + min(coin_max_profit_rec(v,i+1,j-1), coin_max_profit_rec(v,i,j-2));
	return max(p1,p2);
}

int coin_max_profit_dp(vector<int>& v) {
	vector<vector<int>> opt(v.size(), vector<int>(v.size(), 0));

	for(int i = 0; i < v.size();i++) opt[i][i] = v[i];

	for(int s = 1; s < v.size(); s++) {
		for(int i = 0; i < v.size()-s; i++) {
			int j = i+s;
			int p1 = (i < v.size()-2)?opt[i+2][j]:0;
			int p2 = (i < v.size()-1 && j > 0)?opt[i+1][j-1]:0;
			int p3 = (j > 1)?opt[i][j-2]:0;
			opt[i][j] = max(v[i]+min(p1,p2) , v[j]+min(p2,p3));
		}
	}

	return opt[0][v.size()-1];

}

int main(int argc, char const *argv[])
{
	vector<int> v1 = {5,3,7,10};
	vector<int> v2 = {20, 30, 2, 2, 2, 10};
	vector<int> v3 = {8, 15, 3, 7};
	vector<int> v4 = { 5,6};

	cout << coin_max_profit_rec(v1,0,3) << " " << coin_max_profit_dp(v1) <<  endl;
	cout << coin_max_profit_rec(v2,0,5) <<" " << coin_max_profit_dp(v2) << endl;
	cout << coin_max_profit_rec(v3,0,3) << " " << coin_max_profit_dp(v3) <<endl;
	cout << coin_max_profit_rec(v4,0,1) <<" " << coin_max_profit_dp(v4) << endl;

	return 0;
}
