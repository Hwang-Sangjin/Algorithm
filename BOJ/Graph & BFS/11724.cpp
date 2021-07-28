#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

vector<int>v[1002];
int n, m;
bool visited[1002];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;

    int y;
    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int i = 0; i < v[t].size(); i++) {
            y = v[t][i];
            if (visited[y]) continue;
            //cout << y << ' ';
            q.push(y);
            visited[y] = true;
        }
    }
}

int main()
{
    
    cin >> n >> m;

    int x, y;
    while (m--) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        //cout<<"!!" << i << '\n';
        bfs(i);
        res++;
    }
    cout << res;
  
    return 0;
}
