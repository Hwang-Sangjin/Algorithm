#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<int>Bnum;
vector<int>Anum;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    for(int i=0;i<B.size();i++){
        Anum.push_back(A[i]);
        
        Bnum.push_back(B[i]);
    }
    
    sort(Anum.begin(),Anum.end());
    sort(Bnum.begin(),Bnum.end());
    
    int Bindex=0;
    for(int i=0;i<Anum.size();i++){
        for(int j=Bindex;j<Bnum.size();j++){
            if(Anum[i] < Bnum[j]){
                answer++;
                Bindex = j+1;
                break;
            }
        }
    }
    
    
    return answer;
}