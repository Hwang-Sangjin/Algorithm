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
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    
     bool check =prev_permutation(v.begin(), v.end());

     if (check == false) cout << -1;

     else {
         for (auto t : v) {
             cout << t << ' ';
         }
     }

    return 0;
}