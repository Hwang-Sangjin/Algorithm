#include <iostream>
#include <vector>
#include <string>
using namespace std;

int checked;
int word[50];   //N 최대 50개
int N, K;

int maxi = 0;

void DFS(int toPick, int start, int checked){    //증복조합
    
    if(toPick==0){  //배울 알파벳 골랐으면
        
        //그 알파벳들로 N개 단어 중 몇개 읽을 수 있는지 카운트해서 최대값 찾기
        int cnt = 0;
        for(int i = 0; i<N ;i++){
            if((word[i] & checked) == word[i]) cnt++;
        }
        if(maxi < cnt) maxi = cnt;
        return;
    }

    for(int i = start; i<26; i++){
        if((checked & (1<<i)) == 0){   //방문 안 한 경우에만
            checked |= (1<<i);
            DFS(toPick-1, i, checked);
            checked &= ~(1<<i);
        }
        
    }
}

int main(){
    
    cin >> N >> K;
    
    string str;
    for(int i = 0; i<N; i++){
        cin >> str;
        
        int num = 0;
        for(int j = 0; j<str.length(); j++){
            num |= 1 << (str[j] - 'a');
        }
        word[i] = num;
    }
    
    if(K<5) cout << 0;  //anta ~ tica 읽으려면 최소 a,n,t,i,c 5개 이상은 알고 있어야함
    else if (K==26) cout << N;
    else{
        
        //a, n, t, i, c 를 이미 알고 있음을 초기화.
        checked |= 1 << ('a'-'a');
        checked |= 1 << ('n'-'a');
        checked |= 1 << ('t'-'a');
        checked |= 1 << ('i'-'a');
        checked |= 1 << ('c'-'a');
        
        DFS(K-5, 0, checked);
        cout << maxi;
    }
 
    return 0;
}
