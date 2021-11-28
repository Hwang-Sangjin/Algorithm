#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, start =1, index =0;
    
    while(start <=n){
        //cout<<start<<' '<<answer<<'\n';
        if(start >= stations[index]-w && start <= stations[index]+w){
            start = stations[index]+w;
            index++;
        }
        else{
            start +=w*2;
            answer++;
        }
        start++;
    }

    return answer;
}