#include "pch.h"
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
#include <stdio.h>

#define INF 987654321

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
int N, M;
int map[502][502];
int res = -1;

void go(int si, int sj) {
	/*
		**
		**
	*/
	int temp = 0;
	if (si >= N - 1 || sj >= M - 1);
	else {
		for (int i = si; i < si+2; i++) {
			for (int j = sj; j < sj+2; j++) {
				temp += map[i][j];
			}
		}
		res = max(res, temp);
	}
	//****
	temp = 0;
	if (si >= N || sj >= M - 3);
	else {
		for (int i = si; i < si +1; i++) {
			for (int j = sj; j < sj + 4; j++) {
				temp += map[i][j];
			}
		}
		res = max(res, temp);
	}
	/*
		*
		*
		*
		*
	*/
	temp = 0;
	if (si >= N-3 || sj >= M);
	else {
		for (int i = si; i < si +4; i++) {
			for (int j = sj; j < sj + 1; j++) {
				temp += map[i][j];
			}
		}
		res = max(res, temp);
	}
	
	/*
		* *
		* *
		* *
	*/
	temp = 0;
	if (si >= N - 2 || sj >= M-1);
	else {
		for (int i = si; i < si + 3; i++) {
			for (int j = sj; j < sj + 2; j++) {
				temp += map[i][j];
			}
		}
		/*
			* 
			* 
			* *
		*/
		int ntemp = temp;
		ntemp -= map[si][sj + 1] + map[si + 1][sj + 1];
		res = max(res, ntemp);

		/*
			* *
			  *
			  *
		*/
		ntemp = temp;
		ntemp -= map[si+1][sj] + map[si + 2][sj];
		res = max(res, ntemp);

		/*
			  *
			  *
			* *
		*/
		ntemp = temp;
		ntemp -= map[si][sj] + map[si + 1][sj];
		res = max(res, ntemp);

		/*
			* *
			* 
			* 
		*/
		ntemp = temp;
		ntemp -= map[si +1][sj +1] + map[si + 2][sj +1];
		res = max(res, ntemp);

		/*
			  *
			* *
			*
		*/
		ntemp = temp;
		ntemp -= map[si][sj] + map[si + 2][sj + 1];
		res = max(res, ntemp);

		/*
			* 
			* *
			  *
		*/
		ntemp = temp;
		ntemp -= map[si][sj + 1] + map[si + 2][sj];
		res = max(res, ntemp);

		/*
			* 
			* *
			*
		*/
		ntemp = temp;
		ntemp -= map[si][sj + 1] + map[si + 2][sj + 1];
		res = max(res, ntemp);

		/*
			  *
			* *
			  *
		*/
		ntemp = temp;
		ntemp -= map[si][sj] + map[si + 2][sj];
		res = max(res, ntemp);
	}

	/*
		* * *
		* * *
	*/
	temp = 0;
	if (si >= N - 1 || sj >= M - 2);
	else {
		for (int i = si; i < si + 2; i++) {
			for (int j = sj; j < sj + 3; j++) {
				temp += map[i][j];
			}
		}

		/*
			* * *
			* 
		*/
		int ntemp = temp;
		ntemp -= map[si + 1][sj + 1] + map[si + 1][sj + 2];
		res = max(res, ntemp);

		/*
			* * *
			    *
		*/
		ntemp = temp;
		ntemp -= map[si + 1][sj] + map[si + 1][sj + 1];
		res = max(res, ntemp);

		/*
			*
			* * *
		*/
		ntemp = temp;
		ntemp -= map[si][sj + 1] + map[si][sj + 2];
		res = max(res, ntemp);

		/*
			    *
			* * *
		*/
		ntemp = temp;
		ntemp -= map[si][sj] + map[si][sj + 1];
		res = max(res, ntemp);

		/*
			* * 
			  * *
		*/
		ntemp = temp;
		ntemp -= map[si + 1][sj] + map[si][sj + 2];
		res = max(res, ntemp);

		/*
			  * *
			* * 
		*/
		ntemp = temp;
		ntemp -= map[si][sj] + map[si + 1][sj + 2];
		res = max(res, ntemp);

		/*
			  *
			* * *
		*/
		ntemp = temp;
		ntemp -= map[si][sj] + map[si][sj + 2];
		res = max(res, ntemp);

		/*
			* * *
			  *
		*/
		ntemp = temp;
		ntemp -= map[si + 1][sj] + map[si + 1][sj + 2];
		res = max(res, ntemp);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			go(i, j);
		}
	}
	cout << res;

	return 0;
}