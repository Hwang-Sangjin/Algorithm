#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//vector , map
//vector - 뒷구녕으로 삽입, 배열 기반 container participant[0]
//map - key value 알아서 정렬

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    //string을 key로하고 int value로 하는 그런 녀석으로 map
    //participant를 한번 순회를 하면서 map에 하나씩 넣고 계산 이름의 개수를 카운트
    //completion을 한번 순회 카운트를 하나씩 빼보자
    
    map<string, int> m; // map은 int 선언을 하면 default값이 0
    
    for(auto t: participant){ // for auto 는 vector 다른 container -> container 원소들을 모두 순회할 때 됨        
        m[t]++;// map에 t라는 녀석이 한개 더 이써요!
        //cout<<t<<' '<<m[t]<<'\n';
    }
    //cout<<"!!!!!!!!!!!!\n";
    // m이란 map에  participant의 이름의 개수가 저장 성공!
    
    for(auto t: completion){
        m[t]--;
        //cout<<t<<' '<<m[t]<<'\n';
    }
    //cout<<"!!!!!!!!!!!!\n";
    
    //map에서 순회를 하면서 value값이 0이 아닌 녀석을 찾으면 된다
    for(auto t: m){ // m의 원소들은 뭘까? -> fair <string,int>
        //cout<<t.first<<' '<<t.second<<'\n';
        if(t.second != 0){
            answer = t.first;
        }
    }
    
    return answer;
}