#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <queue>

int dk[6] = { 0,0,0,0,1,-1 };
int di[6] = { -1,0,1,0,0,0 };
int dj[6] = { 0,1,0,-1,0,0 };

using namespace std;

char map[32][32][32];
bool v[32][32][32];

int main()
{
    int L, R, C;

    while (1) {
        char temp;
        int si, sj, sk;
        int ei, ej, ek;
        bool find = false;
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0) {
            break;
        }
        memset(v, false, sizeof(v));

        scanf_s("%1c", &temp);
        
        for (int k = 0; k < L; k++) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    scanf("%1c", &map[k][i][j]);
                    if (map[k][i][j] == 'S') {
                        si = i;
                        sj = j;
                        sk = k;
                    }
                    else if (map[k][i][j] == 'E') {
                        ei = i;
                        ej = j;
                        ek = k;
                    }
                }
                scanf("%1c", &temp);
            }
            scanf("%1c", &temp);
        }
        
        queue <pair<pair<int, int>, pair<int,int>>> q;
        q.push({ {sk,0},{si,sj } });
        v[sk][si][sj] = true;

        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto tij = t.second;
            auto tkc = t.first;
            int ti = tij.first;
            int tj = tij.second;
            int tk = tkc.first;
            int tcnt = tkc.second;
            //cout << ti << ' ' << tj << ' ' << tk << ' ' << tcnt << '\n';

            for (int k = 0; k < 6; k++) {
                int nk = tk + dk[k];
                int nj = tj + dj[k];
                int ni = ti + di[k];
                //cout << ni << ' ' << nj << ' ' << nk << ' ' << tcnt << '\n';

                if (nk < 0 || ni < 0 || nj < 0 || nk >= L || ni >= R || nj >= C || v[nk][ni][nj] || map[nk][ni][nj] == '#') continue;

                if (map[nk][ni][nj] == 'E') {
                    cout << "Escaped in "<<tcnt+1<<" minute(s)." << '\n';
                    find = true;
                    break;
                }

                q.push({ {nk,tcnt + 1},{ni,nj} });
                v[nk][ni][nj] = true;
            }
            if (find) break;
        }

        if (find == false) {
            cout << "Trapped!" << '\n';
        }
    }
    return 0;
}

