#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;
string s;
bool sosu[1000002];


bool so(long long num) {
   if (num < 2) return false;
   long long a = (long long) sqrt(num);
   for (long long i = 2; i <= a; i++) if (num % i == 0) return false;
   return true;
}

void func(int n, int k){
    stack<int> st;
    
    while(n>=k){
        int temp = n%k;
        st.push(temp);
        n/=k;
    }
    st.push(n);
    
    while(!st.empty()){
        s+=to_string(st.top());
        st.pop();
    }
}

int solution(int n, int k) {
    int answer = 0;
    
    sosu[0] = true; sosu[1] = true;
    for(int i=2;i<=1000000;i++){
        for(int j=2;i*j<=1000000;j++){
            sosu[i*j] = true; // 소수가 아니면 true
        }
    }
    
    func(n,k);
    s+='0';
    
    cout<<s<<'\n';
    
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='0' && temp!=""){
            long long t = stoll(temp);
            //cout<<t<<'\n';
            if(t<=1000000){
                if(sosu[t] == false) answer++;
            }
            else{
                if(so(t))answer++;
            }
            temp="";
        }
        else{
            temp+=s[i];
            //cout<<temp<<'\n';
        }
        //cout<<s[i];
    }
    
    return answer;
}