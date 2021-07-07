#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int k;
vector<char> c;
vector<int> v;
bool check[11];
long long minres = -1;
long long maxres = -1;

void go(int cnt) {
    if (cnt == k) {
        string temp="";
        for (int i = 0; i <= k;i++) {
            temp += v[i]+48;
        }
        //cout << temp;
        long long tempint = stoll(temp);
        if (minres == -1 || minres > tempint) minres = tempint;
        if (maxres == -1 || maxres < tempint) maxres = tempint;
        return;
    }
    
    for (int i = 0; i <= 9; i++) {
        if (c[cnt] == '<') {
            if (v[cnt] < i && check[i] == false) {
                v.push_back(i);
                check[i] = true;
                go(cnt + 1);
                v.pop_back();
                check[i] = false;
            }
        }
        else {
            if (v[cnt] > i && check[i] == false) {
                v.push_back(i);
                check[i] = true;
                go(cnt + 1);
                v.pop_back();
                check[i] = false;
            }
        }
    }
}

int main() {
    cin >> k;
    char temp;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        c.push_back(temp);
    }

    for (int i = 0; i <= 9; i++) {
        v.push_back(i);
        check[i] = true;
        go(0);
        v.pop_back();
        check[i] = false;
    }
    if (minres < pow(10, k)) {
        cout << maxres << '\n'<<'0' << minres;
    }
    else {
        cout << maxres << '\n' << minres;
    }

   

    return 0;
}