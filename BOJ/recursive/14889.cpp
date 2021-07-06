#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int map[22][22];
vector<int> v;

int res = -1;

int N;

void go(int index, int cnt) {
    if (cnt == N / 2) {
        bool check[22];
        memset(check, false, sizeof(check));
        for (auto t : v) {
            check[t] = true;
        }

        int start=0, link=0;

        for (int i = 1; i < N; i++) {
            if (check[i]==true) {
                for (int j = i + 1; j <= N; j++) {
                    if (check[j]==true) {
                        start += map[i][j];
                        start += map[j][i];
                    }
                }
            }
            else if (check[i] == false) {
                for (int j = i + 1; j <= N; j++) {
                    if (check[j] == false) {
                        link += map[i][j];
                        link += map[j][i];
                    }
                }
            }
        }

        int sub = abs(start - link);
        if (res == -1 || res > sub)res = sub;
        return;
    }
    for (int i = index + 1; i <= N; i++) {
        v.push_back(i);
        go(i, cnt + 1);
        v.pop_back();
    }
}

int main() {
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    go(0,0);

    cout << res;

    return 0;
}