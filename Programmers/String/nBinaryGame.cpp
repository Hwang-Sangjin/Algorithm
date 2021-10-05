#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

char c[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string nBinary(int n, int index){
    stack<char> st;
    string res="";
    //cout<<index<<'\n';
    
    while(index!=0){
        //cout<<c[index%n];
        st.push(c[index%n]);
        index /=n; 
    }
    
    while(!st.empty()){
        //cout<<res<<'\n';
        res+=st.top();
        st.pop();
    }
    
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string temp="0";
    int resCnt = m*t;
    
    int index =0;
    
    for(int i=1;i<=resCnt;i++){
        temp+=nBinary(n,i);
        //cout<<temp<<'\n';
    }
    
    for(int i=0;i<t;i++){
        int pos = i*m+p-1;
        answer+=temp[pos];
    }
    
    return answer;
}