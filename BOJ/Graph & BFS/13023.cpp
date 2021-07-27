#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

bool v[2002];
vector<int> relation[2002];
int n, m;

void dfs(int x, int index) {
    v[x] = true;
    if (index == 4) {
        cout << 1;
        exit(0);
    }

    for (int i = 0; i < relation[x].size(); i++) {
        if (v[relation[x][i]] == false) {
            dfs(relation[x][i], index + 1);
        }
    }
    v[x] = false;
}

int main()
{
    
    cin >> n >> m;

    int x, y;
    while (m--) {
        cin >> x >> y;
        relation[x].push_back(y);
        relation[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }
    cout << 0;

    return 0;
}
