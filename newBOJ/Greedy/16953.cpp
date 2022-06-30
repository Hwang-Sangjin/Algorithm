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
    
    int A,B;
    cin>>A>>B;

    int res=1;
    while(1){
        if(B==A){
            break;
        }
        if( B < A){
            res = -1;
            break;
        }

        if(B%10==1){
            res++;
            B--;
            B /= 10;
        }
        else if(B%2==0){
            res++;
            B/=2;
        }
        else{
            res = -1;
            break;
        }
    }
    cout<<res;

    return 0;
}