#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

vector<pair<int, int>> v;
int N;
int ans = 0;
int price = 0;
int res = 0;

void go(int index) {
    if (index > N) {
        if (index == N+1) {
            if (res < price) res = price;
        }
        return;
    }

    price += v[index].second;
    go(index + v[index].first);
    price -= v[index].second;
    go(index + 1);
}

int main() {
    cin >> N;

    int t,p;
    v.push_back({ 0,0 });
    for (int i = 0; i < N; i++) {
        cin >> t >> p;
        v.push_back({ t,p });
    }
    
    go(1);
    
    cout << res;
    return 0;
}