#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;

int main()
{
	
	stack<int> st;
	int N;
	cin >> N;
	vector<int> H (N+2);

	int temp;
	for (int i = 1; i <= N; i++) {
		cin >> H[i];
	}

	st.push(0);
	int res = 0;

	for (int i = 1; i <= N +1; i++) {
		
		while (!st.empty() && H[st.top()] > H[i]) {
			int t = st.top();
			st.pop();
			res = max(res, H[t] * (i - st.top() -1));
		}
		st.push(i);
	}
	cout << res;

}
