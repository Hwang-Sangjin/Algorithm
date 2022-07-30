#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <string> 
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int sum;
int dp[102][10002];
int bite[102];
int cost[102];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N,K; cin>>N>>K;

    for(int i=1;i<=N;i++) cin>>bite[i];
    for(int i=1;i<=N;i++){
        cin>>cost[i];
        sum+=cost[i];
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<=sum;j++){
            if(cost[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + bite[i]);
            }
        }
    }

    for(int i=0;i<=sum;i++){
        if(dp[N][i]>= K){
            cout<<i;
            break;
        }
    }

   

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}