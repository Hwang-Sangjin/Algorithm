#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (a > b) return true;
		else return false;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int, vector<int>, cmp>pq;

	int N;
	cin >> N;
	
	int cmd;
	while (N--) {
		cin >> cmd;
		if (cmd == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(cmd);
		}
	}

	return 0;
}

