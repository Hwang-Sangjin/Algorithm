#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <climits>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;


int main() {
	int T;
	cin >> T;

	while (T--) {
		deque<char> left;
		deque<char> right;

		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<') {
				if (left.empty()) {

				}
				else {
					right.push_front(left.back());
					left.pop_back();
				}
			}
			else if (s[i] == '>') {
				if (right.empty()) {

				}
				else {
					left.push_back(right.front());
					right.pop_front();
				}
			}
			else if (s[i] == '-') {
				if (left.empty()) {

				}
				else {
					left.pop_back();
				}
			}
			else {
				left.push_back(s[i]);
			}
		}

		for (int i = 0; i < left.size();i++) {
			cout << left[i];
		}
		for (int i = 0; i < right.size(); i++) {
			cout << right[i];
		}
		cout << '\n';

	}
	
	return 0;
}