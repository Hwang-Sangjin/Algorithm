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
    int N;
    cin >> N;
    long long res = 0;
    int index = 0;

    for (int i = 1; i <= 10; i++) {
        if (pow(10, i) > N) {
            index = i;
            break;
        }
    }

    //cout << index;
    
    for (int i = 1; i < index; i++) {
        res += (pow(10, i) - pow(10, i - 1)) * i;
    }
    
    int temp = pow(10, index-1);
    int dis = N-temp+1;
    res += dis * index;
    cout << res;

    return 0;
}