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

bool map[22];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	memset(map, false, sizeof(map));

	string com;
	int x;

	while (n--) {
		cin >> com;

		if (com == "add") {
			cin >> x;
			map[x] = true;
		}
		else if (com == "remove") {
			cin >> x;
			map[x] = false;
		}
		else if (com == "check") {
			cin >> x;
			if (map[x] == true) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (com == "toggle") {
			cin >> x;
			map[x] = !map[x];
		}
		else if (com == "all") {
			memset(map, true, sizeof(map));
		}
		else if (com == "empty") {
			memset(map, false, sizeof(map));
		}
	}


	
	return 0;
}