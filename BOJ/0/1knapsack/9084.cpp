#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
int dp[10001];

int main() {
    int T,temp;
    cin >> T;

    while (T--) {
        memset(dp, 0, sizeof(dp));
        int N,M;
        cin >> N;
        
        vector<int> coin;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            coin.push_back(temp);
        }

        cin >> M;
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coin[i]; j <= M; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }
        cout << dp[M] << '\n';
    }

    return 0;
}