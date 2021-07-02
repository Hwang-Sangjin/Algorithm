#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int E, S, M;
    cin >> E >> S >> M;
    E--;
    M--;
    S--;

    int res;
    int i = 0;
    while (1) {
        int year = i * 28 + S;
        
        if (year % 15 == E && year % 19 == M) {
            res = year;
            break;
        }

        i++;
    }
    cout << res+1;

    return 0;
}