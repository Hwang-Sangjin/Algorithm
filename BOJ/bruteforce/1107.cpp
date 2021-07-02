#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

bool broken[11];

int check(int x) {
    int cnt=0;
    if (x == 0) {
        if (broken[0] == true) cnt = 0;
        else cnt = 1;
    }
    else {
        while (x > 0) {
            if (broken[x % 10] == true) {
                return 0;
            }
            x = x / 10;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int N,M;
    cin >> N>>M;

    int b;
    while (M--) {
        cin >> b;
        broken[b] = true;
    }

    int res = abs(100 - N);

    for (int i = 0; i <= 1000000; i++) {
        int cnt = check(i);

        if (cnt == 0) continue;
        else {
            res = (res > cnt + abs(N - i)) ? cnt + abs(N - i) : res;
        }
    }
    cout << res;

    return 0;
}