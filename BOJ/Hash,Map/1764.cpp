#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>
#include <map>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	map<string,int> m;
	set<string>s;
	int N, M;
	cin >> N >> M;

	string temp;
	while (N--) {
		cin >> temp;
		m[temp]++;
		s.insert(temp);
	}
	while (M--) {
		cin >> temp;
		m[temp]++;
		s.insert(temp);
	}
	vector<string> answer;
	for (auto t : s) {
		if (m[t] == 2) {
			answer.push_back(t);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size()<<'\n';
	for (auto t : answer) {
		cout << t << '\n';
	}
	

	return 0;
}

