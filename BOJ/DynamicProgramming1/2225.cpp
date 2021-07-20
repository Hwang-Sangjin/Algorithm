#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int dp[202][202];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int p = 0; p <= j; p++) {
                dp[j][i] = (dp[j][i] + dp[j-p][i-1])% 1000000000;
            }
        }
    }

    cout << dp[n][k];

    return 0;
}

