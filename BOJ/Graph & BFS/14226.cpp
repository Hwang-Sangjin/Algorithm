#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

int di[4] = { -1,0,1,0};
int dj[4] = { 0,1,0,-1};

using namespace std;

int v[2002][2002];

void bfs(int S) {
	queue <pair<pair<int, int>, int>>q;
	q.push({ {1,0},0 });
	v[1][0] = true;

	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		int tindex = t.first.first;
		int tclip = t.first.second;
		int tcnt = t.second;

		if (tindex == S) {
			cout << tcnt;
			break;
		}

		if (tindex <= 0 || tindex >= 2000) continue;

		if (v[tindex][tindex] == false) {
			v[tindex][tindex] = true;
			q.push({ {tindex,tindex},tcnt + 1 });
		}
		if (v[tindex-1][tclip] == false) {
			v[tindex - 1][tclip] = true;
			q.push({ {tindex-1,tclip},tcnt + 1 });
		}

		if (tindex + tclip >= 2000) continue;
		if (v[tindex + tclip][tclip] == false) {
			v[tindex + tclip][tclip] = true;
			q.push({ {tindex + tclip,tclip},tcnt + 1 });
		}
	}

}

int main()
{
	int S;
	cin >> S;

	bfs(S);
}

