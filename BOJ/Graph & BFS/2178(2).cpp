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

using namespace std;

int di[4] = { -1,0,1,0 }; // direction i
int dj[4] = { 0,1,0, -1};// direction j
//bfs
/*
    1. queue
    2. 방문 여부 체크하는 data필요
    3. 하나씩 사용후에 queue를 pop
    4. 4 방향 탐색
    5. 방문 할 필요가 없는 녀석 check
*/

// x y -> x-1 y(12) x y+1(3)

//queue -> fifo

int map[102][102];// int 전역 변수시 0
bool v[102][102]; //bool 전역 변수시 false
int N, M;

int bfs() {
    queue<pair<pair<int, int>,int>> q; //pos, count
    q.push({ {1,1},1 });
    v[1][1] = true;
    int temp;
    bool check = false;//목표지점을 찾았는지 아닌지

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        auto tpos = t.first;
        int ti = tpos.first;
        int tj = tpos.second;
        int tcnt = t.second;

        for (int k = 0; k < 4; k++) {
            int ni = ti + di[k];
            int nj = tj + dj[k];
            /*
            * 1. 맵 범위 안에 있는가?
            * 2. 유효한 녀석인가?
            * 3. 이미 방문한 녀석인가?
            * //4. 도착지점
            */
            if (ni <= 0 || nj <= 0 || ni > N || nj > M || map[ni][nj] == 0 || v[ni][nj]) continue;//방문 할 필요가 없는 녀석

            if (ni == N && nj == M) {
                temp = tcnt + 1;
                check = true;
                break;
            }

            q.push({ {ni,nj},tcnt + 1 });
            v[ni][nj] = true;
        }
        if (check) break;
    }
    return temp;
}

int main() {
    int res = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf_s("%1d", &map[i][j]);
        }
    }
    
    res = bfs();
    cout << res;

    return 0;
}