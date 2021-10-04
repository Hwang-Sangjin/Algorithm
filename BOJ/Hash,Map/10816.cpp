#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	map<int,int> m;
	int N,temp;
	cin >> N;

	while (N--) {
		cin >> temp;
		m[temp]++;
	}

	int M;
	cin >> M;
	while (M--) {
		cin >> temp;
		cout << m[temp] << ' ';
	}

	return 0;
}

