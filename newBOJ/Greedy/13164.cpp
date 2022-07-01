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
    
    int N,K;

    cin>>N>>K;

    vector<int> v(N);

    for(int i=0;i<N;i++){
        cin>>v[i];
    }

    vector<int>diff(N-1);

    int res =0;
    for(int i=0;i<N-1;i++){
        diff[i] = v[i+1] - v[i];
        res +=diff[i];
    }

    sort(diff.begin(),diff.end(),greater<>());

    for(int i=0;i<K-1;i++){
        res-=diff[i];
    }
    cout<<res;

    
    return 0;
}