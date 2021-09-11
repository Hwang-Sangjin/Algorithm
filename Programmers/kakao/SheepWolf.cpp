#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;
bool v[18][18][18];
bool con[18][18];
int N;
vector<int> Info;
int answer = 1;

void bfs() {
    queue<pair<pair<int, pair<int, int>>,vector<bool>>>q;
    vector<bool> fir(18, false);
    fir[0] = true;
    q.push({ { 0,{1,0} }, fir});
    v[0][1][0] = true;

    while (!q.empty()) {
        auto tt = q.front();
        auto t = tt.first;
        vector<bool> curCon = tt.second;
        q.pop();
        int curIndex = t.first;
        auto condition = t.second;
        int sCnt = condition.first;
        int wCnt = condition.second;
        //cout << curIndex << ' ' << sCnt << ' ' << wCnt << '\n';
        if (answer < sCnt)answer = sCnt;

        for (int i = 0; i < N; i++) {
            if (con[curIndex][i] == false) continue;

            int ncon = Info[i];
            int nsCnt = sCnt;
            int nwCnt = wCnt;
            int ni = i;
            vector<bool> newCon = curCon;
            
            if (newCon[ni]) {

            }
            else {
                if (ncon == 0)nsCnt++;
                else nwCnt++;
                newCon[ni] = true;
            }

            if (v[ni][nsCnt][nwCnt]) continue;

            if (nsCnt <= nwCnt) continue;
            else {
                q.push({ { ni,{nsCnt,nwCnt} },newCon });
                v[ni][nsCnt][nwCnt] = true;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    N = info.size();
    Info = info;
    for (int i = 0; i < edges.size(); i++) {
        con[edges[i][0]][edges[i][1]] = true;
        con[edges[i][1]][edges[i][0]] = true;
    }


    bfs();

    return answer;
}