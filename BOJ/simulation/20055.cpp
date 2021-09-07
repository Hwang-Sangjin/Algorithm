#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;

int di[4] = { -1,0,1,0};
int dj[4] = { 0,1,0,-1};

int n, k;

int main()
{
	cin >> n >> k;
	int res = 0;

	deque<int>up;
	deque<int> down;
	vector<bool> robot (n+1,false);
	queue<int> robotIndex;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		up.push_back(temp); // f 10 1 10 6 b 
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		down.push_front(temp); // f 2 8 4 3 b
	}

	

	while (1) {
		res++;
		/*for (int i = 0; i < n; i++) {
			cout << up[i] << ' ';
		}
		cout << '\n';
		for (int i = 0; i < n; i++) {
			cout << down[i] << ' ';
		}
		cout << '\n';*/

		down.push_back(up[n - 1]);
		up.pop_back();
		up.push_front(down[0]);
		down.pop_front();

		int qsize = robotIndex.size();
		while (qsize--) {
			int t = robotIndex.front();
			robotIndex.pop();
			robot[t] = false;
			if (t + 1 == n - 1) {
				continue;
			}
			else {
				robot[t + 1] = true;
				robotIndex.push(t + 1);
			}
		}

		qsize = robotIndex.size();
		while (qsize--) {
			int t = robotIndex.front();
			robotIndex.pop();

			if (t + 1 == n - 1) {
				if (up[t + 1] == 0) {

				}
				else {
					up[t + 1]--;
					robot[t] = false;
				}
			}
			else {
				if (robot[t + 1] == true || up[t + 1] == 0) {
					robotIndex.push(t);
				}
				else {
					robot[t] = false;
					robot[t + 1] = true;
					robotIndex.push(t + 1);
					up[t + 1] --;
				}
			}
		}

		if (up[0] != 0) {
			robot[0] = true;
			robotIndex.push(0);
			up[0]--;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (up[i] == 0) cnt++;
			if (down[i] == 0) cnt++;
		}
		//cout << cnt << "!!\n";
		if (cnt >= k)break;
	}
	cout << res;
}

