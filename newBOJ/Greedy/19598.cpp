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
vector<pair<int,int>> v;
int N;
priority_queue<int,vector<int>,greater<int>>pq;

int greedy(){
    pq.push(v[0].second);

    for(int i=1;i<N;i++){
        pq.push(v[i].second);

        if(pq.top() <= v[i].first){
            pq.pop();
        }
    }
    return pq.size();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    

    cin>>N;

    int s,f;
    for(int i=0;i<N;i++){
        cin>>s>>f;
        v.push_back({s,f});
    }

    sort(v.begin(),v.end());

    cout<<greedy();

    
    return 0;
}