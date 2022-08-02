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

int money[8]= {50000,10000,5000,1000,500,100,50,10}; 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;

        cout<<'#'<<test_case<<'\n';
        for(int i=0;i<8;i++){
            cout<<N/money[i]<<' ';
            N%=money[i];
        }
        cout<<'\n';
	}

  
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}