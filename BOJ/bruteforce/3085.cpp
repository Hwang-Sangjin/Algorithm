#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
int res = 0;
int N;

void check(vector<vector<int>> v) {
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        for (int j = 0; j < N - 1; j++) {
            if (v[i][j] == v[i][j + 1]) {
                cnt++;
            }
            else {
                res = max(res, cnt);
                cnt = 1;
            }
        }
        res = max(res, cnt);
        cnt = 1;
        for (int j = 0; j < N - 1; j++) {
            if (v[j][i] == v[j+1][i]) {
                cnt++;
            }
            else {
                res = max(res, cnt);
                cnt = 1;
            }
        }
        res = max(res, cnt);
    }

    return;
}

int main() {

    
    cin >> N;

    vector<vector<int>>m(N);

    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        for (int j = 0; j < N; j++) {
            //cout << temp[j];
            if (temp[j] == 'C') {
                m[i].push_back(1);
            }
            else if (temp[j] == 'P') {
                m[i].push_back(2);
            }
            else if (temp[j] == 'Z') {
                m[i].push_back(3);
            }
            else if (temp[j] == 'Y') {
                m[i].push_back(4);
            }
            
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            vector<vector<int>>change = m;
            int temp = change[i][j];
            change[i][j] = change[i + 1][j];
            change[i + 1][j] = temp;

            check(change);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            vector<vector<int>>change = m;
            int temp = change[i][j];
            change[i][j] = change[i][j+1];
            change[i][j+1] = temp;

            check(change);
        }
    }

    cout << res;

    return 0;
}