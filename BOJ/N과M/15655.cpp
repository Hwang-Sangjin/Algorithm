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
vector<int> arr;
vector<int>v;

void recursive(int x, int least) {
    if (x == M) {
        for (auto t : v) {
            cout << t << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = least; i < N; i++) {
        if (check[i]) continue;
        check[i] = true;
        v.push_back(arr[i]);
        recursive(x + 1,i);
        v.pop_back();
        check[i] = false;
    }
}

int main() {
    
    
    cin >> N >> M;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    recursive(0,0);
    
    return 0;
}