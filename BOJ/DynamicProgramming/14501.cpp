#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int dp[17];

int main()
{
    int n;
    cin >> n;
    vector<int> t(n + 2);
    vector<int> p(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    int res = 0;
    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j]);

            if (j + t[j] == i) {
                dp[i] = max(dp[i], dp[j] + p[j]);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res;

    return 0;
}

