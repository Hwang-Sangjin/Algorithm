#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool che[1000002];
vector<int> sosu;

int main() {

    che[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        for (int j = 2; i * j <= 1000000; j++) {
            che[i * j] = true;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        if (che[i]) continue;
        sosu.push_back(i);
    }

    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        bool check = false;

        for (auto t : sosu) {
            if (che[n - t] == false) {
                printf("%d = %d + %d\n", n, t, n - t);
                check = true;
                break;
            }
        }
        if (check == false) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    
    return 0;
}