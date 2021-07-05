#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

vector<char> v;
vector<char>res;
int L, C;

void go(int index, int cnt) {
    if (cnt == L) {
        int mo = 0;
        int ja = 0;

        for (auto t : res) {
            if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') mo++;
            else ja++;
        }

        if (mo >= 1 && ja >= 2) {
            for (auto t : res) {
                cout << t;
            }
            cout << '\n';
        }
        return;
    }

    for (int i = index + 1; i < C; i++) {
        res.push_back(v[i]);
        go(i, cnt + 1);
        res.pop_back();
    }
}

int main() {

    
   

    cin >> L >> C;

    char temp;
    for (int i = 0; i < C; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    go(-1, 0);
    
    return 0;
}