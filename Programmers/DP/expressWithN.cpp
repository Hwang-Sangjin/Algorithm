#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer=-1;
    
    vector<set<int>> dp(9);
    dp[1].insert(N);
    
    int temp =N;
    for(int i=2;i<=8;i++){
        temp = temp*10+N;
        dp[i].insert(temp);
        
        for(int j=1;j<=i;j++){
            for(int k=i-j;k>0;k--){
                for(auto a: dp[j]){
                    for(auto b: dp[k]){
                        dp[i].insert(a+b);
                        dp[i].insert(a*b);
                        if(a>b){
                            dp[i].insert(a-b);
                        }
                        if(a/b>0){
                            dp[i].insert(a/b);
                        }
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=8;i++){
        if(dp[i].count(number)){
            answer = i;
            break;
        }
    }
    
    return answer;
}