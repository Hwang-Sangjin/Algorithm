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
#include<string>

using namespace std;

bool isAlpha(string test) {
	char firstLetter = test[0];

	if (firstLetter >= '0' && firstLetter <= '9') {
		return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N,M;
	cin >> N >> M;
	map<string, int> poketmonMap;
	map<int, string> poketmonMapInt;

	string temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		poketmonMap[temp] = i;
		poketmonMapInt[i] = temp;
	}

	string test;
	while (M--) {
		cin >> test;
		if (isAlpha(test)) {//영어
			cout << poketmonMap[test] << '\n';
		}
		else {//숫자
			cout << poketmonMapInt[stoi(test)] << '\n';
		}
	}

	return 0;
}

