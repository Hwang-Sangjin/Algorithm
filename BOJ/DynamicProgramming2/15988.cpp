#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;

long long dp[1000002];

int main()
{
    int t;
    cin >> t;

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;

    int n;
    int mx = 4;
    while (t--) {
        cin >> n;
        if (mx < n) {
            for (int i = mx; i <= n; i++) {
                dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%1000000009;
            }
            mx = n;
        }
        cout << dp[n] << '\n';
    }

    return 0;
}

