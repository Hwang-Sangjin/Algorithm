#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <time.h>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;

int N;

int map[12][12];

vector<int>v;
bool check = false;

bool possible(int index) {
	int sum = 0;
	for (int i = index; i >=0; i--) {
		sum += v[i];

		if (map[i][index] == 1 && sum <= 0)	return false;
        if (map[i][index] == -1 && sum >= 0)	return false;
        if (map[i][index] == 0 && sum != 0)	return false;
	}
	return true;
}

void go(int cnt) {
	if (cnt == N) {
		for (auto t : v) {
			cout << t << ' ';
		}
		exit(0);
	}

	for (int i = -10; i <= 10; i++) {
		v.push_back(i);

		if (possible(cnt)) {
			go(cnt + 1);
		}
		v.pop_back();
	}
}

int main() {

	cin >> N;
	
	string s;
	cin >> s;

	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (s[index] == '-') {
				map[i][j] =-1;
			}
			else if (s[index] == '+') {
				map[i][j] = 1;
			}
			if (s[index] == '0') {
				map[i][j] = 0;
			}
			
			index++;
		}
	}
	

	go(0);


	
	return 0;
}