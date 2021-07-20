#include <iostream>
#include <cmath>
using namespace std;

int dp[100002];

int main()
{
    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1; 
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; i++) {
        dp[i] = i;

        for (int k = 2; pow(k, 2) <= i; k++) {
            long long temp = pow(k, 2);
            if (dp[i] > dp[i - temp] + 1) {
                dp[i] = dp[i - temp] + 1;
            }
        }
    }
    cout << dp[n];

    return 0;
}

