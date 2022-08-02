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
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int N,M;
    cin>>N>>M;

    vector<int> v(N);
    int s=0,e=0;

    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    int cnt=0;
    int temp=0;
    while(e<=N){
        //cout<<s<<' '<<e<<' '<<temp<<'\n';
        if(temp >= M){
            temp-=v[s];
            s++;
        }
        else if(temp< M){
            temp+=v[e];
            e++;
        }
        if(temp==M){
            cnt++;
        }
    }

    cout<<cnt;

  
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}