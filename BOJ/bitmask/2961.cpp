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

struct food{
    int sour;
    int bitter;
};

int N;
vector<food> element;
long long res=-1;

void DFS(){
    long long s,b;
    for(int i=1;i<(1<<N);i++){
        long long tS=1;
        long long tB =0;
        for(int j=0;j<N;j++){
            
            int temp = (1<<j);

            if(temp&i){
                tS*=element[j].sour;
                tB+=element[j].bitter;
            }
        }

        if(res==-1 || res > abs(tS-tB)){
            res = abs(tS-tB);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    
    cin>>N;

    int s,b;

    for(int i=0;i<N;i++){
        cin>>s>>b;
        food temp = {s,b};
        element.push_back(temp);
    }

    DFS();
    cout<<res;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}