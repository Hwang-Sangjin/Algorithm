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
    
    string s;

    cin>>s;

    int cnt=0;

    string maxS = "";
    string minS = "";

    for(int i=0;i<s.length();i++){
        if(s[i]=='K'){
            maxS+='5';
            for(int j=0;j<cnt;j++){
                maxS+='0';
            }

            if(cnt>=1){
                minS+='1';
                for(int j=0;j<cnt-1;j++){
                    minS+='0';
                }
            }
            
            minS+='5';
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    if(cnt!=0){
        for(int i=0;i<cnt;i++){
            maxS+='1';
        }
        minS+='1';
        for(int i=0;i<cnt-1;i++){
            minS+='0';
        }
    }
    cout<<maxS<<'\n'<<minS;
    
    return 0;
}