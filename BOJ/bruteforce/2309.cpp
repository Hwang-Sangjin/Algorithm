#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;

    vector<int> mask(7, 1);

    int temp;
    for (int i = 0; i < 9; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    mask.push_back(0);
    mask.push_back(0);
    sort(mask.begin(), mask.end());
    sort(v.begin(), v.end());

    do {
        int res = 0;
        for (int i = 0; i < 9; i++) {
            if (mask[i] == 0) continue;
            else {
                res += v[i];
            }
        }
        if (res == 100) {
            for (int i = 0; i < 9; i++) {
                if (mask[i] == 0) continue;
                else {
                    cout << v[i] << '\n';
                }
            }
            break;
        }

    } while (next_permutation(mask.begin(), mask.end()));


    return 0;
}