#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> nmap = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{1,7,0},{2,6},{1,3},{2,4}};
int rec_count(0);
int mem_count(0);


int num_ways_rec(int snum, int numleft) {
	if(numleft == 1) return 1;
	rec_count++;
	int res(0);
	for(auto x:nmap[snum]) {
		res += num_ways_rec(x,numleft-1);
	}
	return res;
}

int numways_mem(int snum, int numleft, vector<vector<int>>& memo) {
	if(numleft == 1) return 1;
	if(memo[snum][numleft] != -1) return memo[snum][numleft];

	mem_count++;
	int res(0);
	for(auto x:nmap[snum]) {
		res += numways_mem(x,numleft-1, memo);
	}
	memo[snum][numleft] = res;
	return res;
}

int numways_dp(int snum, int length) {
	vector<vector<int>> nw(10, vector<int>(length+1,0));
	for(int i=0;i<10;i++) {
		nw[i][1] = 1;
	}
	for(int i = 2; i <= length;i++) {
		for(int s = 0; s < 10; s++) {
			for(auto x:nmap[s])
				nw[s][i] += nw[x][i-1];
		}
	}
	return nw[snum][length];
}


int main(int argc, char const *argv[])
{

	cout << num_ways_rec(1,10) << endl;
	cout << rec_count << endl;

	vector<vector<int>> memo(10,vector<int>(11,-1));
	cout << numways_mem(1,10,memo) << endl;
	cout << mem_count << endl;
	
	cout << numways_dp(1,10) << endl;

	return 0;
}
