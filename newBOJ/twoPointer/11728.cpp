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

    vector<int> A(N);
    vector<int> B(M);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<M;i++){
        cin>>B[i];
    }

    int a=0,b=0;
    vector<int>res;

    while(a<=N || b<=M){
        if(a==N){
            for(int i=b;i<M;i++){
                res.push_back(B[i]);
            }
            break;
        }
        if(b==M){
            for(int i=a;i<N;i++){
                res.push_back(A[i]);
            }
            break;
        }

        if(A[a]<=B[b]){
            res.push_back(A[a++]);
        }
        else{
            res.push_back(B[b++]);
        }
    }
    for(auto t: res){
        cout<<t<<' ';
    }

  
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}