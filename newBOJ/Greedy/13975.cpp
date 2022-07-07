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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;
    cin>>T;

    while(T--){
        int K;
        long long temp;
        cin>>K;
        long long res =0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        while(K--){
            cin>>temp;
            pq.push(temp);
        }
        while(pq.size()!=1){
            long long f = pq.top();
            pq.pop();
            long long s = pq.top();
            pq.pop();

            res+=s+f;
            pq.push(f+s);
        }
        cout<<res;
    }
    
    return 0;
}