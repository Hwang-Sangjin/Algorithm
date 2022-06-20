#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <string> 
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <sstream>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;

vector<vector<int>>res(10);
vector<int> v;

void insertTree(int depth, int start, int end) {
	//cout << depth << ' ' << start << ' ' << end << '\n';
	if (start >= end) return;

	int mid = (start + end) / 2;

	res[depth].push_back(v[mid]);

	insertTree(depth + 1, start, mid);
	insertTree(depth + 1, mid+1, end);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int K;
	cin >> K;

	
	

	int t;
	for (int i = 0; i < pow(2, K) - 1; i++) {
		cin >> t;
		v.push_back(t);
	}

	insertTree(0, 0, pow(2, K)-1);

	for (int i = 0; i < K; i++) {
		for (auto t : res[i]) {
			cout << t << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}

