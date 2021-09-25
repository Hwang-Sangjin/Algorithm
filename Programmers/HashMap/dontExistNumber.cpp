#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> numbers) {
    int answer =0;
    map<int, bool> m;
    for(int i=0;i<numbers.size();i++){
        m[numbers[i]] = true;
    }
    
    for(int i=0;i<10;i++){
        if(m[i])continue;
        answer+=i;
    }
    
    return answer;
}