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
    cin >> N;

    int temp;
    for (int i = 1; i <= N; i++) {
        
        v.push_back(i);
    }
    
    do {

        for (auto t : v) {
            cout << t << ' ';
        }
        cout << '\n';

    } while (next_permutation(v.begin(), v.end()));

    return 0;
}