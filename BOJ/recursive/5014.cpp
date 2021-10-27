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
int v[1000002];
bool check;
int res = -1;

void go(int now, int cnt) {
	//	cout << now << ' ' << cnt<<'\n';
	if (now == G) {
		check = true;
		if (res == -1)res = cnt;
		else {
			res = min(cnt, res);
		}
		
		return;
	}

	if (now + U <= F && (v[now+U]==0||v[now+U] >cnt+1)) {
		v[now + U] = cnt+1;
		go(now + U, cnt + 1);
	}
	if (now - D > 0 && (v[now-D]==0 || v[now - D] >cnt+1)) {
		v[now - D] = cnt+1;
		go(now - D,cnt + 1);
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;

	v[S] = 0;
	go(S, 0);

	if (check) {
		cout << res;
	}
	else {
		cout << "use the stairs";
	}

	return 0;
}