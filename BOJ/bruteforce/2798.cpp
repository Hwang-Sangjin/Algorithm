#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> mask(n-3);

    bool check = false;
    int res = 0;
    int disres = -1;
    mask.push_back(1);
    mask.push_back(1);
    mask.push_back(1);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    do {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (mask[i] == 1) {
                temp += v[i];
            }
        }
        if (temp > m) continue;
        int distemp = abs(m - temp);
        

        if (disres == -1 || distemp < disres) {
            res = temp;
            disres = abs(m - res);
        }

    } while (next_permutation(mask.begin(), mask.end()));

    cout << res;
    return 0;
}
