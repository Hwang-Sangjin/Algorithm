#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;
int n, m, v;
vector<int> map[1002];
bool visited[1002];

void dfs(int x) {
    cout << x << ' ';
    visited[x] = true;
    int y;
    for (int i = 0; i < map[x].size(); i++) {
        y = map[x][i];
        if (visited[y]) continue;
        dfs(y);
    }
}

void bfs() {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    int y;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << t << ' ';
        
        for (int i = 0; i < map[t].size(); i++) {
            y = map[t][i];
            if (visited[y]) continue;
            q.push(y);
            visited[y] = true;
        }
    }
}

int main()
{
    cin >> n >> m >> v;
    int x, y;
    while (m--) {
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        sort(map[i].begin(), map[i].end());
    }


    dfs(v);

    memset(visited, false, sizeof(visited));
    cout << '\n';
    bfs();

  
    return 0;
}
