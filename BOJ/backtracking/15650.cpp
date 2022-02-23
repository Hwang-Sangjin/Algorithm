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

using namespace std;

int N, M;
bool v[10];
vector<int> con;

void go(int index,int cnt) {
	if (cnt == M) {
		for (auto t : con) {
			cout << t << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = index; i <= N; i++) {
		if (v[i]) continue;
		v[i] = true;
		con.push_back(i);
		go(i,cnt + 1);
		con.pop_back();
		v[i] = false;
	}

}

int main() {
	cin >> N >> M;

	go(1,0);
}