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

    int X,N;
    cin>>X>>N;

    vector<int> v(X);

    for(int i=0;i<X;i++){
        cin>>v[i];
    }

    int s=0,e=N-1;
    int maxV=0;
    int cnt=0;
    int temp=0;

    for(int i=s;i<=e;i++){
        temp+=v[i];
    }
    maxV=temp;
    cnt=1;
    for(int i=1;i<X-N+1;i++){
        
        temp+=v[N+i-1];
        temp-=v[i-1];

        if(temp == maxV){
            cnt++;
        }
        else if(temp > maxV){
            maxV=temp;
            cnt=1;
        }
    }

    if(maxV==0){
        cout<<"SAD";
    }
    else{
        cout<<maxV<<'\n'<<cnt;
    }
    
  
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}