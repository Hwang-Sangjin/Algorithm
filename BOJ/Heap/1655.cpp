#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;

struct minCmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
struct maxCmp {
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int, vector<int>, minCmp> minPQ;// 큰애들 오름 차순으로 정렬
	priority_queue<int, vector<int>, maxCmp> maxPQ;//작은 애들 내림차순으로 정렬
	int N;
	cin >> N;
	int minCnt = 0;
	int maxCnt = 0;

	int temp;
	while (N--) {
		cin >> temp;
		if (minCnt >= maxCnt) {
			if (minCnt == 0) {
				maxPQ.push(temp);
				maxCnt++;
			}
			else {
				if (minPQ.top() < temp) {
					maxPQ.push(minPQ.top());
					minPQ.pop();
					minPQ.push(temp);
				}
				else {
					maxPQ.push(temp);
				}
				maxCnt++;
			}
		}
		else if (minCnt < maxCnt) {
			if (maxCnt == 0) {
				minPQ.push(temp);
				minCnt++;
			}
			else {
				if (maxPQ.top() > temp) {
					minPQ.push(maxPQ.top());
					maxPQ.pop();
					maxPQ.push(temp);
				}
				else {
					minPQ.push(temp);
				}
				minCnt++;
			}
		}
		cout << maxPQ.top()<<'\n';
	}
	return 0;
}

