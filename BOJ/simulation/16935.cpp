#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

int di[4] = { -1,0,1,0};
int dj[4] = { 0,1,0,-1};

using namespace std;
vector<vector<int>> map(102,vector<int>(102));
int N, M, R;

void upSideDown() {
	vector<vector<int>> temp(102, vector<int>(102));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[N - 1 - i][j];
		}
	}
	map = temp;
}

void leftSideRight() {
	vector<vector<int>> temp(102, vector<int>(102));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[i][M-j-1];
		}
	}
	map = temp;
}

void diagnalChange() {
	swap(N, M);
	vector<vector<int>> temp(102, vector<int>(102));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[j][i];
		}
	}
	map = temp;
}

void clockwiseChange() {
	int ki = N / 2;
	int kj = M / 2;
	vector<vector<int>> temp(102, vector<int>(102));

	for (int i = 0; i < ki; i++) {
		for (int j = kj; j < M; j++) {
			temp[i][j] = map[i][j - kj];
		}
	}
	for (int i = ki; i < N; i++) {
		for (int j = kj; j < M; j++) {
			temp[i][j] = map[i-ki][j];
		}
	}
	for (int i = ki; i < N; i++) {
		for (int j = 0; j < kj; j++) {
			temp[i][j] = map[i][j+ kj];
		}
	}
	for (int i = 0; i < ki; i++) {
		for (int j = 0; j < kj; j++) {
			temp[i][j] = map[i + ki][j];
		}
	}
	map = temp;
}

void antiClockwiseChange() {
	int ki = N / 2;
	int kj = M / 2;
	vector<vector<int>> temp(102, vector<int>(102));

	for (int i = 0; i < ki; i++) {
		for (int j = kj; j < M; j++) {
			temp[i][j] = map[i+ki][j];
		}
	}
	for (int i = ki; i < N; i++) {
		for (int j = kj; j < M; j++) {
			temp[i][j] = map[i][j-kj];
		}
	}
	for (int i = ki; i < N; i++) {
		for (int j = 0; j < kj; j++) {
			temp[i][j] = map[i-ki][j];
		}
	}
	for (int i = 0; i < ki; i++) {
		for (int j = 0; j < kj; j++) {
			temp[i][j] = map[i][j + kj];
		}
	}
	map = temp;
}

int main()
{
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int com;
	while (R--) {
		cin >> com;
		if (com == 1) {
			upSideDown();
		}
		else if (com == 2) {
			leftSideRight();
		}
		else if (com == 3) {
			upSideDown();
			diagnalChange();
		}
		else if (com == 4) {
			leftSideRight();
			diagnalChange();
		}
		else if (com == 5) {
			clockwiseChange();
		}
		else if (com == 6) {
			antiClockwiseChange();
		}
	}

	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<<map[i][j]<<' ';
		}
		cout << '\n';
	}

}

