#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> st;
    
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            char t = st.top();
            if(t == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    
    if(st.empty()) answer=1;
    
    return answer;
}