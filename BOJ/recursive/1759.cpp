#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    vector<char> v;
    vector<int> mask;
    
    int L, C;

    cin >> L >> C;

    char temp;
    for (int i = 0; i < C; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < L; i++) {
        mask.push_back(0);
    }
    for (int i = 0; i < C - L; i++) {
        mask.push_back(1);
    }

    do {
        int mo = 0;
        int ja = 0;
        vector<char> temp;
        for (int i = 0; i < C; i++) {
            if (mask[i] == 0) {
                if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') mo++;
                else ja++;
                temp.push_back(v[i]);
            }
        }

        if (mo >= 1 && ja >= 2) {
            for (auto t : temp) {
                cout << t;
            }
            cout << '\n';
        }
        
        
    } while (next_permutation(mask.begin(), mask.end()));
    
    return 0;
}