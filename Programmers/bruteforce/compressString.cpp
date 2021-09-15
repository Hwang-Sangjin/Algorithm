#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int solution(string s) {
    int answer = s.length();
    int len = s.length();
    
    for(int i=1;i<=len/2;i++){
        string result = "";
        
        string ss = s.substr(0,i);
        int cnt=1;
        
        for(int j=i;j<=len;j+=i){
            if(ss == s.substr(j,i)){
                cnt++;
            }
            else{
                if(cnt==1){
                    result+=ss;
                }
                else{
                    result+=(to_string(cnt)+ss);
                }
                ss=s.substr(j,i);
                cnt=1;
            }
        }
        if((len%i)!=0){
            result+=s.substr((len/i)*i);
        }
        if(answer > result.size()) answer =result.size();
    }
    
    
    
    return answer;
}