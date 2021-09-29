#include <string>
#include <vector>
#include <set>

using namespace std;

int n, Number;
int answer =-1;

void dfs(int index, int currentNumber){
    if(index>=9) return;
    if(currentNumber == Number){
        if(answer == -1) answer = index;
        else{
            answer = min(answer, index);
        }
        return;
    }
    
    int temp=0;
    
    for(int i=0;i+index<9;i++){
        temp = temp*10 +n;
        dfs(index+1+i,currentNumber+temp);
        dfs(index+1+i,currentNumber-temp);
        dfs(index+1+i,currentNumber*temp);
        dfs(index+1+i,currentNumber/temp);
    }
}

int solution(int N, int number) {
    n =N;
    Number = number;
    dfs(0,0);
    return answer;
}