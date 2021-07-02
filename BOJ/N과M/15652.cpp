#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
int N, M;
bool check[10];
vector<int>v;

void recursive(int x, int least) {
    if (x == M) {
        for (auto t : v) {
            cout << t << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = least; i <= N; i++) {
        //if (check[i]) continue;
        //check[i] = true;
        v.push_back(i);
        recursive(x + 1,i);
        v.pop_back();
        //check[i] = false;
    }
}

int main() {
    
    
    cin >> N >> M;

    recursive(0,1);
    
    return 0;
}