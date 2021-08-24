//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

bool v[200002];
int pre[200002];

int main() {
	int n, m, res;
	cin >> n >> m;

	queue<pair<int, int>>q;
	q.push({ n,0 });
	v[n] = true;

	while (!q.empty()) {
		auto temp = q.front();
		int tposition = temp.first;
		int tcnt = temp.second;
		//cout << tposition << '\n';
		if (tposition == m) {
			cout << tcnt<<'\n';
			break;
		}
		q.pop();

		int nextp = 0;
		nextp = tposition - 1;
		if (nextp < 0 || v[nextp]);
		else {
			q.push({ nextp,tcnt + 1 });
			v[nextp] = true;
			pre[nextp] = tposition;
		}

		nextp = tposition + 1;
		if (nextp > 100000 || v[nextp]);
		else {
			q.push({ nextp,tcnt + 1 });
			v[nextp] = true;
			pre[nextp] = tposition;
		}

		nextp = tposition * 2;
		if (nextp > 100000 || v[nextp]);
		else {
			q.push({ nextp,tcnt + 1 });
			v[nextp] = true;
			pre[nextp] = tposition;
		}
	}

	stack<int> st;
	queue <int> qq;
	qq.push(m);
	
	while (!q.empty()) {
		int t = qq.front();
		qq.pop();
		if (t == n) {
			st.push(t);
			break;
		}

		qq.push(pre[t]);
		st.push(t);
	}
	
	while (!st.empty()) {
		cout << st.top()<<' ';
		st.pop();
	}

	return 0;
}