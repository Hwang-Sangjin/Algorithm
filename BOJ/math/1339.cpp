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
#include <map>
#include <set>

using namespace std;
map<char, int>m;

int main() {
	int N;
	cin >> N;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			m[temp[j]]+=pow(10,temp.length()-j-1);
		}
	}
	vector<int> con;
	for (auto t : m) {
		//cout << t.first << ' ' << t.second << '\n';
		con.push_back(t.second);
	}
	int l = con.size();
	sort(con.begin(), con.end());
	int res = 0;
	int index;
	for (int i = 0; i < con.size(); i++) {
		index = i + 10 - l;
		
		res += con[i] * index;
	}
	cout << res;

	return 0;
}