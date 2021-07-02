#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 1) {
            cout << 1 <<'\n';
            continue;
        }

        int i = 2;
        long long res = 1;
        while (1) {
            res = (((res * 10) % n) + 1) % n;

            if (res == 0) {
                cout << i << '\n';
                break;
            }
            i++;
        }

    }



    return 0;
}