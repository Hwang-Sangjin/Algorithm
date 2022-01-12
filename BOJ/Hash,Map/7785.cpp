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
#include <map>
#include <set>

using namespace std;

bool comp(string s1, string s2) {
	return s1 > s2;	//string 사전 역순 
}

int main() {
	map<string, bool>giggle;
	vector<string> answer;
	int N;
	cin >> N;

	string em, com;
	while (N--) {
		cin >> em >> com;
		giggle[em] = !giggle[em];
	}

	for (auto t : giggle) {
		//cout << t.first << ' ' << t.second<<'\n';
		if (t.second == 0) continue;
		else {
			answer.push_back(t.first);
		}
	}

	sort(answer.begin(), answer.end(), comp);

	for (auto t : answer) {
		cout << t << '\n';
	}
}