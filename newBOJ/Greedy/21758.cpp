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
    
    int N;
    cin>>N;

    vector<int> v(N+1);

    int total = 0;
    for(int i=0;i<N;i++){
        cin>>v[i];
        total+=v[i];
    }

    int ans = 0;
    int dup;

    //벌 - 꿀 - 벌

    for(int i=1;i<N;i++){
        dup = v[i];
        ans = max(ans,total - v[0] - v[N-1] + dup);
    }

    //벌 - 벌 - 꿀
    dup = total- v[0];
    for(int i=1;i<N-1;i++){
        dup -=v[i];
        ans = max(ans,total -v[0] - v[i] + dup);
    }

    //꿀 - 벌 - 벌
    dup = total - v[N-1];
    for(int i=N-2;i>0; i--){
        dup -= v[i];
        ans = max(ans,total - v[N-1] - v[i] + dup);
    }

    cout<<ans;


    
    return 0;
}