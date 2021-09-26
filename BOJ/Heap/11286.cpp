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
	bool operator()(pair<int,int>a, pair<int, int>b) {
		if (a.first > b.first) return true;
		else if (a.first == b.first) {
			if (a.second > b.second) return true;
			else return false;
		}
		else return false;
	}
};

int main()
{
	//cout << pow(-1,true);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<pair<int, int>, vector<pair<int,int>>, cmp>pq;

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
				auto t = pq.top();
				cout << t.second<<'\n';
				pq.pop();
			}
		}
		else {
			if (cmd > 0) {
				pq.push({ cmd,cmd });
			}
			else if(cmd<0){
				pq.push({ abs(cmd),cmd });
			}
		}
	}

	return 0;
}

