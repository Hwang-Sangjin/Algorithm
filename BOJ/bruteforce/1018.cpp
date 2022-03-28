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

int chessMap[52][52];
int N, M;
int tempMap[52][52];

int check(int y, int x) {
	int w = 0, b = 0;

	memset(tempMap, 0, sizeof(tempMap));
	bool ch = true;
	for (int i = y; i < y + 8; i++) {
		if (ch) {
			tempMap[i][x] = 1;
			if (tempMap[i][x] != chessMap[i][x])w++;
			ch = false;
		}
		else {
			if (tempMap[i][x] != chessMap[i][x])w++;
			ch = true;
		}
	}
	for (int i = y; i < y + 8; i++) {
		for (int j = x+1; j < x + 8; j++) {
			if (tempMap[i][j - 1] == 1) {
				tempMap[i][j] = 0;
				if (tempMap[i][j] != chessMap[i][j])w++;
			}
			else {
				tempMap[i][j] = 1;
				if (tempMap[i][j] != chessMap[i][j])w++;
			}
		}
	}

	memset(tempMap, 0, sizeof(tempMap));
	ch = false;
	for (int i = y; i < y + 8; i++) {
		if (ch) {
			tempMap[i][x] = 1;
			if (tempMap[i][x] != chessMap[i][x])b++;
			ch = false;
		}
		else {
			if (tempMap[i][x] != chessMap[i][x])b++;
			ch = true;
		}
	}
	for (int i = y; i < y + 8; i++) {
		for (int j = x+1; j < x + 8; j++) {
			if (tempMap[i][j - 1] == 1) {
				tempMap[i][j] = 0;
				if (tempMap[i][j] != chessMap[i][j])b++;
			}
			else {
				tempMap[i][j] = 1;
				if (tempMap[i][j] != chessMap[i][j])b++;
			}
		}
	}


	return min(w, b);
}

int main() {
	cin >> N >> M;

	char temp;
	for (int i = 0; i < N; i++) {
		scanf_s("%1c", &temp);
		for (int j = 0; j < M; j++) {
			scanf_s("%1c", &temp);
			if (temp == 'W') {
				chessMap[i][j] = 1;
			}
		}
	}
	int res = 2502;
	
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			res = min(res, check(i, j));
		}
	}
	cout << res;
}

