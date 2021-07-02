#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
int N, M;
bool check[10];
vector<int>v;

void go(int x, int cnt) {
    
    if (cnt == M) {
        for (auto t : v) {
            cout << t << ' ';
        }
        cout << '\n';
        return;
    }
    else {
        for (int i = 1; i <= N; i++) {
            if (check[i]) continue;
            check[i] = true;
            v.push_back(i);
            go(i, cnt + 1);
            v.pop_back();
            check[i] = false;
        }
    }
   
    return;
}

int main() {
    
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        check[i] = true;
        v.push_back(i);
        go(i, 1);
        v.pop_back();
        check[i] = false;
    }
    
    return 0;
}