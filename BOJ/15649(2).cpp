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

void recursive(int x) {
    if (x == M) {
        for (auto t : v) {
            cout << t << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (check[i]) continue;
        check[i] = true;
        v.push_back(i);
        recursive(x + 1);
        v.pop_back();
        check[i] = false;
    }
}

int main() {
    
    
    cin >> N >> M;

    recursive(0);
    
    return 0;
}