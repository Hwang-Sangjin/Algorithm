#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

vector<int> map[20002];
int color[20002];

void bfs(int x) {
    queue <int> q;
    q.push(x);
    color[x] = 1;

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        int tempcolor = color[t];

        int y;
        for (int i = 0; i < map[t].size(); i++) {
            y = map[t][i];
            if (color[y] != 0) continue;
            q.push(y);
            if (tempcolor == 1)color[y] = 2;
            else if(tempcolor ==2) color[y] = 1;
        }
    }

}

int main()
{
    int t;
    cin >> t;

    int v, e;
    while (t--) {
        cin >> v >> e;

        int x, y;
        while (e--) {
            cin >> x >> y;
            map[x].push_back(y);
            map[y].push_back(x);
        }

        for (int i = 1; i <= v; i++) {
            if (color[i] == 0) {
                bfs(i);
            }
        }
        

        bool res = true;
        for (int i = 1; i <= v; i++) {
            for (int j = 0; j < map[i].size(); j++) {
                int next = map[i][j];
                if (color[i] == color[next]) {
                    res = false;
                    break;
                }
            }
            if (res == false) break;
        }
        if (res) cout << "YES\n";
        else cout << "NO\n";

        memset(color, 0, sizeof(color));
        memset(map, 0, sizeof(map));
    }
  
    return 0;
}
