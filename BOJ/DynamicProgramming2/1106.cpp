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
int dp[100002];

struct marketing{
    int cost;
    int num;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

    int c,n;
    cin>>c>>n;

    vector<marketing> v;

    int tc,tn;
    for(int i=0;i<n;i++){
        cin>>tc>>tn;
        v.push_back({tc,tn});
    }

    for(int i=1;i<=100000;i++){
        for(int j=0;j<n;j++){
            if(i% v[j].cost==0){
                dp[i] = max(dp[i],(i/v[j].cost) * v[j].num);
            }
            if(i>=v[j].cost){
                dp[i] = max(dp[i],dp[i-v[j].cost] + v[j].num);
            }
        }
        if (c<=dp[i]) {
			cout << i;
			return 0;
		}
    }


  
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}