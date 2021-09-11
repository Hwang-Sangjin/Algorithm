#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n= skill.size();
    
    for(int i=0;i<n;i++){
        int skillType = skill[i][0];
        int si = skill[i][1];
        int sj = skill[i][2];
        int ei = skill[i][3];
        int ej = skill[i][4];
        int skillDegree = skill[i][5];
        if(skillType == 1){
            skillDegree*=-1;
        }
        
        for(int x = si;x<=ei;x++){
            for(int y = sj;y<=ej;y++){
                board[x][y]+=skillDegree;
            }
        }
    }
    
    for(int x = 0;x<board.size();x++){
            for(int y = 0;y<board[0].size();y++){
                if(board[x][y]>0)answer++;
            }
        }
    
    return answer;
}