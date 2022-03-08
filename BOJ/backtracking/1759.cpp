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
#include <set>
#include <map>

using namespace std;
int L, C;
vector<char> v;
map<char, bool>isMo;

void go(string t,int index, int mo, int ja) {
	if (t.length() == L) {
		if (mo >= 1 && ja >= 2) {
			cout << t << '\n';
		}
		return;
	}
	for (int i = index; i < C; i++) {
		if (isMo[v[i]]) {
			go(t + v[i], i + 1, mo + 1, ja);
		}
		else {
			go(t + v[i], i + 1, mo, ja+1);
		}
	}


}

int main() {
	isMo['a'] = true;
	isMo['e'] = true;
	isMo['i'] = true;
	isMo['o'] = true;
	isMo['u'] = true;

	cin >> L >> C;
	char temp;
	string t = "";
	for (int i = 0; i < C; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	go(t, 0, 0, 0);
}