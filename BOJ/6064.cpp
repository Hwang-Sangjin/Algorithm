#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int x, int y) {
    int z;

    while (y != 0) {
        z = x % y;
        x = y;
        y = z;
    }

    return x;
}

int main() {
    int T;
    cin >> T;
    int M, N, x, y;
    while (T--) {
        cin >> M >> N >> x >> y;
        int tx = 1;
        int ty = 1;
        
        int g = gcd(M, N);
        g = M * N / g;
        bool check = false;
        int res = 1;
        while (1) {
            if (res > g) break;
            //cout << tx << ' ' << ty << '\n';

            if (tx == x && ty == y) {
                cout << res << '\n';
                check = true;
                break;
            }

            else {
                if (tx == x) {
                    res += M;
                    ty += M;
                    ty = ty % N;
                    if (ty == 0) ty = N;
                }
                else {
                    if (tx > x) {
                        int temp = M - tx + x;
                        res += temp;
                        tx = x;
                        ty += temp;
                        ty = ty % N;
                        if (ty == 0) ty = N;
                    }
                    else {
                        int temp = x-tx;
                        res += temp;
                        tx = x;
                        ty += temp;
                        ty = ty % N;
                        if (ty == 0) ty = N;
                    }
                }
            }
        }

        if (check == false) {
            cout << -1 << '\n';
        }
    }

    return 0;
}