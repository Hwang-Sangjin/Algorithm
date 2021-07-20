#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;

int cost[1002][3];
int dp[1002][3];//0 red, 1 green, 2 blue

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    for (int j = 0; j < 3; j++) {
        dp[1][j] = cost[1][j];
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    int res = min(min(dp[n][0], dp[n][1]), dp[n][2]);
    cout << res;

    return 0;
}

