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
    
    int N,temp;
    cin>>N;

    priority_queue<int,vector<int>,greater<int>> pq;

    while(N--){
        cin>>temp;
        pq.push(temp);
    }

    int res=0;
    while(pq.size()!=1){
        int f = pq.top(); pq.pop();
        int s = pq.top(); pq.pop();

        res+=f+s;
        pq.push(f+s);
    }
    cout<<res;
    
    return 0;
}