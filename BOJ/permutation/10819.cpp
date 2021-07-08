#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int>v;

int main() {
    int N;
    int res = 0;
    cin >> N;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());

    do {

        int temp = 0;
        for (int i = 0; i < N-1; i++) {
            temp += abs(v[i] - v[i + 1]);
        }

        if (temp > res) res = temp;
    } while (next_permutation(v.begin(), v.end()));

    cout << res;
    return 0;
}