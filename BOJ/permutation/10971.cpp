#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int map[12][12];
vector<int> v;

int res = -1;

int main() {

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        v.push_back(i);
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    do {

        int temp = 0;
        bool check = true;

        for (int i = 0; i < N - 1; i++) {
            if (map[v[i]][v[i + 1]] == 0) {
                check = false;
                break;
            }
            temp += map[v[i]][v[i + 1]];
        }
        if (map[v[N - 1]][v[0]] == 0) check = false;
        else {
            temp += map[v[N - 1]][v[0]];
        }


        if (check == false) continue;

        if (res == -1 || res > temp) res = temp;
        
    } while (next_permutation(v.begin(), v.end()));

    cout << res;

    return 0;
}