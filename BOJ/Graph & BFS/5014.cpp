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
#include <stdio.h>

#define INF 987654321

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
int F, S, U, D, G;
bool v[1000002];
bool check;
int res = 0;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ S,0 });
	v[S] = true;

	while (!q.empty()) {
		auto t = q.front();
		int ti = t.first;
		int tcnt = t.second;
		q.pop();

		if (ti == G) {
			res = tcnt;
			check = true;
			break;
		}

		if (ti + U <= F && v[ti + U] == false) {
			q.push({ ti + U,tcnt + 1 });
			v[ti + U] = true;
		}
		

		if (ti - D > 0 && v[ti - D] == false) {
			q.push({ ti - D,tcnt + 1 });
			v[ti - D] = true;
		}
		
	}

}

int main() {
	cin >> F >> S >> G >> U >> D;

	bfs();
	
	if (check) {
		cout << res;
	}
	else {
		cout << "use the stairs";
	}


	return 0;
}