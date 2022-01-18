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

//next_permutation -> #include <algorithm>

vector<int>v;

int main() {
	int N,temp,res =0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	//1 4 8 10 15 20 -> 6자리의 모든 순열의 가지수? 6!
	//1 4 8 10 20 15 -> 
	//1 4 8 15 10 20
	do {
		int temp = 0;
		for (int i = 0; i < N-1;i++) {
			temp += abs(v[i] - v[i + 1]);
		}
		res = max(res, temp);
	} while (next_permutation(v.begin(),v.end()));

	cout << res;
}